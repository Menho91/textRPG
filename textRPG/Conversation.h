#ifndef __CONVERSATION_H_
#define __CONVERSATION_H_

#include "CommonInclude.h"

class Conversation
{
private:
	string prompt;
	vector<string> option;
	string ending;
	int choice;
public:
	Conversation(const string& start, const vector<string>& options = {}, const string& end = NULL)
		: prompt(start), option(options), ending(end), choice(0)
	{ }
	string GetPrompt() const
	{
		return prompt;
	}
	string GetEnding() const
	{
		return ending;
	}
	int GetChoice() const
	{
		return choice;
	}
	void SetChoice(int cho)
	{
		choice = cho;
	}
	vector<string> GetOption() const
	{
		return option;
	}
};
#endif