/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// DivStatement.h
// Allows you to divide values

#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED
#include "Statement.h"

class DivStatement : public Statement
{
public:
	DivStatement(char variable, int value); // constructor
	virtual void execute(ProgramState* state, std::ostream& outf); // divide values in state
private:
	char m_variable;
	int m_value;
};

DivStatement::DivStatement(char variable, int value) // constructor
{
	m_variable = variable;
	m_value = value;
}

void DivStatement::execute(ProgramState* state, std::ostream& outf)
{
	state->divide(m_variable, m_value, outf); // divides and updates this value into m_alphabetArray[] in ProgramState
	state->incrementCounter(); // increments to next line so next line is executed
}

#endif