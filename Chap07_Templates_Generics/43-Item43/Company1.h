#pragma once

#include <string>

class CompanyA
{
public:
	void sendCleartext(const std::string& msg) {}
	void sendEncrypted(const std::string& msg) {}
};


class CompanyB
{
public:
	void sendCleartext(const std::string& msg) {}
	void sendEncrypted(const std::string& msg) {}
};


class MsgInfo {};


template<typename Company>
class MsgSender
{
public:

	void sendClear(const MsgInfo& info)
	{
		std::string msg;
		Company c;
		c.sendCleartext(msg);
	}

	void sendSecret(const MsgInfo& info)
	{
	}
};


template<typename Company>
class LoggingMsgSender : public MsgSender<Company>
{
public:
	void sendClearMsg(const MsgInfo& info)
	{
		sendClear(info);
	}
};