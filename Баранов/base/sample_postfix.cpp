#include <iostream>
#include <string>
#include <cctype>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  double res;
  int count_args=0;
  setlocale(LC_ALL, "Russian");
  cout << "Введите формулу арифметического выражения: ";
  cin >> expression;
  for (int j = 0; j < expression.size(); j++)
  {
	  if (isalpha(expression[j]))
		  count_args++;
  }
  TPostfix postfix(expression,count_args);
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  postfix.CalculateCountOfArgs();
  double *args;
	  args = new double[postfix.GetCountOfNum()];
	  for (int i = 0; i < postfix.GetCountOfNum(); i++)
	  {
		  cout << "Введите аргументы" << endl;
		  cin >> args[i];
	  }
  res = postfix.Calculate(postfix.GetCountOfNum(),args);
  cout << res << endl;
  return 0;
}
