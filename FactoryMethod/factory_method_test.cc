#include "phone_factory.h"

int main() {
    // 当有新增需求，或者需求发生变更时，直接新增一个工厂类进行扩展即可
    auto factory = PhoneFactory();
    auto product = factory.Production();
    product->Show();

    return 0;
}