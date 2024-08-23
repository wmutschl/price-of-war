addpath('nicer_plots_in_Dynare'); % for nicer prior vs posterior plots
@{NEWLINE}

%%%%%%%%%%%%%%%
% OBSERVABLES %
%%%%%%%%%%%%%%%
varobs
plot_gdp_S plot_pi_S
plot_gdp_N plot_pi_N
plot_gdp_D plot_pi_D
;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DECLARE WHICH IRFS TO MATCH %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% we use helper function "pow_data_selector(country,varname,weight)" to set values and weights
matched_irfs;
  var plot_gdp_S; varexo eps_war; periods 1:9; values (pow_data_selector(1,1,0)); weights (pow_data_selector(1,1,1));
  var plot_gdp_N; varexo eps_war; periods 1:9; values (pow_data_selector(2,1,0)); weights (pow_data_selector(2,1,1));
  var plot_gdp_D; varexo eps_war; periods 1:9; values (pow_data_selector(3,1,0)); weights (pow_data_selector(3,1,1));

  var plot_pi_S;  varexo eps_war; periods 1:9; values (pow_data_selector(1,2,0)); weights (pow_data_selector(1,2,1));
  var plot_pi_N;  varexo eps_war; periods 1:9; values (pow_data_selector(2,2,0)); weights (pow_data_selector(2,2,1));
  var plot_pi_D;  varexo eps_war; periods 1:9; values (pow_data_selector(3,2,0)); weights (pow_data_selector(3,2,1));
end;
@{NEWLINE}

@#ifdef SLICE
%%%%%%%%%%%%%%%%%%%%%%%%%%%
% STANDARD SLICE SAMPLING %
%%%%%%%%%%%%%%%%%%%%%%%%%%%
method_of_moments(mom_method = irf_matching
                 ,simulation_method = stoch_simul
                 ,order = 1
                 ,mh_nblocks = @{MH_NBLOCKS}
                 ,mh_drop = 0.5
                 ,mh_replic = 200
                 ,posterior_sampling_method = 'slice'
                 ,posterior_sampler_options = ('save_tmp_file',0
                                              )
                 ,plot_priors = 0
                 ,qz_criterium = 1.000001
                 ,dirname = @{MODEL_NAME}_slice
                 ,tex
                 ,graph_format = pdf
                 );
@{NEWLINE}
@#endif

@#ifdef SLICE_ROTATED
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ROTATED SLICE WITH COVARIANCE MATRIX FROM PREVIOUS STANDARD SLICE %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% copy results from previous slice
CheckPath('method_of_moments','@{MODEL_NAME}_slice_rotated');
CheckPath('metropolis','@{MODEL_NAME}_slice_rotated');
[status, cmdout] = system(sprintf('rsync -a --delete "%s/" "%s/"', '@{MODEL_NAME}_slice/method_of_moments', '@{MODEL_NAME}_slice_rotated/method_of_moments'));
[status, cmdout] = system(sprintf('rsync -a --delete "%s/" "%s/"', '@{MODEL_NAME}_slice/metropolis', '@{MODEL_NAME}_slice_rotated/metropolis'));
@{NEWLINE}

method_of_moments(mom_method = irf_matching
                 ,mh_nblocks = @{MH_NBLOCKS}
                 ,mh_replic = 1000
                 ,plot_priors = 0
                 ,load_mh_file
                 ,posterior_sampling_method = 'slice'
                 ,posterior_sampler_options = ('save_tmp_file',0
                                              ,'rotated',1
                                              ,'use_mh_covariance_matrix',1
                                              )
                 ,qz_criterium = 1.000001
                 ,dirname = @{MODEL_NAME}_slice_rotated
                 ,tex
                 ,graph_format = pdf
);
@{NEWLINE}
@#endif

@#ifdef MODE_COMPUTE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NUMERICALLY FIND MODE USING MODE FROM PREVIOUS POSTERIOR DRAWS AS INITIAL POINT %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
method_of_moments(mom_method = irf_matching
                 ,plot_priors = 0
                 ,mode_file = '@{MODEL_NAME}_slice_rotated/method_of_moments/@{MODEL_NAME}_mh_mode'
                 ,mode_compute = 5
                 %,additional_optimizer_steps=[8]
                 ,mh_replic=0
                 ,qz_criterium = 1.000001
                 ,dirname = @{MODEL_NAME}_mode_compute
                 ,tex
                 ,graph_format = pdf
                 );
@{NEWLINE}
@#endif

@#ifdef RWMH
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% RANDOM-WALK-METROPOLIS-HASTINGS USING PREVIOUSLY OPTIMIZED MODE AND HESSIAN %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
method_of_moments(mom_method = irf_matching
                 ,mh_drop = 0.5
                 ,mh_jscale = 0.5
                 ,mh_nblocks = @{MH_NBLOCKS}
                 ,mh_replic = 1000000
                 ,mode_compute = 0
                 ,mode_file = '@{MODEL_NAME}_mode_compute/method_of_moments/@{MODEL_NAME}_mode'
                 ,plot_priors = 0
                 ,posterior_sampling_method = 'random_walk_metropolis_hastings'
                 ,posterior_sampler_options = ('proposal_distribution'
                                              %,'rand_multivariate_normal'
                                              ,'rand_multivariate_student'
                                              ,'student_degrees_of_freedom',10
                                              %,'use_mh_covariance_matrix',1
                                              )
                 ,qz_criterium = 1.000001
                 ,raftery_lewis_diagnostics
                 ,dirname=@{MODEL_NAME}_rwmh
                 ,tex
                 ,graph_format = pdf
                 );
@{NEWLINE}
@#endif