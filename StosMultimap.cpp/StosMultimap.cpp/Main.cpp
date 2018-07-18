#include <iostream>

#include "Interpreter.hpp"

int main()
{
	using namespace SimpleInterpreter;


	std::cout << "===================================== Etap 1 =====================================" << std::endl;
	{
		Interpreter interpreter;

		std::cout << "============= Pusty interpreter =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("12.3");
		interpreter.Push("7.7");

		std::cout << "============= 2 elementy na stosie (7.7 i 12.3) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Add();

		std::cout << "============= Suma 7.7 + 12.3 = 20.0 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("2.5");
		interpreter.Sub();

		std::cout << "============= Odjecie wyniku od 2.5 (2.5 - 20 = -17.5) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("7.25");
		interpreter.Push("10");
		interpreter.Push("201.5");

		interpreter.Div();
		interpreter.Add();

		std::cout << "============= Dzielenie i dodawanie (201.5 / 10 + 7.25 = 27.4). Na stosie 27.4 i -17.5 =============" << std::endl;
		std::cout << interpreter << std::endl;
	}
//
	std::cout << "===================================== Etap 2 =====================================" << std::endl;
	{
		Interpreter interpreter;

		interpreter.Push("12.3");
		interpreter.Push("Num1");

		std::cout << "============= Na stosie Num1 i 12.3 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.DefVar();

		std::cout << "============= Stworzenie zmiennej Num1 = 12.3 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("Num1");
		interpreter.Push("2.3");
		interpreter.Sub();

		std::cout << "============= 2.3 - Num1 = -10.0 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("Num1");
		interpreter.Set();

		std::cout << "============= Num1 = -10 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("9.87");
		interpreter.Push("Num1");
		interpreter.Mul();
		interpreter.Push("Num2");
		interpreter.DefVar();

		std::cout << "============= Num2 = Num1 * 9.87 (Num2 = -98.7) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("Num2");
		interpreter.Push("Num1");
		interpreter.DefVar();

		std::cout << "============= Num1 = Num2 (2 zmienne Num1 i 1 Num2) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("8.7");
		interpreter.Push("Num1");
		interpreter.Add();
		interpreter.Push("Num1");
		interpreter.Set();

		std::cout << "============= Wyswietl Num1 (druga) (-90) =============" << std::endl;
		interpreter.Push("Num1");
		interpreter.Disp();

		interpreter.Push("Num1");
		interpreter.RemVar();

		std::cout << "============= Wyswietl Num1 (pierwsza) (-10) =============" << std::endl;
		interpreter.Push("Num1");
		interpreter.Disp();

		std::cout << "============= 2 zmienne. Num1 = -10, Num2 = -98.7 =============" << std::endl;
		std::cout << interpreter << std::endl;
	}
//
//	std::cout << "===================================== Etap 3 =====================================" << std::endl;
//	{
//		std::vector<Operation> mainOperations = {
//			// Create Num1
//			{ OpTypes::Push, "123.3" },
//			{ OpTypes::Push, "Num1" },
//			{ OpTypes::DefVar, "" },
//
//			// Disp Num1
//			{ OpTypes::Push, "Num1" },
//			{ OpTypes::Disp, "" },
//
//			// stack = Num1 + 7
//			{ OpTypes::Push, "7" },
//			{ OpTypes::Push, "Num1" },
//			{ OpTypes::Add, "" },
//
//			// Num1 = stack
//			{ OpTypes::Push, "Num1" },
//			{ OpTypes::Set, "" },
//
//			// Disp Num1
//			{ OpTypes::Push, "Num1" },
//			{ OpTypes::Disp, "" },
//		};
//
//		Interpreter interpreter;
//		interpreter.SetOperations(mainOperations);
//
//		std::cout << "============= Przed wykonaniem =============" << std::endl;
//		std::cout << interpreter << std::endl;
//
//		interpreter.Execute();
//
//		std::cout << "============= Po wykonaniu =============" << std::endl;
//		std::cout << interpreter << std::endl;
//	}
//
//	std::cout << "===================================== Etap 4 =====================================" << std::endl;
//	{
//		std::vector<std::pair<std::string, std::string>> invalidOperations = {
//			// Set last param
//			{ "Push", "2" },
//			{ "Push", "Param3" },
//			{ "DefVar", "" },
//
//			// Set second param
//			{ "Push", "3" },
//			{ "Push", "Param2" },
//			{ "DefVar", "" },
//
//			// Set first param
//			{ "Push", "4" },
//			{ "Push", "Param1" },
//			{ "DefVar", "" },
//
//			// Param1 * Param1
//			{ "Push", "Param1" },
//			{ "Push", "Param1" },
//			{ "Mul", "" },
//
//			// Param2 * Param2
//			{ "Push", "Param2" },
//			{ "Push", "Param2" },
//			{ "Mul", "" },
//
//			{ "InvalidOp", "123" }
//		};
//
//		std::vector<std::pair<std::string, std::string>> mainOperations = {
//			// Set last param
//			{ "Push", "2" },
//			{ "Push", "Param3" },
//			{ "DefVar", "" },
//
//			// Set second param
//			{ "Push", "3" },
//			{ "Push", "Param2" },
//			{ "DefVar", "" },
//
//			// Set first param
//			{ "Push", "4" },
//			{ "Push", "Param1" },
//			{ "DefVar", "" },
//
//			// Param1 * Param1
//			{ "Push", "Param1" },
//			{ "Push", "Param1" },
//			{ "Mul", "" },
//
//			// Param2 * Param2
//			{ "Push", "Param2" },
//			{ "Push", "Param2" },
//			{ "Mul", "" },
//
//			// Param3 * Param3
//			{ "Push", "Param3" },
//			{ "Push", "Param3" },
//			{ "Mul", "" },
//
//			// Param3^2 + Param2^2
//			{ "Add", "" },
//
//			// (Param3^2 + Param2^2) + Param1^2
//			{ "Add", "" },
//
//			// Create result
//			{ "Push", "Result" },
//			{ "DefVar", "" },
//
//			// Remove first param
//			{ "Push", "Param1" },
//			{ "RemVar", "" },
//
//			// Remove second param
//			{ "Push", "Param2" },
//			{ "RemVar", "" },
//
//			// Remove last param
//			{ "Push", "Param3" },
//			{ "RemVar", "" },
//
//			// Disp Result
//			{ "Push", "Result" },
//			{ "Disp", "" },
//
//			// Push invalid variable name
//			{ "Push", "Param1" },
//			{ "Push", "Result" },
//			{ "Mul", "" },
//		};
//
//
//		Interpreter interpreter;
//
//		std::cout << "============= Blad parsowania =============" << std::endl;
//		try
//		{
//			interpreter.ParseOperations(invalidOperations);
//		}
//		catch (const std::exception& exc)
//		{
//			std::cout << "ERROR: " << exc.what() << std::endl;
//		}
//
//		interpreter.ParseOperations(mainOperations);
//
//		std::cout << "============= Przed wykonaniem =============" << std::endl;
//		std::cout << interpreter << std::endl;
//
//		std::cout << "============= Blad \"Invalid value\" na ostatniej lini (Mul). Result = 29 =============" << std::endl;
//		interpreter.Execute();
//
//		std::cout << "============= Po wykonaniu (Result = 29) =============" << std::endl;
//		std::cout << interpreter << std::endl;
//	}
//
//	return 0;
}