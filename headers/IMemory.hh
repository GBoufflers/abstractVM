#ifndef __IMEMORY_HH__
#define __IMEMORY_HH__

#include	<stack>
#include	<string>
#include	<ostream>
#include	<iostream>

class	IMemory
{
public:
  virtual std::stack<std::string> &getPile() const = 0;
  virtual void setPile(std::stack<std::string> &)  = 0;
  virtual ~IMemory();
};

#endif
