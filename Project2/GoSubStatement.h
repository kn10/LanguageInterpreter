/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// GoSubStatement.h
// Keeps track of return values
// GOSUB causes the Facile program to remember where it jumped from

#ifndef GO_SUB_STATEMENT_INCLUDED
#define GO_SUB_STATEMENT_INCLUDED

#include "Statement.h"

class GoSubStatement : public Statement
{
public:
	GoSubStatement(int value); // constructor, given value; and GoSubStatement needs to know where the value of the next RETURN statement is

	virtual void execute(ProgramState* state, std::ostream& outf); // of course, our execute statement, this time we will be using ProgramState's stack implementation.

private:
	int m_value;
};

GoSubStatement::GoSubStatement(int value) // constructor
{
	m_value = value;
}

void GoSubStatement::execute(ProgramState* state, std::ostream& outf)
{
	// Keeps track of RETURN statements when reached
	state->pushToStack(state->getIncrement() + 1); // pushes the next line to the Stack so when a RETURN statement is reached,
	// the next line to be executed would be the top value of the stack
	state->updateIncrement(m_value); // changes the next line value to whatever the value of GOSUB x is, where x is the next value
}

#endif