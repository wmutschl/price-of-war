%%%%%%%%%%%%%%%%%%%%%%%%%
%% plots used in paper %%
%%%%%%%%%%%%%%%%%%%%%%%%%
SLIDES = true;

fontSize = 18;
fontSizeTitle  = 23;
fontSizeLabels = 21;
fontSizeLegend = 18;

%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gdp matching: warsite %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%
if SLIDES
    fig_matching_output = figure('name','output matching');
    fig_matching_output.Position(3) = 600;
    subplot(1,2,1);
else
    fig_matching_output_warsite = figure('name','output matching: war site');
    fig_matching_output_warsite.Position(3) = 600;
end

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
if SLIDES
    xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
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

if ~SLIDES
    exportgraphics(fig_matching_output_warsite,"plots/paper_fig_matching_output_warsite_@{MODEL_NAME}.pdf",'ContentType','vector');
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gdp matching: nearby/distant %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if SLIDES
    subplot(1,2,2);
else
    fig_matching_output_foreign = figure('name','output matching: foreign');
    fig_matching_output_foreign.Position(3) = 600;
end

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Output}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_nearby = plot(irf_horizon-1,nearby.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.gdp(:,3)',fliplr(nearby.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
point_N = plot(irf_horizon-1,oo_.irfs.plot_gdp_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);

ub_distant = plot(irf_horizon-1,distant.gdp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.gdp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.gdp(:,3)',fliplr(distant.gdp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.gdp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
point_D = plot(irf_horizon-1,oo_.irfs.plot_gdp_D_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);

hold off;
leg = legend([point_nearby, point_distant],{'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
if ~SLIDES
    ylabel('Percent', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-8.3 8.3]);
yticks(-8:4:8)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

if SLIDES
    exportgraphics(fig_matching_output,"plots/slides_fig_matching_output.pdf",'ContentType','vector');
else
    exportgraphics(fig_matching_output_foreign,"plots/paper_fig_matching_output_foreign_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% inflation matching: warsite %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if SLIDES
    fig_matching_inflation = figure('name','inflation matching');
    fig_matching_inflation.Position(3) = 600;
    subplot(1,2,1);
else    
    fig_matching_inflation_warsite = figure('name','inflation matching: war site');
    fig_matching_inflation_warsite.Position(3) = 600;
end

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
if SLIDES
    xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
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

if ~SLIDES
    exportgraphics(fig_matching_inflation_warsite,"plots/paper_fig_matching_inflation_warsite_@{MODEL_NAME}.pdf",'ContentType','vector');
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% inflation matching: nearby/distant %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if SLIDES
    subplot(1,2,2);
else    
    fig_matching_inflation_foreign = figure('name','inflation matching: foreign');
    fig_matching_inflation_foreign.Position(3) = 600;
end

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
%title('\textbf{Inflation}', 'Interpreter','latex', 'FontSize',fontSizeTitle);
yline(0,'LineWidth',lineWidth);
hold on;

ub_nearby = plot(irf_horizon-1,nearby.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
lb_nearby = plot(irf_horizon-1,nearby.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.inflation(:,3)',fliplr(nearby.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
point_nearby = plot(irf_horizon-1,nearby.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_N);
point_N = plot(irf_horizon-1,oo_.irfs.plot_pi_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);

ub_distant = plot(irf_horizon-1,distant.inflation(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
lb_distant = plot(irf_horizon-1,distant.inflation(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.inflation(:,3)',fliplr(distant.inflation(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
point_distant = plot(irf_horizon-1,distant.inflation(:,1)','-','LineWidth',lineWidth,'Color',col_D);
point_D = plot(irf_horizon-1,oo_.irfs.plot_pi_D_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);

hold off;
leg = legend([point_nearby, point_distant],{'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
if ~SLIDES
    ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-12.3 12.3]);
yticks(-12:6:12)

grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

if SLIDES
    exportgraphics(fig_matching_inflation,"plots/slides_fig_matching_inflation.pdf",'ContentType','vector');
else
    exportgraphics(fig_matching_inflation_foreign,"plots/paper_fig_matching_inflation_foreign_@{MODEL_NAME}.pdf",'ContentType','vector');
end


%%%%%%%%%%%%%%%
%% military  %%
%%%%%%%%%%%%%%%
if SLIDES
    fig_validation_milex_warshock = figure('name','validation: milex and warshock');
    fig_validation_milex_warshock.Position(3) = 600;
    subplot(1,2,1);
else
    fig_validation_milex = figure('name','validation: milex');
    fig_validation_milex.Position(3) = 600;
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('Military', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.milex(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.milex(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.milex(:,3)',fliplr(warsite.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_S;
point_warsite = plot(irf_horizon-1,warsite.milex(:,1)','-','LineWidth',lineWidth,'Color',col_S);
point_S = plot(irf_horizon-1,oo_.irfs.plot_g_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
%ub_nearby = plot(irf_horizon-1,nearby.milex(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
%lb_nearby = plot(irf_horizon-1,nearby.milex(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
%shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.milex(:,3)',fliplr(nearby.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
%point_nearby = plot(irf_horizon-1,nearby.milex(:,1)','-','LineWidth',lineWidth,'Color',col_N);
%point_N = plot(irf_horizon-1,oo_.irfs.plot_g_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
%ub_distant = plot(irf_horizon-1,distant.milex(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
%lb_distant = plot(irf_horizon-1,distant.milex(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
%shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.milex(:,3)',fliplr(distant.milex(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
%point_distant = plot(irf_horizon-1,distant.milex(:,1)','-','LineWidth',lineWidth,'Color',col_D);
%point_D = plot(irf_horizon-1,oo_.irfs.plot_g_D_eps_war(irf_horizon),marker_D,'LineWidth',lineWidth,'Color',col_D);
hold off;
%leg = legend([point_warsite, point_nearby, point_distant],{'War site', 'Nearby', 'Distant'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
leg = legend([point_warsite],{'War site'},'Location','NorthEast','NumColumns',2,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-10.3 10.3]);
yticks(-10:5:10)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

if ~SLIDES
    exportgraphics(fig_validation_milex,"plots/paper_fig_validation_milex_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%%%%
%% war shock  %%
%%%%%%%%%%%%%%%%
if SLIDES
    subplot(1,2,2);
else
    fig_validation_warshock = figure('name','validation: warshock');
    fig_validation_warshock.Position(3) = 600;
end

set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('War shock', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
point_war_S = plot(irf_horizon-1, oo_.irfs.war_eps_war(irf_horizon), '-', 'Color',col_S, 'LineWidth',lineWidth);
hold off;

leg = legend([point_war_S],{'War site'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
if SLIDES
    xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
if ~SLIDES
    ylabel('Level', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([0 1.51]);
yticks(0:0.5:1.5)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

if SLIDES
    exportgraphics(fig_validation_milex_warshock,"plots/slides_fig_validation_milex_warshock.pdf",'ContentType','vector');
else
    exportgraphics(fig_validation_warshock,"plots/paper_fig_validation_warshock_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%
%% capital %%
%%%%%%%%%%%%%
if SLIDES
    fig_validation_capital_productivity = figure('name','validation: capital and producitivity');
    fig_validation_capital_productivity.Position(3) = 600;
    subplot(1,2,1);
else
    fig_validation_capital = figure('name','validation: capital');
    fig_validation_capital.Position(3) = 600;
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('Capital', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.capital(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.capital(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.capital(:,3)',fliplr(warsite.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_S;
point_warsite = plot(irf_horizon-1,warsite.capital(:,1)','-','LineWidth',lineWidth,'Color',col_S);
point_S = plot(irf_horizon-1,oo_.irfs.plot_k_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
%ub_nearby = plot(irf_horizon-1,nearby.capital(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
%lb_nearby = plot(irf_horizon-1,nearby.capital(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
%shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.capital(:,3)',fliplr(nearby.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
%point_nearby = plot(irf_horizon-1,nearby.capital(:,1)','-','LineWidth',lineWidth,'Color',col_N);
%point_N = plot(irf_horizon-1,oo_.irfs.plot_k_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
%ub_distant = plot(irf_horizon-1,distant.capital(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
%lb_distant = plot(irf_horizon-1,distant.capital(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
%shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.capital(:,3)',fliplr(distant.capital(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
%point_distant = plot(irf_horizon-1,distant.capital(:,1)','-','LineWidth',lineWidth,'Color',col_D);
%point_D = plot(irf_horizon-1,oo_.irfs.plot_k_D_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_D);
hold off;
%leg = legend([point_warsite, point_nearby, point_distant],{'War site', 'Nearby', 'Distant'},'Location','SouthWest','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
leg = legend([point_warsite],{'War site'},'Location','NorthEast','NumColumns',2,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percent', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-31 31]);
yticks(-30:10:30)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

if ~SLIDES
    exportgraphics(fig_validation_capital,"plots/paper_fig_validation_capital_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%%%%%%%
%% productivity  %%
%%%%%%%%%%%%%%%%%%%
if SLIDES
    subplot(1,2,2);
else
    fig_validation_productivity = figure('name','validation: productivity');
    fig_validation_productivity.Position(3) = 600;
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('Productivity', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
ub_warsite = plot(irf_horizon-1,warsite.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_S); ub_warsite.Color(4) = 0.1;
lb_warsite = plot(irf_horizon-1,warsite.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_S); lb_warsite.Color(4) = 0.1;
shaded_warsite = fill([irf_horizon-1,fliplr(irf_horizon-1)],[warsite.tfp(:,3)',fliplr(warsite.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_warsite.FaceColor =  col_S;
point_warsite = plot(irf_horizon-1,warsite.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_S);
point_S = plot(irf_horizon-1,oo_.irfs.plot_a_S_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_S);
%ub_nearby = plot(irf_horizon-1,nearby.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_N); ub_nearby.Color(4) = 0.1;
%lb_nearby = plot(irf_horizon-1,nearby.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_N); lb_nearby.Color(4) = 0.1;
%shaded_nearby = fill([irf_horizon-1,fliplr(irf_horizon-1)],[nearby.tfp(:,3)',fliplr(nearby.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_nearby.FaceColor =  col_N;
%point_nearby = plot(irf_horizon-1,nearby.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_N);
%point_N = plot(irf_horizon-1,oo_.irfs.plot_a_N_eps_war(irf_horizon),'--','LineWidth',lineWidth,'Color',col_N);
%ub_distant = plot(irf_horizon-1,distant.tfp(:,3)','-','LineWidth',lineWidth,'Color',col_D); ub_distant.Color(4) = 0.1;
%lb_distant = plot(irf_horizon-1,distant.tfp(:,2)','-','LineWidth',lineWidth,'Color',col_D); lb_distant.Color(4) = 0.1;
%shaded_distant = fill([irf_horizon-1,fliplr(irf_horizon-1)],[distant.tfp(:,3)',fliplr(distant.tfp(:,2)')],'g','FaceAlpha',0.1,'EdgeColor','none','LineStyle','none'); shaded_distant.FaceColor =  col_D;
%point_distant = plot(irf_horizon-1,distant.tfp(:,1)','-','LineWidth',lineWidth,'Color',col_D);
%point_D = plot(irf_horizon-1,oo_.irfs.plot_a_D_eps_war(irf_horizon),marker_D,'LineWidth',lineWidth,'Color',col_D);
hold off;
%leg = legend([point_warsite, point_nearby, point_distant],{'War site', 'Nearby', 'Distant'},'Location','SouthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
leg = legend([point_warsite],{'War site'},'Location','NorthEast','NumColumns',2,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
if SLIDES
    xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
if ~SLIDES
    ylabel('Percent', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-42 42]);
yticks(-40:20:40);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

if SLIDES
    exportgraphics(fig_validation_capital_productivity,"plots/slides_fig_validation_capital_productivity.pdf",'ContentType','vector');
else
    exportgraphics(fig_validation_productivity,"plots/paper_fig_validation_productivity_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%%%%%%%
%% import prices %%
%%%%%%%%%%%%%%%%%%%
if SLIDES
    fig_mechanism_import_prices_volumes = figure('name','import prices and import volumes');
    fig_mechanism_import_prices_volumes.Position(3) = 600;
    subplot(1,2,1);
else
    fig_mechanism_import_prices = figure('name','mechanism: import prices');
    fig_mechanism_import_prices.Position(3) = 600;
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('Import prices', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
point_pSN = plot(irf_horizon-1, 100*oo_.irfs.p_S_N_eps_war(irf_horizon), '-', 'Color',col_N, 'LineWidth',lineWidth);
point_pSD = plot(irf_horizon-1, 100*oo_.irfs.p_S_D_eps_war(irf_horizon), '-', 'Color',col_D, 'LineWidth',lineWidth);
%point_pSR = plot(irf_horizon-1, 100*oo_.irfs.p_S_R_eps_war(irf_horizon), '-', 'Color',col_R, 'LineWidth',lineWidth);
hold off;
%leg = legend([point_pSN point_pSD point_pSR],["$p_{SN}$", "$p_{SD}$", "$p_{SR}$"],'Location','West','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
leg = legend([point_pSN point_pSD],["$p_{SN}$", "$p_{SD}$"],'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
if SLIDES
    xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
ylabel('Percent', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([0 55]);
yticks(0:10:50)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
if ~SLIDES
    exportgraphics(fig_mechanism_import_prices,"plots/paper_fig_mechanism_import_prices_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%%%%%%%%
%% import volumes %%
%%%%%%%%%%%%%%%%%%%%
if SLIDES
    subplot(1,2,2)
else
    fig_mechanism_import_volumes = figure('name','mechanism: import volumes');
    fig_mechanism_import_volumes.Position(3) = 600;
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('Import volumes', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
point_ySN = plot(irf_horizon-1, 100*oo_.irfs.y_S_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N, 'LineWidth',lineWidth);
point_ySD = plot(irf_horizon-1, 100*oo_.irfs.y_S_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D, 'LineWidth',lineWidth);
hold off;
leg = legend([point_ySN point_ySD],{'$y_{SN}$','$y_{SD}$'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
if SLIDES
    xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
end
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-3.2 0.05]);
yticks(-3:1:0)
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';

if SLIDES
    exportgraphics(fig_mechanism_import_prices_volumes,"plots/slides_fig_mechanism_import_prices_volumes.pdf",'ContentType','vector');
else
    exportgraphics(fig_mechanism_import_volumes,"plots/paper_fig_mechanism_import_volumes_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%%%%%%%%%%%
%% Aggregates Nearby %%
%%%%%%%%%%%%%%%%%%%%%%%
if SLIDES
    fig_mechanism_aggregates = figure('name','mechanism: aggregates');
    fig_mechanism_aggregates.Position(3) = 600;
    subplot(1,2,1);
else
    fig_mechanism_nearby = figure('name','mechanism: nearby');
    fig_mechanism_nearby.Position(3) = 600;
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('Nearby', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
point_iN = plot(irf_horizon-1, 100*oo_.irfs.i_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), ':', 'Color',col_N, 'LineWidth',lineWidth);
point_cN = plot(irf_horizon-1, 100*oo_.irfs.c_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '--', 'Color',col_N, 'LineWidth',lineWidth);
point_nxN = plot(irf_horizon-1, 100*oo_.irfs.nx_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-.', 'Color',col_N, 'LineWidth',lineWidth);
point_xN = plot(irf_horizon-1, 100*oo_.irfs.x_N_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_N')), '-', 'Color',col_N, 'LineWidth',lineWidth);
hold off;
leg = legend([point_iN point_cN point_nxN point_xN],{'${i}_N$','${c}_N$','${nx}_N$','${x}_N$'},'Location','SouthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-3.1 1.1]);
yticks(-3:1:1);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
if ~SLIDES
    exportgraphics(fig_mechanism_nearby,"plots/paper_fig_mechanism_nearby_@{MODEL_NAME}.pdf",'ContentType','vector');
end

%%%%%%%%%%%%%%%%%%%%%%%%
%% Aggregates Distant %%
%%%%%%%%%%%%%%%%%%%%%%%%
if SLIDES
    subplot(1,2,2);
else
    fig_mechanism_distant = figure('name','mechanism: distant');
    fig_mechanism_distant.Position(3) = 600;
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
if SLIDES
    title('Distant', 'Interpreter','latex', 'FontSize',fontSizeTitle);
end
yline(0,'LineWidth',lineWidth);
hold on;
point_iD = plot(irf_horizon-1, 100*oo_.irfs.i_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), ':', 'Color',col_D, 'LineWidth',lineWidth);
point_cD = plot(irf_horizon-1, 100*oo_.irfs.c_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '--', 'Color',col_D, 'LineWidth',lineWidth);
point_nxD = plot(irf_horizon-1, 100*oo_.irfs.nx_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-.', 'Color',col_D, 'LineWidth',lineWidth);
point_xD = plot(irf_horizon-1, 100*oo_.irfs.x_D_eps_war(irf_horizon)./oo_.steady_state(ismember(M_.endo_names,'gdp_D')), '-', 'Color',col_D, 'LineWidth',lineWidth);
hold off;
leg = legend([point_iD point_cD point_nxD point_xD],{'${i}_D$','${c}_D$','${nx}_D$','${x}_D$'},'Location','SouthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
xlabel('Year after start of war', 'Interpreter','latex', 'FontSize',fontSizeLabels);
ylabel('Percentage points', 'Interpreter','latex', 'FontSize',fontSizeLabels);
xlim([-0.1 8.1]);
xticks(0:1:8);
ylim([-3.1 1.1]);
yticks(-3:1:1);
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
if SLIDES
    exportgraphics(fig_mechanism_aggregates,"plots/slides_fig_mechanism_aggregates.pdf",'ContentType','vector');
else
    exportgraphics(fig_mechanism_distant,"plots/paper_fig_mechanism_distant_@{MODEL_NAME}.pdf",'ContentType','vector');
end
