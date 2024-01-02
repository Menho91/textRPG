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
	Conversation(const string& start, const vector<string>& options = {""}, const string& end = "")
		: prompt(start), option(options), ending(end), choice(0)
	{ }
	const string& GetPrompt() const
	{
		return prompt;
	}
	const vector<string>& GetOptions() const
	{
		return option;
	}
	const string& GetEnding() const
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
};
#endif