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
  WAR_DELTA_A_S   ,  , 0    , 0.10 , inv_gamma_pdf , 0.050 , 0.15 ;
  WAR_DELTA_G_S   ,  , 0    , 1.00 , inv_gamma_pdf , 0.050 , 0.15 ;
  WAR_DELTA_K_S   ,  , 0    , 0.10 , inv_gamma_pdf , 0.025 , 0.15 ;
  WAR_DELTA_M_S   ,  , 0    , 1.00 , inv_gamma_pdf , 0.020 , 0.15 ;
  WAR_DELTA_M_N   ,  , 0    , 1.00 , inv_gamma_pdf , 0.010 , 0.15 ;
  WAR_DELTA_M_D   ,  , 0    , 1.00 , inv_gamma_pdf , 0.005 , 0.15 ;
  WAR_RHO1_ROOT_S ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  WAR_RHO2_ROOT_S ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOA_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_S          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_N          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
  RHOM_D          ,  , 0    , 0.99 , beta_pdf      , 0.500 , 0.15 ;
end;
@{NEWLINE}

@#ifdef SLICE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% POSTERIOR MEAN FROM SLICE %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  WAR_DELTA_A_S = 0.055479416552947;
  WAR_DELTA_G_S = 0.025824312707286;
  WAR_DELTA_K_S = 0.017791968906345;
  WAR_DELTA_M_S = 0.013145056630695;
  WAR_DELTA_M_N = 0.011966992623502;
  WAR_DELTA_M_D = 0.003573535919287;
WAR_RHO1_ROOT_S = 0.689614340874530;
WAR_RHO2_ROOT_S = 0.690845812831013;
         RHOA_S = 0.700441844093189;
         RHOM_S = 0.519506569210922;
         RHOM_N = 0.369467313655702;
         RHOM_D = 0.644066038102285;
@{NEWLINE}
@#endif

@#ifdef SLICE_ROTATED
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% POSTERIOR MEAN FROM ROTATED SLICE %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  WAR_DELTA_A_S = 0.055293929677572;
  WAR_DELTA_G_S = 0.025805535536720;
  WAR_DELTA_K_S = 0.018107734215815;
  WAR_DELTA_M_S = 0.013142216535639;
  WAR_DELTA_M_N = 0.012039260484949;
  WAR_DELTA_M_D = 0.003584017976143;
WAR_RHO1_ROOT_S = 0.689291580178607;
WAR_RHO2_ROOT_S = 0.687845845787376;
         RHOA_S = 0.704894404001434;
         RHOM_S = 0.521445249325249;
         RHOM_N = 0.375478040258721;
         RHOM_D = 0.646523586157324;
@{NEWLINE}
@#endif
@#endif