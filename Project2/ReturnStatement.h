/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// ReturnStatement.h
// Jumps execution of the program back to the line following the most recently-executed GOSUB statement.

#ifndef RETURN_STATEMENT_INCLUDED
#define RETURN_STATEMENT_INCLUDED

#include "Statement.h"

class ReturnStatement : public Statement
{
public:
	virtual void execute(ProgramState* state, std::ostream& outf);

private:
};

void ReturnStatement::execute(ProgramState* state, std::ostream& outf)
{
	if (state->getTop() == 0)
	{
		outf << "Illegal return statement\n";
		exit(1);
	}

	state->updateIncrement(state->getTop());
	state->popStack();
}

#endif