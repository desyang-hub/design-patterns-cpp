#include "observer.h"

Observer::Observer() : m_cb(nullptr)
{
}

Observer::Observer(const CallBack& callBack) : m_cb(callBack) {}

Observer::Observer(CallBack&& callBack) : m_cb(std::move(callBack)) {}

Observer::~Observer()
{
}