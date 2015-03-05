/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// Subtracts int from the value of the variable var
// SUB var int

#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED
#include "Statement.h"

class SubStatement : public Statement
{
public:
	// Constructor
	SubStatement(char variable, int value); // constructor
	virtual void execute(ProgramState* state, std::ostream& outf); // subtracts value
private:
	char m_variable;
	int m_value;
};

// Constructor
SubStatement::SubStatement(char variable, int value)
{
	m_variable = variable;
	m_value = value;
}

void SubStatement::execute(ProgramState* state, std::ostream& outf)
{
	state->subtract(m_variable, m_value); // subtracts value from variable
	state->incrementCounter(); // updates increment
}

#endif