#ifndef __CONVERSATION_H_
#define __CONVERSATION_H_

#include "CommonInclude.h"

class Conversation
{
private:
	string prompt;
	vector<string> option;
	vector<string> ending;
public:
	Conversation(const string& start, const vector<string>& options = {}, const vector<string>& end = {})
		: prompt(start), option(options), ending(end)
	{ }
	const string& GetPrompt() const
	{
		return prompt;
	}
	const vector<string>& GetOptions() const
	{
		return option;
	}
	const vector<string>& GetEnding() const
	{
		return ending;
	}
};
#endif