#include "subject.h"
#include <iostream>

using namespace std;

// 网站管理者
void SendEmail(const std::string& msg) {
    cout << "发送📧: " << msg << " => " << "@WebOwnerObserver" << endl;
}


int main() {

    Subject webset;
    webset.AddObserver([](){
        SendEmail("网站的内容已经更新");
    });

    {
        std::string user = "xioaming";
        // 必须确保捕获数据的声明周期大于你的对象，否则会发生异常
        // 不能用引用捕获&user
        webset.AddObserver([user](){
            cout << "[UserMessagePush]"  << user << "你订阅的网站更新了" << endl;
        });
    }

    webset.AddObserver([](){
        cout << "[UserMessagePush] 网站更新了快去看看" << endl;
    });

    webset.Update();

    return 0;
}