#include "interceptor.h"

int main() {

    std::unique_ptr<Interceptor> interceptor = std::make_unique<PasswordInterceptor>();

    interceptor = std::make_unique<PortInterceptor>(std::move(interceptor));
    interceptor = std::make_unique<HttpInterceptor>(std::move(interceptor));

    std::make_unique<HttpInterceptor>();

    Request request = {
        "192.0.0.1",
        8080,
        "admin",
        "desyang"
    };

    bool is_verify = interceptor->verify(request);
    LOG_INFO << "verify: " << is_verify << endl;

    request = {
        "192.168.0.1",
        8081,
        "desyang",
        "desyang"
    };
    is_verify = interceptor->verify(request);
    LOG_INFO << "verify: " << is_verify << endl;


    request = {
        "192.168.0.1",
        8080,
        "admin",
        "desyang"
    };
    is_verify = interceptor->verify(request);
    LOG_INFO << "verify: " << is_verify << endl;


    request = {
        "192.168.0.1",
        8080,
        "desyang",
        "desyang"
    };
    is_verify = interceptor->verify(request);
    LOG_INFO << "verify: " << is_verify << endl;
    return 0;
}