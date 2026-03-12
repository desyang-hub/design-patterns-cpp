#include "config.hpp"

Configration::Configration(/* args */)
{
}

Configration::~Configration()
{
}

Configration& Configration::GetConfig() {
    static Configration m_config;
    return m_config;
}

void Configration::LoadConfig(const std::string& config_path) {
    LOG_INFO << "Load Config from " << config_path << " successful" << std::endl;
}
