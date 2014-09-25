#include "ServletManager.h"


ServletManager::ServletManager(void)
{
	m_chat = new ChatServlet();
}


ServletManager::~ServletManager(void)
{
	if(m_chat != NULL)
	{
		delete m_chat;
		m_chat = NULL;
	}
}
