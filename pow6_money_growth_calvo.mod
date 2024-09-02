@#define MODEL_NAME = "pow6_money_growth_calvo"

@#define COUNTRIES                        = ["R", "BD", "BN", "TD", "TN", "S"]

@#define MONETARY_POLICY_RULE             = "MONEY_GROWTH_RATE_RULE"
@#define EXCHANGE_RATE_PEG_WITH_R         = false

@#define GOODS_MARKET_STRUCTURE           = "MONOPOLISTIC_COMPETITION_CES"
@#define LABOR_MARKET_STRUCTURE           = "MONOPOLISTIC_COMPETITION_CES"
@#define NOMINAL_PRICE_SETTING            = "CALVO"
@#define NOMINAL_WAGE_SETTING             = "CALVO"

@#define HABIT                            = "EXTERNAL"
@#define CONSUMPTION_TRANSACTION_COSTS    = false
@#define MONEY_IN_UTILITY                 = false

@#include "_pow_model_core.inc"
@{NEWLINE}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                             SAVE FIGURES                              %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
exportgraphics(fig_matching,"plots/fig_matching_@{MODEL_NAME}.pdf",'ContentType','vector');