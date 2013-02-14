#ifndef				__CHIPSETCPU_HH__
#define				__CHIPSETCPU_HH__

#include			"IChipsetCpu.hh"

class	ChipsetCpu : public IChipsetCpu
{
public:
  ChipsetCpu();
  virtual ~ChipsetCpu();
  /*********************/
  putInList() = 0;
  putInputList() = 0;
};

#endif
