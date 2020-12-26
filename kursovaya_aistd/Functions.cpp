#include "Functions.h"

bool correct = true; // for unit tests
void allResults(string str)
{
	cout << "string: " << str << endl;
	MyList* elements = chek_and_separation(str);
	MyList* new_elements = from_infix_to_prefix(elements);
	MyList* again = reverse(new_elements);
	cout << "prefix: ";
	MyList* again1 = out_this_and_copy(again);
	double res = calculate_it(again1);
	cout << "result: " << res << endl;
}
bool check_if_number(char symbol)
{
	string allNumbers("0123456789");
	for (int i = 0; i < allNumbers.size(); i++)
	{
		if (symbol == allNumbers[i]) return true;
	}
	return false;
}

bool check_if_letter(char symbol)
{
	string letter("cosintglqrtexpab");
	for (int i = 0; i < letter.size(); i++)
	{
		if (symbol == letter[i])
			return true;
	}
	return false;
}

int operation_priority(char symbol)
{
	if (symbol == ')' || symbol == '(')
		return brecket;
	if (symbol == '+' || symbol == '-')
		return minus_plus;
	if (symbol == '*' || symbol == '/')
		return multiply_divide;
	if (symbol == '^')
		return degree;
	return not_operator;
}

int what_function(string function)
{
	if (function == "sin")
		return SIN;
	if (function == "cos")
		return	COS;
	if (function == "tg")
		return TG;
	if (function == "ctg")
		return CTG;
	if (function == "log")
		return LOG;
	if (function == "ln")
		return LN;
	if (function == "sqrt")
		return SQRT;
	if (function == "pi")
		return PI;
	if (function == "exp")
		return EXP;
	return NOT_FUNCTION; 
}

double count_function(int function, double argument)
{ 
	double counted = 0;
	switch (function)
	{
	case SIN:
		counted = sin(argument);
		break;
	case COS:
		counted = cos(argument);
		break;
	case TG:
		counted = tan(argument);
		break;
	case CTG:
		counted = (cos(argument) / sin(argument));
		break;
	case LOG:
		counted = log10(argument);
	case LN:
		counted = log(argument);
		break;
	case SQRT:
		counted = sqrt(argument);
		break;
	case EXP:
		counted = exp(argument);
		break;
	}
	return counted;
}

double count_operation(string operation, double first_argument, double second_argument)
{
	double result = 0;
	switch (operation[0])
	{
	case '-':
		result = (first_argument - second_argument);
		break;
	case '+':
		result = (first_argument + second_argument);
		break;
	case '*':
		result = (first_argument * second_argument);
		break;
	case '/':
		result = (first_argument / second_argument);
		break;
	case '^':
		result = (pow(first_argument, second_argument));
		break;
	}
	return result;
}

MyList* chek_and_separation(string str)
{
	MyList* elements = new MyList;
	int lBreckets = 0;
	int rBreckets = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			lBreckets++;
			elements->push(operation_priority(str[i]), "(");
			if ((operation_priority(str[i + 1]) != not_operator) && (str[i + 1] != '('))
			{
				cout << "not correct!";
				correct = false;
				return nullptr;
			}
		}
		else if (check_if_number(str[i]) == true)
		{
			double curr_number;
			/*int i_sup = i;
			int amountOfPoint = 0;
			while (is_number(str[i_sup]) == true || str[i_sup] == '.')
			{
				i_sup++;
				if (str[i_sup] == '.')
				{
					amountOfPoint++;
				}
				if (amountOfPoint > 1)
				{
					cout << "incorrect!";
					return nullptr;
				}
			}
			int differ = i_sup - i;
			char* sup = new char[differ];
			int j = 0;
			while (is_number(str[i]) == true || str[i] == '.')
			{
				sup[j] = str[i];
				i++;
				j++;
			}
			i--;
			string str(sup);
			curr_number = stod(str);
			elements->push(curr_number);
			delete[]sup;*/
			string number;
			int amountOfPoint = 0;
			while (check_if_number(str[i]) == true || str[i] == '.')
			{
				number.push_back(str[i]);
				if (str[i] == '.')
				{
					amountOfPoint++;
				}
				if (amountOfPoint > 1)
				{
					cout << "incorrect!";
					correct = false;
					return nullptr;
				}
				i++;
			}
			i--;
			curr_number = stod(number);
			elements->push(curr_number);
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z' || str[i + 1] >= 'A' && str[i + 1] <= 'Z' || str[i + 1] == '(')
			{
				cout << "incorrect!";
				correct = false;
				return nullptr;
			}
		}
		else if (str[i] == ')')
		{
			rBreckets++;
			if (rBreckets > lBreckets)
			{
				cout << "incorrect!";
				correct = false;
				return nullptr;
			}
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z' || str[i + 1] >= 'A' && str[i + 1] <= 'Z' || str[i + 1] == '(' || check_if_number(str[i + 1]) == true)
			{
				cout << "incorrect!";
				correct = false;
				return nullptr;
			}
			elements->push(operation_priority(str[i]), ")"); 
		}
		else if (operation_priority(str[i]) != not_operator)
		{
			if (str[i + 1] == ')')
			{
				cout << "incorrect!";
				correct = false;
				return nullptr;
			}
			if ((operation_priority(str[i + 1]) != not_operator) && (str[i + 1] != '('))
			{
				cout << "incorrect!";
				correct = false;
				return nullptr;
			}

			string math_operator;
			math_operator.push_back(str[i]);
			elements->push(operation_priority(str[i]), math_operator);
		}
		else if (check_if_letter(str[i]) == true)
		{
			string function;
			while (check_if_letter(str[i]) == true)
			{
				function.push_back(str[i]);
				i++;
			}
			i--;
			if (what_function(function) == PI) 
			{
				elements->push(M_PI, "pi"); 
			}
			else if (what_function(function) == NOT_FUNCTION || str[i + 1] != '(')
			{
				cout << "incorrect!";
				correct = false;
				return nullptr;
			}
			else
			{
				elements->push(priorities::function, function);
			}
		}
		else
		{
			cout << "incorrect!";
			correct = false;
			return nullptr;
		}
	}
	if (rBreckets < lBreckets)
	{
		cout << "incorrect!";
		correct = false;
		return nullptr;
	}
	return elements;
}


MyList* from_infix_to_prefix(MyList* elements) // но в этой функции только часть реализации. Продолжение в ф-ции reverse и в функции out_this_and_copy
{
	MyList* reversed = new MyList;
	if (elements == nullptr)
		return nullptr;
	Stack tack;
	while (elements->isEmpty() == false)
	{
		Element* now_element = new Element;
		now_element = elements->pop();
		string now_string = now_element->getString();
		double now_data = now_element->getData();
		if (now_string == ")")
			tack.push(now_element);
		else if ((now_string == "&") || (now_string == "pi")) 
		{
			reversed->push(now_element);
		}
		else if (now_string == "(")
		{
			while (tack.peek()->getString() != ")")
			{
				reversed->push(tack.pop());
			}
			tack.pop(); // )
		}
		else
		{
			if (tack.isEmpty() == false)
			{
				while (now_data <= tack.peek()->getData())
				{
					reversed->push(tack.pop());
					if (tack.isEmpty())
						break;
				}
			}
			tack.push(now_element);
		}
	}
	while (tack.isEmpty() == false)
	{
		reversed->push(tack.pop());
	}
	return reversed;
}

MyList* reverse(MyList* reversed)
{
	MyList* normal = new MyList;
	while (reversed->isEmpty() == false)
	{
		Element* now_element = reversed->pop();
		string now_string = now_element->getString();
		double now_data = now_element->getData();
		if (now_string == "&")
		{
			normal->push(now_data);
		}
		else
		{
			normal->push(now_data, now_string);
		}
	}
	return normal;
}

MyList* out_this_and_copy(MyList* normal)
{
	MyList* normal2 = new MyList;
	while (normal->isEmpty() == false)
	{
		Element* now_element = normal->popFront();
		string now_string = now_element->getString();
		double now_data = now_element->getData();
		if (now_string == "&")
		{
			cout << now_data << ' ';
			normal2->push(now_data);
		}
		else
		{
			cout << now_string << ' ';
			normal2->push(now_data, now_string);
		}
	}
	return normal2;
}


double calculate_it(MyList* normal2)
{

	cout << endl;
	Stack stack;
	double result = 0;
	while (normal2->isEmpty() == false)
	{
		Element* now_element = normal2->pop();
		string now_string = now_element->getString();
		double now_data = now_element->getData();
		if ((now_string == "&") || (now_string == "pi"))
		{
			stack.push(now_element); 
		}
		else
		{
			double second_operand = 0;
			if ((now_data == priorities::function) && (!stack.isEmpty()))
			{
				result = count_function(what_function(now_string), stack.pop()->getData());
				stack.push(result);
			}
			else if (!stack.isEmpty()) 
			{
				result = stack.pop()->getData(); 
				if (stack.isEmpty())
				{
					return 0;
				}
				second_operand = stack.pop()->getData();
				result = count_operation(now_string, result, second_operand);
				stack.push(result);
			}
		}
	}
	return result;
}