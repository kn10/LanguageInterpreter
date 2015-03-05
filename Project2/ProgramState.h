/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

/*
The ProgramState class encapsulates the state of an executing Facile
program. The state of a Facile program consists of three parts:

* The program counter, which specifies the line number of the statement that will execute next.
* An array of 26 integers, holding the current values of the 26 variables.
* A stack of integers, which is used to hold return lines for GOSUB statements.

*/

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED
#include "Stack.h"
#include <vector>
#include <string>

class ProgramState
{
public:
	// Constructor
	ProgramState(int numLines);

	// Add member functions ...
	void jump(int value, std::ostream& outf); // jumps to next line that corresponds to value
	void updateIncrement(int value); // updates what line to execute next
	void incrementCounter(); // updates the increment (or numLines)
	int getIncrement() const; // print the program counter
	int getNumLines() const; // print total number of lines in ProgramState

	// Stack member functions
	int getTop() const; // prints the top return line in the stack
	void pushToStack(int value); // pushes value to top of the Stack
	void popStack(); // pops value on top of the Stack

	// For Statements:
	void changeVariable(char variable, int value); // LetStatement function to change variable to certain value
	int getValue(char variable) const; // PrintStatement function to print value of certain variable

	// Mathematical operations
	void add(char variable, int value); // AddStatement function, adds value to certain variable
	void subtract(char variable, int value);
	void multiply(char variable, int value);
	void divide(char variable, int value, std::ostream& outf);

private:
	int m_numLines; // total lines in ProgramState
	int m_alphabetArray[26]; // an array of 26 letters, initialized to 0
	Stack<int> m_returnLines; // a Stack of integers, used to hold return lines for GOSUB statements
	int m_increment; // incrementer
};

// Helper function:
int changeCharToInt(char variable)
{
	if (variable == 'A')
		return 1;
	if (variable == 'B')
		return 2;
	if (variable == 'C')
		return 3;
	if (variable == 'D')
		return 4;
	if (variable == 'E')
		return 5;
	if (variable == 'F')
		return 6;
	if (variable == 'G')
		return 7;
	if (variable == 'H')
		return 8;
	if (variable == 'I')
		return 9;
	if (variable == 'J')
		return 10;
	if (variable == 'K')
		return 11;
	if (variable == 'L')
		return 12;
	if (variable == 'M')
		return 13;
	if (variable == 'N')
		return 14;
	if (variable == 'O')
		return 15;
	if (variable == 'P')
		return 16;
	if (variable == 'Q')
		return 17;
	if (variable == 'R')
		return 18;
	if (variable == 'S')
		return 19;
	if (variable == 'T')
		return 20;
	if (variable == 'U')
		return 21;
	if (variable == 'V')
		return 22;
	if (variable == 'W')
		return 23;
	if (variable == 'X')
		return 24;
	if (variable == 'Y')
		return 25;
	if (variable == 'Z')
		return 26;
	else
		return 0;
}

ProgramState::ProgramState(int numLines) // constructor
{
	m_numLines = numLines;
	m_alphabetArray[26] = {};
	m_increment = 1;
}

int ProgramState::getIncrement() const
{
	return m_increment; // returns line statement currently being executed
}

int ProgramState::getTop() const
{
	// used to save return lines and used to know what line to
	//execute next for GOSUB statements after a RETURN statement has been reached

	if (!m_returnLines.empty()) // if the stack is not empty
		return m_returnLines.top(); // returns the top int of the stack
	else
		return 0; // if stack is empty, then top is 0
}

void ProgramState::changeVariable(char variable, int value) // updates the variable, used for LetStatements
{
	m_alphabetArray[changeCharToInt(variable)] = value;
}

void ProgramState::incrementCounter() // updates what line to execute next
{
	m_increment++;
}

int ProgramState::getValue(char variable) const // returns value of the variable as stored in the alphabet array
{
	return m_alphabetArray[changeCharToInt(variable)];
}

// Mathematical operations:
void ProgramState::add(char variable, int value) // adds value to variable
{
	m_alphabetArray[changeCharToInt(variable)] += value;
}

void ProgramState::subtract(char variable, int value) // subtracts value to variable
{
	m_alphabetArray[changeCharToInt(variable)] -= value;
}

void ProgramState::multiply(char variable, int value) // multiples value to variable
{
	m_alphabetArray[changeCharToInt(variable)] *= value;
}

void ProgramState::divide(char variable, int value, std::ostream& outf) // divides value to variable
{
	if (value == 0) // can't divide by 0
	{
		outf << "Divide by zero exception\n"; // streams error message if dividing by 0, then exits program
		exit(1);
	}

	else
		m_alphabetArray[changeCharToInt(variable)] /= value; // updates variable to value if not dividing by 0
}

void ProgramState::jump(int value, std::ostream& outf) // jumps to line of corresponding variable, useful in GOTO statements, IF statements
{
	updateIncrement(value);
}

void ProgramState::updateIncrement(int number) // updates line to value
{
	m_increment = number;
}

void ProgramState::pushToStack(int value) // pushes value to top of stack
// used in GOSUB statements, to save lines
{
	m_returnLines.push(value);
}

int ProgramState::getNumLines() const // print total number of lines in ProgramState
{
	return m_numLines;
}

void ProgramState::popStack() // deletes top of the Stack, used in GOSUB statements, and RETURN statements
{
	m_returnLines.pop();
}

#endif