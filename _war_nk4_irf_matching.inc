addpath('nicer_plots_in_Dynare'); % for nicer prior vs posterior plots
  
%%%%%%%%%%%%%%%
% OBSERVABLES %
%%%%%%%%%%%%%%%
varobs
plot_gdp_H plot_pi_H
plot_gdp_N plot_pi_N
plot_gdp_D plot_pi_D

plot_k_H plot_a_H plot_g_H
plot_k_N plot_a_N plot_g_N
plot_k_D plot_a_D plot_g_D
;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DECLARE WHICH IRFS TO MATCH %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% we use helper function "data_selector(country,varname,weight)" that provides values and weights
matched_irfs;
  var plot_gdp_H; varexo eps_war; periods 1:9; values (data_selector(1,1,0)); weights (data_selector(1,1,1));
  var plot_gdp_N; varexo eps_war; periods 1:9; values (data_selector(2,1,0)); weights (data_selector(2,1,1));
  var plot_gdp_D; varexo eps_war; periods 1:9; values (data_selector(3,1,0)); weights (data_selector(3,1,1));

  var plot_pi_H;  varexo eps_war; periods 1:9; values (data_selector(1,2,0)); weights (data_selector(1,2,1));
  var plot_pi_N;  varexo eps_war; periods 1:9; values (data_selector(2,2,0)); weights (data_selector(2,2,1));
  var plot_pi_D;  varexo eps_war; periods 1:9; values (data_selector(3,2,0)); weights (data_selector(3,2,1));

  %var plot_k_H; varexo eps_war; periods 1:9; values (data_selector(1,3,0)); weights (data_selector(1,3,1));
  %var plot_k_N; varexo eps_war; periods 1:9; values (data_selector(2,3,0)); weights (data_selector(2,3,1));
  %var plot_k_D; varexo eps_war; periods 1:9; values (data_selector(3,3,0)); weights (data_selector(3,3,1));

  %var plot_a_H;  varexo eps_war; periods 1:9; values (data_selector(1,4,0)); weights (data_selector(1,4,1));
  %var plot_a_N;  varexo eps_war; periods 1:9; values (data_selector(2,4,0)); weights (data_selector(2,4,1));
  %var plot_a_D;  varexo eps_war; periods 1:9; values (data_selector(3,4,0)); weights (data_selector(3,4,1));

  %var plot_g_H;  varexo eps_war; periods 1:9; values (data_selector(1,5,0)); weights (data_selector(1,5,1));
  %var plot_g_N;  varexo eps_war; periods 1:9; values (data_selector(2,5,0)); weights (data_selector(2,5,1));
  %var plot_g_D;  varexo eps_war; periods 1:9; values (data_selector(3,5,0)); weights (data_selector(3,5,1));
end;
  
%%%%%%%%%%
% PRIORS %
%%%%%%%%%%
estimated_params;
  WAR_RHO1_ROOT_H ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.10 ;
  WAR_RHO2_ROOT_H ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.10 ;  
  WAR_DELTA_K_H   ,  , 0    , 0.10 , inv_gamma_pdf , 0.025 , 0.10 ;  
  WAR_DELTA_A_H   ,  , 0    , 0.10 , inv_gamma_pdf , 0.020 , 0.10 ;  
  WAR_DELTA_G_H   ,  , 0    , 1.00 , inv_gamma_pdf , 0.035 , 0.10 ;
  WAR_DELTA_G_RDN ,  , 0    , 1.00 , inv_gamma_pdf , 0.001 , 0.10 ;  
  RHOA_H          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.10 ;  
  RHOG_H          ,  , 0    , 0.60 , beta_pdf      , 0.600 , 0.10 ;
  RHOG_RDN        ,  , 0    , 0.60 , beta_pdf      , 0.600 , 0.10 ;  
  RHOR_H          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.10 ;
  @#if MONETARY_POLICY == "TAYLOR_RULE"
  PSIRPI_H        ,  , 1.01 , 4.00 , normal_pdf    , 2.000 , 0.10 ;
  PSIRGDP_H       ,  , 0    , 0.75 , normal_pdf    , 0.500 , 0.10 ;
  @#endif
  RHOR_RDN        ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.10 ;
  @#if MONETARY_POLICY == "TAYLOR_RULE"
  PSIRPI_RDN      ,  , 1.01 , 4.00 , normal_pdf    , 2.000 , 0.10 ;
  PSIRGDP_RDN     ,  , 0    , 0.75 , normal_pdf    , 0.500 , 0.10 ;  
  @#endif
end;
  
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
                 %,load_mh_file
                 %,mh_replic=0
                 ,posterior_sampling_method = 'slice'
                 ,posterior_sampler_options = ('save_tmp_file',0
                                              )
                 ,plot_priors = 0
                 ,qz_criterium = 1.000001
                 ,dirname = war_slice
                 ,tex
                 ,graph_format = pdf
                 );
  
@#endif

@#ifdef SLICE_ROTATED
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ROTATED SLICE WITH COVARIANCE MATRIX FROM PREVIOUS STANDARD SLICE %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% copy results from previous slice
CheckPath('method_of_moments','war_slice_rotated');
CheckPath('metropolis','war_slice_rotated');
[status, cmdout] = system(sprintf('rsync -a --delete "%s/" "%s/"', 'war_slice/method_of_moments', 'war_slice_rotated/method_of_moments'));
[status, cmdout] = system(sprintf('rsync -a --delete "%s/" "%s/"', 'war_slice/metropolis', 'war_slice_rotated/metropolis'));
  
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
                 ,dirname = war_slice_rotated
                 ,tex
                 ,graph_format = pdf
);
  
@#endif

@#ifdef MODE_COMPUTE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MODE COMPUTE USING POSTERIOR MODE FROM PREVIOUS POSTERIOR DRAWS %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
method_of_moments(mom_method = irf_matching
                 ,plot_priors = 0
                 ,mode_file = 'war_slice_rotated/method_of_moments/war_nk4_mh_mode'
                 ,mode_compute = 5
                 %,additional_optimizer_steps=[8]
                 ,mh_replic=0
                 ,qz_criterium = 1.000001
                 ,dirname = war_mode_compute
                 ,tex
                 ,graph_format = pdf
                 );
  
@#endif

@#ifdef RWMH
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% RANDOM-WALK-METROPOLIS-HASTINGS USING PREVIOUSLY COMPUTED MODE & HESSIAN %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
method_of_moments(mom_method = irf_matching
                 ,mh_drop = 0.5
                 ,mh_jscale = 0.5
                 ,mh_nblocks = @{MH_NBLOCKS}
                 ,mh_replic = 100 %100000
                 %,load_mh_file
                 %,mh_replic=0
                 ,mode_compute = 0
                 ,mode_file = 'war_mode_compute/method_of_moments/war_nk4_mode'
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
                 ,dirname=war_rwmh
                 ,tex
                 ,graph_format = pdf
                 );
  
@#endif

% housekeeping
rmpath('nicer_plots_in_Dynare');