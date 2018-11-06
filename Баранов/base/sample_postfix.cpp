#include <iostream>
#include <string>
#include <cctype>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  double res;
  int count=0;
  int count_of_args=0;
  setlocale(LC_ALL, "Russian");
  cout << "Введите формулу арифметического выражения: ";
  cin >> expression;
  for (int j = 0; j < expression.size(); j++)
  {
	  if (isalpha(expression[j]))
	  {
		  count_of_args++;
		  for (int i = j + 1; i < expression.size(); i++)
		  {
			  if (expression[j] == expression[i])
				  count = count_of_args - 1;
		  }
	  }
  }
  TPostfix postfix(expression,count_of_args);
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  double *args;
  args = new double[count];
  for (int i = 0; i < count; i++)
  {
	  cout << "Введите аргументы" << endl;
	  cin >> args[i];
  }
  res = postfix.Calculate(count,args);
  cout << res << endl;
  return 0;
}
