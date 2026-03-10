#pragma once

#include "factory.h"
#include "phone.h"

class PhoneFactory : public Factory
{
public:
    std::shared_ptr<Product> Production() const {
        return std::make_shared<Phone>();
    }
};