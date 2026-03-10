#include "config.hpp"

int main() {
    auto config = Configration::GetConfig();
    config.LoadConfig("config.json");
    return 0;
}