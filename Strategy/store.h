#pragma once

#include <memory>

#include "../Log/log.hpp"

#include "strategy.h"


class Store
{
private:
    std::unique_ptr<Strategy> m_discount_strategy = std::make_unique<HighSeasonStrategy>();
public:
    void set_discount_strategy(std::unique_ptr<Strategy> strategy) {
        m_discount_strategy = std::move(strategy);
    }

    float calculate_prices(float goods_prices) const {
        LOG_INFO << "当前销售策略折扣：" << m_discount_strategy->get_rate() << endl;
        return m_discount_strategy->get_rate() * goods_prices;
    }
};