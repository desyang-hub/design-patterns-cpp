#include "store.h"

#include <iostream>
using namespace std;

int main() {
    Store s;

    float prices = 198.0f;
    float discount_prices = s.calculate_prices(prices);
    cout << "discount_prices: " << discount_prices << endl;

    s.set_discount_strategy(std::make_unique<LowSeasonStrategy>());
    discount_prices = s.calculate_prices(prices);
    cout << "discount_prices: " << discount_prices << endl;
    
    return 0;
}