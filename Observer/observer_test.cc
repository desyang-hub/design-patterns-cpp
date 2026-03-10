#include "subject.h"
#include <iostream>

using namespace std;

// 网站管理者
class WebOwnerObserver : public Observer
{
public:
    void SendEmail(const std::string& msg) const {
        cout << "发送📧: " << msg << " => " << "@WebOwnerObserver" << endl;
    }
};


int main() {

    Subject webset;

    WebOwnerObserver webOwnerObserver;
    webOwnerObserver.SetCallBack([&webOwnerObserver](const Observer&){
        webOwnerObserver.SendEmail("网站的内容已经更新");
    });

    webset.AddObserver(webOwnerObserver);

    webset.AddObserver([](const Observer&){
        cout << "[UserMessagePush] 你订阅的网站更新了" << endl;
    });

    webset.AddObserver([](const Observer&){
        cout << "[UserMessagePush] 网站更新了快去看看" << endl;
    });

    webset.Update();

    return 0;
}