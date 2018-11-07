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
  int count_of_num = 0;
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
  string GetArgs();
  void ToPostfix();
  void CalculateCountOfArgs();
  int GetCountOfNum() { return count_of_num; }
  double Calculate(int count,double *arguments);
};

#endif
