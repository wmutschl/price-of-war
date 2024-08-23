%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                           FIGURE: MATCHING                            %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching = figure('name','Matching');
fig_matching.Position(3) = 1400;
fig_matching.Position(4) = 800;
  
%%%%%%%%%%%%%%%%
% gdp: warsite %
%%%%%%%%%%%%%%%%
subplot(3,3,1);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Output}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.gdp(:,3)',fliplr(warsite.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor = col_S;
point_warsite = plot(irf_horizon-1,warsite.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_S);
plot(irf_horizon-1,oo_.irfs.plot_gdp_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
hold off;
leg = legend(point_warsite,{'War site'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% gdp: nearby vs distant (belligerent) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(3,3,4);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Belligerents}','Interpreter','latex','FontSize',fontSizeTitle-6);
yline(0,'LineWidth',lineWidth);
hold on;
ub_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_belligerent_nearby.Color(4) = 0.1;
lb_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_belligerent_nearby.Color(4) = 0.1;
shaded_belligerent_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.nearby.gdp(:,3)',fliplr(belligerent.nearby.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_nearby.FaceColor = col_N;
point_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_gdp_BN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_belligerent_distant = plot(irf_horizon-1,belligerent.distant.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_belligerent_distant.Color(4) = 0.1;
lb_belligerent_distant = plot(irf_horizon-1,belligerent.distant.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_belligerent_distant.Color(4) = 0.1;
shaded_belligerent_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.distant.gdp(:,3)',fliplr(belligerent.distant.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_distant.FaceColor = col_D;
point_belligerent_distant = plot(irf_horizon-1,belligerent.distant.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_gdp_BD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
hold off;
leg = legend([point_belligerent_nearby,point_belligerent_distant],{'Nearby','Distant'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% gdp: nearby vs distant (third) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(3,3,7);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Third}','Interpreter','latex','FontSize',fontSizeTitle-6);
yline(0,'LineWidth',lineWidth);
hold on;
ub_nearby = plot(irf_horizon-1,nearby.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.gdp(:,3)',fliplr(nearby.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor = col_N;
point_nearby = plot(irf_horizon-1,nearby.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_gdp_TN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_distant = plot(irf_horizon-1,distant.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.gdp(:,3)',fliplr(distant.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor = col_D;
point_distant = plot(irf_horizon-1,distant.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_gdp_TD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
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
subplot(3,3,2);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Inflation}','Interpreter','latex','FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.inflation(:,3)',fliplr(warsite.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor = col_S;
point_warsite = plot(irf_horizon-1,warsite.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_S);
plot(irf_horizon-1,oo_.irfs.plot_pi_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
hold off;
leg = legend(point_warsite,{'War site'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
%ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% inflation: nearby vs distant (belligerent) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(3,3,5);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Belligerents}','Interpreter','latex','FontSize',fontSizeTitle-6);
yline(0,'LineWidth',lineWidth);
hold on;
ub_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_belligerent_nearby.Color(4) = 0.1;
lb_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_belligerent_nearby.Color(4) = 0.1;
shaded_belligerent_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.nearby.inflation(:,3)',fliplr(belligerent.nearby.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_nearby.FaceColor = col_N;
point_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_pi_BN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_belligerent_distant = plot(irf_horizon-1,belligerent.distant.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_belligerent_distant.Color(4) = 0.1;
lb_belligerent_distant = plot(irf_horizon-1,belligerent.distant.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_belligerent_distant.Color(4) = 0.1;
shaded_belligerent_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.distant.inflation(:,3)',fliplr(belligerent.distant.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_distant.FaceColor = col_D;
point_belligerent_distant = plot(irf_horizon-1,belligerent.distant.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_pi_BD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
hold off;
leg = legend([point_belligerent_nearby,point_belligerent_distant],{'Nearby','Distant'},'Location','North','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
%ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% inflation: nearby vs distant (third) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(3,3,8);
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
title('\textbf{Third}','Interpreter','latex','FontSize',fontSizeTitle-6);
yline(0,'LineWidth',lineWidth);
hold on;
ub_nearby = plot(irf_horizon-1,nearby.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.inflation(:,3)',fliplr(nearby.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor = col_N;
point_nearby = plot(irf_horizon-1,nearby.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_N);
plot(irf_horizon-1,oo_.irfs.plot_pi_TN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
ub_distant = plot(irf_horizon-1,distant.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.inflation(:,3)',fliplr(distant.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor = col_D;
point_distant = plot(irf_horizon-1,distant.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_D);
plot(irf_horizon-1,oo_.irfs.plot_pi_TD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
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
  
% %%%%%%%%%%%
% % capital %
% %%%%%%%%%%%
% subplot(3,3,3);
% set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
% title('\textbf{Capital}','Interpreter','latex','FontSize',fontSizeTitle);
% yline(0,'LineWidth',lineWidth);
% hold on;
% ub_warsite = plot(irf_horizon-1,warsite.capital(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
% lb_warsite = plot(irf_horizon-1,warsite.capital(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
% shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.capital(:,3)',fliplr(warsite.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor = col_S;
% point_warsite = plot(irf_horizon-1,warsite.capital(:,1)','-','LineWidth',lineWidth,'Color',col_S);
% plot(irf_horizon-1,oo_.irfs.plot_k_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
% ub_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.capital(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_belligerent_nearby.Color(4) = 0.1;
% lb_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.capital(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_belligerent_nearby.Color(4) = 0.1;
% shaded_belligerent_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.nearby.capital(:,3)',fliplr(belligerent.nearby.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_nearby.FaceColor = col_N;
% point_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.capital(:,1)','-','LineWidth',lineWidth,'Color',col_N);
% plot(irf_horizon-1,oo_.irfs.plot_k_BN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
% ub_belligerent_distant = plot(irf_horizon-1,belligerent.distant.capital(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_belligerent_distant.Color(4) = 0.1;
% lb_belligerent_distant = plot(irf_horizon-1,belligerent.distant.capital(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_belligerent_distant.Color(4) = 0.1;
% shaded_belligerent_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.distant.capital(:,3)',fliplr(belligerent.distant.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_distant.FaceColor = col_D;
% point_belligerent_distant = plot(irf_horizon-1,belligerent.distant.capital(:,1)','-','LineWidth',lineWidth,'Color',col_D);
% plot(irf_horizon-1,oo_.irfs.plot_k_BD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
% ub_nearby = plot(irf_horizon-1,nearby.capital(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
% lb_nearby = plot(irf_horizon-1,nearby.capital(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
% shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.capital(:,3)',fliplr(nearby.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor = col_N;
% point_nearby = plot(irf_horizon-1,nearby.capital(:,1)','-','LineWidth',lineWidth,'Color',col_N);
% plot(irf_horizon-1,oo_.irfs.plot_k_TN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
% ub_distant = plot(irf_horizon-1,distant.capital(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
% lb_distant = plot(irf_horizon-1,distant.capital(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
% shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.capital(:,3)',fliplr(distant.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor = col_D;
% point_distant = plot(irf_horizon-1,distant.capital(:,1)','-','LineWidth',lineWidth,'Color',col_D);
% plot(irf_horizon-1,oo_.irfs.plot_k_TD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
% hold off;
% %leg = legend([point_warsite,point_nearby,point_distant],{'War site','Nearby','Distant'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %leg = legend([point_warsite,point_nearby,point_distant,point_belligerent_nearby,point_belligerent_distant],{'War site','Nearby (Third)','Distant (Third)','Nearby (Belligerent)','Distant (Belligerent)'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
% %ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
% xlim([-0.4 8.4]);
% xticks(0:2:8);
% grid on; box on;
% ax = gca;
% ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
% ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
% ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%
% % military expenditures %
% %%%%%%%%%%%%%%%%%%%%%%%%%
% subplot(3,3,6);
% set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
% title('\textbf{Military}','Interpreter','latex','FontSize',fontSizeTitle);
% yline(0,'LineWidth',lineWidth);
% hold on;
% ub_warsite = plot(irf_horizon-1,warsite.milex(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
% lb_warsite = plot(irf_horizon-1,warsite.milex(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
% shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.milex(:,3)',fliplr(warsite.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor = col_S;
% point_warsite = plot(irf_horizon-1,warsite.milex(:,1)','-','LineWidth',lineWidth,'Color',col_S);
% plot(irf_horizon-1,oo_.irfs.plot_g_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
% 
% ub_nearby = plot(irf_horizon-1,nearby.milex(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
% lb_nearby = plot(irf_horizon-1,nearby.milex(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
% shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.milex(:,3)',fliplr(nearby.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor = col_N;
% point_nearby = plot(irf_horizon-1,nearby.milex(:,1)','-','LineWidth',lineWidth,'Color',col_N);
% plot(irf_horizon-1,oo_.irfs.plot_g_TN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
% ub_distant = plot(irf_horizon-1,distant.milex(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
% lb_distant = plot(irf_horizon-1,distant.milex(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
% shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.milex(:,3)',fliplr(distant.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor = col_D;
% point_distant = plot(irf_horizon-1,distant.milex(:,1)','-','LineWidth',lineWidth,'Color',col_D);
% plot(irf_horizon-1,oo_.irfs.plot_g_TD_eps_war(irf_horizon),marker_D,'LineWidth',lineWidth,'Color',col_D);
% 
% ub_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.milex(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_belligerent_nearby.Color(4) = 0.1;
% lb_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.milex(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_belligerent_nearby.Color(4) = 0.1;
% shaded_belligerent_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.nearby.milex(:,3)',fliplr(belligerent.nearby.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_nearby.FaceColor = col_N;
% point_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.milex(:,1)','-','LineWidth',lineWidth,'Color',col_N);
% plot(irf_horizon-1,oo_.irfs.plot_g_TN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
% ub_distant = plot(irf_horizon-1,distant.milex(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
% lb_distant = plot(irf_horizon-1,distant.milex(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
% shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.milex(:,3)',fliplr(distant.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor = col_D;
% point_distant = plot(irf_horizon-1,distant.milex(:,1)','-','LineWidth',lineWidth,'Color',col_D);
% plot(irf_horizon-1,oo_.irfs.plot_g_TD_eps_war(irf_horizon),marker_D,'LineWidth',lineWidth,'Color',col_D);
% 
% hold off;
% %leg = legend([point_warsite,point_nearby,point_distant],{'War site','Nearby','Distant'},'Location','North','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %leg = legend([point_warsite],{'War site'},'Location','North','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
% %ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
% xlim([-0.4 8.4]);
% xticks(0:2:8);
% grid on; box on;
% ax = gca;
% ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
% ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
% ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % total factor productivity %
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% subplot(2,4,4);
% set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
% title('\textbf{TFP}','Interpreter','latex','FontSize',fontSizeTitle);
% yline(0,'LineWidth',lineWidth);
% hold on;
% ub_warsite = plot(irf_horizon-1,warsite.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
% lb_warsite = plot(irf_horizon-1,warsite.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
% shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.tfp(:,3)',fliplr(warsite.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor = col_S;
% point_warsite = plot(irf_horizon-1,warsite.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_S);
% plot(irf_horizon-1,oo_.irfs.plot_a_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
% %ub_nearby = plot(irf_horizon-1,nearby.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
% %lb_nearby = plot(irf_horizon-1,nearby.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
% %shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.tfp(:,3)',fliplr(nearby.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor = col_N;
% %point_nearby = plot(irf_horizon-1,nearby.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
% %plot(irf_horizon-1,oo_.irfs.plot_a_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
% %ub_distant = plot(irf_horizon-1,distant.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
% %lb_distant = plot(irf_horizon-1,distant.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
% %shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.tfp(:,3)',fliplr(distant.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor = col_D;
% %point_distant = plot(irf_horizon-1,distant.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
% %plot(irf_horizon-1,oo_.irfs.plot_a_D_eps_war(irf_horizon),marker_D,'LineWidth',lineWidth,'Color',col_D);
% hold off;
% %leg = legend([point_warsite,point_nearby,point_distant],{'War site','Nearby','Distant'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% leg = legend([point_warsite],{'War site'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
% %ylabel('Percent','Interpreter','latex','FontSize',fontSizeLabels);
% xlim([-0.4 8.4]);
% xticks(0:2:8);
% grid on; box on;
% ax = gca;
% ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
% ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
% ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
% 
% %%%%%%%%%%%%%
% % war shock %
% %%%%%%%%%%%%%
% subplot(2,4,8);
% set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
% title('\textbf{War shock}','Interpreter','latex','FontSize',fontSizeTitle);
% yline(0,'LineWidth',lineWidth);
% hold on;
% point_war_shock = plot(irf_horizon-1,oo_.irfs.war_eps_war(irf_horizon),'-','LineWidth',lineWidth,'Color',col_S);
% hold off;
% leg = legend(point_war_shock,{'$\omega_t$'},'Location','South','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% xlabel('Year after war onset','Interpreter','latex','FontSize',fontSizeLabels);
% ylabel('Level','Interpreter','latex','FontSize',fontSizeLabels);
% xlim([-0.4 8.4]);
% xticks(0:2:8);
% grid on; box on;
% ax = gca;
% ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
% ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
% ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';