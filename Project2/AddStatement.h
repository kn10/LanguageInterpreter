/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// AddStatement.h
// class AddStatement allows you to add values in the Facile interpreter program.
// ADD A 3
// would add 3 to the variable A

#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"

class AddStatement : public Statement
{
public:

	// Constructor
	AddStatement(char variable, int addValue);

	virtual void execute(ProgramState* state, std::ostream& outf); // adds value to present variable

private:
	int m_addValue;
	char m_variable;
};

// Constructor
AddStatement::AddStatement(char variable, int value)
{
	m_addValue = value;
	m_variable = variable;
}

void AddStatement::execute(ProgramState* state, std::ostream& outf)
{
	state->add(m_variable, m_addValue); // add value to certain variable
	state->incrementCounter(); // increment counter
}

#endif