#pragma once

#include <functional>

class Observer;
using CallBack = std::function<void(const Observer&)>;

// 观察者
class Observer
{
private:
    CallBack m_cb;
public:
    Observer();
    Observer(const CallBack& callBack);
    Observer(CallBack&& callBack);
    ~Observer();

    // 次一点的写法,微小的性能损耗，代码量少一点
    void SetCallBack(CallBack callBack) {
        m_cb = std::move(callBack);
    }

    void Notify() {
        if (m_cb) {
            m_cb(*this);
        }
    }
};

