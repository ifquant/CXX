/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : common.h
#   Last Modified : 2018-11-07 02:26
#   Describe      :
#
# ====================================================*/

#ifndef  _XQUANT_COMMON_H
#define  _XQUANT_COMMON_H


#include <tbb/atomic.h>
#include <cassert>
#include <string>

#include "task_pool.h"

namespace xquant {

static inline const std::string kEmptyStr;

template <typename T> 
class Singleton {
  public:
    static T& Instance() {
      static T kInstance;
      return kInstance;
    }
  protected:
    Singleton() {}
};


struct Limits {
  double msg_rate = 0;               // per second
  double msg_rate_per_security = 0;  // per security per second
  double order_qty = 0;
  double order_value = 0;
  double value = 0;                  // per security
  double turnover = 0;
  double total_value = 0;
  double total_turnover = 0;
};

struct Throttle {
  tbb::atomic<int> n = 0;
  int operator()(int tm) const {
    if (tm != this->tm) return 0;
    return n;
  }
  int tm = 0;

  void Update(int tm2) {
    if (tm2 != tm) {
      n = 0;
      tm2 = tm;
    } else {
      n++;
    }
  }
};

struct PositionValue {
  double total_bought = 0;
  double total_sold = 0;
  double total_outstanding_buy = 0;
  double total_outstanding_sell = 0;

  void HandleNew(bool is_buy, double qty, double price, double multiplier,
                 bool is_fx);
  void HandleTrade(bool is_buy, double qty, double price, double price0,
                   double multiplier, bool is_bust, bool is_otc, bool is_fx);
  void HandleFinish(bool is_buy, double leaves_qty, double price0,
                    double multiplier, bool is_fx);
};

inline void PositionValue::HandleNew(bool is_buy, double qty, double price,
                                     double multiplier, bool is_fx) {
  assert(qty > 0);
  if (is_fx) price = 1;
  auto value = qty * price * multiplier;
  if (is_buy) {
    total_outstanding_buy += value;
  } else {
    total_outstanding_sell += value;
  }
}

inline void PositionValue::HandleTrade(bool is_buy, double qty, double price,
                                       double price0, double multiplier,
                                       bool is_bust, bool is_otc, bool is_fx) {
  assert(qty > 0);
  if (is_fx) {
    price = 1;
    price0 = 1;
  }
  if (!is_buy) qty = -qty;
  auto value = qty * price * multiplier;
  if (is_otc) {
    // do nothing
  } else if (!is_bust) {
    auto value0 = qty * price0 * multiplier;
    if (value > 0) {
      total_outstanding_buy -= value0;
      total_bought += value;
    } else {
      total_outstanding_sell -= -value0;
      total_sold += -value;
    }
  } else {
    if (value > 0) {
      total_bought -= value;
    } else {
      total_sold -= -value;
    }
  }
}

inline void PositionValue::HandleFinish(bool is_buy, double leaves_qty,
                                        double price0, double multiplier,
                                        bool is_fx) {
  assert(leaves_qty);
  if (is_fx) price0 = 1;
  auto value = leaves_qty * price0 * multiplier;
  if (is_buy) {
    total_outstanding_buy -= value;
  } else {
    total_outstanding_sell -= value;
  }
}

inline TaskPool kSharedTaskPool;
inline TaskPool kWriteTaskPool;




}









#endif // _XQUANT_COMMON_H


