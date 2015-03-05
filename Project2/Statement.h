/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

/*
This is the abstract Statement class, from which various statement
classes will need to extend. There is only one method in the Statement
class, an execute() method that executes the statement,
making any necessary changes to the given ProgramState.
*/

#ifndef STATEMENT_INCLUDED
#define STATEMENT_INCLUDED

#include "ProgramState.h"
#include <fstream>
#include <iostream>

class Statement
{
public:
	/*

	execute() takes a ProgramState and executes this statement, by
	making any necessary changes to the ProgramState (e.g. new value for
	the program counter, changing value of some variable, pushing or
	popping from the line number stack).

	execute() also takes a ostream parameter; if any output is to be
	written, write it to the given ostream

	In the event that execution of the statement causes a fatal error
	that should termine the Facile program, such as division by zero or
	a RETURN statement without a corresponding GOSUB, the program may exit
	instead of returning from execute()

	*/

	virtual void execute(ProgramState* state, std::ostream& outf) = 0;

private:
};

// Note: Do not need Statement.cpp

#endif