#pragma once

#include "request.h"

class Servlet
{
public:
    virtual ~Servlet() {}

    virtual void do_get(const Request& req, Response& resp) const = 0;
    virtual void do_post(const Request& req, Response& resp) const = 0;
};

class UserServlet : public Servlet
{
public:
    void do_get(const Request& req, Response& resp) const override;
    void do_post(const Request& req, Response& resp) const override;
};

void UserServlet::do_get(const Request& req, Response& resp) const {
    resp = {1, "success", req.body + " do_get"};
}

void UserServlet::do_post(const Request& req, Response& resp) const {
    resp = {1, "success", req.body + " do_post"};
}