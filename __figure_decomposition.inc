PLOTS_PRINT = 1;
irfs = oo_.irfs;

idx_WAR_DELTA = find(ismember(M_.param_names,["WAR_DELTA_K_H";
                                              "WAR_DELTA_A_H";
                                              "WAR_DELTA_G_H";
                                              "WAR_DELTA_G_RDN";                                              
                                              ]));

% SIMULATION FOR CAPITAL DESTRUCTION ONLY
M_.params(idx_WAR_DELTA) = 0;
M_.params(ismember(M_.param_names,'WAR_DELTA_K_H')) = WAR_DELTA_K_H;
stoch_simul(order=1,irf=100,periods=0,nograph,nodecomposition,nocorr,nofunctions,noprint);
irfs_WAR_DELTA_K_H = oo_.irfs;

% SIMULATION FOR TFP DESTRUCTION ONLY
M_.params(idx_WAR_DELTA) = 0;
M_.params(ismember(M_.param_names,'WAR_DELTA_A_H')) = WAR_DELTA_A_H;
stoch_simul(order=1,irf=100,periods=0,nograph,nodecomposition,nocorr,nofunctions,noprint);
irfs_WAR_DELTA_A_H = oo_.irfs;

% SIMULATION FOR MILITARY SPENDING ONLY
M_.params(idx_WAR_DELTA) = 0;
M_.params(ismember(M_.param_names,'WAR_DELTA_G_H')) = WAR_DELTA_G_H;
M_.params(ismember(M_.param_names,'WAR_DELTA_G_RDN')) = WAR_DELTA_G_RDN;
stoch_simul(order=1,irf=100,periods=0,nograph,nodecomposition,nocorr,nofunctions,noprint);
irfs_WAR_DELTA_G = oo_.irfs;

gdpH_dat = sum([irfs_WAR_DELTA_G.plot_gdp_H_eps_war(horizon);
                irfs_WAR_DELTA_A_H.plot_gdp_H_eps_war(horizon);
                irfs_WAR_DELTA_K_H.plot_gdp_H_eps_war(horizon);
                ],2)/length(horizon);

gdpN_dat = sum([irfs_WAR_DELTA_G.plot_gdp_N_eps_war(horizon);
                irfs_WAR_DELTA_A_H.plot_gdp_N_eps_war(horizon);
                irfs_WAR_DELTA_K_H.plot_gdp_N_eps_war(horizon);
                ],2)/length(horizon);

gdpD_dat = sum([irfs_WAR_DELTA_G.plot_gdp_D_eps_war(horizon);
                irfs_WAR_DELTA_A_H.plot_gdp_D_eps_war(horizon);
                irfs_WAR_DELTA_K_H.plot_gdp_D_eps_war(horizon);
                ],2)/length(horizon);

cpiH_dat = sum([irfs_WAR_DELTA_G.plot_pi_H_eps_war(horizon);
                irfs_WAR_DELTA_A_H.plot_pi_H_eps_war(horizon);
                irfs_WAR_DELTA_K_H.plot_pi_H_eps_war(horizon);
                ],2)/length(horizon);

cpiN_dat = sum([irfs_WAR_DELTA_G.plot_pi_N_eps_war(horizon);
                irfs_WAR_DELTA_A_H.plot_pi_N_eps_war(horizon);
                irfs_WAR_DELTA_K_H.plot_pi_N_eps_war(horizon);
                ],2)/length(horizon);

cpiD_dat = sum([irfs_WAR_DELTA_G.plot_pi_D_eps_war(horizon);
                irfs_WAR_DELTA_A_H.plot_pi_D_eps_war(horizon);
                irfs_WAR_DELTA_K_H.plot_pi_D_eps_war(horizon);
                ],2)/length(horizon);

% Shades of grey (RGB triplets)
shades = [0.2, 0.2, 0.2;  % Dark Grey
          %0.4, 0.4, 0.4;  % Medium Dark Grey
          0.5, 0.5, 0.5;  % Medium Grey
          %0.6, 0.6, 0.6;  % Medium Light Grey
          0.8, 0.8, 0.8]; % Light Grey
cols = [173/255, 216/255, 230/255; % light blue
        0/255, 128/255, 128/255; % teal
        0/255, 100/255, 0/255; % dark green
        ];
cols = [107/255, 142/255, 35/255;  % olive green
        183/255, 65/255, 14/255;   % rust red
        112/255, 128/255, 144/255; % slate gray
        ];
col_star = 'black';

%fig_decomposition_output = figure('Name','Decomposition: output');
fig_decomposition = figure('name','decomposition');
fig_decomposition.Position(3) = 1200;
fig_decomposition.Position(4) = 375;
subplot(1,2,1)
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');

% Create a stacked bar chart
hold on;
%yline(0,'LineWidth',linWidth0);
hh_gdp = bar([gdpH_dat gdpN_dat gdpD_dat]', 'stacked');
plot(1,sum(irfs.plot_gdp_H_eps_war(horizon))/length(horizon),'pentagram', 'LineWidth',linWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
plot(2,sum(irfs.plot_gdp_N_eps_war(horizon))/length(horizon),'pentagram', 'LineWidth',linWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
plot(3,sum(irfs.plot_gdp_D_eps_war(horizon))/length(horizon),'pentagram', 'LineWidth',linWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
%title('Output');
%legend({'Gov''t', 'TFP', 'Capital', 'Iceberg','Total'},'Location','North','Box', 'off','NumColumns',5);
leg = legend({'Military', 'TFP', 'Capital', 'Total'},'Location','southeast','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = legendBackgroundAlpha;
ylim([-24 2])
xlim([0.25 3.75])
xticks([1 2 3])
xticklabels({'Home','Nearby','Distant'})
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
hold off;
% Apply the colors or shades
for i = 1:3
   hh_gdp(i).FaceColor = 'flat';
   %hh_gdp(i).CData = repmat(shades(i, :), 3, 1);
   hh_gdp(i).CData = repmat(cols(i, :), 3, 1);
end

%if PLOTS_PRINT
%    filename = "war_plots/fig_decomposition_output.pdf";
%    saveas(fig_decomposition_output,filename,'pdf')
%    system(sprintf('pdfcrop %s %s',filename,filename));
%end


%fig_decomposition_cpi = figure('Name','Decomposition: cpi');
subplot(1,2,2)
set(gca,'FontSize',FontSize,'TickLabelInterpreter','latex');
hold on;
hh_cpi = bar([cpiH_dat cpiN_dat cpiD_dat]', 'stacked');
star_cpi_H = plot(1,sum(irfs.plot_pi_H_eps_war(horizon))/length(horizon),'pentagram', 'LineWidth',linWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
star_cpi_N = plot(2,sum(irfs.plot_pi_N_eps_war(horizon))/length(horizon),'pentagram', 'LineWidth',linWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
star_cpi_D = plot(3,sum(irfs.plot_pi_D_eps_war(horizon))/length(horizon),'pentagram', 'LineWidth',linWidth,'MarkerEdgeColor',col_star,'MarkerFaceColor',col_star,'MarkerSize',20);
%yline(0,'LineWidth',linWidth0);
%title('Inflation');
%legend({'Gov''t', 'TFP', 'Capital', 'Iceberg','Total'},'Location','North','Box', 'off','NumColumns',5);
leg = legend({'Military', 'TFP', 'Capital', 'Total'},'Location','NorthEast','NumColumns',1,'Interpreter','latex','FontSize',FontSizeLegend); leg.BackgroundAlpha = legendBackgroundAlpha;
ylim([-0.75 10])
xlim([0.25 3.75])
xticks([1 2 3])
xticklabels({'Home','Nearby','Distant'})
grid on; box on;
ax = gca;
ax.XColor = 'black'; ax.YColor = 'black'; ax.LineWidth = 0.75;
ax.GridColor = [0.25 0.25 0.25]; ax.GridLineStyle = '-'; ax.GridAlpha = 0.45;
ax.TickDir='none'; ax.XAxisLocation = 'bottom'; ax.YAxisLocation = 'left';
% Apply the colors or shades
for i = 1:3
   hh_cpi(i).FaceColor = 'flat';
   %hh_gdp(i).CData = repmat(shades(i, :), 3, 1);
   hh_cpi(i).CData = repmat(cols(i, :), 3, 1);
end
% if PLOTS_PRINT
%     filename = "war_plots/fig_decomposition_cpi.pdf";
%     saveas(fig_decomposition_cpi,filename,'pdf')
%     system(sprintf('pdfcrop %s %s',filename,filename));
% end

if PLOTS_PRINT
    filename = "war_plots_paper/fig_decomposition.pdf";
    exportgraphics(fig_decomposition,filename,'ContentType','vector');
end

% Adding a legend at the bottom
% axes('Position',[0, 0, 1, 1],'Visible','off');
% lgd = legend([hh_cpi(1),hh_cpi(2),hh_cpi(3), star_cpi_H],{'Military', 'TFP', 'Capital','Total'},'Location','South','NumColumns',4,'FontSize',FontSizeLegend);
% lgd.Position = [0.27 0.01 lgd.Position(3) lgd.Position(4)];

% if PLOTS_PRINT
%     filename = "war_plots/fig_decomposition.pdf";
%     saveas(fig_decomposition,filename,'pdf')
%     system(sprintf('pdfcrop %s %s',filename,filename));
% end