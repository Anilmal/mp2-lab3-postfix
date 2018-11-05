#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  double res;
  int count;
  setlocale(LC_ALL, "Russian");
  cout << "Ведите колличество аргументов ";
  cin >> count;
  cout << endl;
  cout << "Введите формулу арифметического выражения: ";
  cin >> expression;
  TPostfix postfix(expression,count);
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
