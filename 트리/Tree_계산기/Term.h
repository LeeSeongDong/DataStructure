#ifndef __TERM_H__
#define __TERM_H__

#include "Header.h"

union Token
{
	int num;
	char opr;
};

struct Term
{
	Token token;
	string result;
	char type;

	friend ostream& operator<<(ostream& os, const Term &term)
	{
		if (term.type == NUMBER)
		{
			os << term.token.num;
		}
		else
		{
			os << term.result;
		}
		return os;
	}
};

#endif