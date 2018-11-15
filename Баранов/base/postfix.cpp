#include "postfix.h"
#include "stack.h"
void TPostfix::ToPostfix()
{
	TStack<char> operations(infix.size());
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
		{
			TStack<char> operations1(infix.size());
			while (infix[i] != ')')
			{
				if (isalpha(infix[i]))
				{
					postfix += infix[i];
				}
				else if (OperationIs(infix[i]))
				{
					if (operations1.IsEmpty())
						operations1.Put(infix[i]);
					else if (Priority(infix[i]) <= Priority(operations1.Get()))
					{
						postfix += operations1.Get();
						operations1.Pop();
						if (Priority(infix[i]) == Priority(operations1.Get()))
						{
							postfix += operations1.Get();
							operations1.Pop();
						}
						operations1.Put(infix[i]);
					}
					else
						operations1.Put(infix[i]);
				}
				i++;
			}
			if(infix[i]==')')
			{
				while (!operations1.IsEmpty())
				{
					postfix += operations1.Get();//abc*+
					operations1.Pop();
				}
			}
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
double* TPostfix::GetArgs(double *arguments)//12
{ 
	string tmp=postfix;//ab+a
	string args;
	double param[100];
	int b=0;
	for (int i = 0; i < tmp.length(); i++)
	{
		if (isalpha(tmp[i]))//ab
		{
			if (b == GetCountOfArgs())
				b = 0;
				param[i] = arguments[b];//a=1 b=2
				for (int j = i + 1; j < tmp.length(); j++)
				{
					if (tmp[i] == tmp[j])//j=4
						param[j] = arguments[b];//1
					else
						continue;
				}
				b++;
		}
		else
			param[i] = 0;
	}
	return param;
}
void TPostfix::CalculateCountOfArgs()
{
	string tmp = infix;
	for (int i = 0; i < tmp.length(); i++)
	{
		if (isalpha(tmp[i]))
		{
			for (int j = i + 1; j < tmp.length(); j++)
			{
				if (tmp[i] == tmp[j])
				{
					tmp[j] = ' ';
					count_of_args--;
				}
			}
		}
	}
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
	TStack<double> res(99);
	double tmp1;
	double tmp2;
	double *args = GetArgs(arguments);
	for (int i = 0; i < postfix.size(); i++)
	{
		if (isalpha(postfix[i]))
		{
			res.Put(args[i]);
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
