#include "phone_factory.h"

// 模板类的偏特化
template<class T>
struct factory_builder {
    static T Create() {
        return T();
    }
};

template<class T>
struct factory_builder<T*> {
    static T* Create() {
        return new T();
    }
};

template<class FactoryImpls>
auto build_factory() -> decltype(factory_builder<FactoryImpls>::Create()) {
    return factory_builder<FactoryImpls>::Create();
}

// 模拟实际场景中的接口
void take_order(std::unique_ptr<Factory> factory) {
    factory->Production()->Show();
}

int main() {
    // 以下模拟业务代码，当产品发生改变，无需修改原有接口，秩序修改工厂创建的地方就可以实现业务功能的增加
    std::unique_ptr<Factory> factory = std::make_unique<PhoneFactory>();

    take_order(std::move(factory));

    return 0;
}