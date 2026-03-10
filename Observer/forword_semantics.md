## 完美转发


```cpp
// 完美转发版本
template <typename T>
Observer(T&& val) : m_cb(std::forward<T>(val)) {}
```

这个函数会自动区分参数是临时对象还是左值引用
相当于用一个函数实现了两种不同参数的实现

临时对象：只会调用一次移动构造函数
左值引用：调用一次拷贝构造函数