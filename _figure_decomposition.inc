SLIDES = true;
irfs = oo_.irfs;

idx_WAR_DELTA = find(ismember(M_.param_names,["WAR_DELTA_K_S";
                                              "WAR_DELTA_A_S";
                                              "WAR_DELTA_G_S";
                                              "WAR_DELTA_M_S";
                                              "WAR_DELTA_M_N";
                                              "WAR_DELTA_M_D";
                                              ]));

% SIMULATION FOR CAPITAL DESTRUCTION ONLY
M_.params(idx_WAR_DELTA) = 0;
M_.params(ismember(M_.param_names,'WAR_DELTA_K_S')) = WAR_DELTA_K_S;
stoch_simul(order=1,irf=100,periods=0,nograph,nodecomposition,nocorr,nofunctions,noprint);
irfs_WAR_DELTA_K = oo_.irfs;

% SIMULATION FOR TFP DESTRUCTION ONLY
M_.params(idx_WAR_DELTA) = 0;
M_.params(ismember(M_.param_names,'WAR_DELTA_A_S')) = WAR_DELTA_A_S;
stoch_simul(order=1,irf=100,periods=0,nograph,nodecomposition,nocorr,nofunctions,noprint);
irfs_WAR_DELTA_A = oo_.irfs;

% SIMULATION FOR MILITARY EXPENDITURES ONLY
M_.params(idx_WAR_DELTA) = 0;
M_.params(ismember(M_.param_names,'WAR_DELTA_G_S')) = WAR_DELTA_G_S;
stoch_simul(order=1,irf=100,periods=0,nograph,nodecomposition,nocorr,nofunctions,noprint);
irfs_WAR_DELTA_G = oo_.irfs;

% SIMULATION FOR MONETARY ONLY
M_.params(idx_WAR_DELTA) = 0;
M_.params(ismember(M_.param_names,'WAR_DELTA_M_S')) = WAR_DELTA_M_S;
M_.params(ismember(M_.param_names,'WAR_DELTA_M_N')) = WAR_DELTA_M_N;
M_.params(ismember(M_.param_names,'WAR_DELTA_M_D')) = WAR_DELTA_M_D;
stoch_simul(order=1,irf=100,periods=0,nograph,nodecomposition,nocorr,nofunctions,noprint);
irfs_WAR_DELTA_M = oo_.irfs;

gdpS_dat = sum([irfs_WAR_DELTA_M.plot_gdp_S_eps_war(irf_horizon);
                irfs_WAR_DELTA_G.plot_gdp_S_eps_war(irf_horizon);
                irfs_WAR_DELTA_A.plot_gdp_S_eps_war(irf_horizon);
                irfs_WAR_DELTA_K.plot_gdp_S_eps_war(irf_horizon);
                ],2)/length(irf_horizon);

gdpN_dat = sum([irfs_WAR_DELTA_M.plot_gdp_N_eps_war(irf_horizon);
                irfs_WAR_DELTA_G.plot_gdp_N_eps_war(irf_horizon);
                irfs_WAR_DELTA_A.plot_gdp_N_eps_war(irf_horizon);
                irfs_WAR_DELTA_K.plot_gdp_N_eps_war(irf_horizon);
                ],2)/length(irf_horizon);

gdpD_dat = sum([irfs_WAR_DELTA_M.plot_gdp_D_eps_war(irf_horizon);
                irfs_WAR_DELTA_G.plot_gdp_D_eps_war(irf_horizon);
                irfs_WAR_DELTA_A.plot_gdp_D_eps_war(irf_horizon);
                irfs_WAR_DELTA_K.plot_gdp_D_eps_war(irf_horizon);
                ],2)/length(irf_horizon);

cpiS_dat = sum([irfs_WAR_DELTA_M.plot_pi_S_eps_war(irf_horizon);
                irfs_WAR_DELTA_G.plot_pi_S_eps_war(irf_horizon);
                irfs_WAR_DELTA_A.plot_pi_S_eps_war(irf_horizon);
                irfs_WAR_DELTA_K.plot_pi_S_eps_war(irf_horizon);
                ],2)/length(irf_horizon);

cpiN_dat = sum([irfs_WAR_DELTA_M.plot_pi_N_eps_war(irf_horizon);
                irfs_WAR_DELTA_G.plot_pi_N_eps_war(irf_horizon);
                irfs_WAR_DELTA_A.plot_pi_N_eps_war(irf_horizon);
                irfs_WAR_DELTA_K.plot_pi_N_eps_war(irf_horizon);
                ],2)/length(irf_horizon);

cpiD_dat = sum([irfs_WAR_DELTA_M.plot_pi_D_eps_war(irf_horizon);
                irfs_WAR_DELTA_G.plot_pi_D_eps_war(irf_horizon);
                irfs_WAR_DELTA_A.plot_pi_D_eps_war(irf_horizon);
                irfs_WAR_DELTA_K.plot_pi_D_eps_war(irf_horizon);
                ],2)/length(irf_horizon);

% Shades of grey (RGB triplets)
shades = [0.2, 0.2, 0.2;  % Dark Grey
          0.4, 0.4, 0.4;  % Medium Dark Grey
          %0.5, 0.5, 0.5;  % Medium Grey
          0.6, 0.6, 0.6;  % Medium Light Grey
          0.8, 0.8, 0.8]; % Light Grey

%173/255, 216/255, 230/255; % light blue
%0/255, 128/255, 128/255; % teal
%0/255, 100/255, 0/255; % dark green

cols = [70/255, 130/255, 180/255;  % steal blue
        107/255, 142/255, 35/255;  % olive green
        183/255, 65/255, 14/255;   % rust red
        112/255, 128/255, 144/255; % slate gray
        ];
col_star = 'black';

if SLIDES
    fig_decomposition_output = figure('name','decomposition: output');
    fig_decomposition_output.Position(3) = 600;
else
    fig_decomposition = figure('name','decomposition');
    fig_decomposition.Position(3) = 1200;
    fig_decomposition.Position(4) = 375;
    subplot(1,2,1);
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');

% Create a stacked bar chart
hold on;
hh_gdp = bar([gdpS_dat gdpN_dat gdpD_dat]', 'stacked');
star_gdp_S = plot(1,sum(irfs.plot_gdp_S_eps_war(irf_horizon))/length(irf_horizon),'pentagram', 'LineWidth',lineWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
star_gdp_N = plot(2,sum(irfs.plot_gdp_N_eps_war(irf_horizon))/length(irf_horizon),'pentagram', 'LineWidth',lineWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
star_gdp_D = plot(3,sum(irfs.plot_gdp_D_eps_war(irf_horizon))/length(irf_horizon),'pentagram', 'LineWidth',lineWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
%title('Output');
leg = legend({'Monetary','Military', 'TFP', 'Capital', 'Total'},'Location','southeast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
ylim([-18 2]);
xlim([0.25 3.75]);
xticks([1 2 3]);
xticklabels({'War site','Nearby','Distant'})
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
hold off;
% Apply the colors or shades
for i = 1:4
   hh_gdp(i).FaceColor = 'flat';
   %hh_gdp(i).CData = repmat(shades(i, :), 3, 1);
   hh_gdp(i).CData = repmat(cols(i, :), 3, 1);
end

if SLIDES
    exportgraphics(fig_decomposition_output,'plots/slides_fig_decomposition_output.pdf','ContentType','vector');
end

if SLIDES
    fig_decomposition_cpi = figure('name','decomposition: cpi');
    fig_decomposition_cpi.Position(3) = 600;
else
    subplot(1,2,2);
end
set(gca,'FontSize',fontSize,'TickLabelInterpreter','latex');
hold on;
hh_cpi = bar([cpiS_dat cpiN_dat cpiD_dat]', 'stacked');
star_cpi_S = plot(1,sum(irfs.plot_pi_S_eps_war(irf_horizon))/length(irf_horizon),'pentagram', 'LineWidth',lineWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
star_cpi_N = plot(2,sum(irfs.plot_pi_N_eps_war(irf_horizon))/length(irf_horizon),'pentagram', 'LineWidth',lineWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
star_cpi_D = plot(3,sum(irfs.plot_pi_D_eps_war(irf_horizon))/length(irf_horizon),'pentagram', 'LineWidth',lineWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
leg = legend({'Monetary','Military', 'TFP', 'Capital', 'Total'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',fontSizeLegend); leg.BackgroundAlpha = alphaLegend;
ylim([-0.25 4.8]);
xlim([0.25 3.75]);
xticks([1 2 3])
xticklabels({'War Site','Nearby','Distant'})
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '--'; ax.GridAlpha = 0.15;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
% Apply the colors or shades
for i = 1:4
   hh_cpi(i).FaceColor = 'flat';
   %hh_gdp(i).CData = repmat(shades(i, :), 3, 1);
   hh_cpi(i).CData = repmat(cols(i, :), 3, 1);
end

if SLIDES
    exportgraphics(fig_decomposition_cpi,'plots/slides_fig_decomposition_cpi.pdf','ContentType','vector');
else
    exportgraphics(fig_decomposition,'plots/paper_fig_decomposition_@{MODEL_NAME}.pdf','ContentType','vector');
end