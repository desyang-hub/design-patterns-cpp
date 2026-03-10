## 移动语义

```cpp
void AddObserver(Observer&& observer) {
    m_observers.push_back(std::move(observer));
}
```

以上这个函数只会发生一次移动构造函数，由vector::push_back(T&& obj)函数内部，通过调用T类型的移动构造函数进行函数对象的构造，直接将对象构造到vector所持有的内存当中

右值引用传递&&不会产生任何拷贝或移动构造，作用与引用类似，到了函数内部后，会变成左值引用，因为有类型名称了，需要对右值应用进行转发，可以使用std::forword或者使用std::move语义来欺骗编译器将其作为右值引用来进行转发。


```cpp
Observer::Observer(CallBack callBack) : 
    m_cb(std::move(callBack)) {

}
```
实参是临时对象，那么会调用移动构造函数构造形参对象，接着调用移动构造成员函数m_cb
实参是左值对象，那么会调用拷贝构造函数构造形参对象，接着调用移动构造成员函数m_cb