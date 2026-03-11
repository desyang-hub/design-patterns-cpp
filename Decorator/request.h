#pragma once

#include <string>

struct request
{
    std::string host;
    int port;
    std::string name;
    std::string password;
};

using Request = struct request;