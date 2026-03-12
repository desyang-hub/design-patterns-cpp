/**
 * @FilePath     : /design-patterns-cpp/Proxy/request.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-03-12 12:01:55
 * @LastEditors  : desyang
 * @LastEditTime : 2026-03-12 12:03:01
**/
#pragma once

#include <string>

struct request
{
    std::string patten;
    std::string token;
    std::string body; // json
};

using Request = struct request;

struct response
{
    int code;
    std::string msg;
    std::string body;
};

using Response = struct response;

const Response NOT_FOUND = {404, "NOT_FOUND"};
const Response NOT_SUPPORT = {403, "NOT_SUPPORT"};
const Response SERVICE_INNER_ERROR = {501, "SERVICE_INNER_ERROR"};