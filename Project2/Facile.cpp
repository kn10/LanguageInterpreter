/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// Facile.cpp
// Facile interpreter

// Libraries:
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>

// Header files:
#include "Statement.h"
#include "LetStatement.h"
#include "ProgramState.h"
#include "PrintStatement.h"
#include "AddStatement.h"
#include "ReturnStatement.h"
#include "GoSubStatement.h"
#include "GoToStatement.h"
#include "IfStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "IllegalStatement.h"

using namespace std;

// Functions:
// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns a vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

int main()
{
	string filename;
	do
	{
	cout << "Enter Facile program file name: ";
	

	
		getline(cin, filename);
		ifstream infile(filename.c_str());

		if (!infile)
		{
			cout << "Cannot open " << filename << "!" << endl;
			return 1;
		}

		interpretProgram(infile, cout);
	} while (filename != "end");
	return 0;
}

void parseProgram(istream& inf, vector<Statement*>& program)
{
	program.push_back(nullptr);
	//cout << "Pushed back: " << program[0] << endl;

	string line;

	while (!inf.eof())
	{
		getline(inf, line);
		program.push_back(parseLine(line));
		//cout << "Pushed back: " << parseLine(line) << endl; // delete later;
	}
}

Statement* parseLine(string line)
{
	Statement* statement;
	stringstream ss;
	string type;
	char variable;
	int value;

	// Variables for IF statements:
	string comparison;
	string then;
	int lineNumber;

	ss << line;
	ss >> type;

	if (type == "LET")
	{
		ss >> variable;
		ss >> value;
		statement = new LetStatement(variable, value);
		return statement;
	}
	if (type == "PRINT")
	{
		ss >> variable;
		statement = new PrintStatement(variable);
		return statement;
	}
	/* Mathematical Operations */
	if (type == "ADD")
	{
		ss >> variable;
		ss >> value;
		statement = new AddStatement(variable, value);
		return statement;
	}

	if (type == "SUB")
	{
		ss >> variable;
		ss >> value;
		statement = new SubStatement(variable, value);
		return statement;
	}

	if (type == "MULT")
	{
		ss >> variable;
		ss >> value;
		statement = new MultStatement(variable, value);
		return statement;
	}

	if (type == "DIV")
	{
		ss >> variable;
		ss >> value;
		statement = new DivStatement(variable, value);
		return statement;
	}

	if (type == "GOTO")
	{
		ss >> value;
		statement = new GoToStatement(value);
		return statement;
	}

	/* If Statement */
	if (type == "IF")
	{
		ss >> variable;
		ss >> comparison;
		ss >> value;
		ss >> then;
		ss >> lineNumber;
		statement = new IfStatement(variable, comparison, value, lineNumber);
		return statement;
	}

	/* Subroutines */
	if (type == "GOSUB")
	{
		ss >> value;
		statement = new GoSubStatement(value);
		return statement;
	}

	if (type == "RETURN")
	{
		statement = new ReturnStatement();
		return statement;
	}

	if (type == "END" || type == ".")
		return nullptr;

	else
		return new IllegalStatement();
}

void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement*> program;
	parseProgram(inf, program);
	ProgramState* state1 = new ProgramState(program.size());
	int program_size = program.size();

	// Facile interpreter's first line is 1
	while (state1->getIncrement() < program_size && state1->getIncrement() > 0) // UPDATE THIS
	{
		if (program[state1->getIncrement()] == nullptr)
			break;

		program[state1->getIncrement()]->execute(state1, outf);
	}

	if (state1->getIncrement() >= program_size || state1->getIncrement() <= 0) // For GOTO statement termination if incorrect GOTO statement value is inputted
		outf << "Illegal jump instruction\n";

	//cout << "End of output." << endl << endl; // delete later;
}

/*cout << "Program vector of Statements: " << endl;
for (auto x : program)
{
cout << x << endl;
}*/

//cout<< "size of program: " << program.size() << endl;

//cout << "Increment Counter: " << state1->getIncrement() << endl;
//cout << endl;

//cout << "Program size: " << program.size() << endl;

// Call Stack:

// Finish the function: