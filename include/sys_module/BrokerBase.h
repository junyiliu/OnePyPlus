#include "../DataType.h"
#include <functional>

#pragma once

namespace op {

using std::shared_ptr;
using std::unique_ptr;

enum class ActionType;
class OrderGenerator;
class MarketOrder;
class Environment;
class SubmitOrderChecker;

class BrokerBase {
  public:
    BrokerBase();
    Environment *env;

    void run();

  protected:
    template <typename T>
    void save_to_env(const T *self_ptr, const string &name);
    double _required_cash_func(const shared_ptr<MarketOrder> &order);

    virtual Cash_func_ptr_type cash_func() = 0;
    shared_ptr<SubmitOrderChecker> _checker;

  private:
    shared_ptr<OrderGenerator> _order_generator;
    void _clear_submitted_order();
    void _generate_order();
    void _check_order();
    void _submit_order();
    const string _judge_long_or_short(const ActionType &action_type);
    void _process_cancel_tst_order();
    void _process_cancel_pending_order();
};
} // namespace op
