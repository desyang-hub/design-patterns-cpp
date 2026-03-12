#pragma once

#include "servlet.h"
#include "../Log/log.hpp"

#include <memory>
#include <vector>

class GatewayServlet : public Servlet
{
private:
    std::vector<std::unique_ptr<Servlet>> m_servlets;
    mutable int m_idx{0};
public:
    void do_get(const Request& req, Response& resp) const override;
    void do_post(const Request& req, Response& resp) const override;

    void add_servlet(std::unique_ptr<Servlet> servlet);
};

void GatewayServlet::do_get(const Request& req, Response& resp) const {
    LOG_INFO << "Server Host: " << m_idx << ", Method: do_get()" << endl;
    m_servlets[m_idx++]->do_get(req, resp);
    m_idx %= m_servlets.size();
}
void GatewayServlet::do_post(const Request& req, Response& resp) const {
    LOG_INFO << "Server Host: " << m_idx << ", Method: do_post()" << endl;
    m_servlets[m_idx++]->do_post(req, resp);
    m_idx %= m_servlets.size();
}


void GatewayServlet::add_servlet(std::unique_ptr<Servlet> servlet) {
    m_servlets.emplace_back(std::move(servlet));
}