/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

#ifndef PRINT_STATEMENT_INCLUDED
#define PRINT_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class PrintStatement : public Statement
{
public:
	PrintStatement(char variableName); // constructor

	virtual void execute(ProgramState* state, std::ostream& outf);

private:
	char m_variableName;
};

PrintStatement::PrintStatement(char variableName) // constructor
{
	m_variableName = variableName;
}

void PrintStatement::execute(ProgramState* state, std::ostream& outf)
{
	outf << state->getValue(m_variableName); // calls getValue function to print value of corresponding variable
	outf << "\n"; // print new line
	state->incrementCounter(); // increment program counter for later use - GOSUB statements, stack implementation(???)
}

#endif