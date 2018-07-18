#include "Operation.hpp"

namespace SimpleInterpreter
{
	Operation::Operation(OpTypes operationType, const std::string& param) :
		OperationType{ operationType }, Param{ param }
	{
	}

	std::ostream& operator << (std::ostream& out, const Operation& operation)
	{
		out << "    ";
		switch (operation.OperationType)
		{
			case OpTypes::DefVar:	out << "DefVar";	break;
			case OpTypes::RemVar:	out << "RemVar";	break;
			case OpTypes::Set:		out << "Set";		break;
			case OpTypes::Push:		out << "Push";		break;
			case OpTypes::Disp:		out << "Disp";		break;
			case OpTypes::Add:		out << "Add";		break;
			case OpTypes::Sub:		out << "Sub";		break;
			case OpTypes::Mul:		out << "Mul";		break;
			case OpTypes::Div:		out << "Div";		break;
		}

		if (!operation.Param.empty()) out << ": " << operation.Param;

		return out;
	}


}