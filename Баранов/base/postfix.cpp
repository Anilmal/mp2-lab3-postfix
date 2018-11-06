#include "postfix.h"
#include "stack.h"


void TPostfix::ToPostfix()
{
	TStack<char> operations(infix.length());
	postfix = "";
	for (int i = 0; i < infix.length(); i++)
	{
		if (isalpha(infix[i]))
		{
			postfix += infix[i];
		}
		else if (OperationIs(infix[i]))
		{
			if (operations.IsEmpty())
				operations.Put(infix[i]);
			else if (Priority(infix[i]) <= Priority(operations.Get()))
			{
				postfix += operations.Get();
				operations.Pop();
				if (Priority(infix[i]) == Priority(operations.Get()))
				{
					postfix += operations.Get();
					operations.Pop();
				}
				operations.Put(infix[i]);
			}
			else
				operations.Put(infix[i]);
		}
		else if (infix[i] == '(')
			operations.Put(infix[i]);
		else if (infix[i] == ')')
		{
			while (operations.Get() != '(')
			{
				postfix += operations.Get();
					operations.Pop();
			}
			operations.Pop();
		}
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
int TPostfix::GetCountOfArgs()
{ 
	TStack<char>args(infix.size());
	for (int i = 0; i < infix.length(); i++)
	{
		if (isalpha(infix[i]))
		{
			args.Put(infix[i]);
		}
	}
	return count_of_args;
}
int TPostfix::Priority(char sym)
{
	if (sym == '*' || sym == '/')
		return 2;
	if (sym == '+' || sym == '-')
		return 1;
}
double TPostfix::Calculate(int count,double *arguments)// пользователь передает колличесво аргументов их значения
{
	if (count > count_of_args)
		throw"ERROR";
	TStack<double> res(count_of_args);
	double tmp1;
	double tmp2;
	int j = 0;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (isalpha(postfix[i])&& !res.IsFull())
		{
			res.Put(arguments[j]);
			j++;
			if (j == count-1)
				j = 0;
		}
		else if(OperationIs(postfix[i]))
		{

				tmp1 = res.Get();
				res.Pop();
				tmp2 = res.Get();
				res.Pop();
				if (postfix[i] == '+')
					res.Put(tmp1 + tmp2);
				if (postfix[i] == '-')
					res.Put(tmp2 - tmp1);
				if (postfix[i] == '/')
					res.Put(tmp2 / tmp1);
				if (postfix[i] == '*')
					res.Put(tmp2 * tmp1);
		}
	}
	return res.Get();
}
