#pragma once

#include <iostream>
#include <string.h>
#include <assert.h>

#include "../Log/log.hpp"

const char STRING_EOF = '\0';

// final 禁止继承
class String final
{
private:
    char* m_ptr;
     
    void buildString(const char* ptr);

    // 释放所持有的资源
    void freeString() {
        if (m_ptr) {
            // 释放资源
            LOG_INFO << "String::freeString() >>> " << m_ptr << endl;
            delete[] m_ptr;
        }
    }

    void append(const char* ptr);
public:
    String(const char* ptr = nullptr);
    ~String();
    
    // 拷贝构造
    String(const String& str);
    // 拷贝赋值
    String& operator=(const String& str);

    // 移动构造
    String(String&& str);
    // 移动赋值
    String& operator=(String&& str);

public:
    size_t Size() const {
        return strlen(m_ptr);
    }

    char* Get() const;

    String& Append(const String& str);
    String& Append(const char* ptr);

    String& operator<<(const String& str) {
        return Append(str);
    }

    String& operator<<(const char* ptr) {
        return Append(ptr);
    }

    char& operator[](int i) const {
        if (i >= Size()) throw std::runtime_error("Index exceed limited.");
        return m_ptr[i];
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str);
};


void String::buildString(const char* ptr) {
    int len = 1;
    // 对于传入的一个字符串，需要对其进行处理
    if (ptr) {
        len = strlen(ptr) + 1;
        m_ptr = new char[len];
        strcpy(m_ptr, ptr);
        m_ptr[len - 1] = STRING_EOF;
    }
    else { // nullptr
        m_ptr = new char[len];
        m_ptr[len-1] = STRING_EOF;
    }
}

void String::append(const char* ptr) {
    assert(ptr != nullptr);
    assert(strlen(ptr));

    // 1. 构造新数据
    int len = Size() + strlen(ptr) + 1;
    char* ptr_new = new char[len];
    strcpy(ptr_new, m_ptr);
    strcpy(ptr_new + Size(), ptr);
    ptr_new[len - 1] = STRING_EOF;

    // 2. 释放旧数据
    freeString();

    // 3. 替换数据
    m_ptr = ptr_new;
}

String::String(const char* ptr)
{
    LOG_INFO << "String 构造函数" << endl;
    buildString(ptr);
}

String::~String()
{
    LOG_INFO << "~String() 调用析构函数" << endl;
    freeString();
}

// 拷贝构造
String::String(const String& str) {
    LOG_INFO << "String 拷贝构造" << endl;
    buildString(str.m_ptr);
}

// 拷贝赋值
String& String::operator=(const String& str) {
    LOG_INFO << "String 拷贝赋值" << endl;
    freeString();
    buildString(str.m_ptr);
    return *this;
}

// 移动构造
String::String(String&& str) : m_ptr(str.m_ptr) {
    LOG_INFO << "String 移动构造" << endl;
    str.m_ptr = nullptr;
}

// 移动赋值
String& String::operator=(String&& str) {
    LOG_INFO << "String 移动赋值" << endl;
    freeString();
    m_ptr = str.m_ptr;
    str.m_ptr = nullptr;
    return *this;
}


char* String::Get() const {
    return m_ptr;
}

String& String::Append(const String& str) {
    // 创建一个两倍长度的数组，接着
    if (str.Size() == 0) return *this;

    append(str.Get());

    return *this;
}

String& String::Append(const char* ptr) {
    if (ptr && strlen(ptr)) {
        append(ptr);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.m_ptr;
}