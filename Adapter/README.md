## 适配器模式 (Adapter) - [结构型]


### 关于unique_ptr说明

```cpp
void processRequest(std::unique_ptr<Interceptor> ptr) {
    // ...
}

int main() {
    std::unique_ptr<Interceptor> myPtr = std::make_unique<HttpInterceptor>();
    
    // 编译错误！
    // 试图调用拷贝构造函数，但 unique_ptr 禁止拷贝。
    processRequest(myPtr); 
    
    return 0;
}
```