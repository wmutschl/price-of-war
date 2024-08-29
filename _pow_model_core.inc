@#define NEWLINE = "  "
@#includepath "DynareModWizard/modfile"

@#define CLOSING_COUNTRY                    = "R"
@#define GROWTH                             = false
@#define INTERMEDIATE_INPUTS                = true
@#define CAPITAL                            = true
@#define ADJUSTMENT_COSTS_IN_CAPITAL_LOM    = "CAPITAL"
@#define CAPITAL_UTILIZATION_RESOURCE_COSTS = ""
@#define PARTIAL_INDEXATION_PRICES          = false
@#define PARTIAL_INDEXATION_WAGES           = false
@#define PRICING_REGIMES                    = ["PCP"]
@#define DOMINANT_CURRENCY                  = ""
@#define INTERNATIONAL_BONDS                = ["R"]
@#define CLOSING_CONDITION                  = "CARRYING_COST"
@#define IMPORT_ADJUSTMENT_COSTS            = true
@#define IMPORT_CONTENT_GOV_SPENDING        = false
@#define ICEBERG_COSTS                      = false
@#define ADD_FLEX_MODEL                     = false

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                         ENDOGENOUS VARIABLES                          %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
var
@#include "__var.inc"

% add plotting variables
@#for j in COUNTRIES
  plot_gdp_@{j} plot_pi_@{j} plot_k_@{j} plot_g_@{j} plot_a_@{j} plot_lab_@{j} plot_x_@{j} plot_nx_@{j}
@#endfor
@{NEWLINE}
% war shock
  war
;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                          EXOGENOUS VARIABLES                          %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
varexo
@#include "__varexo.inc"

% innovation to war shock
  eps_war
;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                              PARAMETERS                               %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
parameters
% declare latex names for estimated parameters (the duplicate declaration in __parameters.inc below will not overwrite the latex names)
  RHOA_S            ${\rho^{A}_{S}}$
  RHOG_S            ${\rho^{G}_{S}}$
@#if length(COUNTRIES) == 6
  RHOG_BN           ${\rho^{G}_{B_N}}$
  RHOG_BD           ${\rho^{G}_{B_D}}$
@#endif
@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
  RHOM_S            ${\rho^{M}_{S}}$
    @#if length(COUNTRIES) == 6
  RHOM_BN           ${\rho^{M}_{B_N}}$
  RHOM_BD           ${\rho^{M}_{B_D}}$
  RHOM_TN           ${\rho^{M}_{T_N}}$
  RHOM_TD           ${\rho^{M}_{T_D}}$
    @#else
  RHOM_N            ${\rho^{M}_{N}}$
  RHOM_D            ${\rho^{M}_{D}}$
    @#endif
@#elseif MONETARY_POLICY_RULE == "INTEREST_RATE_RULE"
  RHOR_S            ${\rho^{R}_{S}}$
  PSIRPI_S          ${\psi^{\Pi}_{S}}$
  PSIRGDP_S         ${\psi^{GDP}_{S}}$
  RHOR_RDN          ${\rho^{R}}$
  PSIRPI_RDN        ${\psi^{\Pi}}$
  PSIRGDP_RDN       ${\psi^{GDP}}$
@#endif
  WAR_RHO1_ROOT_S   ${\rho_{I}}$
  WAR_RHO2_ROOT_S   ${\rho_{II}}$
  WAR_DELTA_K_S     ${\Delta^{K}_{S}}$
  WAR_DELTA_A_S     ${\Delta^{A}_{S}}$
  WAR_DELTA_ZETA_S  ${\Delta^{\zeta}_{S}}$
  WAR_DELTA_L_S     ${\Delta^{L}_{S}}$
  WAR_DELTA_G_S     ${\Delta^{G}_{S}}$
    @#if length(COUNTRIES) == 6
  WAR_DELTA_G_BN    ${\Delta^{G}_{B_N}}$
  WAR_DELTA_G_BD    ${\Delta^{G}_{B_D}}$
    @#endif
@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
  WAR_DELTA_M_S     ${\Delta^{M}_{S}}$
    @#if length(COUNTRIES) == 6
  WAR_DELTA_M_BN    ${\Delta^{M}_{B_N}}$
  WAR_DELTA_M_BD    ${\Delta^{M}_{B_D}}$
  WAR_DELTA_M_TN    ${\Delta^{M}_{T_N}}$
  WAR_DELTA_M_TD    ${\Delta^{M}_{T_D}}$
    @#else
  WAR_DELTA_M_N     ${\Delta^{M}_{T_N}}$
  WAR_DELTA_M_D     ${\Delta^{M}_{T_D}}$
    @#endif
@#endif

@#include "__parameters.inc"
;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                            MODEL EQUATIONS                            %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model;
@#include "__model_aux.inc"
@#include "__model_core.inc"
end;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%
% war process (add) %
%%%%%%%%%%%%%%%%%%%%%
model;
// define persitence parameters in terms of AR roots
#WAR_RHO1_S = (WAR_RHO1_ROOT_S + WAR_RHO2_ROOT_S);
#WAR_RHO2_S = - WAR_RHO1_ROOT_S*WAR_RHO2_ROOT_S;
[name='war process']
war = WAR_RHO1_S*war(-1) + WAR_RHO2_S*war(-2) + eps_war;
end;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced productivity decline in S (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('evolution of total factor productivity in S');
log(a_S) = (1-RHOA_S)*log(steady_state(a_S)) + RHOA_S*log(a_S(-1)) + eps_a_S - WAR_DELTA_A_S*war;
end;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced investment-productivity decline in S (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('investment-specific productivity in S');
log(zeta_S) = RHOZETA_S * log(zeta_S(-1)) + eps_zeta_S - WAR_DELTA_ZETA_S*war;
end;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced labor supply shifter in S (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('labor supply shifter in S');
log(chil_S) = (1-RHOCHIL_S) * log(steady_state(chil_S)) + RHOCHIL_S * log(chil_S(-1)) + eps_chil_S + WAR_DELTA_L_S*war;
end;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced capital destruction in S (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('capital accumulation in S');
@#if ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "INVESTMENT"
k_S = ( (1-DELTAK_S) * k_S(-1) + zeta_S * (1 - PhiK_S_curr) * i_S ) * exp(-WAR_DELTA_K_S*war);
@#elseif ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "CAPITAL"
k_S = ( (1-DELTAK_S) * k_S(-1) + zeta_S * PhiK_S_curr * k_S(-1) ) * exp(-WAR_DELTA_K_S*war);
@#endif
end;
@{NEWLINE}

model_replace('optimal investment decision in S');
@#if ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "INVESTMENT"
lambda_S = exp(-WAR_DELTA_K_S*war) * lambda_S * qk_S * zeta_S * ( 1 - PhiK_S_curr - PhiKprime_S_curr * (i_S/i_S(-1)) ) + BETA_S * exp(-WAR_DELTA_K_S*war(+1)) * lambda_S(+1) * qk_S(+1) * zeta_S(+1) * PhiKprime_S_fwrd * (i_S(+1)/i_S)^2;
@#elseif ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "CAPITAL"
lambda_S = exp(-WAR_DELTA_K_S*war) * lambda_S * qk_S * zeta_S * PhiKprime_S_curr;
@#endif
end;
@{NEWLINE}

model_replace('optimal capital decision in S');
@#if CAPITAL_UTILIZATION_RESOURCE_COSTS == "EXPONENTIAL" || CAPITAL_UTILIZATION_RESOURCE_COSTS == "QUADRATIC"
    @#if ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "CAPITAL"
lambda_S * qk_S = BETA_S * lambda_S(+1) * ( qk_S(+1) * ( 1 - DELTAK_S + zeta_S(+1) * ( PhiK_S_fwrd - PhiKprime_S_fwrd * i_S(+1)/k_S) ) * exp(-WAR_DELTA_K_S*war(+1)) + rk_S(+1) * u_S(+1) - PhiU_S_fwrd );
    @#else
lambda_S * qk_S = BETA_S * lambda_S(+1) * ( qk_S(+1) * ( 1 - DELTAK_S ) * exp(-WAR_DELTA_K_S*war(+1)) + rk_S(+1) * u_S(+1) - PhiU_S_fwrd );
    @#endif
@#else
    @#if ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "CAPITAL"
lambda_S * qk_S = BETA_S * lambda_S(+1) * ( qk_S(+1) * ( 1 - DELTAK_S + zeta_S(+1) * ( PhiK_S_fwrd - PhiKprime_S_fwrd * i_S(+1)/k_S) ) * exp(-WAR_DELTA_K_S*war(+1)) + rk_S(+1) );
    @#else
lambda_S * qk_S = BETA_S * lambda_S(+1) * ( qk_S(+1) * ( 1 - DELTAK_S ) * exp(-WAR_DELTA_K_S*war(+1)) + rk_S(+1) );
    @#endif
@#endif
end;
@{NEWLINE}

@#if length(COUNTRIES) == 6
    @#define MILEXCOUNTRIES = ["S", "BN", "BD"]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% military spending in fiscal policy rule in war site and belligerents (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#else
    @#define MILEXCOUNTRIES = ["S"]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% military spending in fiscal policy rule in war site (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#endif
@#for j in MILEXCOUNTRIES
model_replace('government spending rule in @{j}');
g_@{j}/steady_state(gdp_@{j}) = (1-RHOG_@{j})*steady_state(g_@{j})/steady_state(gdp_@{j}) + RHOG_@{j} * g_@{j}(-1)/steady_state(gdp_@{j}) + eps_g_@{j} + WAR_DELTA_G_@{j}*war;
end;
@#endfor
@{NEWLINE}

@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced money growth rate rule in S, N, D (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    @#for j in (COUNTRIES - ["R"])
model_replace('money growth rule in @{j}');
(m_@{j}/m_@{j}(-1)*pi_@{j}) = (1-RHOM_@{j})*steady_state(pi_@{j}) + RHOM_@{j} * (m_@{j}(-1)/m_@{j}(-2)*pi_@{j}(-1)) + eps_m_@{j} + WAR_DELTA_M_@{j} * war;
end;
    @#endfor

@#elseif MONETARY_POLICY_RULE == "INTEREST_RATE_RULE"
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced symmetry of monetary policy parameters in Nearby, Distant, Rest of World (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    @#for j in COUNTRIES when j != "S"
model_replace('interest rate rule in @{j}');
rnom_@{j}/steady_state(rnom@{_}@{j}) = (rnom_@{j}(-1)/steady_state(rnom@{_}@{j}))^RHOR_RDN * ( (pi_@{j}/steady_state(pi_@{j}))^PSIRPI_RDN * (gdp_@{j}/steady_state(gdp_@{j}))^PSIRGDP_RDN )^(1-RHOR_RDN) * exp(eps_r_@{j});
end;
var_remove RHOR_@{j} PSIRPI_@{j} PSIRGDP_@{j};
    @#endfor

@#endif
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% equations for plotting variables (add) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model;
@#for j in COUNTRIES
plot_gdp_@{j} = 100*( gdp_@{j} / steady_state(gdp_@{j}) - 1 );
@#endfor
@{NEWLINE}
@#for j in COUNTRIES
plot_k_@{j} = 100*( k_@{j} / steady_state(k_@{j}) - 1 );
@#endfor
@{NEWLINE}
@#for j in COUNTRIES
plot_a_@{j} = 100*( a_@{j} / steady_state(a_@{j}) - 1 );
@#endfor
@{NEWLINE}
@#for j in COUNTRIES
plot_lab_@{j} = 100*( l_@{j} / steady_state(l_@{j}) - 1 );
@#endfor
@{NEWLINE}
@#for j in COUNTRIES
plot_x_@{j} = 100*( x_@{j} / steady_state(x_@{j}) - 1 );
@#endfor
@{NEWLINE}
@#for j in COUNTRIES
plot_g_@{j} = 100*( g_@{j} - steady_state(g_@{j}) ) / steady_state(gdp_@{j});
@#endfor
@{NEWLINE}
@#for j in COUNTRIES
plot_nx_@{j} = 100*( nx_@{j} - steady_state(nx_@{j}) ) / steady_state(gdp_@{j});
@#endfor
@{NEWLINE}
@#for j in COUNTRIES
plot_pi_@{j} = 100*( pi_@{j} - steady_state(pi_@{j}) );
@#endfor
end;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                          STEADY-STATE MODEL                           %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
steady_state_model;
@#include "__steady_state_model.inc"

war = 0; % no war in steady-state
@{NEWLINE}

% plotting variables in steady-state
@#for j in COUNTRIES
plot_gdp_@{j} = 0; plot_pi_@{j} = 0; plot_k_@{j} = 0; plot_a_@{j} = 0;
plot_g_@{j} = 0; plot_nx_@{j} = 0; plot_lab_@{j} = 0; plot_x_@{j} = 0;
@#endfor
@{NEWLINE}

end;
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                        CALIBRATION AND PRIORS                         %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#include MODEL_NAME + "_calibration_and_priors.inc"
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                            EMPIRICAL IRFS                             %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
addpath('data'); % folder with empirical IRFs
[warsite,nearby,distant,belligerent,irf_horizon] = pow_irfs_data_all;
@{NEWLINE}

@#ifdef MATCHING
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                             IRF MATCHING                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    @#include "_pow_model_irf_matching.inc"
@{NEWLINE}
@#endif

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                              SIMULATION                               %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
steady;
stoch_simul(order=1,irf=10,periods=0,nograph,nodecomposition,nocorr,nodisplay,noprint);
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                             PLOT SETTINGS                             %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if strcmp(computer,'MACA64') || strcmp(computer,'MACI64') % add path to latex on macOS
    setenv('PATH',[getenv('PATH') ':/usr/local/bin:$HOME/.local/bin:/Library/TeX/texbin']);
end
CheckPath('.','plots');
@{NEWLINE}

% colors
col_S = "#800080"; marker_S = '-*';
col_N = "#FF0808"; marker_N = 'o';
col_D = "#0000FF"; marker_D = '^';
col_R = "#000000"; marker_R = 'x';
@{NEWLINE}

% sizes
alphaLegend    = 0.8;
fontSize       = 18;
fontSizeTitle  = 23;
fontSizeLabels = 21;
fontSizeLegend = 18;
lineWidth      = 2;
@{NEWLINE}

@#include "_figure_matching" + ((string) length(COUNTRIES)) + ".inc"
@{NEWLINE}
@#if length(COUNTRIES) == 4
    @#include "_figure_transmission" + ((string) length(COUNTRIES)) + ".inc"
@#endif
@#ifdef PLOTS_PAPER
    @#include "_figure_data_paper.inc"
    @#include "_figure_decomposition.inc"
@#endif
@{NEWLINE}

@#ifdef SLICE
    @#define MODEL_NAME = MODEL_NAME + "_slice"
@#endif
@#ifdef SLICE_ROTATED
    @#define MODEL_NAME = MODEL_NAME + "_slice_rotated"
@#endif
@#ifdef MODE_COMPUTE
    @#define MODEL_NAME = MODEL_NAME + "_mode_compute"
@#endif
@#ifdef RWMH
    @#define MODEL_NAME = MODEL_NAME + "_rwmh"
@#endif
@#ifdef ML
    @#define MODEL_NAME = MODEL_NAME + "_ml"
@#endif
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                             HOUSEKEEPING                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
rmpath('data');
@#ifdef MATCHING
rmpath('nicer_plots_in_Dynare');
@#endif