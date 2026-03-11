#pragma once

#include <memory>

#include "request.h"
#include "../Log/log.hpp"

// 拦截器接口
class Interceptor
{
public:
    virtual bool verify(const Request&) const = 0;
    virtual ~Interceptor() {}
};


class PasswordInterceptor : public Interceptor
{
public:
    explicit PasswordInterceptor(std::unique_ptr<Interceptor> interceptor=nullptr);
    bool verify(const Request&) const override;
};

PasswordInterceptor::PasswordInterceptor(
    std::unique_ptr<Interceptor> interceptor) {}

bool PasswordInterceptor::verify(const Request& req) const {
    // 模拟查询数据库进行账号密码校对
    if (req.name != "desyang" || req.password != "desyang") {
        LOG_INFO << "账号或密码错误请求被拦截" << endl;
        return false;
    }
    LOG_INFO << "账号密码校验通过" << endl;
    return true;
}


// Decorator
class InterceptorDecorator : public Interceptor
{
private:
    std::unique_ptr<Interceptor> m_interceptor{nullptr};
    virtual bool do_verify(const Request& req) const = 0;

public:
    bool verify(const Request&) const override;
    explicit InterceptorDecorator(std::unique_ptr<Interceptor> interceptor=nullptr);

};

InterceptorDecorator::InterceptorDecorator(
    std::unique_ptr<Interceptor> interceptor) :
    m_interceptor(std::move(interceptor)) {
    }

bool InterceptorDecorator::verify(const Request& req) const {
    if (!do_verify(req)) {
        return false;
    }
    // 先验证自己通不通过, 装饰器类暂时不处理业务，只将拦截进行传递
    if (m_interceptor)
        return m_interceptor->verify(req);

    return true;
}


// http拦截器接口 ConcrentInterceptor
class HttpInterceptor : public InterceptorDecorator
{
private:
    bool do_verify(const Request&) const override;
public:
    explicit HttpInterceptor(std::unique_ptr<Interceptor> interceptor = nullptr);
    
};

HttpInterceptor::HttpInterceptor(
    std::unique_ptr<Interceptor> interceptor) :
    InterceptorDecorator(std::move(interceptor)) {}

bool HttpInterceptor::do_verify(const Request& req) const {
    if (req.host != "192.168.0.1") {
        LOG_INFO << "非法host请求: " << req.host << " 即将进行拦截" << endl;
        return false;
    }
    LOG_INFO << "主机正常" << endl;
    return true;
}

class PortInterceptor : public InterceptorDecorator
{
private:
    bool do_verify(const Request&) const override;
public:
    explicit PortInterceptor(std::unique_ptr<Interceptor> interceptor = nullptr);

};

PortInterceptor::PortInterceptor(
    std::unique_ptr<Interceptor> interceptor) :
    InterceptorDecorator(std::move(interceptor)) {
    }


bool PortInterceptor::do_verify(const Request& req) const {
    if (req.port != 8080) {
        LOG_INFO << "端口异常：" << req.port << ", 该请求被拦截" << endl;
        return false;
    }
    LOG_INFO << "端口正确" << endl;
    return true;
}

