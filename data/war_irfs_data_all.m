function [warsite,nearby,distant,irf_horizon] = war_irfs_data_all
alph=0.1;
projection_horizon=9;
irf_horizon = 1:projection_horizon;

%% warsite gdp
warsite.gdp = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/groups_gdp.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.site', numel('l0.site')) == 1
        tmp = str2num(erase(line,["l0.site", "nan"]));
        warsite.gdp(idx,1) = tmp(1);
        warsite.gdp(idx,2) = tmp(1) - tcrit*tmp(2);
        warsite.gdp(idx,3) = tmp(1) + tcrit*tmp(2);
        warsite.gdp(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% warsite inflation
warsite.inflation = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/groups_inflation.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.site', numel('l0.site')) == 1
        tmp = str2num(erase(line,["l0.site", "nan"]));
        warsite.inflation(idx,1) = tmp(1);
        warsite.inflation(idx,2) = tmp(1) - tcrit*tmp(2);
        warsite.inflation(idx,3) = tmp(1) + tcrit*tmp(2);
        warsite.inflation(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% warsite capital
warsite.capital = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/groups_cs.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.site', numel('l0.site')) == 1
        tmp = str2num(erase(line,["l0.site", "nan"]));
        warsite.capital(idx,1) = tmp(1);
        warsite.capital(idx,2) = tmp(1) - tcrit*tmp(2);
        warsite.capital(idx,3) = tmp(1) + tcrit*tmp(2);
        warsite.capital(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% warsite tfp
warsite.tfp = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/groups_tfp.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.site', numel('l0.site')) == 1
        tmp = str2num(erase(line,["l0.site", "nan"]));
        warsite.tfp(idx,1) = tmp(1);
        warsite.tfp(idx,2) = tmp(1) - tcrit*tmp(2);
        warsite.tfp(idx,3) = tmp(1) + tcrit*tmp(2);
        warsite.tfp(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% warsite military expenditures
warsite.milex = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/groups_milex_prior_gdp_2015USD.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.site', numel('l0.site')) == 1
        tmp = str2num(erase(line,["l0.site", "nan"]));
        warsite.milex(idx,1) = tmp(1);
        warsite.milex(idx,2) = tmp(1) - tcrit*tmp(2);
        warsite.milex(idx,3) = tmp(1) + tcrit*tmp(2);
        warsite.milex(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% nearby gdp
nearby.gdp = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_gdp.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_nearby', numel('l0.trans_e(1)_f(closest)_nearby')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_nearby", "nan"]));
        nearby.gdp(idx,1) = tmp(1);
        nearby.gdp(idx,2) = tmp(1) - tcrit*tmp(2);
        nearby.gdp(idx,3) = tmp(1) + tcrit*tmp(2);
        nearby.gdp(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% nearby inflation
nearby.inflation = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_inflation.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_nearby', numel('l0.trans_e(1)_f(closest)_nearby')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_nearby", "nan"]));
        nearby.inflation(idx,1) = tmp(1);
        nearby.inflation(idx,2) = tmp(1) - tcrit*tmp(2);
        nearby.inflation(idx,3) = tmp(1) + tcrit*tmp(2);
        nearby.inflation(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% nearby capital
nearby.capital = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_cs.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_nearby', numel('l0.trans_e(1)_f(closest)_nearby')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_nearby", "nan"]));
        nearby.capital(idx,1) = tmp(1);
        nearby.capital(idx,2) = tmp(1) - tcrit*tmp(2);
        nearby.capital(idx,3) = tmp(1) + tcrit*tmp(2);
        nearby.capital(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% nearby tfp
nearby.tfp = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_tfp.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_nearby', numel('l0.trans_e(1)_f(closest)_nearby')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_nearby", "nan"]));
        nearby.tfp(idx,1) = tmp(1);
        nearby.tfp(idx,2) = tmp(1) - tcrit*tmp(2);
        nearby.tfp(idx,3) = tmp(1) + tcrit*tmp(2);
        nearby.tfp(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% nearby military expenditures
nearby.milex = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_milex_prior_gdp_2015USD.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_nearby', numel('l0.trans_e(1)_f(closest)_nearby')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_nearby", "nan"]));
        nearby.milex(idx,1) = tmp(1);
        nearby.milex(idx,2) = tmp(1) - tcrit*tmp(2);
        nearby.milex(idx,3) = tmp(1) + tcrit*tmp(2);
        nearby.milex(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% distant gdp
distant.gdp = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_gdp.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_distant', numel('l0.trans_e(1)_f(closest)_distant')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_distant", "nan"]));
        distant.gdp(idx,1) = tmp(1);
        distant.gdp(idx,2) = tmp(1) - tcrit*tmp(2);
        distant.gdp(idx,3) = tmp(1) + tcrit*tmp(2);
        distant.gdp(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% distant inflation
distant.inflation = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_inflation.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_distant', numel('l0.trans_e(1)_f(closest)_distant')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_distant", "nan"]));
        distant.inflation(idx,1) = tmp(1);
        distant.inflation(idx,2) = tmp(1) - tcrit*tmp(2);
        distant.inflation(idx,3) = tmp(1) + tcrit*tmp(2);
        distant.inflation(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% distant capital
distant.capital = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_cs.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_distant', numel('l0.trans_e(1)_f(closest)_distant')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_distant", "nan"]));
        distant.capital(idx,1) = tmp(1);
        distant.capital(idx,2) = tmp(1) - tcrit*tmp(2);
        distant.capital(idx,3) = tmp(1) + tcrit*tmp(2);
        distant.capital(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% distant tfp
distant.tfp = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_tfp.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_distant', numel('l0.trans_e(1)_f(closest)_distant')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_distant", "nan"]));
        distant.tfp(idx,1) = tmp(1);
        distant.tfp(idx,2) = tmp(1) - tcrit*tmp(2);
        distant.tfp(idx,3) = tmp(1) + tcrit*tmp(2);
        distant.tfp(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);


%% distant military expenditures
distant.milex = nan(projection_horizon,4);
f = "data/dmwmin(10000)_eww(0)_l[all]/e(1)_f(closest)_milex_prior_gdp_2015USD.txt";
fid = fopen(f, 'r');
idx = 1;
line = fgetl(fid);
while ischar(line)
    if strncmp(line, 'No. Observations', numel('No. Observations')) == 1
        tmp_obs = str2num(erase(line,["No. Observations:", "AIC", ":"]));
        tcrit = -tinv(alph/2,tmp_obs(1)-19);
    end
    if strncmp(line, 'l0.trans_e(1)_f(closest)_distant', numel('l0.trans_e(1)_f(closest)_distant')) == 1
        tmp = str2num(erase(line,["l0.trans_e(1)_f(closest)_distant", "nan"]));
        distant.milex(idx,1) = tmp(1);
        distant.milex(idx,2) = tmp(1) - tcrit*tmp(2);
        distant.milex(idx,3) = tmp(1) + tcrit*tmp(2);
        distant.milex(idx,4) = tmp(2);
        idx = idx+1;
    end
    line = fgetl(fid);
end
fclose(fid);