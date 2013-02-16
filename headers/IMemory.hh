#ifndef __IMEMORY_HH__
#define __IMEMORY_HH__

#include	<stack>
#include	<string>
#include	"IOperand.hh"

class	IMemory
{
public:
  virtual ~IMemory() {};
  virtual std::stack<IOperand *> &getPile() const = 0;
  virtual void setPile(std::stack<IOperand *> &)  = 0;
};

#endif
