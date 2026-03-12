#include "gateway.h"

#include <iostream>

using namespace std;

Response client_get_request(const Servlet& servlet, const Request& request) {
    Response resp;

    cout << "=== Send Get request ===" << endl;
    servlet.do_get(request, resp);
    return resp;
}

Response client_post_request(const Servlet& servlet, const Request& request) {
    Response resp;

    cout << "=== Send Post request ===" << endl;
    servlet.do_post(request, resp);
    return resp;
}


ostream& operator<<(ostream& os, const Response& resp) {
    return os << "resp{" << resp.code << "," << resp.msg << "," << resp.body <<  "}";
}

int main() {
    Request get_request = {"/user/get", "", "{'id': '1'}"};
    Request post_request = {"/user/add", "", "{'id': '1', 'name': 'desyang'}"};
    GatewayServlet gateway_servlet;

    auto user_servlet = std::make_unique<UserServlet>();

    Response resp = client_get_request(*user_servlet, get_request);
    cout << resp << endl;
    resp = client_post_request(*user_servlet, post_request);
    cout << resp << endl;


    gateway_servlet.add_servlet(std::move(user_servlet));
    gateway_servlet.add_servlet(std::make_unique<UserServlet>());
    resp = client_get_request(gateway_servlet, get_request);
    cout << resp << endl;
    resp = client_post_request(gateway_servlet, post_request);
    cout << resp << endl;
    resp = client_get_request(gateway_servlet, get_request);
    cout << resp << endl;
    return 0;
}