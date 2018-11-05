#include "postfix.h"
#include "stack.h"
#include <iostream>

void TPostfix::ToPostfix()
{
	TStack<char> operations(infix.length());
	postfix = "";
	string tmp = "";
	TStack<char> operations1(infix.length());
	for (int i = 0; i < infix.length(); i++)
	{
		if (isalpha(infix[i]))//a
		{
			postfix += infix[i];
			count_of_args++;
		}
		else if (OperationIs(infix[i]))
		{
			if (operations.IsEmpty())
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
		else if (infix[i] == '(')
			{
				i++;
				while (infix[i]!=')')
				{
					if (isalpha(infix[i]))//bc
					{
						tmp += infix[i];
					}
					else if (operations1.IsEmpty())
						operations1.Put(infix[i]);//-
					else if (Priority(infix[i]) <= Priority(operations1.Get()))
					{
						tmp += operations1.Get();
						operations1.Pop();
						operations1.Put(infix[i]);
					}
					else
						operations1.Put(infix[i]);
						i++;
				}
				while (!operations1.IsEmpty())
				{
					tmp += operations1.Get();//bc-
					operations1.Pop();
				}
				postfix += tmp;
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
int TPostfix::Priority(char sym)
{
	if (sym == '*' || sym == '/')
		return 2;
	if (sym == '+' || sym == '-')
		return 1;
}
double TPostfix::Calculate(int count,double *arguments)// пользователь передает колличесво аргументов их значения
{
	if (count != count_of_args)
		throw"ERROR";
	TStack<double> res(postfix.size());
	double tmp1;
	double tmp2;
	int j = 0;
	while (j != count)
	{
		res.Put(arguments[j]);
		j++;
	}
	for (int i = 0; i < postfix.size(); i++)
	{
			//if (isalpha(postfix[i]))//a b
			//{
			//	if (!res.IsEmpty() && res.Get() == arguments[j] && j<count_of_args)
			//	{
			//		j++;//[1]
			//		res.Put(arguments[j]);//2 2
			//	}
			//	else
			//		res.Put(arguments[j]);//2
			//}
		if(OperationIs(postfix[i]))
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
