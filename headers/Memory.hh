#ifndef __MEMORY_HH__
#define __MEMORY_HH__

#include	<stack>
#include	"IMemory.hh"

class	Memory : public IMemory
{
private:
  std::stack<IOperand *>	mem;
public:
  Memory();
  virtual ~Memory();

  virtual std::stack<IOperand *> &getPile();
  virtual void setPile(std::stack<IOperand *> &);
};

#endif
