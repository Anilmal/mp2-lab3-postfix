#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
public:
  TStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  void Put(const T &elem)
  {
	  if (!IsFull())
		  pMem[++top] = elem;
	  else
		  throw ("ERROR");
  }
  void Pop()
  {
	  if (top < 0)
		  throw top;
	  else
		  pMem[--top];
  }
  T Get()
  {
	  if (top < 0)
		  throw top;
	  else
		  return  pMem[top];
  }
  bool IsEmpty()
  {
	 
	  if (top == -1)
		  return true;
	  else
		  return false;
  }
  bool IsFull()
  {
	  if (top == (size-1))
		  return true;
	  else
		  return false;
  }
};
#endif
