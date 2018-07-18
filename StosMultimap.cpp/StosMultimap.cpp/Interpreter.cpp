#include "Interpreter.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

namespace SimpleInterpreter
{
#pragma region Etap 0
	
	// Konwertuje tekst na float. Jesli sie nie da, to rzuca wyjatkiem.
	float Interpreter::StringToFloat(const std::string& valueStr)
	{
		float value;
		std::stringstream stream{ valueStr };
		if (!(stream >> value))
			throw std::runtime_error{ "Invalid value" };

		return value;
	}

	// Konwertuje float na tekst
	std::string Interpreter::FloatToString(float value)
	{
		std::stringstream stream;
		stream << value;
		return stream.str();
	}

	// Wykonuje funkcje odpowiadajaca podanej operacji.
	void Interpreter::ExecuteOperation(const Operation& operation)
	{
		switch (operation.OperationType)
		{
			case OpTypes::DefVar:
			DefVar();
			break;

			case OpTypes::RemVar:
			RemVar();
			break;

			case OpTypes::Set:
			Set();
			break;

			case OpTypes::Push:
			Push(operation.Param);
			break;

			case OpTypes::Disp:
			Disp();
			break;

			case OpTypes::Add:
			Add();
			break;

			case OpTypes::Sub:
			Sub();
			break;

			case OpTypes::Mul:
			Mul();
			break;

			case OpTypes::Div:
			Div();
			break;

			default:
			throw std::runtime_error{ "Invalid operation" };
		}
	}

	std::ostream& operator << (std::ostream& out, const Interpreter& interpreter)
	{
		out << "VARIABLES:" << std::endl;
		interpreter.PrintVariables(out);

		out << "OPERATIONS:" << std::endl;
		interpreter.PrintOperations(out);

		out << "OPERATIONS QUEUE:" << std::endl;
		interpreter.PrintOperationsQueue(out);

		out << "DATA STACK:" << std::endl;
		interpreter.PrintDataStack(out);

		return out;
	}

#pragma endregion

#pragma region Etap 1

	// Etap 1:
	// Zwracana jest wartoœæ ze szczytu stosu (przekonwertowana ze string na float).
	// Etap 2:
	// Jesli wartosc na szczycie stosu to nazwa zmiennej, to zwraca jej wartosc.
	// W przeciwnym wypadku zwraca wartoœæ ze stosu (przekonwertowana ze string na float).

	float Interpreter::PopNum()
	{
		if (!mapa.empty()) {
			float f;
			auto p = mapa.equal_range(stos.top());
			if (p.first == p.second) {
				float value = StringToFloat(stos.top());
				stos.pop();
				return value;
			}
			else {
				f = (--p.second)->second;
				stos.pop();
				return f;
			}
		}
		/////////////////////
		float value = StringToFloat(stos.top());
		stos.pop();
		return value;
		/////////////////
		auto p = mapa.equal_range(stos.top());
		return 0.0f;
	}

	// Zamienia wartosc na string i wrzuca na stos.
	void Interpreter::PushNum(float value)
	{
		// Etap 1
		stos.push(FloatToString(value));
	}

	// Wrzuca string na stos.
	void Interpreter::Push(const std::string& param)
	{
		// Etap 1
		stos.push(param);
	}
	
	// Sciaga 2 elementy ze stosu, dodaje je, wynik zapisuje na stosie.
	void Interpreter::Add()
	{
		// Etap 1
		float n1 = PopNum();
		float n2 = PopNum();
		PushNum(n1 + n2);
	}

	// Sciaga 2 elementy ze stosu, odejmuje od pierwszego drugi, wynik zapisuje na stosie.
	void Interpreter::Sub()
	{
		// Etap 1
		float n1 = PopNum();
		float n2 = PopNum();
		PushNum(n1 - n2);
	}

	// Sciaga 2 elementy ze stosu, mnozy pierwszy przez drugi, wynik zapisuje na stosie.
	void Interpreter::Mul()
	{
		// Etap 1
		float n1 = PopNum();
		float n2 = PopNum();
		PushNum(n1 * n2);
	}

	// Sciaga 2 elementy ze stosu, dzieli pierwszy przez drugi, wynik zapisuje na stosie.
	void Interpreter::Div()
	{
		// Etap 1
		float n1 = PopNum();
		float n2 = PopNum();
		PushNum(n1 / n2);
	}
	
	void Interpreter::PrintDataStack(std::ostream& out) const
	{
		// Etap 1
		std::stack<std::string> stos2 = stos;
		int i = 0;
		while (!stos2.empty()) {
			out << "  " << i << ": " << stos2.top() << std::endl;
			stos2.pop();
			i++;
		}
	}

#pragma endregion

#pragma region Etap 2

	// Zwraca string ze szczytu stosu
	std::string Interpreter::PopIdent()
	{
		// Etap 2
		if (!stos.empty())
		{
			std::string temp = stos.top();
			stos.pop();
			return temp;
		}
		return "";
	}

	// Pobiera nazwe zmiennej ze stosu, nastepnie jej wartosc i tworzy zmienna.
	void Interpreter::DefVar()
	{
		// Etap 2
		std::string temp = PopIdent();
		float value = PopNum();
		mapa.insert(std::make_pair(temp, value));
	}

	// Pobiera nazwe zmiennej ze stosu i usuwa ja.
	void Interpreter::RemVar()
	{
		// Etap 2
		std::string temp = PopIdent();
		auto p = mapa.equal_range(temp);
		if (p.first != p.second) {
			auto it = --p.second;
			mapa.erase(it);
		}
	}

	// Pobiera nazwe zmiennej ze stosu, pobiera wartosc ze stosu i przypisuje zmiennej wartosc.
	void Interpreter::Set()
	{
		// Etap 2
		std::string temp = PopIdent();
		float value = PopNum();

		auto p = mapa.equal_range(temp);
		if (p.first != p.second) {
			(--p.second)->second = value;
		}
	}
	
	// Sciaga wartosc ze stosu i ja drukuje na ekran.
	void Interpreter::Disp()
	{
		// Etap 2
		std::cout << PopNum() << std::endl;
	}
	
	void Interpreter::PrintVariables(std::ostream& out) const
	{
		// Etap 2
		for_each(mapa.begin(), mapa.end(), [&](auto it) { out << it.first << "  " << it.second << std::endl; });
	}

#pragma endregion

#pragma region Etap 3

	void Interpreter::SetOperations(const std::vector<Operation>& operations)
	{
		// Etap 3
		wektor.clear();
		std::queue<Operation> pusta;
		kolejka = pusta;
		wektor = operations;
		int n = operations.size();
		for (int i = 0; i < n; i++) {
			kolejka.push(operations[i]);
		}
	}

	// Wykonuje caly program
	void Interpreter::Execute()
	{
		// Etap 3
		try {
			while (!kolejka.empty()) {
				Operation op = kolejka.front();
				kolejka.pop();
				ExecuteOperation(op);
			}
		}
		catch (std::exception e) {
			cout << "ERROR:" << e.what() << std::endl;
		}
	}

	void Interpreter::PrintOperations(std::ostream& out) const
	{
		// Etap 3
		
	}

	void Interpreter::PrintOperationsQueue(std::ostream& out) const
	{
		// Etap 3
	}

#pragma endregion

#pragma region Etap 4

	void Interpreter::ParseOperations(const std::vector<std::pair<std::string, std::string>>& operations)
	{
		// Etap 4
	}

#pragma endregion
}
