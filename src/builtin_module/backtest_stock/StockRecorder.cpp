#include "../../sys_module/models/BarBase.h"
#include "StockRecorder.h"
#include "StockSeries.h"

namespace sys {
using std::make_shared;
using std::shared_ptr;

StockRecorder::StockRecorder()
    : RecorderBase::RecorderBase() {
    save_to_env<StockRecorder>(this, "StockRecorder");
};

shared_ptr<BarBase> StockRecorder::bar_class(const string &ticker,
                                             const string &frequency) {
    return std::make_shared<BarBase>(ticker, frequency);
};

void StockRecorder::initialize() {
    //TODO:settle match_engine
    holding_pnl = make_shared<HoldingPnlSeries>();
    realized_pnl = make_shared<RealizedPnlSeries>();
    commission = make_shared<CommissionSeries>();
    market_value = make_shared<MarketValueSeries>();
    margin = make_shared<MarginSeries>();
    position = make_shared<PositionSeries>();
    avg_price = make_shared<AvgPriceSeries>();

    cash = make_shared<MoneySeries>("cash", initial_cash);
    frozen_cash = make_shared<MoneySeries>("frozen_cash", 0);
    balance = make_shared<MoneySeries>("balance", initial_cash);
};

void StockRecorder::_update_cash(const string &trading_date){};

} // namespace sys