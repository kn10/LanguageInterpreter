/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// Multiples values and updates array
#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED
#include "Statement.h"
class MultStatement : public Statement
{
public:
	MultStatement(char variable, int value); // constructor
	virtual void execute(ProgramState* state, std::ostream& outf);
private:
	char m_variable;
	int m_value;
};

MultStatement::MultStatement(char variable, int value)
{
	m_variable = variable;
	m_value = value;
}
void MultStatement::execute(ProgramState* state, std::ostream& outf)
{
	state->multiply(m_variable, m_value); // multiples value and updates array
	state->incrementCounter(); // increments next line to be executed
}
#endif