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
@#if HABIT == true
  @#for j in COUNTRIES
HABIT_@{j}    = 0.75;   % habit preference in @{j}
  @#endfor
@#endif
@#for j in COUNTRIES
TARGET_L_@{j} = 1;      % steady-state labor supply in @{j}
@#endfor
@#for j in COUNTRIES
DELTAK_@{j}   = 0.10;   % capital depreciation rate in @{j}
@#endfor
@#for j in COUNTRIES
PHIK_@{j}     = 4;      % investment-adjustment costs in @{j}
@#endfor
@#if CAPITAL == true && CAPITAL_UTILIZATION == true
  @#for j in COUNTRIES
PHIU_@{j}     = 0.95;   % capital utilization costs in @{j}
  @#endfor
@#endif
@#if CONSUMPTION_TRANSACTION_COSTS == true
    @#for j in COUNTRIES
PHIV1_@{j} = 0.029;
    @#endfor
    @#for j in COUNTRIES
PHIV2_@{j} = 0.350;
    @#endfor
@#endif
  
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
  
  
% MONETARY POLICY
@#for j in COUNTRIES
TARGET_PI_@{j} = 1;    % inflation target in @{j}
@#endfor
RHOR_RDN    = 0.50; % interest rate rule smoothing in R, D, N (symmetric)
RHOR_H      = 0.50; % interest rate rule smoothing in H
PSIRPI_RDN  = 1.50; % interest rate rule inflation feedback in R, D, N (symmetric)
PSIRPI_H    = 1.50; % interest rate rule inflation feedback in H
PSIRGDP_RDN = 0.50; % interest rate rule gdp gap feedback in R, D, N (symmetric)
PSIRGDP_H   = 0.50; % interest rate rule gdp gap feedback in H
  
% FISCAL POLICY
@#for j in COUNTRIES
TARGET_G_to_GDP_@{j} = 0.2; % government spending ratio (relative to GDP) in steady-state in @{j}
@#endfor
RHOG_RDN = 0.90; % fiscal spending rule smoothing in R, D, N (symmetric)
RHOG_H   = 0.75; % fiscal spending rule smoothing in H
  
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
@#for j in COUNTRIES
RHOCHIL_@{j}       = 0; % persistence in labor supply shifter in @{j}
@#endfor
@#for j in COUNTRIES
RHOZETA_@{j}       = 0; % persistence in investment-specific productivity in @{j}
@#endfor
@#for j in COUNTRIES
  @#for i in COUNTRIES
RHOETA_@{i}_@{j}      = 0; % persistence in preference shifter for bonds issued in @{i} and hold by @{j}
  @#endfor
@#endfor
  
% TRADE PARAMETERS
SIZE_H = 0.06; % size of households and firms in H
SIZE_N = 0.06; % size of households and firms in N
SIZE_D = 0.06; % size of households and firms in D
  
OPENNESS_H = 0.30*(1 - ALPHAX_H*(EPSILONP_H-1)/EPSILONP_H); % steady-state share of imports to GDP in steady-state in H (30%)
OPENNESS_N = 0.30*(1 - ALPHAX_N*(EPSILONP_N-1)/EPSILONP_N); % steady-state share of imports to GDP in steady-state in N (30%)
OPENNESS_D = 0.30*(1 - ALPHAX_D*(EPSILONP_D-1)/EPSILONP_D); % steady-state share of imports to GDP in steady-state in D (30%)

OMEGA_N_H  = 1;    % N and H are fully integrated
OMEGA_D_H  = 0.01; % almost no trade between D and H 
OMEGA_R_H  = (OPENNESS_H - OMEGA_N_H*SIZE_N - OMEGA_D_H*SIZE_D)/(1-SIZE_H-SIZE_N-SIZE_D); % R is "closing" country for balanced trade in H
  
OMEGA_H_N  = 1;    % H and N are fully integrated
OMEGA_D_N  = 0.01; % almost no trade between D and N
OMEGA_R_N  = (OPENNESS_N - OMEGA_H_N*SIZE_H - OMEGA_D_N*SIZE_D)/(1-SIZE_H-SIZE_N-SIZE_D); % R is "closing" country for balanced trade in N

OMEGA_H_D  = 0.01; % almost no trade between H and D
OMEGA_N_D  = 0.01; % almost no trade between N and D
OMEGA_R_D  = (OPENNESS_D - OMEGA_H_D*SIZE_H - OMEGA_N_D*SIZE_N)/(1-SIZE_H-SIZE_N-SIZE_D); % R is "closing" country for balanced trade in D
  
% balanced trade pins down remaining parameters in R
OMEGA_H_R = OMEGA_R_H;
OMEGA_N_R = OMEGA_R_N;
OMEGA_D_R = OMEGA_R_D;
  
@#for j in COUNTRIES
SIGMA_@{j} = 0.9; % trade elasticity in @{j}
@#endfor
  
PHINX_N_H = 20;  PHINX_D_H = 10;  PHINX_R_H = 0; % import adjustment costs in H
PHINX_H_N = 20;  PHINX_D_N =  0;  PHINX_R_N = 0; % import adjustment costs in N
PHINX_H_D = 10;  PHINX_N_D =  0;  PHINX_R_D = 0; % import adjustment costs in D
PHINX_H_R =  0;  PHINX_D_R =  0;  PHINX_N_R = 0; % import adjustment costs in R
  
PHIB_H_H = 0    ;  PHIB_N_H = 0.001;  PHIB_D_H = 0.001;  PHIB_R_H = 0.001; % bond carrying costs in H
PHIB_H_N = 0.001;  PHIB_N_N = 0    ;  PHIB_D_N = 0.001;  PHIB_R_N = 0.001; % bond carrying costs in N
PHIB_H_D = 0.001;  PHIB_N_D = 0.001;  PHIB_D_D = 0    ;  PHIB_R_D = 0.001; % bond carrying costs in D
PHIB_H_R = 0.001;  PHIB_N_R = 0.001;  PHIB_D_R = 0.001;  PHIB_R_R = 0    ; % bond carrying costs in R
  
% WAR PARAMETERS
WAR_RHO1_ROOT_H = 0; % first root in AR(2) war shock process
WAR_RHO2_ROOT_H = 0; % second root in AR(2) war shock process
WAR_DELTA_K_H   = 0; % size of initial capital destruction in H
WAR_DELTA_A_H   = 0; % size of initial productivity decline in H
WAR_DELTA_G_H   = 0; % size of military spending increase in H
WAR_DELTA_G_RDN = 0; % size of military spending increase in R, D, N (symmetric)
  
shocks;
var eps_war = 1; % innovation to war shock
end;
  

@#ifdef SLICE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESTIMATED PARAMETERS: SLICE 24 CHAINS (LINUX SERVER)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if (SIGMAC_H == 2) && (SIGMA_H == 0.9)
    % WAR_RHO1_ROOT_H        0.500       0.6967      0.5546      0.8492     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6890      0.5372      0.8401     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0245      0.0045      0.0552     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0881      0.0773      0.1000     invg       0.2000
    % RHOA_H                 0.500       0.5894      0.4099      0.7771     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.0591      0.0266      0.0918     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0292      0.0049      0.0547     invg       0.2000
    % RHOG_H                 0.750       0.7991      0.4989      0.9899     beta       0.2000
    % RHOG_RDN               0.750       0.8822      0.7903      0.9897     beta       0.2000
    % RHOR_H                 0.500       0.8722      0.8117      0.9367     beta       0.2000
    % RHOR_RDN               0.500       0.5638      0.3025      0.8435     beta       0.2000
    % PSIRGDP_H              0.500       0.2396      0.0946      0.3814     norm       0.2000
    % PSIRGDP_RDN            0.500       0.5972      0.4595      0.7499     norm       0.2000
    % PSIRPI_H               2.000       2.0748      1.7479      2.3633     norm       0.2000
    % PSIRPI_RDN             2.000       1.8380      1.5741      2.1144     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6967;
    WAR_RHO2_ROOT_H = 0.6890;
    WAR_DELTA_K_H   = 0.0245;
    WAR_DELTA_A_H   = 0.0881;
    RHOA_H          = 0.5894;
    WAR_DELTA_G_H   = 0.0591;
    WAR_DELTA_G_RDN = 0.0292;
    RHOG_H          = 0.7991;
    RHOG_RDN        = 0.8822;
    RHOR_H          = 0.8722;
    RHOR_RDN        = 0.5638;
    PSIRGDP_H       = 0.2396;
    PSIRGDP_RDN     = 0.5972;
    PSIRPI_H        = 2.0748;
    PSIRPI_RDN      = 1.8380;
elseif (SIGMAC_H == 1) && (SIGMA_H == 0.9)
    % WAR_RHO1_ROOT_H        0.500       0.6911      0.5277      0.8581     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6945      0.5393      0.8599     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0222      0.0048      0.0487     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0792      0.0651      0.0962     invg       0.2000
    % RHOA_H                 0.500       0.5545      0.3446      0.7294     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.0739      0.0255      0.1221     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0404      0.0044      0.0747     invg       0.2000
    % RHOG_H                 0.750       0.8358      0.5747      0.9899     beta       0.2000
    % RHOG_RDN               0.750       0.8786      0.7818      0.9897     beta       0.2000
    % RHOR_H                 0.500       0.8359      0.7601      0.9203     beta       0.2000
    % RHOR_RDN               0.500       0.5535      0.2417      0.8027     beta       0.2000
    % PSIRGDP_H              0.500       0.2665      0.1158      0.4079     norm       0.2000
    % PSIRGDP_RDN            0.500       0.5992      0.4645      0.7497     norm       0.2000
    % PSIRPI_H               2.000       2.0507      1.7221      2.3674     norm       0.2000
    % PSIRPI_RDN             2.000       1.8370      1.5637      2.1210     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6911;
    WAR_RHO2_ROOT_H = 0.6945;
    WAR_DELTA_K_H   = 0.0222;
    WAR_DELTA_A_H   = 0.0792;
    RHOA_H          = 0.5545;
    WAR_DELTA_G_H   = 0.0739;
    WAR_DELTA_G_RDN = 0.0404;
    RHOG_H          = 0.8358;
    RHOG_RDN        = 0.8786;
    RHOR_H          = 0.8359;
    RHOR_RDN        = 0.5535;
    PSIRGDP_H       = 0.2665;
    PSIRGDP_RDN     = 0.5992;
    PSIRPI_H        = 2.0507;
    PSIRPI_RDN      = 1.8370;
elseif (SIGMAC_H == 2) && (SIGMA_H == 1.5)
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    % SIGMAC=2 and SIGMA=1.5 %
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    % WAR_RHO1_ROOT_H        0.500       0.6767      0.5232      0.8214     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6480      0.4856      0.7993     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0205      0.0047      0.0417     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0840      0.0711      0.0994     invg       0.2000
    % RHOA_H                 0.500       0.6065      0.4380      0.8011     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.1149      0.0306      0.2149     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0166      0.0029      0.0328     invg       0.2000
    % RHOG_H                 0.750       0.7709      0.5291      0.9886     beta       0.2000
    % RHOG_RDN               0.750       0.8815      0.7641      0.9898     beta       0.2000
    % RHOR_H                 0.500       0.7973      0.6975      0.8933     beta       0.2000
    % RHOR_RDN               0.500       0.4546      0.1429      0.7226     beta       0.2000
    % PSIRGDP_H              0.500       0.2694      0.1130      0.4113     norm       0.2000
    % PSIRGDP_RDN            0.500       0.6329      0.5083      0.7498     norm       0.2000
    % PSIRPI_H               2.000       2.0802      1.7797      2.3820     norm       0.2000
    % PSIRPI_RDN             2.000       1.7163      1.4123      1.9934     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6767;
    WAR_RHO2_ROOT_H = 0.6480;
    WAR_DELTA_K_H   = 0.0205;
    WAR_DELTA_A_H   = 0.0840;
    RHOA_H          = 0.6065;
    WAR_DELTA_G_H   = 0.1149;
    WAR_DELTA_G_RDN = 0.0166;
    RHOG_H          = 0.7709;
    RHOG_RDN        = 0.8815;
    RHOR_H          = 0.7973;
    RHOR_RDN        = 0.4546;
    PSIRGDP_H       = 0.2694;
    PSIRGDP_RDN     = 0.6329;
    PSIRPI_H        = 2.0802;
    PSIRPI_RDN      = 1.7163;

elseif (SIGMAC_H == 1) && (SIGMA_H == 1.5)
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    % SIGMAC=1 and SIGMA=1.5 %
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    % WAR_RHO1_ROOT_H        0.500       0.6695      0.5222      0.8208     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6680      0.5033      0.8104     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0186      0.0050      0.0352     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0756      0.0581      0.0932     invg       0.2000
    % RHOA_H                 0.500       0.5871      0.3805      0.7491     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.1657      0.0315      0.3354     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0220      0.0029      0.0458     invg       0.2000
    % RHOG_H                 0.750       0.7931      0.5648      0.9885     beta       0.2000
    % RHOG_RDN               0.750       0.8833      0.7784      0.9898     beta       0.2000
    % RHOR_H                 0.500       0.7734      0.6536      0.9039     beta       0.2000
    % RHOR_RDN               0.500       0.4676      0.1627      0.7378     beta       0.2000
    % PSIRGDP_H              0.500       0.2661      0.1277      0.3974     norm       0.2000
    % PSIRGDP_RDN            0.500       0.6285      0.4991      0.7499     norm       0.2000
    % PSIRPI_H               2.000       2.0581      1.7375      2.3534     norm       0.2000
    % PSIRPI_RDN             2.000       1.7380      1.4418      2.0248     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6695;
    WAR_RHO2_ROOT_H = 0.6680;
    WAR_DELTA_K_H   = 0.0186;
    WAR_DELTA_A_H   = 0.0756;
    RHOA_H          = 0.5871;
    WAR_DELTA_G_H   = 0.1657;
    WAR_DELTA_G_RDN = 0.0220;
    RHOG_H          = 0.7931;
    RHOG_RDN        = 0.8833;
    RHOR_H          = 0.7734;
    RHOR_RDN        = 0.4676;
    PSIRGDP_H       = 0.2661;
    PSIRGDP_RDN     = 0.6285;
    PSIRPI_H        = 2.0581;
    PSIRPI_RDN      = 1.7380;
end
@#endif


@#ifdef SLICE_ROTATED
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESTIMATION RESULTS: ROTATED SLICE 24 CHAUNS (LINUX SERVER) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if SIGMAC_H == 2 && SIGMA_H == 0.9
    % WAR_RHO1_ROOT_H        0.500       0.6830      0.5284      0.8547     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6869      0.5272      0.8451     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0253      0.0047      0.0565     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0881      0.0775      0.1000     invg       0.2000
    % RHOA_H                 0.500       0.5977      0.4171      0.7849     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.0588      0.0281      0.0914     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0307      0.0058      0.0568     invg       0.2000
    % RHOG_H                 0.750       0.7766      0.4633      0.9900     beta       0.2000
    % RHOG_RDN               0.750       0.8796      0.7852      0.9900     beta       0.2000
    % RHOR_H                 0.500       0.8667      0.8037      0.9299     beta       0.2000
    % RHOR_RDN               0.500       0.5547      0.2773      0.8343     beta       0.2000
    % PSIRGDP_H              0.500       0.2439      0.1006      0.3946     norm       0.2000
    % PSIRGDP_RDN            0.500       0.5985      0.4637      0.7499     norm       0.2000
    % PSIRPI_H               2.000       2.0677      1.7598      2.3786     norm       0.2000
    % PSIRPI_RDN             2.000       1.8378      1.5688      2.1189     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6830;
    WAR_RHO2_ROOT_H = 0.6869;
    WAR_DELTA_K_H   = 0.0253;
    WAR_DELTA_A_H   = 0.0881;
    RHOA_H          = 0.5977;
    WAR_DELTA_G_H   = 0.0588;
    WAR_DELTA_G_RDN = 0.0307;
    RHOG_H          = 0.7766;
    RHOG_RDN        = 0.8796;
    RHOR_H          = 0.8667;
    RHOR_RDN        = 0.5547;
    PSIRGDP_H       = 0.2439;
    PSIRGDP_RDN     = 0.5985;
    PSIRPI_H        = 2.0677;
    PSIRPI_RDN      = 1.8378;
elseif SIGMAC_H == 1 && SIGMA_H == 0.9
    % WAR_RHO1_ROOT_H        0.500       0.6870      0.5212      0.8508     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6826      0.5139      0.8511     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0234      0.0044      0.0509     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0788      0.0626      0.0950     invg       0.2000
    % RHOA_H                 0.500       0.5752      0.3829      0.7751     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.0779      0.0258      0.1348     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0413      0.0055      0.0778     invg       0.2000
    % RHOG_H                 0.750       0.8240      0.5324      0.9900     beta       0.2000
    % RHOG_RDN               0.750       0.8853      0.7966      0.9898     beta       0.2000
    % RHOR_H                 0.500       0.8366      0.7586      0.9185     beta       0.2000
    % RHOR_RDN               0.500       0.5511      0.2792      0.8386     beta       0.2000
    % PSIRGDP_H              0.500       0.2747      0.1226      0.4171     norm       0.2000
    % PSIRGDP_RDN            0.500       0.5985      0.4633      0.7499     norm       0.2000
    % PSIRPI_H               2.000       2.0610      1.7434      2.3607     norm       0.2000
    % PSIRPI_RDN             2.000       1.8364      1.5628      2.1174     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6870;
    WAR_RHO2_ROOT_H = 0.6826;
    WAR_DELTA_K_H   = 0.0234;
    WAR_DELTA_A_H   = 0.0788;
    RHOA_H          = 0.5752;
    WAR_DELTA_G_H   = 0.0779;
    WAR_DELTA_G_RDN = 0.0413;
    RHOG_H          = 0.8240;
    RHOG_RDN        = 0.8853;
    RHOR_H          = 0.8366;
    RHOR_RDN        = 0.5511;
    PSIRGDP_H       = 0.2747;
    PSIRGDP_RDN     = 0.5985;
    PSIRPI_H        = 2.0610;
    PSIRPI_RDN      = 1.8364;
elseif SIGMAC_H == 2 && SIGMA_H == 1.5
    % WAR_RHO1_ROOT_H        0.500       0.6605      0.5021      0.8168     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6620      0.5043      0.8215     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0197      0.0047      0.0391     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0845      0.0723      0.1000     invg       0.2000
    % RHOA_H                 0.500       0.6098      0.4402      0.7948     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.1197      0.0299      0.2259     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0169      0.0028      0.0329     invg       0.2000
    % RHOG_H                 0.750       0.7745      0.5286      0.9900     beta       0.2000
    % RHOG_RDN               0.750       0.8835      0.7761      0.9900     beta       0.2000
    % RHOR_H                 0.500       0.7960      0.6991      0.8975     beta       0.2000
    % RHOR_RDN               0.500       0.4516      0.1564      0.7316     beta       0.2000
    % PSIRGDP_H              0.500       0.2669      0.1135      0.4095     norm       0.2000
    % PSIRGDP_RDN            0.500       0.6344      0.5118      0.7500     norm       0.2000
    % PSIRPI_H               2.000       2.0711      1.7574      2.3825     norm       0.2000
    % PSIRPI_RDN             2.000       1.7182      1.4182      2.0122     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6605;
    WAR_RHO2_ROOT_H = 0.6620;
    WAR_DELTA_K_H   = 0.0197;
    WAR_DELTA_A_H   = 0.0845;
    RHOA_H          = 0.6098;
    WAR_DELTA_G_H   = 0.1197;
    WAR_DELTA_G_RDN = 0.0169;
    RHOG_H          = 0.7745;
    RHOG_RDN        = 0.8835;
    RHOR_H          = 0.7960;
    RHOR_RDN        = 0.4516;
    PSIRGDP_H       = 0.2669;
    PSIRGDP_RDN     = 0.6344;
    PSIRPI_H        = 2.0711;
    PSIRPI_RDN      = 1.7182;
elseif SIGMAC_H == 1 && SIGMA_H == 1.5
    % WAR_RHO1_ROOT_H        0.500       0.6643      0.4966      0.8308     beta       0.2000
    % WAR_RHO2_ROOT_H        0.500       0.6638      0.4926      0.8289     beta       0.2000
    % WAR_DELTA_K_H          0.020       0.0192      0.0045      0.0375     invg       0.2000
    % WAR_DELTA_A_H          0.030       0.0753      0.0586      0.0945     invg       0.2000
    % RHOA_H                 0.500       0.5884      0.3991      0.7886     beta       0.2000
    % WAR_DELTA_G_H          0.100       0.1604      0.0281      0.3332     invg       0.2000
    % WAR_DELTA_G_RDN        0.010       0.0215      0.0026      0.0451     invg       0.2000
    % RHOG_H                 0.750       0.7833      0.5542      0.9900     beta       0.2000
    % RHOG_RDN               0.750       0.8768      0.7626      0.9899     beta       0.2000
    % RHOR_H                 0.500       0.7684      0.6434      0.8962     beta       0.2000
    % RHOR_RDN               0.500       0.4687      0.1812      0.7611     beta       0.2000
    % PSIRGDP_H              0.500       0.2744      0.1210      0.4126     norm       0.2000
    % PSIRGDP_RDN            0.500       0.6322      0.5101      0.7500     norm       0.2000
    % PSIRPI_H               2.000       2.0688      1.7735      2.3946     norm       0.2000
    % PSIRPI_RDN             2.000       1.7418      1.4403      2.0344     norm       0.2000
    WAR_RHO1_ROOT_H = 0.6643;
    WAR_RHO2_ROOT_H = 0.6638;
    WAR_DELTA_K_H   = 0.0192;
    WAR_DELTA_A_H   = 0.0753;
    RHOA_H          = 0.5884;
    WAR_DELTA_G_H   = 0.1604;
    WAR_DELTA_G_RDN = 0.0215;
    RHOG_H          = 0.7833;
    RHOG_RDN        = 0.8768;
    RHOR_H          = 0.7684;
    RHOR_RDN        = 0.4687;
    PSIRGDP_H       = 0.2744;
    PSIRGDP_RDN     = 0.6322;
    PSIRPI_H        = 2.0688;
    PSIRPI_RDN      = 1.7418;
end
@#endif