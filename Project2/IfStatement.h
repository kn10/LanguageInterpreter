/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// IfStatement.h
// A conditional GOTO Statement
// Compares value of some variable to some value, and
// jumps execution of the program to the given line number if
// comparison is true.

#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "Statement.h"

class IfStatement : public Statement
{
public:
	// Constructor
	IfStatement(char variable, std::string comparison, int value, int lineNumber);
	virtual void execute(ProgramState* state, std::ostream& outf);

private:
	char m_variable;
	std::string m_comparison;
	int m_value;
	int m_lineNumber;
};

// Constructor
IfStatement::IfStatement(char variable, std::string comparison, int value, int lineNumber)
{
	m_variable = variable;
	m_comparison = comparison;
	m_value = value;
	m_lineNumber = lineNumber;
}

void IfStatement::execute(ProgramState* state, std::ostream& outf)
{
	if (state->getValue(m_variable)) // compares values
		state->jump(m_lineNumber, outf); // if if statement is true, uses jump() function to jump to next line
	else
		state->incrementCounter(); // if not true, increments the line by 1;
}

#endif