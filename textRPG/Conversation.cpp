#include "Conversation.h"

Conversation::Conversation(string& start, vector<string>& options)
	: prompt(start), option(options), choice(0)
{ }