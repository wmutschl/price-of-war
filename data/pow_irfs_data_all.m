function [warsite,nearby,distant,belligerent,irf_horizon] = pow_irfs_data_all
tcrit = 1.65;

%% gdp
warsite.gdp = importdata("data/csv/full/third/spec[gdp]_var[lgdp_detrended]_type[dc]_scope[hf]_h[0_8].csv"); warsite.gdp = warsite.gdp.data(:,[2 3 4]); warsite.gdp(:,4) = (warsite.gdp(:,3)-warsite.gdp(:,1))./tcrit;
nearby.gdp = importdata("data/csv/full/third/spec[gdp]_var[lgdp_detrended]_type[dc]_scope[nd]_h[0_8].csv"); nearby.gdp = nearby.gdp.data(:,[2 3 4]); nearby.gdp(:,4) = (nearby.gdp(:,3)-nearby.gdp(:,1))./tcrit;
distant.gdp = importdata("data/csv/full/third/spec[gdp]_var[lgdp_detrended]_type[dc]_scope[nd]_h[0_8].csv"); distant.gdp = distant.gdp.data(:,[5 6 7]); distant.gdp(:,4) = (distant.gdp(:,3)-distant.gdp(:,1))./tcrit;
belligerent.nearby.gdp = importdata("data/csv/full/bell/spec[gdp]_var[lgdp_detrended]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.nearby.gdp = belligerent.nearby.gdp.data(:,[2 3 4]); belligerent.nearby.gdp(:,4) = (belligerent.nearby.gdp(:,3)-belligerent.nearby.gdp(:,1))./tcrit;
belligerent.distant.gdp = importdata("data/csv/full/bell/spec[gdp]_var[lgdp_detrended]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.distant.gdp = belligerent.distant.gdp.data(:,[5 6 7]); belligerent.distant.gdp(:,4) = (belligerent.distant.gdp(:,3)-belligerent.distant.gdp(:,1))./tcrit;

%% warsite inflation
warsite.inflation = importdata("data/csv/full/third/spec[gdp]_var[inflation]_type[dc]_scope[hf]_h[0_8].csv"); warsite.inflation = warsite.inflation.data(:,[2 3 4]); warsite.inflation(:,4) = (warsite.inflation(:,3)-warsite.inflation(:,1))./tcrit;
nearby.inflation = importdata("data/csv/full/third/spec[gdp]_var[inflation]_type[dc]_scope[nd]_h[0_8].csv"); nearby.inflation = nearby.inflation.data(:,[2 3 4]); nearby.inflation(:,4) = (nearby.inflation(:,3)-nearby.inflation(:,1))./tcrit;
distant.inflation = importdata("data/csv/full/third/spec[gdp]_var[inflation]_type[dc]_scope[nd]_h[0_8].csv"); distant.inflation = distant.inflation.data(:,[5 6 7]); distant.inflation(:,4) = (distant.inflation(:,3)-distant.inflation(:,1))./tcrit;
belligerent.nearby.inflation = importdata("data/csv/full/bell/spec[gdp]_var[inflation]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.nearby.inflation = belligerent.nearby.inflation.data(:,[2 3 4]); belligerent.nearby.inflation(:,4) = (belligerent.nearby.inflation(:,3)-belligerent.nearby.inflation(:,1))./tcrit;
belligerent.distant.inflation = importdata("data/csv/full/bell/spec[gdp]_var[inflation]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.distant.inflation = belligerent.distant.inflation.data(:,[5 6 7]); belligerent.distant.inflation(:,4) = (belligerent.distant.inflation(:,3)-belligerent.distant.inflation(:,1))./tcrit;

%% warsite capital
warsite.capital = importdata("data/csv/full/third/spec[gdp]_var[lcs_2010ppp]_type[dc]_scope[hf]_h[0_8].csv"); warsite.capital = warsite.capital.data(:,[2 3 4]); warsite.capital(:,4) = (warsite.capital(:,3)-warsite.capital(:,1))./tcrit;
nearby.capital = importdata("data/csv/full/third/spec[gdp]_var[lcs_2010ppp]_type[dc]_scope[nd]_h[0_8].csv"); nearby.capital = nearby.capital.data(:,[2 3 4]); nearby.capital(:,4) = (nearby.capital(:,3)-nearby.capital(:,1))./tcrit;
distant.capital = importdata("data/csv/full/third/spec[gdp]_var[lcs_2010ppp]_type[dc]_scope[nd]_h[0_8].csv"); distant.capital = distant.capital.data(:,[5 6 7]); distant.capital(:,4) = (distant.capital(:,3)-distant.capital(:,1))./tcrit;
belligerent.nearby.capital = importdata("data/csv/full/bell/spec[gdp]_var[lcs_2010ppp]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.nearby.capital = belligerent.nearby.capital.data(:,[2 3 4]); belligerent.nearby.capital(:,4) = (belligerent.nearby.capital(:,3)-belligerent.nearby.capital(:,1))./tcrit;
belligerent.distant.capital = importdata("data/csv/full/bell/spec[gdp]_var[lcs_2010ppp]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.distant.capital = belligerent.distant.capital.data(:,[5 6 7]); belligerent.distant.capital(:,4) = (belligerent.distant.capital(:,3)-belligerent.distant.capital(:,1))./tcrit;

%% warsite tfp
warsite.tfp = importdata("data/csv/full/third/spec[gdp]_var[ltfp]_type[dc]_scope[hf]_h[0_8].csv"); warsite.tfp = warsite.tfp.data(:,[2 3 4]); warsite.tfp(:,4) = (warsite.tfp(:,3)-warsite.tfp(:,1))./tcrit;
nearby.tfp = importdata("data/csv/full/third/spec[gdp]_var[ltfp]_type[dc]_scope[nd]_h[0_8].csv"); nearby.tfp = nearby.tfp.data(:,[2 3 4]); nearby.tfp(:,4) = (nearby.tfp(:,3)-nearby.tfp(:,1))./tcrit;
distant.tfp = importdata("data/csv/full/third/spec[gdp]_var[ltfp]_type[dc]_scope[nd]_h[0_8].csv"); distant.tfp = distant.tfp.data(:,[5 6 7]); distant.tfp(:,4) = (distant.tfp(:,3)-distant.tfp(:,1))./tcrit;
belligerent.nearby.tfp = importdata("data/csv/full/bell/spec[gdp]_var[ltfp]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.nearby.tfp = belligerent.nearby.tfp.data(:,[2 3 4]); belligerent.nearby.tfp(:,4) = (belligerent.nearby.tfp(:,3)-belligerent.nearby.tfp(:,1))./tcrit;
belligerent.distant.tfp = importdata("data/csv/full/bell/spec[gdp]_var[ltfp]_type[dc]_scope[nd]_h[0_8].csv"); belligerent.distant.tfp = belligerent.distant.tfp.data(:,[5 6 7]); belligerent.distant.tfp(:,4) = (belligerent.distant.tfp(:,3)-belligerent.distant.tfp(:,1))./tcrit;

%% warsite military expenditures
warsite.milex = importdata("data/csv/full/third/spec[gdp]_var[milex]_type[opg]_scope[hf]_h[0_8].csv"); warsite.milex = warsite.milex.data(:,[2 3 4]); warsite.milex(:,4) = (warsite.milex(:,3)-warsite.milex(:,1))./tcrit;
nearby.milex = importdata("data/csv/full/third/spec[gdp]_var[milex]_type[opg]_scope[nd]_h[0_8].csv"); nearby.milex = nearby.milex.data(:,[2 3 4]); nearby.milex(:,4) = (nearby.milex(:,3)-nearby.milex(:,1))./tcrit;
distant.milex = importdata("data/csv/full/third/spec[gdp]_var[milex]_type[opg]_scope[nd]_h[0_8].csv"); distant.milex = distant.milex.data(:,[5 6 7]); distant.milex(:,4) = (distant.milex(:,3)-distant.milex(:,1))./tcrit;
belligerent.nearby.milex = importdata("data/csv/full/bell/spec[gdp]_var[milex]_type[opg]_scope[nd]_h[0_8].csv"); belligerent.nearby.milex = belligerent.nearby.milex.data(:,[2 3 4]); belligerent.nearby.milex(:,4) = (belligerent.nearby.milex(:,3)-belligerent.nearby.milex(:,1))./tcrit;
belligerent.distant.milex = importdata("data/csv/full/bell/spec[gdp]_var[milex]_type[opg]_scope[nd]_h[0_8].csv"); belligerent.distant.milex = belligerent.distant.milex.data(:,[5 6 7]); belligerent.distant.milex(:,4) = (belligerent.distant.milex(:,3)-belligerent.distant.milex(:,1))./tcrit;

%% irf horizon
irf_horizon = 1:size(warsite.gdp,1);