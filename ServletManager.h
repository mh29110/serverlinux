//#pragma once
#ifndef SERVLET_MANAGER_H
#define SERVLET_MANAGER_H
#include "ChatServlet.h"
class ServletManager
{
public:
	ServletManager(void);
	~ServletManager(void);
	ChatServlet * m_chat;
};

#endif //SERVLET_MANAGER_H
