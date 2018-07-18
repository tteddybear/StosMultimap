#ifndef SIMPLE_INTERPRETER_OPERATION_HPP
#define SIMPLE_INTERPRETER_OPERATION_HPP

#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace SimpleInterpreter
{
	enum OpTypes
	{
		DefVar,
		RemVar,

		Set,
		Push,
		Disp,
		
		Add,
		Sub,
		Mul,
		Div,
	};

	struct Operation
	{
		OpTypes OperationType;
		std::string Param;

		Operation(OpTypes operationType, const std::string& param = "");

		friend std::ostream& operator << (std::ostream& out, const Operation& operation);
	};
}

#endif // !SIMPLE_INTERPRETER_OPERATION_HPP
