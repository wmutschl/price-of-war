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
  RHOM_N            ${\rho^{M}_{N}}$
  RHOM_D            ${\rho^{M}_{D}}$
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
  WAR_DELTA_G_B     ${\Delta^{G}_{B}}$
    @#endif
@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
  WAR_DELTA_M_S     ${\Delta^{M}_{S}}$
  WAR_DELTA_M_N     ${\Delta^{M}_{T_N}}$
  WAR_DELTA_M_D     ${\Delta^{M}_{T_D}}$
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% military spending in fiscal policy rule in war site and belligerents (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#else
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% military spending in fiscal policy rule in war site (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@#endif
model_replace('government spending rule in S');
g_S/steady_state(gdp_S) = (1-RHOG_S)*steady_state(g_S)/steady_state(gdp_S) + RHOG_S * g_S(-1)/steady_state(gdp_S) + eps_g_S + WAR_DELTA_G_S*war;
end;
@#if length(COUNTRIES) == 6
    @#for j in ["BN", "BD"]
model_replace('government spending rule in @{j}');
g_@{j}/steady_state(gdp_@{j}) = (1-RHOG_@{j})*steady_state(g_@{j})/steady_state(gdp_@{j}) + RHOG_@{j} * g_@{j}(-1)/steady_state(gdp_@{j}) + eps_g_@{j} + WAR_DELTA_G_B*war;
end;
    @#endfor
@#endif
@{NEWLINE}

@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
    @#if EXCHANGE_RATE_PEG_WITH_R == true
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% exchange rate peg instead of money growth rate rule in S, N, D (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        @#for j in COUNTRIES when j != "R"
model_replace('money growth rule in @{j}');
dner_@{j}_R = 1 + eps_m_@{j};
end;
        @#endfor
    @#else
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced money growth rate rule in S, N, D (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
model_replace('money growth rule in S');
(m_S/m_S(-1)*pi_S) = (1-RHOM_S)*steady_state(pi_S) + RHOM_S * (m_S(-1)/m_S(-2)*pi_S(-1)) + eps_m_S + WAR_DELTA_M_S * war;
end;
        @#for j in ["N", "D"]
            @#if length(COUNTRIES) == 4
model_replace('money growth rule in @{j}');
(m_@{j}/m_@{j}(-1)*pi_@{j}) = (1-RHOM_@{j})*steady_state(pi_@{j}) + RHOM_@{j} * (m_@{j}(-1)/m_@{j}(-2)*pi_@{j}(-1)) + eps_m_@{j} + WAR_DELTA_M_@{j} * war;
end;
            @#elseif length(COUNTRIES) == 6
                @#for c in ["B", "T"]
model_replace('money growth rule in @{c}@{j}');
(m_@{c}@{j}/m_@{c}@{j}(-1)*pi_@{c}@{j}) = (1-RHOM_@{j})*steady_state(pi_@{c}@{j}) + RHOM_@{j} * (m_@{c}@{j}(-1)/m_@{c}@{j}(-2)*pi_@{c}@{j}(-1)) + eps_m_@{c}@{j} + WAR_DELTA_M_@{j} * war;
end;
var_remove RHOM_@{c}@{j};
                @#endfor
            @#endif
        @#endfor
    @#endif
@#elseif MONETARY_POLICY_RULE == "INTEREST_RATE_RULE"
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% war-induced symmetry of monetary policy parameters in N, D, R (replace) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%%                              CALIBRATION                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@{NEWLINE}
% HOUSEHOLD PARAMETERS
@#for j in COUNTRIES
BETA_@{j}     = 1/1.04; % discount factor in @{j}
@#endfor
@#for j in COUNTRIES
SIGMAC_@{j}   = 2;      % risk aversion in @{j}
@#endfor
@#for j in COUNTRIES
SIGMAL_@{j}   = 2;      % inverse Frisch elasticity in @{j}
@#endfor
@#if HABIT == "EXTERNAL"
    @#for j in COUNTRIES
PHIC_@{j}     = 0.50;   % habit preference in @{j}
    @#endfor
@#endif
@#for j in COUNTRIES
TARGET_L_@{j} = 1;      % steady-state labor supply in @{j}
@#endfor
@#if CAPITAL == true
    @#for j in COUNTRIES
DELTAK_@{j}   = 0.10;   % capital depreciation rate in @{j}
    @#endfor
    @#for j in COUNTRIES
        @#if ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "CAPITAL"
PHIK_@{j}     = 4*4;      % capital adjustment costs in @{j}
        @#elseif ADJUSTMENT_COSTS_IN_CAPITAL_LOM == "INVESTMENT"
PHIK_@{j}     = 4*4;      % investment adjustment costs in @{j}
        @#endif
    @#endfor
    @#if CAPITAL_UTILIZATION_RESOURCE_COSTS == "EXPONENTIAL" || CAPITAL_UTILIZATION_RESOURCE_COSTS == "QUADRATIC"
        @#for j in COUNTRIES
PHIU_@{j}     = 0.75;   % capital utilization costs in @{j}
        @#endfor
    @#endif
@#endif
@#if MONEY_IN_UTILITY == true
    @#for j in COUNTRIES
TARGET_M_to_GDP_@{j}   = 0.5; % money supply to gdp ratio in @{j}
    @#endfor
    @#for j in COUNTRIES
SIGMAM_@{j}           = 5; % money demand elasticity in @{j}
    @#endfor
@#endif
@#if CONSUMPTION_TRANSACTION_COSTS == true
    @#for j in COUNTRIES
PHIV1_@{j} = 0.029;
    @#endfor
    @#for j in COUNTRIES
PHIV2_@{j} = 0.35;
    @#endfor
@#endif
@{NEWLINE}

% FIRM PARAMETERS
@#for j in COUNTRIES
ALPHAX_@{j}   = 0.45;   % bias towards intermediate inputs in production in @{j}
@#endfor
@#for j in COUNTRIES
ALPHAK_@{j}   = 0.40;   % bias towards capital in production in @{j}
@#endfor
@#for j in COUNTRIES
EPSILONP_@{j} = 11;     % elasticity of substitution between differentiated good varieties in @{j}
@#endfor
@#if LABOR_MARKET_STRUCTURE == "MONOPOLISTIC_COMPETITION_CES"
  @#for j in COUNTRIES
EPSILONW_@{j} = 11;     % elasticity of substitution bettwen differentiated labor varieties in @{j}
  @#endfor
@#endif
@#for j in COUNTRIES
THETAP_@{j}   = 0.15;   % price stickiness probability in @{j}
@#endfor
@#if NOMINAL_WAGE_SETTING == "CALVO"
  @#for j in COUNTRIES
THETAW_@{j}   = 0.15;   % wage stickiness probability in @{j}
  @#endfor
@#endif
@#if PARTIAL_INDEXATION_WAGES == true
    @#for j in COUNTRIES
IOTAW_@{j}   = 0.75;   % partial wage indexation to past inflation in @{j}
    @#endfor
@#endif
@#if PARTIAL_INDEXATION_PRICES == true
    @#for j in COUNTRIES
IOTAP_@{j}   = 0.50;   % partial price indexation to past inflation in @{j}
    @#endfor
@#endif
@{NEWLINE}

% MONETARY POLICY
@#for j in COUNTRIES
TARGET_PI_@{j} = 1; % inflation target in @{j}
@#endfor
@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
    @#for j in ["R","D","N","S"]
RHOM_@{j}      = 0; % money growth rule smoothing in @{j}
    @#endfor
@#elseif MONETARY_POLICY_RULE == "INTEREST_RATE_RULE"
RHOR_S      = 0.50; % interest rate rule smoothing in S
RHOR_RDN    = 0.50; % interest rate rule smoothing in R, D, N (symmetric)
PSIRPI_S    = 1.50; % interest rate rule inflation feedback in S
PSIRPI_RDN  = 1.50; % interest rate rule inflation feedback in R, D, N (symmetric)
PSIRGDP_S   = 0.50; % interest rate rule gdp gap feedback in S
PSIRGDP_RDN = 0.50; % interest rate rule gdp gap feedback in R, D, N (symmetric)
@#endif
@{NEWLINE}

% FISCAL POLICY
@#for j in COUNTRIES
TARGET_G_to_GDP_@{j} = 0.2; % government spending ratio (relative to GDP) in steady-state in @{j}
@#endfor
@#for j in COUNTRIES
RHOG_@{j}            = 0;   % fiscal spending rule smoothing in @{j}
@#endfor
@{NEWLINE}

% STOCHASTIC PROCESSES
TARGET_A_GLOBAL = 1; % global total factor productivity in steady-state
@#for j in COUNTRIES
TARGET_A_@{j}      = 1; % total factor productivity in steady-state in @{j}
@#endfor
RHOA_GLOBAL     = 0; % global persistence in total factor productivity
@#for j in COUNTRIES
RHOA_@{j}          = 0; % persistence in total factor productivity in @{j}
@#endfor
@#for j in COUNTRIES
RHOMU_@{j}         = 0; % persistence in discount factor preference shifter in @{j}
@#endfor
@#if MONEY_IN_UTILITY == true
    @#for j in COUNTRIES
RHOCHIM_@{j}       = 0; % persistence in money demand shifter in @{j}
    @#endfor
@#endif
@#for j in COUNTRIES
RHOCHIL_@{j}       = 0; % persistence in labor supply shifter in @{j}
@#endfor
@#for j in COUNTRIES
RHOZETA_@{j}       = 0; % persistence in investment-specific productivity in @{j}
@#endfor
@{NEWLINE}

% TRADE PARAMETERS
@#for j in COUNTRIES
SIGMA_@{j} = 0.9; % trade elasticity in @{j}
@#endfor
@{NEWLINE}

@#for j in COUNTRIES when j != "R"
SIZE_@{j} = 0.05; % size of households and firms in @{j}
@#endfor
@{NEWLINE}

@#for j in COUNTRIES when j != "R"
OPENNESS_@{j} = 0.25*(1 - ALPHAX_@{j}*(EPSILONP_@{j}-1)/EPSILONP_@{j}); % steady-state share of imports to GDP in steady-state in @{j}
@#endfor
@{NEWLINE}

@#if length(COUNTRIES) == 4

OMEGA_N_S  = 1;   % Nearby and War site are fully integrated
OMEGA_D_N  = 0.1; % Distant is far away from Nearby
OMEGA_D_S  = 0.1; % Distant is far away from War site
@{NEWLINE}

OMEGA_S_N = OMEGA_N_S; % balanced trade in steady-state
OMEGA_N_D = OMEGA_D_N; % balanced trade in steady-state
OMEGA_S_D = OMEGA_D_S; % balanced trade in steady-state

OMEGA_R_S = (OPENNESS_S - OMEGA_N_S*SIZE_N - OMEGA_D_S*SIZE_D)/(1-SIZE_S-SIZE_N-SIZE_D); % R is the "closing country"
OMEGA_R_N = (OPENNESS_N - OMEGA_S_N*SIZE_S - OMEGA_D_N*SIZE_D)/(1-SIZE_S-SIZE_N-SIZE_D); % R is the "closing country"
OMEGA_R_D = (OPENNESS_D - OMEGA_S_D*SIZE_S - OMEGA_N_D*SIZE_N)/(1-SIZE_S-SIZE_N-SIZE_D); % R is the "closing country"

OMEGA_S_R = OMEGA_R_S; % balanced trade in steady-state
OMEGA_N_R = OMEGA_R_N; % balanced trade in steady-state
OMEGA_D_R = OMEGA_R_D; % balanced trade in steady-state
@{NEWLINE}

PHINX_N_S = 5; PHINX_D_S = 5; PHINX_R_S = 0; % import adjustment costs in S
PHINX_S_N = 5; PHINX_D_N = 5; PHINX_R_N = 0; % import adjustment costs in N
PHINX_S_D = 5; PHINX_N_D = 5; PHINX_R_D = 0; % import adjustment costs in D
PHINX_S_R = 0; PHINX_D_R = 0; PHINX_N_R = 0; % import adjustment costs in R
@{NEWLINE}

PHIB_S_S = 0    ; PHIB_N_S = 0.001; PHIB_D_S = 0.001; PHIB_R_S = 0.001; % bond carrying costs in S
PHIB_S_N = 0.001; PHIB_N_N = 0    ; PHIB_D_N = 0.001; PHIB_R_N = 0.001; % bond carrying costs in N
PHIB_S_D = 0.001; PHIB_N_D = 0.001; PHIB_D_D = 0    ; PHIB_R_D = 0.001; % bond carrying costs in D
PHIB_S_R = 0.001; PHIB_N_R = 0.001; PHIB_D_R = 0.001; PHIB_R_R = 0    ; % bond carrying costs in R
@{NEWLINE}

@#elseif length(COUNTRIES) == 6

OMEGA_BN_S = 1;   % Nearby countries are fully integrated
OMEGA_BD_S = 0.1; % Distant is far away from War site
OMEGA_TD_S = 0.1; % Distant is far away from War site
OMEGA_TN_S = 1;   % Nearby countries are fully integrated

OMEGA_BD_BN = 0.1; % Distant is far away from Nearby
OMEGA_TD_BN = 0.1; % Distant is far away from Nearby
OMEGA_TN_BN = 1  ; % Nearby countries are fully integrated
OMEGA_S_BN  = 1  ; % Nearby and War Site are fully integrated

OMEGA_TD_BD = 1;   % Distant countries are fully integrated
OMEGA_TN_BD = 0.1; % Distant is far away from Nearby
OMEGA_S_BD  = 0.1; % Distant is far away from War site
OMEGA_BN_BD = 0.1; % Distant is far away from Nearby

OMEGA_TN_TD = 0.1; % Distant is far away from Nearby
OMEGA_S_TD  = 0.1; % Distant is far away from War site
OMEGA_BN_TD = 0.1; % Distant is far away from Nearby
OMEGA_BD_TD = 1;   % Distant countries are fully integrated

OMEGA_S_TN  = 1;   % Nearby and War site are fully integrated
OMEGA_BN_TN = 1;   % Nearby countries are fully integrated
OMEGA_BD_TN = 0.1; % Distant is far away from Nearby
OMEGA_TD_TN = 0.1; % Distant is far away from Nearby
@{NEWLINE}

OMEGA_R_S  = ( OPENNESS_S                       - OMEGA_BN_S *SIZE_BN - OMEGA_TN_S *SIZE_TN - OMEGA_BD_S *SIZE_BD - OMEGA_TD_S *SIZE_TD ) / (1-SIZE_S-SIZE_BN-SIZE_TN-SIZE_BD-SIZE_TD); % R is the "closing country"
OMEGA_R_BN = ( OPENNESS_BN - OMEGA_S_BN*SIZE_S                        - OMEGA_TN_BN*SIZE_TN - OMEGA_BD_BN*SIZE_BD - OMEGA_TD_BN*SIZE_TD ) / (1-SIZE_S-SIZE_BN-SIZE_TN-SIZE_BD-SIZE_TD); % R is the "closing country"
OMEGA_R_BD = ( OPENNESS_BD - OMEGA_S_BD*SIZE_S  - OMEGA_BN_BD*SIZE_BN - OMEGA_TN_BD*SIZE_TN                       - OMEGA_TD_BD*SIZE_TD ) / (1-SIZE_S-SIZE_BN-SIZE_TN-SIZE_BD-SIZE_TD); % R is the "closing country"
OMEGA_R_TN = ( OPENNESS_TN - OMEGA_S_TN*SIZE_S  - OMEGA_BN_TN*SIZE_BN                       - OMEGA_BD_TN*SIZE_BD - OMEGA_TD_TN*SIZE_TD ) / (1-SIZE_S-SIZE_BN-SIZE_TN-SIZE_BD-SIZE_TD); % R is the "closing country"
OMEGA_R_TD = ( OPENNESS_TD - OMEGA_S_TD*SIZE_S  - OMEGA_BN_TD*SIZE_BN - OMEGA_TN_TD*SIZE_TN - OMEGA_BD_TD*SIZE_BD                       ) / (1-SIZE_S-SIZE_BN-SIZE_TN-SIZE_BD-SIZE_TD); % R is the "closing country"

OMEGA_S_R  = OMEGA_R_S;  % balanced trade in steady-state
OMEGA_BN_R = OMEGA_R_BN; % balanced trade in steady-state
OMEGA_BD_R = OMEGA_R_BD; % balanced trade in steady-state
OMEGA_TN_R = OMEGA_R_TN; % balanced trade in steady-state
OMEGA_TD_R = OMEGA_R_TD; % balanced trade in steady-state
@{NEWLINE}

                PHINX_BN_S  = 5; PHINX_BD_S  = 5; PHINX_TN_S  = 5; PHINX_TD_S  = 5; PHINX_R_S  = 0; % import adjustment costs in S
PHINX_S_BN = 5;                  PHINX_BD_BN = 5; PHINX_TN_BN = 5; PHINX_TD_BN = 5; PHINX_R_BN = 0; % import adjustment costs in BN
PHINX_S_BD = 5; PHINX_BN_BD = 5;                  PHINX_TN_BD = 5; PHINX_TD_BD = 5; PHINX_R_BD = 0; % import adjustment costs in BD
PHINX_S_TN = 5; PHINX_BN_TN = 5; PHINX_BD_TN = 5;                  PHINX_TD_TN = 5; PHINX_R_TN = 0; % import adjustment costs in TN
PHINX_S_TD = 5; PHINX_BN_TD = 5; PHINX_BD_TD = 5; PHINX_TN_TD = 5;                  PHINX_R_TD = 0; % import adjustment costs in TD
PHINX_S_R  = 0; PHINX_BN_R  = 0; PHINX_BD_R  = 0; PHINX_TN_R  = 0; PHINX_TD_R  = 0;                 % import adjustment costs in R
@{NEWLINE}

PHIB_S_S  = 0;     PHIB_BN_S  = 0.001; PHIB_BD_S  = 0.001; PHIB_TN_S  = 0.001; PHIB_TD_S  = 0.001; PHIB_R_S  = 0.001; % bond carrying costs in S
PHIB_S_BN = 0.001; PHIB_BN_BN = 0    ; PHIB_BD_BN = 0.001; PHIB_TN_BN = 0.001; PHIB_TD_BN = 0.001; PHIB_R_BN = 0.001; % bond carrying costs in BN
PHIB_S_BD = 0.001; PHIB_BN_BD = 0.001; PHIB_BD_BD = 0;     PHIB_TN_BD = 0.001; PHIB_TD_BD = 0.001; PHIB_R_BD = 0.001; % bond carrying costs in BD
PHIB_S_TN = 0.001; PHIB_BN_TN = 0.001; PHIB_BD_TN = 0.001; PHIB_TN_TN = 0;     PHIB_TD_TN = 0.001; PHIB_R_TN = 0.001; % bond carrying costs in TN
PHIB_S_TD = 0.001; PHIB_BN_TD = 0.001; PHIB_BD_TD = 0.001; PHIB_TN_TD = 0.001; PHIB_TD_TD = 0;     PHIB_R_TD = 0.001; % bond carrying costs in TD
PHIB_S_R  = 0.001; PHIB_BN_R  = 0.001; PHIB_BD_R  = 0.001; PHIB_TN_R  = 0.001; PHIB_TD_R  = 0.001; PHIB_R_R  = 0;     % bond carrying costs in R
@{NEWLINE}

@#endif

% INITIALIZATION WAR PARAMETERS
shocks;
var eps_war = 1; % innovation to war shock
end;
@{NEWLINE}

WAR_RHO1_ROOT_S  = 0; % first root in AR(2) war shock process
WAR_RHO2_ROOT_S  = 0; % second root in AR(2) war shock process
WAR_DELTA_K_S    = 0; % size of initial capital destruction in S
WAR_DELTA_A_S    = 0; % size of initial productivity decline in S
WAR_DELTA_ZETA_S = 0; % size of initial productivity decline in S
WAR_DELTA_L_S    = 0; % size of initial labor supply decline in S
WAR_DELTA_G_S    = 0; % size of initial military spending increase in S
@#if length(COUNTRIES) == 6
WAR_DELTA_G_B    = 0; % size of initial military spending increase in belligerents
@#endif
@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
    @#for j in ["S","N","D"]
WAR_DELTA_M_@{j}    = 0; % size of initial money supply change in @{j}
    @#endfor
@#endif
@{NEWLINE}

@#define LOADPARAMS = false
@#ifdef SLICE
    @#define LOADPARAMS = true
try
    load('@{MODEL_NAME}_slice/method_of_moments/@{MODEL_NAME}_mean.mat', 'xparam1', 'parameter_names');
    strEstimate = 'posterior mean (slice)';
@#endif
@#ifdef SLICE_ROTATED
    @#define LOADPARAMS = true
try
    load('@{MODEL_NAME}_slice_rotated/method_of_moments/@{MODEL_NAME}_mean.mat', 'xparam1', 'parameter_names');
    strEstimate = 'posterior mean (rotated slice)';
@#endif
@#ifdef MODE_COMPUTE
    @#define LOADPARAMS = true
try
    load('@{MODEL_NAME}_mode_compute/method_of_moments/@{MODEL_NAME}_mode.mat', 'xparam1', 'parameter_names');
    strEstimate = 'posterior mode (optimization)';
@#endif
@#ifdef RWMH
    @#define LOADPARAMS = true
try
    load('@{MODEL_NAME}_rwmh/method_of_moments/@{MODEL_NAME}_mean.mat', 'xparam1', 'parameter_names')
    strEstimate = 'posterior mean (rwmh)';
@#endif
@#if LOADPARAMS == true
    fprintf('Use %s estimates for calibration:\n',strEstimate);
    for j = 1:length(xparam1)
        set_param_value(parameter_names{j},xparam1(j));
    end
    disp(array2table(xparam1','VariableNames',parameter_names));
catch
    warning('Estimates not available, use prior mean.');
    WAR_DELTA_A_S   = 0.050;
    WAR_DELTA_G_S   = 0.050;
    @#if length(COUNTRIES) == 6
    WAR_DELTA_G_B   = 0.050;
    @#endif
    WAR_DELTA_K_S   = 0.025;
    @#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
    WAR_DELTA_M_S   = 0.020;
    WAR_DELTA_M_N   = 0.010;
    WAR_DELTA_M_D   = 0.005;
    @#endif
    WAR_RHO1_ROOT_S = 0.500;
    WAR_RHO2_ROOT_S = 0.500;
    RHOA_S          = 0.500;
    @#if length(COUNTRIES) == 6
    RHOG_S          = 0.500;
    RHOG_BN         = 0.500;
    RHOG_BD         = 0.500;
    @#endif
    @#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
    RHOM_S          = 0.500;
    RHOM_N          = 0.500;
    RHOM_D          = 0.500;
    @#elseif MONETARY_POLICY_RULE == "INTEREST_RATE_RULE"
    RHOR_S          = 0.500;
    RHOR_RDN        = 0.500;
    PSIRPI_S        = 2.000;
    PSIRPI_RDN      = 2.000;
    PSIRGDP_S       = 0.500;
    PSIRGDP_RDN     = 0.500;
    @#endif
end
@{NEWLINE}
@#endif

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                PRIORS                                 %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
estimated_params;
  WAR_DELTA_A_S   ,  , 0    , 0.10 , inv_gamma_pdf , 0.050 , 0.15 ;
  WAR_DELTA_G_S   ,  , 0    , 1.00 , inv_gamma_pdf , 0.050 , 0.15 ;
@#if length(COUNTRIES) == 6
  WAR_DELTA_G_B   ,  , 0    , 1.00 , inv_gamma_pdf , 0.050 , 0.15 ;
@#endif
  WAR_DELTA_K_S   ,  , 0    , 0.10 , inv_gamma_pdf , 0.025 , 0.15 ;
@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
  WAR_DELTA_M_S   ,  , 0    , 1.00 , inv_gamma_pdf , 0.020 , 0.15 ;
  WAR_DELTA_M_N   ,  , 0    , 1.00 , inv_gamma_pdf , 0.010 , 0.15 ;
  WAR_DELTA_M_D   ,  , 0    , 1.00 , inv_gamma_pdf , 0.005 , 0.15 ;
@#endif
  WAR_RHO1_ROOT_S ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  WAR_RHO2_ROOT_S ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOA_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
@#if length(COUNTRIES) == 6
  RHOG_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOG_BN         ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOG_BD         ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
@#endif
@#if MONETARY_POLICY_RULE == "MONEY_GROWTH_RATE_RULE"
  RHOM_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_N          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_D          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
@#elseif MONETARY_POLICY_RULE == "INTEREST_RATE_RULE"
  RHOR_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOR_RDN        ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  PSIRPI_S        ,  , 1.01 , 4.00 , normal_pdf    , 2.000 , 0.15 ;
  PSIRPI_RDN      ,  , 1.01 , 4.00 , normal_pdf    , 2.000 , 0.15 ;
  PSIRGDP_S       ,  , 0    , 0.75 , normal_pdf    , 0.500 , 0.15 ;
  PSIRGDP_RDN     ,  , 0    , 0.75 , normal_pdf    , 0.500 , 0.15 ;
@#endif
end;
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
options_.noprint = true;
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
    @#include "_figure_data_paper" + ((string) length(COUNTRIES)) + ".inc"
    @#if length(COUNTRIES) == 4
        @#include "_figure_decomposition.inc"
    @#endif
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