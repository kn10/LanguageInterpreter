/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// IllegalStatement.h
// Checks to see if there are any illegal statements in text file
// If any, then program exits;

#ifndef ILLEGAL_STATEMENT_INCLUDED
#define ILLEGAL_STATEMENT_INCLUDED

#include "Statement.h"

class IllegalStatement : public Statement
{
public:
	virtual void execute(ProgramState* state, std::ostream& outf);
};

void IllegalStatement::execute(ProgramState* state, std::ostream& outf)
{
	outf << "Illegal return statement\n"; // if textfile has illegal return statements, then program exits
	exit(1);
}

#endif