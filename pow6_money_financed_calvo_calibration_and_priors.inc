@#define NEWLINE = "  "

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
    @#for j in COUNTRIES
RHOM_@{j}      = 0; % money growth rule smoothing in @{j}
    @#endfor
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

                PHINX_BN_S  = 8; PHINX_BD_S  = 8; PHINX_TN_S  = 8; PHINX_TD_S  = 8; PHINX_R_S  = 0; % import adjustment costs in S
PHINX_S_BN = 8;                  PHINX_BD_BN = 8; PHINX_TN_BN = 8; PHINX_TD_BN = 8; PHINX_R_BN = 0; % import adjustment costs in BN
PHINX_S_BD = 8; PHINX_BN_BD = 8;                  PHINX_TN_BD = 8; PHINX_TD_BD = 8; PHINX_R_BD = 0; % import adjustment costs in BD
PHINX_S_TN = 8; PHINX_BN_TN = 8; PHINX_BD_TN = 8;                  PHINX_TD_TN = 8; PHINX_R_TN = 0; % import adjustment costs in TN
PHINX_S_TD = 8; PHINX_BN_TD = 8; PHINX_BD_TD = 8; PHINX_TN_TD = 8;                  PHINX_R_TD = 0; % import adjustment costs in TD
PHINX_S_R  = 0; PHINX_BN_R  = 0; PHINX_BD_R  = 0; PHINX_TN_R  = 0; PHINX_TD_R  = 0;                 % import adjustment costs in R
@{NEWLINE}

PHIB_S_S  = 0;     PHIB_BN_S  = 0.001; PHIB_BD_S  = 0.001; PHIB_TN_S  = 0.001; PHIB_TD_S  = 0.001; PHIB_R_S  = 0.001; % bond carrying costs in S
PHIB_S_BN = 0.001; PHIB_BN_BN = 0    ; PHIB_BD_BN = 0.001; PHIB_TN_BN = 0.001; PHIB_TD_BN = 0.001; PHIB_R_BN = 0.001; % bond carrying costs in BN
PHIB_S_BD = 0.001; PHIB_BN_BD = 0.001; PHIB_BD_BD = 0;     PHIB_TN_BD = 0.001; PHIB_TD_BD = 0.001; PHIB_R_BD = 0.001; % bond carrying costs in BD
PHIB_S_TN = 0.001; PHIB_BN_TN = 0.001; PHIB_BD_TN = 0.001; PHIB_TN_TN = 0;     PHIB_TD_TN = 0.001; PHIB_R_TN = 0.001; % bond carrying costs in TN
PHIB_S_TD = 0.001; PHIB_BN_TD = 0.001; PHIB_BD_TD = 0.001; PHIB_TN_TD = 0.001; PHIB_TD_TD = 0;     PHIB_R_TD = 0.001; % bond carrying costs in TD
PHIB_S_R  = 0.001; PHIB_BN_R  = 0.001; PHIB_BD_R  = 0.001; PHIB_TN_R  = 0.001; PHIB_TD_R  = 0.001; PHIB_R_R  = 0;     % bond carrying costs in R
@{NEWLINE}

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
@#for j in COUNTRIES when j != "R"
WAR_DELTA_M_@{j}    = 0; % size of initial money supply change in @{j}
@#endfor
@{NEWLINE}

%%%%%%%%%%
% PRIORS %
%%%%%%%%%%
estimated_params;
  WAR_RHO1_ROOT_S ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  WAR_RHO2_ROOT_S ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  WAR_DELTA_K_S   ,  , 0    , 0.10 , inv_gamma_pdf , 0.025 , 0.15 ;
  WAR_DELTA_A_S   ,  , 0    , 0.10 , inv_gamma_pdf , 0.050 , 0.15 ;
  WAR_DELTA_G_S   ,  , 0    , 1.00 , inv_gamma_pdf , 0.030 , 0.15 ;
  WAR_DELTA_M_S   ,  , 0    , 1.00 , inv_gamma_pdf , 0.020 , 0.15 ;
  WAR_DELTA_M_BN  ,  , 0    , 1.00 , inv_gamma_pdf , 0.010 , 0.15 ;
  WAR_DELTA_M_TN  ,  , 0    , 1.00 , inv_gamma_pdf , 0.010 , 0.15 ;
  WAR_DELTA_M_BD  ,  , 0    , 1.00 , inv_gamma_pdf , 0.005 , 0.15 ;
  WAR_DELTA_M_TD  ,  , 0    , 1.00 , inv_gamma_pdf , 0.005 , 0.15 ;
  RHOA_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_BN         ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_TN         ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_BD         ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_TD         ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOG_S          ,  , 0    , 0.99 , beta_pdf      , 0.400 , 0.15 ;
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESTIMATION RESULTS: SLICE %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESTIMATION RESULTS: SLICE ROTATED %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
WAR_RHO1_ROOT_S = 0.69822;
WAR_RHO2_ROOT_S = 0.69796;
WAR_DELTA_K_S   = 0.01587;
WAR_DELTA_A_S   = 0.055151;
WAR_DELTA_G_S   = 0.03; RHOG_S = 0.5;
WAR_DELTA_G_BN  = 0.03; RHOG_BN = 0.5;
WAR_DELTA_G_BD  = 0.03; RHOG_BD = 0.5;
WAR_DELTA_M_S   = 0.0097335;
WAR_DELTA_M_BN  = 0.0098422;
WAR_DELTA_M_TN  = 0.0098422;
WAR_DELTA_M_BD  = 0.002333;
WAR_DELTA_M_TD  = 0.002333;
RHOA_S          = 0.72971;
RHOM_S          = 0.4665;
RHOM_BN         = 0.43605;
RHOM_TN         = 0.43605;
RHOM_BD         = 0.60569;
RHOM_TD         = 0.60569;