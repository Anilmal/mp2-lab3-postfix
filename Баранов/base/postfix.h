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
  TPostfix(string _infix)
  {
	  infix = _infix;
	  count_of_args = 0;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  void ToPostfix();
  double Calculate(int count,double *arguments);
};

#endif
