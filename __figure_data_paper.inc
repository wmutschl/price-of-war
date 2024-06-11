%%%%%%%%%%%%%%%%%%%%%%%%%
%% plots used in paper %%
%%%%%%%%%%%%%%%%%%%%%%%%%

FontSize = 18;
FontSizeTitle  = 23;
FontSizeLabels = 21;
FontSizeLegend = 18;

fig_matching = figure('name','matching');
fig_matching.Position(3) = 1200;
fig_matching.Position(4) = 375;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gdp matching: warsite vs nearby/distant %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%fig_matching_output = figure('name','output matching');
%fig_matching_output.Position(3) = 600;
subplot(1,2,1);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
%title('\textbf{Output}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
yline(0,'LineWidth',LineWidth);
hold on;

ub_warsite = plot(x, warsite.gdp(:,3)', '-', 'Color',col_H, 'LineWidth',LineWidth); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(x, warsite.gdp(:,2)', '-', 'Color',col_H, 'LineWidth',LineWidth); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill(x2, [warsite.gdp(:,3)', fliplr(warsite.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(x, warsite.gdp(:,1)', '-', 'Color',col_H, 'LineWidth',LineWidth);
point_H = plot(x, oo_.irfs.plot_gdp_H_eps_war(irf_horizon), '--', 'Color',col_H, 'LineWidth',LineWidth);

ub_nearby = plot(x, nearby.gdp(:,3)', '-', 'Color',col_N, 'LineWidth',LineWidth); ub_nearby.Color(4) = 0.05;
lb_nearby = plot(x, nearby.gdp(:,2)', '-', 'Color',col_N, 'LineWidth',LineWidth); lb_nearby.Color(4) = 0.05;
shaded_nearby = fill(x2, [nearby.gdp(:,3)', fliplr(nearby.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(x, nearby.gdp(:,1)', '-', 'Color',col_N, 'LineWidth',LineWidth);
point_N = plot(x, oo_.irfs.plot_gdp_N_eps_war(irf_horizon), '--', 'Color',col_N, 'LineWidth',LineWidth);

ub_distant = plot(x, distant.gdp(:,3)', '-', 'Color',col_D, 'LineWidth',LineWidth); ub_distant.Color(4) = 0.1;
lb_distant = plot(x, distant.gdp(:,2)', '-', 'Color',col_D, 'LineWidth',LineWidth); lb_distant.Color(4) = 0.1;
shaded_distant = fill(x2, [distant.gdp(:,3)', fliplr(distant.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(x, distant.gdp(:,1)', '-', 'Color',col_D, 'LineWidth',LineWidth);
point_D = plot(x, oo_.irfs.plot_gdp_D_eps_war(irf_horizon), '--', 'Color',col_D, 'LineWidth',LineWidth);

hold off;
leg = legend([point_warsite, point_nearby, point_distant],{'Home', 'Nearby', 'Distant'},'Location','SouthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4])
xticks(0:2:8);
ylim([-54 12]);
yticks(-60:10:40)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
%filename = "war_plots_paper/fig_matching_output.pdf";
%exportgraphics(fig_matching_output,filename,'ContentType','vector');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% inflation matching: warsite vs nearby/distant %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%fig_matching_inflation = figure('name','inflation matching');
%fig_matching_inflation.Position(3) = 600;
subplot(1,2,2);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
%title('\textbf{Inflation}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
yline(0,'LineWidth',LineWidth);
hold on;

ub_warsite = plot(x, warsite.inflation(:,3)', '-', 'Color',col_H, 'LineWidth',LineWidth); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(x, warsite.inflation(:,2)', '-', 'Color',col_H, 'LineWidth',LineWidth); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill(x2, [warsite.inflation(:,3)', fliplr(warsite.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(x, warsite.inflation(:,1)', '-', 'Color',col_H, 'LineWidth',LineWidth);
point_H = plot(x, oo_.irfs.plot_pi_H_eps_war(irf_horizon), '--', 'Color',col_H, 'LineWidth',LineWidth);

ub_nearby = plot(x, nearby.inflation(:,3)', '-', 'Color',col_N, 'LineWidth',LineWidth); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(x, nearby.inflation(:,2)', '-', 'Color',col_N, 'LineWidth',LineWidth); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill(x2, [nearby.inflation(:,3)', fliplr(nearby.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(x, nearby.inflation(:,1)', '-', 'Color',col_N, 'LineWidth',LineWidth);
point_N = plot(x, oo_.irfs.plot_pi_N_eps_war(irf_horizon), '--', 'Color',col_N, 'LineWidth',LineWidth);

ub_distant = plot(x, distant.inflation(:,3)', '-', 'Color',col_D, 'LineWidth',LineWidth); ub_distant.Color(4) = 0.1;
lb_distant = plot(x, distant.inflation(:,2)', '-', 'Color',col_D, 'LineWidth',LineWidth); lb_distant.Color(4) = 0.1;
shaded_distant = fill(x2, [distant.inflation(:,3)', fliplr(distant.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(x, distant.inflation(:,1)', '-', 'Color',col_D, 'LineWidth',LineWidth);
point_D = plot(x, oo_.irfs.plot_pi_D_eps_war(irf_horizon), '--', 'Color',col_D, 'LineWidth',LineWidth);

hold off;
leg = legend([point_warsite, point_nearby, point_distant],{'Home', 'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([-5 28]);
yticks(-10:5:40)
grid on;

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

%filename = "war_plots_paper/fig_matching_inflation.pdf";
%exportgraphics(fig_matching_inflation,filename,'ContentType','vector')

filename = "war_plots_paper/fig_matching.pdf";
exportgraphics(fig_matching,filename,'ContentType','vector');



fig_validation = figure('name','validation');
fig_validation.Position(3) = 1200;
fig_validation.Position(4) = 375;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% war shock and productivity validation %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
subplot(1,4,1);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
title('\textbf{War shock}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
%yline(0,'LineWidth',2);
hold on;
point_war_H = plot(x, oo_.irfs.war_eps_war(irf_horizon), '-', 'Color',col_H, 'LineWidth',LineWidth);
hold off;
leg = legend([point_war_H],{'Home'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Level', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([0 1.5]);
yticks(0:0.2:1.4)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';


subplot(1,4,2);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
title('\textbf{Productivity}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
yline(0,'LineWidth',2);
hold on;
ub_warsite = plot(x, warsite.tfp(:,3)', '-', 'Color',col_H, 'LineWidth',LineWidth); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(x, warsite.tfp(:,2)', '-', 'Color',col_H, 'LineWidth',LineWidth); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill(x2, [warsite.tfp(:,3)', fliplr(warsite.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(x, warsite.tfp(:,1)', '-', 'Color',col_H, 'LineWidth',LineWidth);
point_H = plot(x, oo_.irfs.plot_a_H_eps_war(irf_horizon), '--', 'Color',col_H, 'LineWidth',LineWidth);
ub_nearby = plot(x, nearby.tfp(:,3)', '-', 'Color',col_N, 'LineWidth',LineWidth); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(x, nearby.tfp(:,2)', '-', 'Color',col_N, 'LineWidth',LineWidth); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill(x2, [nearby.tfp(:,3)', fliplr(nearby.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(x, nearby.tfp(:,1)', '-', 'Color',col_N, 'LineWidth',LineWidth);
point_N = plot(x, oo_.irfs.plot_a_N_eps_war(irf_horizon), '--', 'Color',col_N, 'LineWidth',LineWidth);
ub_distant = plot(x, distant.tfp(:,3)', '-', 'Color',col_D, 'LineWidth',LineWidth); ub_distant.Color(4) = 0.1;
lb_distant = plot(x, distant.tfp(:,2)', '-', 'Color',col_D, 'LineWidth',LineWidth); lb_distant.Color(4) = 0.1;
shaded_distant = fill(x2, [distant.tfp(:,3)', fliplr(distant.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(x, distant.tfp(:,1)', '-', 'Color',col_D, 'LineWidth',LineWidth);
point_D = plot(x, oo_.irfs.plot_a_D_eps_war(irf_horizon), marker_D, 'Color',col_D, 'LineWidth',LineWidth);
hold off;
leg = legend([point_warsite, point_nearby, point_distant],{'Home', 'Nearby', 'Distant'},'Location','SouthEast','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([-45 15]);
yticks(-60:10:20)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

%fig_validation_warshock_tfp.Resize = 'off';
%filename = "war_plots_paper/fig_validation_warshock_tfp.pdf";
%saveas(fig_validation_warshock_tfp, filename, 'pdf')
%system(sprintf('pdfcrop %s %s', filename, filename));


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% capital and military validation %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%fig_validation_capital_military = figure('name','capital and military');
subplot(1,4,3);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
title('\textbf{Capital}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
yline(0,'LineWidth',2);
hold on;
ub_warsite = plot(x, warsite.capital(:,3)', '-', 'Color',col_H, 'LineWidth',LineWidth); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(x, warsite.capital(:,2)', '-', 'Color',col_H, 'LineWidth',LineWidth); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill(x2, [warsite.capital(:,3)', fliplr(warsite.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(x, warsite.capital(:,1)', '-', 'Color',col_H, 'LineWidth',LineWidth);
point_H = plot(x, oo_.irfs.plot_k_H_eps_war(irf_horizon), '--', 'Color',col_H, 'LineWidth',LineWidth);
ub_nearby = plot(x, nearby.capital(:,3)', '-', 'Color',col_N, 'LineWidth',LineWidth); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(x, nearby.capital(:,2)', '-', 'Color',col_N, 'LineWidth',LineWidth); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill(x2, [nearby.capital(:,3)', fliplr(nearby.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(x, nearby.capital(:,1)', '-', 'Color',col_N, 'LineWidth',LineWidth);
point_N = plot(x, oo_.irfs.plot_k_N_eps_war(irf_horizon), '--', 'Color',col_N, 'LineWidth',LineWidth);
ub_distant = plot(x, distant.capital(:,3)', '-', 'Color',col_D, 'LineWidth',LineWidth); ub_distant.Color(4) = 0.1;
lb_distant = plot(x, distant.capital(:,2)', '-', 'Color',col_D, 'LineWidth',LineWidth); lb_distant.Color(4) = 0.1;
shaded_distant = fill(x2, [distant.capital(:,3)', fliplr(distant.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(x, distant.capital(:,1)', '-', 'Color',col_D, 'LineWidth',LineWidth);
point_D = plot(x, oo_.irfs.plot_k_D_eps_war(irf_horizon), marker_D, 'Color',col_D, 'LineWidth',LineWidth);
hold off;
leg = legend([point_warsite, point_nearby, point_distant],{'Home', 'Nearby', 'Distant'},'Location','SouthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([-47 4]);
yticks(-60:10:20)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

subplot(1,4,4);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
title('\textbf{Military}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
yline(0,'LineWidth',2);
hold on;
ub_warsite = plot(x, warsite.milex(:,3)', '-', 'Color',col_H, 'LineWidth',LineWidth); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(x, warsite.milex(:,2)', '-', 'Color',col_H, 'LineWidth',LineWidth); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill(x2, [warsite.milex(:,3)', fliplr(warsite.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_H;
point_warsite = plot(x, warsite.milex(:,1)', '-', 'Color',col_H, 'LineWidth',LineWidth);
point_H = plot(x, oo_.irfs.plot_g_H_eps_war(irf_horizon), '--', 'Color',col_H, 'LineWidth',LineWidth);
ub_nearby = plot(x, nearby.milex(:,3)', '-', 'Color',col_N, 'LineWidth',LineWidth); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(x, nearby.milex(:,2)', '-', 'Color',col_N, 'LineWidth',LineWidth); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill(x2, [nearby.milex(:,3)', fliplr(nearby.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(x, nearby.milex(:,1)', '-', 'Color',col_N, 'LineWidth',LineWidth);
point_N = plot(x, oo_.irfs.plot_g_N_eps_war(irf_horizon), '--', 'Color',col_N, 'LineWidth',LineWidth);
ub_distant = plot(x, distant.milex(:,3)', '-', 'Color',col_D, 'LineWidth',LineWidth); ub_distant.Color(4) = 0.1;
lb_distant = plot(x, distant.milex(:,2)', '-', 'Color',col_D, 'LineWidth',LineWidth); lb_distant.Color(4) = 0.1;
shaded_distant = fill(x2, [distant.milex(:,3)', fliplr(distant.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(x, distant.milex(:,1)', '-', 'Color',col_D, 'LineWidth',LineWidth);
point_D = plot(x, oo_.irfs.plot_g_D_eps_war(irf_horizon), marker_D, 'Color',col_D, 'LineWidth',LineWidth);
hold off;
leg = legend([point_warsite, point_nearby, point_distant],{'Home', 'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([-4 21]);
yticks(-5:5:20)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

%filename = "war_plots_paper/fig_validation_capital_military.pdf";
%saveas(fig_validation_capital_military, filename, 'pdf');
%system(sprintf('pdfcrop %s %s', filename, filename));

filename = "war_plots_paper/fig_validation.pdf";
exportgraphics(fig_validation,filename,'ContentType','vector');

%fig_mechanism = figure('name','mechanism');
%fig_mechanism.Position(3) = 1400;


fig_mechanism_trade = figure('name','mechanism trade');
fig_mechanism_trade.Position(3) = 1200;
fig_mechanism_trade.Position(4) = 375;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% import prices and import volumes Nearby %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%fig_mechanism_import_prices_import_volumes_N = figure('name','import prices and import volumes N');

subplot(1,2,1);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
%title('\textbf{Import prices}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
yline(0,'LineWidth',2);
hold on;
point_pHN = plot(x, 100*oo_.irfs.p_H_N_eps_war(irf_horizon), '-', 'Color',col_N, 'LineWidth',LineWidth);
point_pHD = plot(x, 100*oo_.irfs.p_H_D_eps_war(irf_horizon), '-', 'Color',col_D, 'LineWidth',LineWidth);
%point_pHR = plot(x, 100*oo_.irfs.p_H_R_eps_war(irf_horizon), '-', 'Color',col_R, 'LineWidth',LineWidth);
hold off;
%leg = legend([point_pHN point_pHD point_pHR],["$p_{HN}$", "$p_{HD}$", "$p_{HR}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
leg = legend([point_pHN point_pHD],["$p_{HN}$", "$p_{HD}$"],'Location','NorthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([0 70]);
yticks(0:10:70)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

subplot(1,2,2);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
yline(0,'LineWidth',2);
hold on;
point_yHN = plot(x, 100*oo_.irfs.y_H_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N, 'LineWidth',LineWidth);
point_yHD = plot(x, 100*oo_.irfs.y_H_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D, 'LineWidth',LineWidth);
hold off;
leg = legend([point_yHN point_yHD],{'$y_{HN}$','$y_{HD}$'},'Location','NorthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([-3.7 0]);
yticks(-4:0.5:0)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

filename = "war_plots_paper/fig_mechanism_trade.pdf";
exportgraphics(fig_mechanism_trade,filename,'ContentType','vector');

% %subplot(1,4,5);
% %set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% %%title('\textbf{Import prices}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% %yline(0,'LineWidth',2);
% %hold on;
% %point_pNH = plot(x, 100*oo_.irfs.p_N_H_eps_war(irf_horizon), '-', 'Color',col_H, 'LineWidth',LineWidth);
% %point_pND = plot(x, 100*oo_.irfs.p_N_D_eps_war(irf_horizon), '-', 'Color',col_D, 'LineWidth',LineWidth);
% %point_pNR = plot(x, 100*oo_.irfs.p_N_R_eps_war(irf_horizon), '-', 'Color',col_R, 'LineWidth',LineWidth);
% %hold off;
% %leg = legend([point_pNH point_pND point_pNR],["$p_{NH}$", "$p_{ND}$", "$p_{NR}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %%xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% %xticks(irf_horizon-1);
% %grid on;
% 
% %subplot(3,4,9);
% %set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% %%title('\textbf{Import prices: D and R}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% %yline(0,'LineWidth',2);
% %hold on;
% %point_pDH = plot(x, 100*oo_.irfs.p_D_H_eps_war(irf_horizon), '-', 'Color',col_H, 'LineWidth',LineWidth);
% %point_pDN = plot(x, 100*oo_.irfs.p_D_N_eps_war(irf_horizon), '-', 'Color',col_N, 'LineWidth',LineWidth);
% %point_pDR = plot(x, 100*oo_.irfs.p_D_R_eps_war(irf_horizon), '-', 'Color',col_R, 'LineWidth',LineWidth);
% %hold off;
% %leg = legend([point_pDH point_pDN point_pDR],["$p_{DH}$", "$p_{DN}$", "$p_{DN}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %%ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% %xticks(0:2:8);
% %grid on;
% 
% subplot(2,4,2);
% set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% title('\textbf{Import volumes: N}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% yline(0,'LineWidth',2);
% hold on;
% point_yHN = plot(x, 100*oo_.irfs.y_H_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_H, 'LineWidth',LineWidth);
% point_yDN = plot(x, 100*oo_.irfs.y_D_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_D, 'LineWidth',LineWidth);
% point_yRN = plot(x, 100*oo_.irfs.y_R_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_R, 'LineWidth',LineWidth);
% hold off;
% leg = legend([point_yHN point_yDN point_yRN],{'$y_{HN}$','$y_{DN}$','$y_{RN}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% xticks(irf_horizon-1);
% grid on;
% 
% %filename = "war_plots_paper/fig_mechanism_import_prices_import_volumes_N.pdf";
% %saveas(fig_mechanism_import_prices_import_volumes_N, filename, 'pdf');
% %system(sprintf('pdfcrop %s %s', filename, filename));
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %% import volumes Distant and RoW %%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %fig_mechanism_import_volumes_D_R = figure('name','import volumes D and R');
% 
% subplot(2,4,3);
% set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% title('\textbf{Import volumes: D}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% yline(0,'LineWidth',2);
% hold on;
% point_yHD = plot(x, 100*oo_.irfs.y_H_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_H, 'LineWidth',LineWidth);
% point_yND = plot(x, 100*oo_.irfs.y_N_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_N, 'LineWidth',LineWidth);
% point_yRD = plot(x, 100*oo_.irfs.y_R_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_R, 'LineWidth',LineWidth);
% hold off;
% leg = legend([point_yHD point_yND point_yRD],{'$y_{HD}$','$y_{ND}$','$y_{RD}$'},'Location','NorthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% xticks(0:2:8);
% grid on;
% ylim([-0.14 0.20]);
% 
% subplot(2,4,4);
% set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% title('\textbf{Import volumes: R}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% yline(0,'LineWidth',2);
% hold on;
% point_yHR = plot(x, 100*oo_.irfs.y_H_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')), '-', 'Color',col_H, 'LineWidth',LineWidth);
% point_yNR = plot(x, 100*oo_.irfs.y_N_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')), '-', 'Color',col_N, 'LineWidth',LineWidth);
% point_yDR = plot(x, 100*oo_.irfs.y_D_R_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_R')), '-', 'Color',col_D, 'LineWidth',LineWidth);
% hold off;
% leg = legend([point_yHR point_yNR point_yDR],{'$y_{HR}$','$y_{NR}$','$y_{DR}$'},'Location','East','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% %xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% xticks(irf_horizon-1);
% grid on;
% ylim([-0.9 0.2]);
% 
% %filename = "war_plots_paper/fig_mechanism_import_volumes_D_R.pdf";
% %saveas(fig_mechanism_import_volumes_D_R, filename, 'pdf');
% %system(sprintf('pdfcrop %s %s', filename, filename));
% 
% %filename = "war_plots_paper/fig_mechanism_trade.pdf";
% %exportgraphics(fig_mechanism_trade,filename,'ContentType','vector');


fig_mechanism_macro = figure('name','mechanism macro');
fig_mechanism_macro.Position(3) = 1200;
fig_mechanism_macro.Position(4) = 375;

subplot(1,2,1);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
yline(0,'LineWidth',2);
hold on;
point_iN = plot(x, 100*oo_.irfs.i_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), ':', 'Color',col_N, 'LineWidth',LineWidth);
point_cN = plot(x, 100*oo_.irfs.c_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '--', 'Color',col_N, 'LineWidth',LineWidth);
point_nxN = plot(x, 100*oo_.irfs.nx_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-.', 'Color',col_N, 'LineWidth',LineWidth);
point_xN = plot(x, 100*oo_.irfs.x_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N, 'LineWidth',LineWidth);
hold off;
leg = legend([point_iN point_cN point_nxN point_xN],{'${i}_N$','${c}_N$','${nx}_N$','${x}_N$'},'Location','NorthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([-4.5 1]);
yticks(-4:1:1);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

subplot(1,2,2);
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
yline(0,'LineWidth',2);
hold on;
point_iD = plot(x, 100*oo_.irfs.i_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), ':', 'Color',col_D, 'LineWidth',LineWidth);
point_cD = plot(x, 100*oo_.irfs.c_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '--', 'Color',col_D, 'LineWidth',LineWidth);
point_nxD = plot(x, 100*oo_.irfs.nx_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-.', 'Color',col_D, 'LineWidth',LineWidth);
point_xD = plot(x, 100*oo_.irfs.x_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D, 'LineWidth',LineWidth);
hold off;
leg = legend([point_iD point_cD point_nxD point_xD],{'${i}_D$','${c}_D$','${nx}_D$','${x}_D$'},'Location','SouthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
xlim([-0.4 8.4]);
xticks(0:2:8);
ylim([-4.5 1]);
yticks(-4:1:1);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

filename = "war_plots_paper/fig_mechanism_macro.pdf";
exportgraphics(fig_mechanism_macro,filename,'ContentType','vector');


% %%%%%%%%%%%%%%%%%
% %% net exports %%
% %%%%%%%%%%%%%%%%%
% subplot(2,4,8);
% set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% title('\textbf{Net exports}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% yline(0,'LineWidth',2);
% hold on;
% point_H = plot(x, 100*oo_.irfs.nx_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')), '-', 'Color',col_H, 'LineWidth',LineWidth);
% point_N = plot(x, 100*oo_.irfs.nx_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N, 'LineWidth',LineWidth);
% point_D = plot(x, 100*oo_.irfs.nx_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D, 'LineWidth',LineWidth);
% hold off;
% leg = legend([point_H point_N point_D],{'${nx}_H$','${nx}_N$','${nx}_D$'},'Location','SouthEast','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% xticks(0:2:8);
% grid on;
% ylim([-3.4 0.3]);
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %% consumption/investment %%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%
% subplot(2,4,7);
% set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% title('\textbf{Consumption/Investment}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% yline(0,'LineWidth',2);
% hold on;
% point_cH = plot(x, 100*oo_.irfs.c_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')), '-', 'Color',col_H, 'LineWidth',LineWidth);
% point_cN = plot(x, 100*oo_.irfs.c_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N, 'LineWidth',LineWidth);
% point_cD = plot(x, 100*oo_.irfs.c_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D, 'LineWidth',LineWidth);
% point_iH = plot(x, 100*oo_.irfs.i_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')), '--', 'Color',col_H, 'LineWidth',LineWidth);
% point_iN = plot(x, 100*oo_.irfs.i_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '--', 'Color',col_N, 'LineWidth',LineWidth);
% point_iD = plot(x, 100*oo_.irfs.i_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '--', 'Color',col_D, 'LineWidth',LineWidth);
% hold off;
% leg = legend([point_cH point_cN point_cD point_iH point_iN point_iD],{'$c_H$','$c_N$','$c_D$','$i_H$','$i_N$','$i_D$'},'Location','SouthWest','NumColumns',2,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% xticks(0:2:8);
% grid on;
% ylim([-20 2]);
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%
% %% intermediate inputs %%
% %%%%%%%%%%%%%%%%%%%%%%%%%
% subplot(2,4,6);
% set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
% title('\textbf{Intermediate inputs}', 'Interpreter','latex', 'FontSize',FontSizeTitle);
% yline(0,'LineWidth',2);
% hold on;
% point_H = plot(x, 100*oo_.irfs.x_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')), '-', 'Color',col_H, 'LineWidth',LineWidth);
% point_N = plot(x, 100*oo_.irfs.x_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N, 'LineWidth',LineWidth);
% point_D = plot(x, 100*oo_.irfs.x_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D, 'LineWidth',LineWidth);
% hold off;
% leg = legend([point_H point_N point_D],{'$x_H$','$x_N$','$c_D$'},'Location','SouthWest','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = alphaLegend;
% xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% %ylabel('Percentage points', 'Interpreter','latex', 'FontSize',FontSizeLabels);
% xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
% xticks(irf_horizon-1);
% grid on;
% ylim([-20 2]);
% 
% 
% %filename = "war_plots_paper/fig_mechanism.pdf";
% %saveas(fig_mechanism, filename, 'eps');
% %system(sprintf('pdfcrop %s %s', filename, filename));
% 
% 
% %filename = "war_plots_paper/fig_mechanism_macro.pdf";
% %exportgraphics(fig_mechanism_macro,filename,'ContentType','vector');
% 
% filename = "war_plots_paper/fig_mechanism.pdf";
% exportgraphics(fig_mechanism,filename,'ContentType','vector');


if PLOTS_PAPER == 1 || PLOTS_SLIDES == 1
    if PLOTS_PAPER == 1
        fig_consumption = figure('name','Consumption');
    elseif PLOTS_SLIDES == 1
        fig_consumption_investment = figure('name','Consumption and investment');
        subplot(1,2,1);
    end
    hold on;
    if isfield(oo_.irfs,'c_H_eps_war')
        point_H = plot(xirf, 100*oo_.irfs.c_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')), '-', 'Color',col_H);
        legendSubsets = [point_H];
        legendLabels = ["Home"];
    end
    if isfield(oo_.irfs,'c_N_eps_war')
        point_N = plot(xirf, 100*oo_.irfs.c_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N);
        legendSubsets = [legendSubsets point_N];
        legendLabels = [legendLabels "Nearby"];
    end    
    if isfield(oo_.irfs,'c_D_eps_war')
        point_D = plot(xirf, 100*oo_.irfs.c_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D);
        legendSubsets = [legendSubsets point_D];
        legendLabels = [legendLabels "Distant"];
    end
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    leg = legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend-2,'Location','SouthWest','NumColumns',1,'Interpreter','latex');
    leg.BackgroundAlpha = 0.4;
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel(sprintf('Percentage points'),'FontSize',FontSize-1);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    ylim([-16 0]);
    xticks(0:2:8);
    grid on;
    if PLOTS_SLIDES == 1
        title('Consumption','FontWeight','normal','FontSize',FontSize+4,'Interpreter', 'latex');
    end
    hold off;
    if PLOTS_PAPER == 1 && PLOTS_PRINT
        filename = "war_plots/fig_consumption.pdf";
        saveas(fig_consumption, filename, 'pdf')
        system(sprintf('pdfcrop %s %s', filename, filename));
    end
end
%%%%%%%%%%%%%%%%%%%%%%%%%
%% Intermediate inputs %%
%%%%%%%%%%%%%%%%%%%%%%%%%
if PLOTS_PAPER == 1 || PLOTS_SLIDES == 1
    if PLOTS_PAPER == 1
        fig_intermediate_inputs = figure('name','Intermediate inputs');
    elseif PLOTS_SLIDES == 1
        fig_netexports_intermediate_inputs = figure('name','Net exports and intermediate inputs');
        subplot(1,2,1);
    end
    hold on;
    if isfield(oo_.irfs,'plot_x_H_eps_war')
        point_H = plot(xirf, oo_.irfs.plot_x_H_eps_war(irf_horizon), '-', 'Color',col_H);
        legendSubsets = [point_H];
        legendLabels = ["Home"];
    end
    if isfield(oo_.irfs,'x_N_eps_war')
        point_N = plot(xirf, 100*oo_.irfs.x_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N);
        legendSubsets = [legendSubsets point_N];
        legendLabels = [legendLabels "Nearby"];
    end
    if isfield(oo_.irfs,'plot_x_D_eps_war')
        point_D = plot(xirf, 100*oo_.irfs.x_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D);
        legendSubsets = [legendSubsets point_D];
        legendLabels = [legendLabels "Distant"];
    end
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize-4);
    leg = legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend-2,'Location','SouthWest','NumColumns',1,'Interpreter','latex');
    leg.BackgroundAlpha = 0.4;
    xlabel('Year after war onset','FontSize',FontSize-4);
    ylabel(sprintf('Percentage points'),'FontSize',FontSize-4);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    if PLOTS_SLIDES == 1        
        title('Intermediate inputs','FontWeight','normal','FontSize',FontSize+4,'Interpreter', 'latex');
    end    
    hold off;
    if PLOTS_PAPER == 1 && PLOTS_PRINT
        filename = "war_plots/fig_imports_intermediates.pdf";
        saveas(fig_imports_intermediates, filename, 'pdf')
        system(sprintf('pdfcrop %s %s', filename, filename));
    end
end


%%%%%%%%%%%%%%%%%
%% Net exports %%
%%%%%%%%%%%%%%%%%
if PLOTS_PAPER == 1 || PLOTS_SLIDES == 1
    if PLOTS_PAPER == 1
        fig_netexports = figure('name','Net exports');
    elseif PLOTS_SLIDES == 1
        subplot(1,2,2);
    end
    hold on;
    if isfield(oo_.irfs,'plot_nx_H_eps_war')
        point_H = plot(xirf, oo_.irfs.plot_nx_H_eps_war(irf_horizon), '-', 'Color',col_H);
        legendSubsets = [point_H];
        legendLabels = ["Home"];
    end
    if isfield(oo_.irfs,'nx_N_eps_war')
        point_N = plot(xirf, 100*oo_.irfs.nx_N_eps_war(irf_horizon), '-', 'Color',col_N);
        legendSubsets = [legendSubsets point_N];
        legendLabels = [legendLabels "Nearby"];
    end
    if isfield(oo_.irfs,'plot_nx_D_eps_war')
        point_D = plot(xirf, 100*oo_.irfs.nx_D_eps_war(irf_horizon), '-', 'Color',col_D);
        legendSubsets = [legendSubsets point_D];
        legendLabels = [legendLabels "Distant"];
    end
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize-4);
    leg = legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend-2,'Location','SouthEast','NumColumns',1,'Interpreter','latex');
    leg.BackgroundAlpha = 0.4;
    xlabel('Year after war onset','FontSize',FontSize-4);
    ylabel(sprintf('Percentage points'),'FontSize',FontSize-4);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    if PLOTS_SLIDES == 1        
        title('Net exports','FontWeight','normal','FontSize',FontSize+4,'Interpreter', 'latex');
    end    
    hold off;
    if PLOTS_PAPER == 1 && PLOTS_PRINT
        filename = "war_plots/fig_imports_intermediates.pdf";
        saveas(fig_imports_intermediates, filename, 'pdf')
        system(sprintf('pdfcrop %s %s', filename, filename));
    end
    if PLOTS_SLIDES == 1 && PLOTS_PRINT
        filename = "war_plots/fig_netexports_intermediate_inputs.pdf";
        saveas(fig_netexports_intermediate_inputs, filename, 'pdf')
        system(sprintf('pdfcrop %s %s', filename, filename));
    end
end



%%%%%%%%%%%%%%%%
%% Investment %%
%%%%%%%%%%%%%%%%
if PLOTS_PAPER == 1 || PLOTS_SLIDES == 1
    if PLOTS_PAPER == 1
        fig_investment = figure('name','Investment');
    elseif PLOTS_SLIDES == 1
        subplot(1,2,2);
    end
    hold on;
    if isfield(oo_.irfs,'i_H_eps_war')
        point_H = plot(xirf, 100*oo_.irfs.i_H_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_H')), '-', 'Color',col_H);
        legendSubsets = [point_H];
        legendLabels = ["Home"];
    end
    if isfield(oo_.irfs,'i_N_eps_war')
        point_N = plot(xirf, 100*oo_.irfs.i_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N);
        legendSubsets = [legendSubsets point_N];
        legendLabels = [legendLabels "Nearby"];
    end    
    if isfield(oo_.irfs,'i_D_eps_war')
        point_D = plot(xirf, 100*oo_.irfs.i_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D);
        legendSubsets = [legendSubsets point_D];
        legendLabels = [legendLabels "Distant"];
    end
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    leg = legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend-2,'Location','SouthWest','NumColumns',1,'Interpreter','latex');
    leg.BackgroundAlpha = 0.4;
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel(sprintf('Percentage points'),'FontSize',FontSize-1);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    ylim([-16 0])
    xticks(0:2:8);
    grid on;
    if PLOTS_SLIDES == 1
        title('Investment','FontWeight','normal','FontSize',FontSize+4,'Interpreter', 'latex');
    end
    hold off;
    if PLOTS_PAPER == 1 && PLOTS_PRINT
        filename = "war_plots/fig_investment.pdf";
        saveas(fig_investment, filename, 'pdf')
        system(sprintf('pdfcrop %s %s', filename, filename));
    end
    if PLOTS_SLIDES == 1 && PLOTS_PRINT
        filename = "war_plots/fig_consumption_investment.pdf";
        saveas(fig_consumption_investment, filename, 'pdf')
        system(sprintf('pdfcrop %s %s', filename, filename));
    end
end




if PLOTS_SLIDES == 0
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Import prices for goods produced in Home %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if PLOTS_PAPER == 1
    fig_import_prices_for_goods_produced_in_H = figure('name','Import prices for goods produced in H');
    hold on;
    if isfield(oo_.irfs,'p_H_N_eps_war')        
        point_N = plot(xirf, 100*oo_.irfs.p_H_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'p_H_N')), '-', 'Color',col_N);
        legendSubsets = [point_N];
        legendLabels = ["Nearby"];
    end
    if isfield(oo_.irfs,'p_D_N_eps_war')
        point_D = plot(xirf, 100*oo_.irfs.p_D_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'p_D_N')), '-', 'Color',col_D);
        legendSubsets = [legendSubsets point_D];
        legendLabels = [legendLabels "Distant"];
    end
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','NorthEast','Box', 'off','NumColumns',3);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    %title('Import prices for goods produced in H')
    hold off;
end
if PLOTS_PRINT
    filename = "war_plots/fig_import_prices_for_goods_produced_in_H.pdf";
    saveas(fig_import_prices_for_goods_produced_in_H, filename, 'pdf')
    system(sprintf('pdfcrop %s %s', filename, filename));
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Change in exchange rates %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if PLOTS_PAPER == 1
    fig_exchange_rates = figure('name','Exchange rates');
subplot(1,2,1)
    hold on;
    if isfield(oo_.irfs,'dner_H_N_eps_war')
        point_H_N = plot(xirf, oo_.irfs.dner_H_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'dner_H_N')), '-', 'Color',col_H);
        legendSubsets = [point_H_N];
        legendLabels = ["Home"];
    end
    if isfield(oo_.irfs,'dner_D_N_eps_war')
        point_D_N = plot(xirf, oo_.irfs.dner_D_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'dner_D_N')), '-', 'Color',col_D);
        legendSubsets = [legendSubsets, point_D_N];
        legendLabels = [legendLabels, "Distant"];
    end
    if isfield(oo_.irfs,'dner_R_N_eps_war')
        point_R_N = plot(xirf, oo_.irfs.dner_R_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'dner_R_N')), '-', 'Color',col_R);
        legendSubsets = [legendSubsets, point_R_N];
        legendLabels = [legendLabels, "RoW"];
    end
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','NorthEast','Box', 'off','NumColumns',3);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Change in Nominal Exchange Rate E_{iN,t+1}/E_{iN,t}')
    hold off;
subplot(1,2,2)
    hold on;
    if isfield(oo_.irfs,'rer_H_N_eps_war')
        point_H_N = plot(xirf, oo_.irfs.rer_H_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'rer_H_N')), '-', 'Color',col_H);
        legendSubsets = [point_H_N];
        legendLabels = ["Home"];
    end
    if isfield(oo_.irfs,'rer_D_N_eps_war')
        point_D_N = plot(xirf, oo_.irfs.rer_D_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'rer_D_N')), '-', 'Color',col_D);
        legendSubsets = [legendSubsets, point_D_N];
        legendLabels = [legendLabels, "Distant"];
    end
    if isfield(oo_.irfs,'rer_R_N_eps_war')
        point_R_N = plot(xirf, oo_.irfs.rer_R_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'rer_R_N')), '-', 'Color',col_R);
        legendSubsets = [legendSubsets, point_R_N];
        legendLabels = [legendLabels, "RoW"];
    end
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','NorthEast','Box', 'off','NumColumns',3);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Real Exchange Rate Q_{iN,t}')
    hold off;
end
if PLOTS_PRINT
    filename = "war_plots/fig_import_prices_for_goods_produced_in_H.pdf";
    saveas(fig_import_prices_for_goods_produced_in_H, filename, 'pdf')
    system(sprintf('pdfcrop %s %s', filename, filename));
end

@#if PLOTS_TRADE == 1
%%%%%%%%%%%%%%%%%%%%%
%% Bilateral trade %%
%%%%%%%%%%%%%%%%%%%%%
fig_trade = figure('name','Bilateral Trade','Units','normalized','Position',[-0.4398 0.1799 0.4395 0.6007]);
subplot(2,4,1);
    hold on;
    point_ex_N_H = plot(xirf, oo_.irfs.export_value_N_H_eps_war(irf_horizon), '-',  'Color',col_N);
    point_ex_D_H = plot(xirf, oo_.irfs.export_value_D_H_eps_war(irf_horizon), '-',  'Color',col_D);
    point_ex_R_H = plot(xirf, oo_.irfs.export_value_R_H_eps_war(irf_horizon), '-',  'Color',col_R);
    point_im_N_H = plot(xirf, oo_.irfs.import_value_N_H_eps_war(irf_horizon), '--', 'Color',col_N);
    point_im_D_H = plot(xirf, oo_.irfs.import_value_D_H_eps_war(irf_horizon), '--', 'Color',col_D);
    point_im_R_H = plot(xirf, oo_.irfs.import_value_R_H_eps_war(irf_horizon), '--', 'Color',col_R);    
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_N_H, point_ex_D_H, point_ex_R_H, point_im_N_H, point_im_D_H, point_im_R_H];
    legendLabels  = ["EX to N"   , "EX to D"   , "EX to R"   , "IM from N" , "IM from D" , "IM from R" ];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Values: H')
    hold off;
subplot(2,4,2);
    hold on;
    point_ex_H_N = plot(xirf, oo_.irfs.export_value_H_N_eps_war(irf_horizon), '-',  'Color',col_H);
    point_ex_D_N = plot(xirf, oo_.irfs.export_value_D_N_eps_war(irf_horizon), '-',  'Color',col_D);
    point_ex_R_N = plot(xirf, oo_.irfs.export_value_R_N_eps_war(irf_horizon), '-',  'Color',col_R);
    point_im_H_N = plot(xirf, oo_.irfs.import_value_H_N_eps_war(irf_horizon), '--', 'Color',col_H);
    point_im_D_N = plot(xirf, oo_.irfs.import_value_D_N_eps_war(irf_horizon), '--', 'Color',col_D);
    point_im_R_N = plot(xirf, oo_.irfs.import_value_R_N_eps_war(irf_horizon), '--', 'Color',col_R);
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_H_N, point_ex_D_N, point_ex_R_N, point_im_H_N, point_im_D_N, point_im_R_N];
    legendLabels  = ["EX to H"   , "EX to D"   , "EX to R"   , "IM from H" , "IM from D" , "IM from R"];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Values: N')
    hold off;
subplot(2,4,3);
    hold on;
    point_ex_H_D = plot(xirf, oo_.irfs.export_value_H_D_eps_war(irf_horizon), '-',  'Color',col_H);
    point_ex_N_D = plot(xirf, oo_.irfs.export_value_N_D_eps_war(irf_horizon), '-',  'Color',col_N);
    point_ex_R_D = plot(xirf, oo_.irfs.export_value_R_D_eps_war(irf_horizon), '-',  'Color',col_R);
    point_im_H_D = plot(xirf, oo_.irfs.import_value_H_D_eps_war(irf_horizon), '--', 'Color',col_H);
    point_im_N_D = plot(xirf, oo_.irfs.import_value_N_D_eps_war(irf_horizon), '--', 'Color',col_N);
    point_im_R_D = plot(xirf, oo_.irfs.import_value_R_D_eps_war(irf_horizon), '--', 'Color',col_R);
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_H_D, point_ex_N_D, point_ex_R_D, point_im_H_D, point_im_N_D, point_im_R_D];
    legendLabels  = ["EX to H"   , "EX to N"   , "EX to R"   , "IM from H" , "IM from N" , "IM from R"];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Values: D')
    hold off;
subplot(2,4,4);
    hold on;
    point_ex_H_R = plot(xirf, oo_.irfs.export_value_H_R_eps_war(irf_horizon), '-',  'Color',col_H);
    point_ex_N_R = plot(xirf, oo_.irfs.export_value_N_R_eps_war(irf_horizon), '-',  'Color',col_N);
    point_ex_D_R = plot(xirf, oo_.irfs.export_value_D_R_eps_war(irf_horizon), '-',  'Color',col_D);
    point_im_H_R = plot(xirf, oo_.irfs.import_value_H_R_eps_war(irf_horizon), '--', 'Color',col_H);
    point_im_N_R = plot(xirf, oo_.irfs.import_value_N_R_eps_war(irf_horizon), '--', 'Color',col_N);
    point_im_D_R = plot(xirf, oo_.irfs.import_value_D_R_eps_war(irf_horizon), '--', 'Color',col_D);
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_H_R, point_ex_N_R, point_ex_D_R, point_im_H_R, point_im_N_R, point_im_D_R];
    legendLabels  = ["EX to H"   , "EX to N"   , "EX to D"   , "IM from H" , "IM from N" , "IM from D"];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Values: R')
    hold off;
subplot(2,4,5);
    hold on;
    point_ex_N_H = plot(xirf, oo_.irfs.export_volume_N_H_eps_war(irf_horizon), '-',  'Color',col_N);
    point_ex_D_H = plot(xirf, oo_.irfs.export_volume_D_H_eps_war(irf_horizon), '-',  'Color',col_D);
    point_ex_R_H = plot(xirf, oo_.irfs.export_volume_R_H_eps_war(irf_horizon), '-',  'Color',col_R);
    point_im_N_H = plot(xirf, oo_.irfs.import_volume_N_H_eps_war(irf_horizon), '--', 'Color',col_N);
    point_im_D_H = plot(xirf, oo_.irfs.import_volume_D_H_eps_war(irf_horizon), '--', 'Color',col_D);
    point_im_R_H = plot(xirf, oo_.irfs.import_volume_R_H_eps_war(irf_horizon), '--', 'Color',col_R);
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_N_H, point_ex_D_H, point_ex_R_H, point_im_N_H, point_im_D_H, point_im_R_H];
    legendLabels  = ["EX to N"   , "EX to D"   , "EX to R"   , "IM from N" , "IM from D" , "IM from R"];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Volumes: H')
    hold off;
subplot(2,4,6);
    hold on;
    point_ex_H_N = plot(xirf, oo_.irfs.export_volume_H_N_eps_war(irf_horizon), '-',  'Color',col_H);
    point_ex_D_N = plot(xirf, oo_.irfs.export_volume_D_N_eps_war(irf_horizon), '-',  'Color',col_D);
    point_ex_R_N = plot(xirf, oo_.irfs.export_volume_R_N_eps_war(irf_horizon), '-',  'Color',col_R);
    point_im_H_N = plot(xirf, oo_.irfs.import_volume_H_N_eps_war(irf_horizon), '--', 'Color',col_H);
    point_im_D_N = plot(xirf, oo_.irfs.import_volume_D_N_eps_war(irf_horizon), '--', 'Color',col_D);
    point_im_R_N = plot(xirf, oo_.irfs.import_volume_R_N_eps_war(irf_horizon), '--', 'Color',col_R);
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_H_N, point_ex_D_N, point_ex_R_N, point_im_H_N, point_im_D_N, point_im_R_N];
    legendLabels  = ["EX to H"   , "EX to D"   , "EX to R"   , "IM from H" , "IM from D" , "IM from R"];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Volumes: N')
    hold off;
subplot(2,4,7);
    hold on;
    point_ex_H_D = plot(xirf, oo_.irfs.export_volume_H_D_eps_war(irf_horizon), '-',  'Color',col_H);
    point_ex_N_D = plot(xirf, oo_.irfs.export_volume_N_D_eps_war(irf_horizon), '-',  'Color',col_N);
    point_ex_R_D = plot(xirf, oo_.irfs.export_volume_R_D_eps_war(irf_horizon), '-',  'Color',col_R);
    point_im_H_D = plot(xirf, oo_.irfs.import_volume_H_D_eps_war(irf_horizon), '--', 'Color',col_H);
    point_im_N_D = plot(xirf, oo_.irfs.import_volume_N_D_eps_war(irf_horizon), '--', 'Color',col_N);
    point_im_R_D = plot(xirf, oo_.irfs.import_volume_R_D_eps_war(irf_horizon), '--', 'Color',col_R);
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_H_D, point_ex_N_D, point_ex_R_D, point_im_H_D, point_im_N_D, point_im_R_D];
    legendLabels  = ["EX to H"   , "EX to N"   , "EX to R"   , "IM from H" , "IM from N" , "IM from R"];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Volumes: D')
    hold off;
subplot(2,4,8);
    hold on;
    point_ex_H_R = plot(xirf, oo_.irfs.export_volume_H_R_eps_war(irf_horizon), '-',  'Color',col_H);
    point_ex_N_R = plot(xirf, oo_.irfs.export_volume_N_R_eps_war(irf_horizon), '-',  'Color',col_N);
    point_ex_D_R = plot(xirf, oo_.irfs.export_volume_D_R_eps_war(irf_horizon), '-',  'Color',col_D);
    point_im_H_R = plot(xirf, oo_.irfs.import_volume_H_R_eps_war(irf_horizon), '--', 'Color',col_H);
    point_im_N_R = plot(xirf, oo_.irfs.import_volume_N_R_eps_war(irf_horizon), '--', 'Color',col_N);
    point_im_D_R = plot(xirf, oo_.irfs.import_volume_D_R_eps_war(irf_horizon), '--', 'Color',col_D);
    yline(0,'LineWidth',2);
    set(gca,'FontSize',FontSize);
    legendSubsets = [point_ex_H_R, point_ex_N_R, point_ex_D_R, point_im_H_R, point_im_N_R, point_im_D_R];
    legendLabels  = ["EX to H"   , "EX to N"   , "EX to D"   , "IM from H" , "IM from N" , "IM from D"];
    legend(legendSubsets,legendLabels,'FontSize',FontSizeLegend,'Location','best','Box', 'off','NumColumns',2);
    xlabel('Year after war onset', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    ylabel('Percent', 'Interpreter','latex', 'FontSize',FontSizeLabels);
    xlim([(irf_horizon(1)-1) (irf_horizon(end)-1)]);
    xticks(0:2:8);
    grid on;
    title('Trade Volumes: R')
    hold off;
@#endif

end

reset(groot);