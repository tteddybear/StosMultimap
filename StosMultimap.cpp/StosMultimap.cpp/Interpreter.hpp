#ifndef SIMPLE_INTERPRETER_INTERPRETER_HPP
#define SIMPLE_INTERPRETER_INTERPRETER_HPP

#include "Operation.hpp"
#include <stack>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

//////////////////////////////////

namespace SimpleInterpreter
{
	class Interpreter
	{
	private:
		std::stack<std::string> stos;
		std::multimap<std::string, float> mapa;
		std::vector<Operation> wektor;
		std::queue<Operation> kolejka;

		static float StringToFloat(const std::string& valueStr);
		static std::string FloatToString(float value);

		std::string PopIdent();
		float PopNum();
		void PushNum(float value);

		void ExecuteOperation(const Operation& operation);

	public:
		void DefVar();
		void RemVar();

		void Set();
		void Push(const std::string& param);
		void Disp();

		void Add();
		void Sub();
		void Mul();
		void Div();

		void SetOperations(const std::vector<Operation>& operations);
		void ParseOperations(const std::vector<std::pair<std::string, std::string>>& operations);
		
		void Execute();

		void PrintOperations(std::ostream& out) const;
		void PrintOperationsQueue(std::ostream& out) const;
		void PrintDataStack(std::ostream& out) const;
		void PrintVariables(std::ostream& out) const;

		void SetOperations(const std::vector<Operation>& operations);

		friend std::ostream& operator << (std::ostream& out, const Interpreter& interpreter);
	};
}

#endif // !SIMPLE_INTERPRETER_INTERPRETER_HPP
