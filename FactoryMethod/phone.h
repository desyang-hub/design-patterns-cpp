#pragma once

#include <string>
#include "product.h"
#include "../Log/log.hpp"

class Phone : public Product
{
private:
    std::string name;
public:
    Phone() : name("Apple") {}
    
    void Show() const {
        LOG_INFO << "Product name: " << name << std::endl;
    }
};
