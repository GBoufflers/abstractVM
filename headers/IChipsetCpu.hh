#ifndef				__ICHIPSETCPU_HH__
#define				__ICHIPSETCPU_HH__

#include	<list>
#include	<string>
#include	<stack>
#include	"IOperand.hh"

class	IChipsetCpu
{
public:
  virtual std::stack<IOperand *> getMemory() const = 0;
  virtual void	setMemory(std::stack<IOperand *> &) = 0;
  /***********************/
  virtual ~IChipsetCpu(){};
};

#endif
