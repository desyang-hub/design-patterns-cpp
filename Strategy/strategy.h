#pragma once

class Strategy
{
public:
    virtual float get_rate() const = 0;
};

class HighSeasonStrategy : public Strategy
{
public:
    float get_rate() const override;
};

float HighSeasonStrategy::get_rate() const {
    return 0.99f;
}


class LowSeasonStrategy : public Strategy
{
public:
    float get_rate() const override;
};

float LowSeasonStrategy::get_rate() const {
    return 0.5f;
}