#pragma once

#include <string>
#include "../Log/log.hpp"

class Configration
{
private:
    Configration();
    virtual ~Configration();
public:
    // 删除构造函数
    Configration(const Configration& config) = delete;
    Configration& operator=(const Configration& config) = delete;
    

    // 删除移动赋值，拷贝赋值
    Configration(Configration&& config) = delete;
    Configration& operator=(Configration&& config) = delete;

    static Configration& GetConfig();

    void LoadConfig(const std::string& config_path);
};


