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
	Conversation(string& start, vector<string>& options, string& end)
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