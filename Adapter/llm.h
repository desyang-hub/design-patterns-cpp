/**
 * @FilePath     : /design-patterns-cpp/Adapter/llm.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-03-11 22:21:54
 * @LastEditors  : desyang
 * @LastEditTime : 2026-03-11 22:28:53
**/
#pragma once

#include "openai.h"

// 个体厂商协议，与OpenAI不匹配
class LLM
{
public:
    virtual ~LLM() {}

    std::string chatting(const std::string& msg) const {
        return "LLM: " + msg + " hallo!";
    }
};

// 做适配器，使其可以适配
class LLMAdaptor : public OpenAI
{
private:
    LLM m_llm;
public:
    LLMAdaptor(const LLM& llm) : m_llm(llm) {}
    LLMAdaptor(LLM&& llm) : m_llm(std::move(llm)) {}
    std::string chat(const std::string& msg) const override;
};

std::string LLMAdaptor::chat(const std::string& msg) const {
    return m_llm.chatting(msg);
}

