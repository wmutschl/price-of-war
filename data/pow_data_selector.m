function out = pow_data_selector(country, varname, weight)
% out = pow_data_selector(country, varname, weight)
% -------------------------------------------------------------------------
% outputs either value or weight of IRF
% -------------------------------------------------------------------------
% INPUTS
% - country   [scalar] identifier for the country
% - varname   [scalar] identifier for the variable of interest
% - weight    [scalar] if > 0 computes weight of IRF from standard error and multiplies with this scalar

% define irf horizon
horizon = 1:9;

% retrieve war-related data
[warsite,nearby,distant,belligerent] = pow_irfs_data_all;

% select country
switch country
    case 1
        country = warsite;
    case 2
        country = nearby;
    case 3
        country = distant;
    case 4
        country = belligerent.nearby;
    case 5
        country = belligerent.distant;
end

% select variable
switch varname
    case 1
        varname = 'gdp';
    case 2
        varname = 'inflation';
    case 3
        varname = 'capital';
    case 4
        varname = 'tfp';
    case 5
        varname = 'milex';
end

% output either irf value or weight
if weight == 0
    % irf estimate
    out = country.(varname)(horizon, 1);
else
     % weight based on standard error estimate
    out = weight./( country.(varname)(horizon, 4).^2 );
end