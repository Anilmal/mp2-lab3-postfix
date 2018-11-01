#include "postfix.h"
#include "stack.h"

string TPostfix::ToPostfix()
{
	char *tmp;
	TStack<char> operations(infix.size());
	TStack<char> symbols(infix.size());
	TStack<char> operations1(infix.size());
	TStack<char> symbols1(infix.size());
	for (int i = 0; i < infix.size(); i++)
	{
		if (!isalpha(infix[i]))
			operations.Put(infix[i]);
		if (infix[i] == '(')
		{
			i++;
			while (infix[i] != ')')
			{
				if (!isalpha(infix[i]))
					operations1.Put(infix[i]);
				else
					symbols1.Put(infix[i]);
				i++;
			}
		}

		else
			symbols.Put(infix[i]);
	}
	tmp = new char[infix.size()];
	for (int i = 0; i < infix.size(); i++)
	{
		if (!symbols.IsEmpty())
		{
			while (!symbols.IsEmpty())
				tmp [i]= char(symbols1.Get());
		}
		if (!operations.IsEmpty())
		{
			while (!operations.IsEmpty())
				tmp [i]= char(operations1.Get());
		}
		if (!symbols.IsEmpty())
		{
			while (!symbols.IsEmpty())
				tmp [i]= char(symbols.Get());
		}
		if (!operations.IsEmpty())
		{
			while (!operations.IsEmpty())
				tmp [i]= char(operations.Get());
		}
	}
	string res(tmp);
	postfix = res;
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
