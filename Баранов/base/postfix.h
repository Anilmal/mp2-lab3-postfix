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
public:
  TPostfix()
  {
   infix = "a + b";
  }
  TPostfix(string _infix)
  {
	  infix = _infix;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  void ToPostfix();
  double Calculate(double *values);
};

#endif
