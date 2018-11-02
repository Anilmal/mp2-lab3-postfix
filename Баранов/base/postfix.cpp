#include "postfix.h"
#include "stack.h"

void TPostfix::ToPostfix()
{
	TStack<char> operations(infix.length());
	postfix = "";
	for (int i = 0; i < infix.length(); i++)
	{
		if (isalpha(infix[i]))//abc
		{
			postfix += infix[i];
		}
		/*if (infix[i] == '(')
		{
			i++;
				while (infix[i] != ')')
				{

				}
		}*/
		else if (operations.IsEmpty())
			operations.Put(infix[i]);//+
		else if (Priority(infix[i]) <= Priority(operations.Get()))
		{
			postfix += operations.Get();//ab+
			operations.Pop();
			operations.Put(infix[i]);//-
		}
		else
			operations.Put(infix[i]);//+*
	}
	while (!operations.IsEmpty())
	{
		postfix += operations.Get();//abc*+
		operations.Pop();
	}
}
bool TPostfix::OperationIs(char inf_elem)
{
	if (inf_elem == '+' || inf_elem == '-' || inf_elem== '*' || inf_elem == '/')
		return true;
	return false;
}
int TPostfix::Priority(char sym)
{
	if (sym == '*' || sym == '/')
		return 2;
	if (sym == '+' || sym == '-')
		return 1;
}
double TPostfix:: Calculate(double *values)
{
	TStack<double>arg(sizeof(values) / sizeof(*values));
	for (size_t i = 0; i < sizeof(values) / sizeof(*values); i++)
	{
		arg.Put(values[i]);
	}
	double res;
	while (!arg.IsEmpty())
	{
		for (int i = 0; i < postfix.size(); i++)
		{
			if (isalpha(postfix[i]))
				postfix[i] = arg.Get();
		}
	}
	res = atof(postfix.c_str());
	return res; // Ввод переменных, вычисление по постфиксной 
}
