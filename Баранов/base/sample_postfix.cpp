#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  TPostfix postfix;
  double res;
  int count=0;
  setlocale(LC_ALL, "Russian");
  cout << "Введите формулу арифметического выражения: ";
  cin >> expression;
  cout << expression << endl;
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  cout << "Ведите колличество аргументов";
  cin >> count;
  cout << endl;
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
