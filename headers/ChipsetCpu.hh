#ifndef				__CHIPSETCPU_HH__
#define				__CHIPSETCPU_HH__

#include			"IChipsetCpu.hh"

class	ChipsetCpu : public IChipsetCpu
{
public:
  ChipsetCpu();
  virtual ~ChipsetCpu();
  /*********************/
  virtual std::stack<IOperand *> getMemory() const;
  virtual void	setMemory(std::stack<IOperand *> &);
};

#endif
