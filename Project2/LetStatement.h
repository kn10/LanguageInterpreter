/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// The LetStatement class encapsulates a LET statement in a Facile program.
// A LET statement looks like this:
//
//     LET A 3
//
// Primarily, it consists of two things: a variable name (denoted by a single
// character) and an integer value.  So, a LetStatement object contains a
// character and an integer, which is the important information contained in
// a LET statement.

// Need to similarly define subclasses for each of the other kinds of
// statements in a Facile program.

#ifndef LET_STATEMENT_INCLUDED
#define LET_STATEMENT_INCLUDED

#include "Statement.h"
//#include "ProgramState.h"
#include <iostream> // delete later;

class LetStatement : public Statement
{
public:
	LetStatement(char variableName, int value); // constructor
	virtual void execute(ProgramState* state, std::ostream& outf); // changes variable to certain value

private:
	char m_variableName;
	int m_value;
};

LetStatement::LetStatement(char variableName, int value) // constructor
{
	m_variableName = variableName;
	m_value = value;
}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState* state, std::ostream& outf)
{
	state->changeVariable(m_variableName, m_value); // sets value to certain variable
	state->incrementCounter(); // increment program counter for later use - GOSUB statements, stack implementation
}

#endif