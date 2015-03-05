/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// GoToStatement.h
// jumps to the next line statement in the Facile program

#ifndef GO_TO_STATEMENT_INCLUDED
#define GO_TO_STATEMENT_INCLUDED

#include "Statement.h"

class GoToStatement : public Statement
{
public:
	// Constructor
	GoToStatement(int value);
	virtual void execute(ProgramState* state, std::ostream& outf);

private:
	int m_value;
};

GoToStatement::GoToStatement(int value)
{
	m_value = value;
}

void GoToStatement::execute(ProgramState* state, std::ostream& outf)
{
	state->jump(m_value, outf); // jumps to the next line statement
}

#endif