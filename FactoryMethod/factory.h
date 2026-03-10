/**
 * @FilePath     : /design-patterns-cpp/FactoryMethod/factory.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-03-10 11:31:22
 * @LastEditors  : desyang
 * @LastEditTime : 2026-03-10 11:45:56
**/
#pragma once

#include <memory>

class Product;

class Factory
{
public:
    virtual std::shared_ptr<Product> Production() const = 0;
};