%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                         FIGURE: TRANSMISSION                          %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_transmission = figure('name','Transmission');
fig_transmission.Position(3) = 1400;
fig_transmission.Position(4) = 800;
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% import price for goods produced in H %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(4,5,1);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import prices: H}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_pHN = plot(irf_horizon-1,100*oo_.irfs.p_H_N_eps_war(irf_horizon),'-','Color',col_N,'LineWidth',lineWidth);
point_pHD = plot(irf_horizon-1,100*oo_.irfs.p_H_D_eps_war(irf_horizon),'-','Color',col_D,'LineWidth',lineWidth);
point_pHR = plot(irf_horizon-1,100*oo_.irfs.p_H_R_eps_war(irf_horizon),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_pHN,point_pHD,point_pHR],["$p_{HN}$","$p_{HD}$","$p_{HR}$"],'Location','NorthWest','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_pNH = plot(irf_horizon-1,100*oo_.irfs.p_N_H_eps_war(irf_horizon),'-','Color',col_H,'LineWidth',lineWidth);
point_pND = plot(irf_horizon-1,100*oo_.irfs.p_N_D_eps_war(irf_horizon),'-','Color',col_D,'LineWidth',lineWidth);
point_pNR = plot(irf_horizon-1,100*oo_.irfs.p_N_R_eps_war(irf_horizon),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_pNH point_pND point_pNR],["$p_{NH}$","$p_{ND}$","$p_{NR}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_pDH = plot(irf_horizon-1,100*oo_.irfs.p_D_H_eps_war(irf_horizon),'-','Color',col_H,'LineWidth',lineWidth);
point_pDN = plot(irf_horizon-1,100*oo_.irfs.p_D_N_eps_war(irf_horizon),'-','Color',col_N,'LineWidth',lineWidth);
point_pDR = plot(irf_horizon-1,100*oo_.irfs.p_D_R_eps_war(irf_horizon),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_pDH point_pDN point_pDR],["$p_{DH}$","$p_{DN}$","$p_{DR}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_pRH = plot(irf_horizon-1,100*oo_.irfs.p_R_H_eps_war(irf_horizon),'-','Color',col_H,'LineWidth',lineWidth);
point_pRN = plot(irf_horizon-1,100*oo_.irfs.p_R_N_eps_war(irf_horizon),'-','Color',col_N,'LineWidth',lineWidth);
point_pRD = plot(irf_horizon-1,100*oo_.irfs.p_R_D_eps_war(irf_horizon),'-','Color',col_D,'LineWidth',lineWidth);
hold off;
leg = legend([point_pRH point_pRN point_pRD],["$p_{RH}$","$p_{RN}$","$p_{RD}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
% import volumes demanded by H %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,5,2);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Import volumes: H}','Interpreter','latex','FontSize',fontSizeTitle-4);
yline(0,'LineWidth',lineWidth);
hold on;
point_yNH = plot(irf_horizon-1,100*oo_.irfs.y_N_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')),'-','Color',col_N,'LineWidth',lineWidth);
point_yDH = plot(irf_horizon-1,100*oo_.irfs.y_D_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')),'-','Color',col_D,'LineWidth',lineWidth);
point_yRH = plot(irf_horizon-1,100*oo_.irfs.y_R_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_yNH point_yDH point_yRH],{'$y_{NH}$','$y_{DH}$','$y_{RH}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_yHN = plot(irf_horizon-1,100*oo_.irfs.y_H_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_H,'LineWidth',lineWidth);
point_yDN = plot(irf_horizon-1,100*oo_.irfs.y_D_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_D,'LineWidth',lineWidth);
point_yRN = plot(irf_horizon-1,100*oo_.irfs.y_R_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_yHN point_yDN point_yRN],{'$y_{HN}$','$y_{DN}$','$y_{RN}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_yHD = plot(irf_horizon-1,100*oo_.irfs.y_H_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_H,'LineWidth',lineWidth);
point_yND = plot(irf_horizon-1,100*oo_.irfs.y_N_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_N,'LineWidth',lineWidth);
point_yRD = plot(irf_horizon-1,100*oo_.irfs.y_R_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_yHD point_yND point_yRD],{'$y_{HD}$','$y_{ND}$','$y_{RD}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_yHR = plot(irf_horizon-1,100*oo_.irfs.y_H_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_H,'LineWidth',lineWidth);
point_yNR = plot(irf_horizon-1,100*oo_.irfs.y_N_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_N,'LineWidth',lineWidth);
point_yDR = plot(irf_horizon-1,100*oo_.irfs.y_D_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_D,'LineWidth',lineWidth);
hold off;
leg = legend([point_yHR point_yNR point_yDR],{'$y_{HR}$','$y_{NR}$','$y_{DR}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_xH = plot(irf_horizon-1,100*oo_.irfs.x_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')),'-','Color',col_H,'LineWidth',lineWidth);
point_xN = plot(irf_horizon-1,100*oo_.irfs.x_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_xD = plot(irf_horizon-1,100*oo_.irfs.x_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_xR = plot(irf_horizon-1,100*oo_.irfs.x_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_xH,point_xN,point_xD,point_xR],{'$x_{H}$','$x_{N}$','$x_{D}$','$x_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_cH = plot(irf_horizon-1,100*oo_.irfs.c_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')),'-','Color',col_H,'LineWidth',lineWidth);
point_cN = plot(irf_horizon-1,100*oo_.irfs.c_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_cD = plot(irf_horizon-1,100*oo_.irfs.c_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_cR = plot(irf_horizon-1,100*oo_.irfs.c_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_cH,point_cN,point_cD,point_cR],{'$c_{H}$','$c_{N}$','$c_{D}$','$c_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_iH = plot(irf_horizon-1,100*oo_.irfs.i_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')),'-','Color',col_H,'LineWidth',lineWidth);
point_iN = plot(irf_horizon-1,100*oo_.irfs.i_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_iD = plot(irf_horizon-1,100*oo_.irfs.i_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_iR = plot(irf_horizon-1,100*oo_.irfs.i_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_iH,point_iN,point_iD,point_iR],{'$i_{H}$','$i_{N}$','$i_{D}$','$i_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
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
point_nxH = plot(irf_horizon-1,100*oo_.irfs.nx_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')),'-','Color',col_H,'LineWidth',lineWidth);
point_nxN = plot(irf_horizon-1,100*oo_.irfs.nx_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')),'-','Color',col_N,'LineWidth',lineWidth);
point_nxD = plot(irf_horizon-1,100*oo_.irfs.nx_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')),'-','Color',col_D,'LineWidth',lineWidth);
point_nxR = plot(irf_horizon-1,100*oo_.irfs.nx_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')),'-','Color',col_R,'LineWidth',lineWidth);
hold off;
leg = legend([point_nxH,point_nxN,point_nxD,point_nxR],{'$nx_{H}$','$nx_{N}$','$nx_{D}$','$nx_{R}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend-4); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels-4);
%ylabel('ppt','Interpreter','latex','FontSize',fontSizeLabels-4);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';