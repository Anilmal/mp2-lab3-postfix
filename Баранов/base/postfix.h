#ifndef __POSTFIX_H__
#define __POSTFIX_H__
#include <string>
#include <cctype>
#include "stack.h"
using namespace std;
class TPostfix
{
  string infix;
  string postfix;
  bool OperationIs(char inf_elem);
  int Priority(char sym);
  int count_of_args=0;
public:
  TPostfix()
  {
   infix = "a + b";
   count_of_args = 2;
  }
  TPostfix(string _infix,int count)
  {
	  infix = _infix;
	  count_of_args = count;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  double* GetArgs(double *arguments);
  void ToPostfix();
  void CalculateCountOfArgs();
  int GetCountOfArgs() { return count_of_args; }
  double Calculate(int count,double *arguments);
};
#endif
