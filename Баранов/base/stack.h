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
      throw "size is not correct";
    pMem = new T[size];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  void Put(const T &elem)
  {
	  if (!IsFull())
	  {
		  top += 1;
		  pMem[top] = elem;
	  }
	  else
		  throw ("cant put");
  }
  void Pop()
  {
	  if (!IsEmpty())
		  top-=1;
	  else
		  throw "cant pop";
  }
  T Get()
  {
	 return  pMem[top];
  }
  bool IsEmpty()
  {
	 
	  return top == -1;
  }
  bool IsFull()
  {
	  return top == (size-1);
  }
};
#endif
