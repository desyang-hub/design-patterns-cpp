#pragma once

#include <string>

// 用户协议
class OpenAI
{
public:
    virtual ~OpenAI(){}

    virtual std::string chat(const std::string& msg) const;
};

std::string OpenAI::chat(const std::string& msg) const {
    return "OpenAI: " + msg + " hi~";
}
