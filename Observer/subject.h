#pragma once

#include "observer.h"
#include "../Log/log.hpp"

#include <vector>

class Subject
{
private:
    // 用于存放订阅者
    std::vector<Observer> m_observers;
public:
    Subject(/* args */);
    ~Subject();

    void AddObserver(const Observer& observer) {
        // 调用拷贝构造
        m_observers.push_back(observer);
    }

    void AddObserver(Observer&& observer) {
        // 调用移动构造
        m_observers.push_back(std::move(observer));
    }

    void AddObserver(const CallBack& callBack) {
        m_observers.emplace_back(std::move(callBack));
    }

    void AddObserver(CallBack &&callBack) {
        m_observers.emplace_back(std::move(callBack));
    }

    // 网站更新
    void Update() {
        LOG_INFO << "[Web] 网站发生了更新，调用订阅者的回调函数" << std::endl;
        
        for (auto& observer : m_observers) {
            observer.Notify();
        }
    }
};

Subject::Subject(/* args */)
{
}

Subject::~Subject()
{
}
