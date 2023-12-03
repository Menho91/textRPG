#ifndef __CONVERSATION_H_
#define __CONVERSATION_H_

#include "CommonInclude.h"

class Conversation
{
private:
	string prompt;
	vector<string> option;
	int choice;
public:
	Conversation(string& start, vector<string>& options) : prompt(start), option(options), choice(0)
	{ }
};
#endif