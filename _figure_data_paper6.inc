%%%%%%%%%%%%%%%%%%%%%%%%%
%% plots used in paper %%
%%%%%%%%%%%%%%%%%%%%%%%%%
fontSize = 18;
fontSizeTitle  = 23;
fontSizeLabels = 21;
fontSizeLegend = 18;

%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gdp matching: warsite %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching_output_warsite = figure('name','output matching: war site');
fig_matching_output_warsite.Position(3) = 600;

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Output}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_warsite = plot(irf_horizon-1,warsite.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.gdp(:,3)',fliplr(warsite.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_S;
point_warsite = plot(irf_horizon-1,warsite.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_S);
point_S = plot(irf_horizon-1,oo_.irfs.plot_gdp_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);

hold off;
leg = legend([point_warsite],{'War site'},'Location','NorthEast','NumColumns',2,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percent', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-31 31]);
yticks(-30:15:30)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

exportgraphics(fig_matching_output_warsite,"plots/paper_fig_matching_output_warsite_@{MODEL_NAME}.pdf",'ContentType','vector');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gdp matching: nearby/distant (belligerent) %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching_output_belligerent = figure('name','output matching: belligerent');
fig_matching_output_belligerent.Position(3) = 600;

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Output}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_belligerent_nearby.Color(4) = 0.1;
lb_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_belligerent_nearby.Color(4) = 0.1;
shaded_belligerent_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.nearby.gdp(:,3)',fliplr(belligerent.nearby.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_nearby.FaceColor =  col_N;
point_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
point_BN = plot(irf_horizon-1,oo_.irfs.plot_gdp_BN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);

ub_belligerent_distant = plot(irf_horizon-1,belligerent.distant.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_belligerent_distant.Color(4) = 0.1;
lb_belligerent_distant = plot(irf_horizon-1,belligerent.distant.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_belligerent_distant.Color(4) = 0.1;
shaded_belligerent_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.distant.gdp(:,3)',fliplr(belligerent.distant.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_distant.FaceColor =  col_D;
point_belligerent_distant = plot(irf_horizon-1,belligerent.distant.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
point_BD = plot(irf_horizon-1,oo_.irfs.plot_gdp_BD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);

hold off;
leg = legend([point_belligerent_nearby, point_belligerent_distant],{'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percent', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
%ylim([-8.3 8.3]);
%yticks(-8:4:8)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

exportgraphics(fig_matching_output_belligerent,"plots/paper_fig_matching_output_belligerent_@{MODEL_NAME}.pdf",'ContentType','vector');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gdp matching: nearby/distant (third) %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching_output_third = figure('name','output matching: third');
fig_matching_output_third.Position(3) = 600;

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Output}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_nearby = plot(irf_horizon-1,nearby.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.gdp(:,3)',fliplr(nearby.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
point_TN = plot(irf_horizon-1,oo_.irfs.plot_gdp_TN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);

ub_distant = plot(irf_horizon-1,distant.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.gdp(:,3)',fliplr(distant.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
point_TD = plot(irf_horizon-1,oo_.irfs.plot_gdp_TD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);

hold off;
leg = legend([point_nearby, point_distant],{'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percent', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
%ylim([-8.3 8.3]);
%yticks(-8:4:8)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

exportgraphics(fig_matching_output_third,"plots/paper_fig_matching_output_third_@{MODEL_NAME}.pdf",'ContentType','vector');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% inflation matching: warsite %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching_inflation_warsite = figure('name','inflation matching: war site');
fig_matching_inflation_warsite.Position(3) = 600;

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Inflation}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_warsite = plot(irf_horizon-1,warsite.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.inflation(:,3)',fliplr(warsite.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_S;
point_warsite = plot(irf_horizon-1,warsite.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_S);
point_S = plot(irf_horizon-1,oo_.irfs.plot_pi_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);

hold off;
leg = legend([point_warsite],{'War site'},'Location','NorthEast','NumColumns',2,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-21 21]);
yticks(-20:10:20)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

exportgraphics(fig_matching_inflation_warsite,"plots/paper_fig_matching_inflation_warsite_@{MODEL_NAME}.pdf",'ContentType','vector');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% inflation matching: nearby/distant (belligerent) %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching_inflation_belligerent = figure('name','inflation matching: belligerent');
fig_matching_inflation_belligerent.Position(3) = 600;

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Inflation}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_belligerent_nearby.Color(4) = 0.1;
lb_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_belligerent_nearby.Color(4) = 0.1;
shaded_belligerent_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.nearby.inflation(:,3)',fliplr(belligerent.nearby.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_nearby.FaceColor =  col_N;
point_belligerent_nearby = plot(irf_horizon-1,belligerent.nearby.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_N);
point_BN = plot(irf_horizon-1,oo_.irfs.plot_pi_BN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);

ub_belligerent_distant = plot(irf_horizon-1,belligerent.distant.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_belligerent_distant.Color(4) = 0.1;
lb_belligerent_distant = plot(irf_horizon-1,belligerent.distant.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_belligerent_distant.Color(4) = 0.1;
shaded_belligerent_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[belligerent.distant.inflation(:,3)',fliplr(belligerent.distant.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_belligerent_distant.FaceColor =  col_D;
point_belligerent_distant = plot(irf_horizon-1,belligerent.distant.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_D);
point_BD = plot(irf_horizon-1,oo_.irfs.plot_pi_BD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);

hold off;
leg = legend([point_nearby, point_distant],{'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
%xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-16.3 16.3]);
yticks(-15:5:15)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

exportgraphics(fig_matching_inflation_belligerent,"plots/paper_fig_matching_inflation_belligerent_@{MODEL_NAME}.pdf",'ContentType','vector');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% inflation matching: nearby/distant (third) %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fig_matching_inflation_foreign = figure('name','inflation matching: third');
fig_matching_inflation_foreign.Position(3) = 600;

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Inflation}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_nearby = plot(irf_horizon-1,nearby.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.inflation(:,3)',fliplr(nearby.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_N);
point_TN = plot(irf_horizon-1,oo_.irfs.plot_pi_TN_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);

ub_distant = plot(irf_horizon-1,distant.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.inflation(:,3)',fliplr(distant.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_D);
point_TD = plot(irf_horizon-1,oo_.irfs.plot_pi_TD_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);

hold off;
leg = legend([point_nearby, point_distant],{'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-16.3 16.3]);
yticks(-15:5:15)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

exportgraphics(fig_matching_inflation_foreign,"plots/paper_fig_matching_inflation_third_@{MODEL_NAME}.pdf",'ContentType','vector');