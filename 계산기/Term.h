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
	char type;
};

#endif