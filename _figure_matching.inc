%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                           FIGURE: MATCHING                            %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching = figure('name','Matching');
fig_matching.Position(3) = 1400;
fig_matching.Position(4) = 800;
  
%%%%%%%%%%%%%%%%
% gdp: warsite %
%%%%%%%%%%%%%%%%
subplot(2,4,1);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Output}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_H); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_H); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.gdp(:,3)',fliplr(warsite.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(irf_horizon-1,warsite.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_H);
plot(irf_horizon-1,oo_.irfs.plot_gdp_H_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_H);
hold off;
leg = legend(point_warsite,{'Home'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%
% gdp: nearby vs distant %
%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,4,5);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Output}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_nearby = plot(irf_horizon-1,nearby.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.gdp(:,3)',fliplr(nearby.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_gdp_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_distant = plot(irf_horizon-1,distant.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.gdp(:,3)',fliplr(distant.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_gdp_D_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
hold off;
leg = legend([point_nearby,point_distant],{'Nearby','Distant'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%
% inflation: warsite %
%%%%%%%%%%%%%%%%%%%%%%
subplot(2,4,2);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Inflation}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_H); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_H); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.inflation(:,3)',fliplr(warsite.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(irf_horizon-1,warsite.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_H);
plot(irf_horizon-1,oo_.irfs.plot_pi_H_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_H);
hold off;
leg = legend(point_warsite,{'Home'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
%ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% inflation: nearby vs distant %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,4,6);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Inflation}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_nearby = plot(irf_horizon-1,nearby.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.inflation(:,3)',fliplr(nearby.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_pi_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_distant = plot(irf_horizon-1,distant.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.inflation(:,3)',fliplr(distant.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_pi_D_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
hold off;
leg = legend([point_nearby,point_distant],{'Nearby','Distant'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
%ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%
% capital %
%%%%%%%%%%%
subplot(2,4,3);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Capital}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.capital(:,3)','-','LineWidth',lineWidth,'Color',col_H); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.capital(:,2)','-','LineWidth',lineWidth,'Color',col_H); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.capital(:,3)',fliplr(warsite.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(irf_horizon-1,warsite.capital(:,1)','-','LineWidth',lineWidth,'Color',col_H);
plot(irf_horizon-1,oo_.irfs.plot_k_H_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_H);
ub_nearby = plot(irf_horizon-1,nearby.capital(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.capital(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.capital(:,3)',fliplr(nearby.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.capital(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_k_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_distant = plot(irf_horizon-1,distant.capital(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.capital(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.capital(:,3)',fliplr(distant.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.capital(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_k_D_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
hold off;
leg = legend([point_warsite,point_nearby,point_distant],{'Home','Nearby','Distant'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
%ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%
% military expenditures %
%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,4,7);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Military}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.milex(:,3)','-','LineWidth',lineWidth,'Color',col_H); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.milex(:,2)','-','LineWidth',lineWidth,'Color',col_H); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.milex(:,3)',fliplr(warsite.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(irf_horizon-1,warsite.milex(:,1)','-','LineWidth',lineWidth,'Color',col_H);
plot(irf_horizon-1,oo_.irfs.plot_g_H_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_H);
ub_nearby = plot(irf_horizon-1,nearby.milex(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.milex(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.milex(:,3)',fliplr(nearby.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.milex(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_g_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_distant = plot(irf_horizon-1,distant.milex(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.milex(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.milex(:,3)',fliplr(distant.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.milex(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_g_D_eps_war(irf_horizon),marker_D,'LineWidth',lineWidth,'Color',col_D);
hold off;
leg = legend([point_warsite,point_nearby,point_distant],{'Home','Nearby','Distant'},'Location','North','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
%ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% total factor productivity %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(2,4,4);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{TFP}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_H); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_H); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.tfp(:,3)',fliplr(warsite.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(irf_horizon-1,warsite.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_H);
plot(irf_horizon-1,oo_.irfs.plot_a_H_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_H);
ub_nearby = plot(irf_horizon-1,nearby.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.tfp(:,3)',fliplr(nearby.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_a_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_distant = plot(irf_horizon-1,distant.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.tfp(:,3)',fliplr(distant.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_a_D_eps_war(irf_horizon),marker_D,'LineWidth',lineWidth,'Color',col_D);
hold off;
leg = legend([point_warsite,point_nearby,point_distant],{'Home','Nearby','Distant'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
%ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%
% war shock %
%%%%%%%%%%%%%
subplot(2,4,8);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{War shock}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
point_war_shock = plot(irf_horizon-1,oo_.irfs.war_eps_war(irf_horizon),'-','LineWidth',lineWidth,'Color',col_H);
hold off;
leg = legend(point_war_shock,{'$\omega_t$'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
ylabel('Level','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';