#pragma once

#include <iostream>

using std::endl;

// 方案 A：最简洁，完全利用流操作符
// 用法：LOG_INFO << "User " << id << " score: " << score;
#define LOG_INFO std::cout << "[INFO] "
#define LOG_ERROR std::cerr << "[ERROR] "
#define LOG_WARN std::cerr << "[WARN] "
