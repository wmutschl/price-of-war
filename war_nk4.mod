@#define COUNTRIES                   = ["R", "D", "N", "H"]           // indices for countries
@#define CLOSING_COUNTRY             = "R"                            // country that is used to "balance out" equations and parameters in a consistent manner
@#define HABIT                       = true                           // false, true
@#define GROWTH                      = false                          // false, true
@#define INTERMEDIATE_INPUTS         = true                           // false, true
@#define CAPITAL                     = true                           // false, true
@#define CAPITAL_UTILIZATION         = false                          // false, true
@#define LABOR_MARKET_STRUCTURE      = "MONOPOLISTIC_COMPETITION_CES" // "PERFECT_COMPETITION", "MONOPOLISTIC_COMPETITION_CES"
@#define NOMINAL_WAGE_SETTING        = "CALVO"                        // "FLEX", "CALVO"
@#define IMPORT_ADJUSTMENT_COSTS     = true                           // false, true
@#define PRICING_REGIMES             = ["PCP"]                        // any combination of elements in ["LCP", "PCP", "DCP"]
@#define DOMINANT_CURRENCY           = ""                             // country in COUNTRIES that has dominant currency in DCP regime
@#define INTERNATIONAL_BONDS         = ["R"]                          // any combination of elements in COUNTRIES
@#define CLOSING_CONDITION           = "CARRYING_COST"                // "CARRYING_COST", "DEBT_ELASTIC"
@#define ICEBERG_COSTS               = false                          // false, true
@#define IMPORT_CONTENT_GOV_SPENDING = false                          // false, true
@#define ADD_FLEX_MODEL              = false                          // false, true

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                         PREPROCESSOR SETTINGS                         %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% COUNTRIES                   = @{COUNTRIES}
% CLOSING_COUNTRY             = @{CLOSING_COUNTRY}
% HABIT                       = @{HABIT}
% GROWTH                      = @{GROWTH}
% INTERMEDIATE_INPUTS         = @{INTERMEDIATE_INPUTS}
% CAPITAL                     = @{CAPITAL}
% CAPITAL_UTILIZATION         = @{CAPITAL_UTILIZATION}
% LABOR_MARKET_STRUCTURE      = @{LABOR_MARKET_STRUCTURE}
% NOMINAL_WAGE_SETTING        = @{NOMINAL_WAGE_SETTING}
% IMPORT_ADJUSTMENT_COSTS     = @{IMPORT_ADJUSTMENT_COSTS}
% PRICING_REGIMES             = @{PRICING_REGIMES}
% DOMINANT_CURRENCY           = @{DOMINANT_CURRENCY}
% INTERNATIONAL_BONDS         = @{INTERNATIONAL_BONDS}
% CLOSING_CONDITION           = @{CLOSING_CONDITION}
% ICEBERG_COSTS               = @{ICEBERG_COSTS}
% IMPORT_CONTENT_GOV_SPENDING = @{IMPORT_CONTENT_GOV_SPENDING}
% ADD_FLEX_MODEL              = @{ADD_FLEX_MODEL}
  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                         ENDOGENOUS VARIABLES                          %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#include "DynareModWizard/modfile/__var.inc"
var
% add plotting variables
@#for j in COUNTRIES
  plot_gdp_@{j} plot_pi_@{j} plot_k_@{j} plot_g_@{j} plot_a_@{j} plot_lab_@{j} plot_x_@{j} plot_nx_@{j}
@#endfor
  war % war shock
;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                          EXOGENOUS VARIABLES                          %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#include "DynareModWizard/modfile/__varexo.inc"
varexo  
% innovation to war shock
  eps_war  
;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                              PARAMETERS                               %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
parameters  
% declare latex names for some parameters (the duplicate declaration below will not overwrite the names)
  RHOA_H    ${\rho^{A}_{H}}$
  RHOG_H    ${\rho^{G}_{H}}$
  RHOR_H    ${\rho^{R}_{H}}$
  PSIRPI_H  ${\psi^{\Pi}_{H}}$
  PSIRGDP_H ${\psi^{GDP}_{H}}$
% common symmetric parameters in monetary & fiscal policy rules in R, D and N
  RHOG_RDN    ${\rho^{G}}$
  RHOR_RDN    ${\rho^{R}}$
  PSIRPI_RDN  ${\psi^{\Pi}}$
  PSIRGDP_RDN ${\psi^{GDP}}$
% war related parameters
  WAR_RHO1_ROOT_H ${\rho_{I}}$
  WAR_RHO2_ROOT_H ${\rho_{II}}$
  WAR_DELTA_K_H   ${\Delta^{K}_{H}}$
  WAR_DELTA_A_H   ${\Delta^{A}_{H}}$
  WAR_DELTA_G_H   ${\Delta^{G}_{H}}$
  WAR_DELTA_G_RDN ${\Delta^{G}}$  
;
  
@#include "DynareModWizard/modfile/__parameters.inc"
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                            MODEL EQUATIONS                            %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model;
@#include "DynareModWizard/modfile/__model.inc"
end;
  
%%%%%%%%%%%%%%%%%%%
% add war process %
%%%%%%%%%%%%%%%%%%%
model;
#WAR_RHO1_H = (WAR_RHO1_ROOT_H + WAR_RHO2_ROOT_H);
#WAR_RHO2_H = - WAR_RHO1_ROOT_H*WAR_RHO2_ROOT_H;
[name='war process']
war = WAR_RHO1_H*war(-1) + WAR_RHO2_H*war(-2) + eps_war;
end;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% add war-induced productivity decline in H %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('evolution of total factor productivity in H');
log(a_H) = (1-RHOA_H)*log(steady_state(a_H)) + RHOA_H*log(a_H(-1)) + eps_a_H - WAR_DELTA_A_H*war;
end;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% add war-induced capital destruction in H %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('capital accumulation (per-capita) in H');
k_H = ( (1-DELTAK_H) * k_H(-1) + (1-PHIK_H/2*(i_H/i_H(-1)-1)^2) * i_H ) * exp(-WAR_DELTA_K_H*war);
end;
  
model_replace('optimal investment decision (per-capita) in H');
1 = exp(-WAR_DELTA_K_H*war) * qk_H * ((1-PHIK_H/2*(i_H/i_H(-1)-1)^2) - PHIK_H*(i_H/i_H(-1)-1)*i_H/i_H(-1)) + BETA_H * exp(-WAR_DELTA_K_H*war(+1)) * lambda_H(+1)/lambda_H * qk_H(+1) * PHIK_H*(i_H(+1)/i_H-1)*(i_H(+1)/i_H)^2;
end;
  
model_replace('optimal capital decision (per-capita) in H');
@#if CAPITAL_UTILIZATION == true
qk_H = BETA_H * lambda_H(+1)/lambda_H * (qk_H(+1)*(1-DELTAK_H) * exp(-WAR_DELTA_K_H*war(+1)) + u_H(+1) * rk_H(+1) - steady_state(rk_H)*(1-PHIU_H)/PHIU_H*(exp((PHIU_H/(1-PHIU_H))*(u_H(+1)-1))-1));
@#else
qk_H = BETA_H * lambda_H(+1)/lambda_H * (qk_H(+1)*(1-DELTAK_H) * exp(-WAR_DELTA_K_H*war(+1)) + rk_H(+1));
@#endif
end;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% add military spending to fiscal policy rules %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('government spending rule in H');
log(g_H/steady_state(g_H)) = RHOG_H * log(g_H(-1)/steady_state(g_H)) + eps_g_H + WAR_DELTA_G_H*war;
end;
@#for j in COUNTRIES when j != "H"
model_replace('government spending rule in @{j}');
log(g_@{j}/steady_state(g_@{j})) = RHOG_RDN * log(g_@{j}(-1)/steady_state(g_@{j})) + eps_g_@{j} + WAR_DELTA_G_RDN*war;
end;
var_remove RHOG_@{j};
@#endfor
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% impose symmetry of monetary policy parameters in R, D and N %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#for j in COUNTRIES when j != "H"
model_replace('monetary policy rule in @{j}');
rnom_@{j} = steady_state(rnom_@{j})^(1-RHOR_RDN) * rnom_@{j}(-1)^RHOR_RDN * ( (pi_@{j}/steady_state(pi_@{j}))^PSIRPI_RDN * (gdp_@{j}/steady_state(gdp_@{j}))^PSIRGDP_RDN )^(1-RHOR_RDN) * exp(eps_r_@{j});
end;
var_remove RHOR_@{j} PSIRPI_@{j} PSIRGDP_@{j};
@#endfor
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% add equations for plotting variables %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model;
@#for j in COUNTRIES
plot_gdp_@{j} = 100*( gdp_@{j} / steady_state(gdp_@{j}) -1 );
plot_k_@{j}   = 100*( k_@{j}   / steady_state(k_@{j})   -1 );
plot_a_@{j}   = 100*( a_@{j}   / steady_state(a_@{j})   -1 );
plot_lab_@{j} = 100*( l_@{j}   / steady_state(l_@{j})   -1 );
plot_x_@{j}   = 100*( x_@{j}   / steady_state(x_@{j})   -1 );
plot_g_@{j}   = 100*(  g_@{j} - steady_state(g_@{j})  ) / steady_state(gdp_@{j});
plot_nx_@{j}  = 100*( nx_@{j} - steady_state(nx_@{j}) ) / steady_state(gdp_@{j});
plot_pi_@{j}  = 100*( pi_@{j} - steady_state(pi_@{j}) );
@#endfor
end;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                          STEADY-STATE MODEL                           %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
steady_state_model;
@#include "DynareModWizard/modfile/__steady_state_model.inc"
  
war = 0; % no war in steady-state
  
% plotting variables in steady-state
@#for j in COUNTRIES
plot_gdp_@{j} = 0; plot_pi_@{j} = 0; plot_k_@{j} = 0; plot_a_@{j} = 0;
plot_g_@{j} = 0; plot_nx_@{j} = 0; plot_lab_@{j} = 0; plot_x_@{j} = 0;
@#endfor
  
end;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                              CALIBRATION                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#include "_war_nk4_calibration.inc"
steady;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                            EMPIRICAL IRFS                             %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
addpath('data'); % folder with empirical IRFs
[warsite,nearby,distant,irf_horizon] = war_irfs_data_all;
  
@#ifdef MATCHING
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                             IRF MATCHING                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#include "_war_nk4_irf_matching.inc"
@#endif
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                              SIMULATION                               %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
stoch_simul(order=1,irf=10,periods=0,nograph,nodecomposition,nocorr,nodisplay,noprint);
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                 PLOTS                                 %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if strcmp(computer,'MACA64') || strcmp(computer,'MACI64') % add path to latex on macOS
    setenv('PATH',[getenv('PATH') ':/usr/local/bin:$HOME/.local/bin:/Library/TeX/texbin']);
end
CheckPath('.','plots');
  
% colors
col_H = "#800080";  marker_H = '-*';
col_N = "#FF0808";  marker_N = 'o';
col_D = "#0000FF";  marker_D = '^';
col_R = "#000000";  marker_R = 'x';
  
% sizes
alphaLegend    = 0.8;
fontSize       = 18;
fontSizeTitle  = 23;
fontSizeLabels = 21;
fontSizeLegend = 18;
lineWidth      = 2;
  
@#include "_figure_matching.inc"
  
@#include "_figure_transmission.inc"
//@#include "_figure_data_paper.inc"
//@#include "_figure_decomposition.inc"
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                             SAVE FIGURES                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
exportgraphics(fig_matching,"plots/fig_matching.pdf",'ContentType','vector');
exportgraphics(fig_transmission,"plots/fig_transmission.pdf",'ContentType','vector');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                             HOUSEKEEPING                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
rmpath('data');