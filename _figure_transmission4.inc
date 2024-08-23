%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                         FIGURE: TRANSMISSION                          %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_transmission = figure('name','Transmission');
fig_transmission.Position(3) = 1400;
fig_transmission.Position(4) = 800;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import price for goods produced in S %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(4,5,1);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import prices: S}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_pSN = plot(irf_horizon-1,100*oo_.irfs.p_S_N_eps_war(irf_horizon),'-','Color',col_N,'LineWidth',lineWidth);
point_pSD = plot(irf_horizon-1,100*oo_.irfs.p_S_D_eps_war(irf_horizon),'-','Color',col_D,'LineWidth',lineWidth);
point_pSR = plot(irf_horizon-1,100*oo_.irfs.p_S_R_eps_war(irf_horizon),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_pSN,point_pSD,point_pSR],["$p_{SN}$","$p_{SD}$","$p_{SR}$"],'Location','NorthWest','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
ylabel('\%','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import price for goods produced in N %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(4,5,6);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import prices: N}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_pNS = plot(irf_horizon-1,100*oo_.irfs.p_N_S_eps_war(irf_horizon),'-','Color',col_S,'LineWidth',lineWidth);
point_pND = plot(irf_horizon-1,100*oo_.irfs.p_N_D_eps_war(irf_horizon),'-','Color',col_D,'LineWidth',lineWidth);
point_pNR = plot(irf_horizon-1,100*oo_.irfs.p_N_R_eps_war(irf_horizon),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_pNS point_pND point_pNR],["$p_{NS}$","$p_{ND}$","$p_{NR}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
ylabel('\%','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import price for goods produced in D %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(4,5,11);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import prices: D}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_pDS = plot(irf_horizon-1,100*oo_.irfs.p_D_S_eps_war(irf_horizon),'-','Color',col_S,'LineWidth',lineWidth);
point_pDN = plot(irf_horizon-1,100*oo_.irfs.p_D_N_eps_war(irf_horizon),'-','Color',col_N,'LineWidth',lineWidth);
point_pDR = plot(irf_horizon-1,100*oo_.irfs.p_D_R_eps_war(irf_horizon),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_pDS point_pDN point_pDR],["$p_{DS}$","$p_{DN}$","$p_{DR}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
ylabel('\%','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import price for goods produced in R %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(4,5,16);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import prices: R}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_pRS = plot(irf_horizon-1,100*oo_.irfs.p_R_S_eps_war(irf_horizon),'-','Color',col_S,'LineWidth',lineWidth);
point_pRN = plot(irf_horizon-1,100*oo_.irfs.p_R_N_eps_war(irf_horizon),'-','Color',col_N,'LineWidth',lineWidth);
point_pRD = plot(irf_horizon-1,100*oo_.irfs.p_R_D_eps_war(irf_horizon),'-','Color',col_D,'LineWidth',lineWidth);
hold off;
leg = legend([point_pRS point_pRN point_pRD],["$p_{RS}$","$p_{RN}$","$p_{RD}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
ylabel('\%','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import volumes demanded by S %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,5,2);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import volumes: S}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_yNS = plot(irf_horizon-1,100*oo_.irfs.y_N_S_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_S')),'-','Color',col_N,'LineWidth',lineWidth);
point_yDS = plot(irf_horizon-1,100*oo_.irfs.y_D_S_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_S')),'-','Color',col_D,'LineWidth',lineWidth);
point_yRS = plot(irf_horizon-1,100*oo_.irfs.y_R_S_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_S')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_yNS point_yDS point_yRS],{'$y_{NS}$','$y_{DS}$','$y_{RS}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import volumes demanded by N %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,5,3);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import volumes: N}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_ySN = plot(irf_horizon-1,100*oo_.irfs.y_S_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_S,'LineWidth',lineWidth);
point_yDN = plot(irf_horizon-1,100*oo_.irfs.y_D_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_D,'LineWidth',lineWidth);
point_yRN = plot(irf_horizon-1,100*oo_.irfs.y_R_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_ySN point_yDN point_yRN],{'$y_{SN}$','$y_{DN}$','$y_{RN}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
%ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import volumes demanded by D %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,5,4);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import volumes: D}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_ySD = plot(irf_horizon-1,100*oo_.irfs.y_S_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_S,'LineWidth',lineWidth);
point_yND = plot(irf_horizon-1,100*oo_.irfs.y_N_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_N,'LineWidth',lineWidth);
point_yRD = plot(irf_horizon-1,100*oo_.irfs.y_R_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_ySD point_yND point_yRD],{'$y_{SD}$','$y_{ND}$','$y_{RD}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
%ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import volumes demanded by R %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,5,5);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import volumes: R}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_ySR = plot(irf_horizon-1,100*oo_.irfs.y_S_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_S,'LineWidth',lineWidth);
point_yNR = plot(irf_horizon-1,100*oo_.irfs.y_N_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_N,'LineWidth',lineWidth);
point_yDR = plot(irf_horizon-1,100*oo_.irfs.y_D_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_D,'LineWidth',lineWidth);
hold off;
leg = legend([point_ySR point_yNR point_yDR],{'$y_{SR}$','$y_{NR}$','$y_{DR}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
%ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%
% intermediate inputs %
%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,5,7);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Intermediate inputs}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_xS = plot(irf_horizon-1,100*oo_.irfs.x_S_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_S')),'-','Color',col_S,'LineWidth',lineWidth);
point_xN = plot(irf_horizon-1,100*oo_.irfs.x_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_xD = plot(irf_horizon-1,100*oo_.irfs.x_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_xR = plot(irf_horizon-1,100*oo_.irfs.x_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_xS,point_xN,point_xD,point_xR],{'$x_{S}$','$x_{N}$','$x_{D}$','$x_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%
% consumption %
%%%%%%%%%%%%%%%
subplot(2,5,8);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Consumption}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_cS = plot(irf_horizon-1,100*oo_.irfs.c_S_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_S')),'-','Color',col_S,'LineWidth',lineWidth);
point_cN = plot(irf_horizon-1,100*oo_.irfs.c_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_cD = plot(irf_horizon-1,100*oo_.irfs.c_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_cR = plot(irf_horizon-1,100*oo_.irfs.c_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_cS,point_cN,point_cD,point_cR],{'$c_{S}$','$c_{N}$','$c_{D}$','$c_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
%ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%
% investment %
%%%%%%%%%%%%%%
subplot(2,5,9);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Investment}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_iS = plot(irf_horizon-1,100*oo_.irfs.i_S_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_S')),'-','Color',col_S,'LineWidth',lineWidth);
point_iN = plot(irf_horizon-1,100*oo_.irfs.i_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_iD = plot(irf_horizon-1,100*oo_.irfs.i_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_iR = plot(irf_horizon-1,100*oo_.irfs.i_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_iS,point_iN,point_iD,point_iR],{'$i_{S}$','$i_{N}$','$i_{D}$','$i_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
%ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%
% net exports %
%%%%%%%%%%%%%%%
subplot(2,5,10);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Net exports}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_nxS = plot(irf_horizon-1,100*oo_.irfs.nx_S_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_S')),'-','Color',col_S,'LineWidth',lineWidth);
point_nxN = plot(irf_horizon-1,100*oo_.irfs.nx_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_nxD = plot(irf_horizon-1,100*oo_.irfs.nx_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_nxR = plot(irf_horizon-1,100*oo_.irfs.nx_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_nxS,point_nxN,point_nxD,point_nxR],{'$nx_{S}$','$nx_{N}$','$nx_{D}$','$nx_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
%ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';