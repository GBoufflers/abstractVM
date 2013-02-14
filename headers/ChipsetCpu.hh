#ifndef				__CHIPSETCPU_HH__
#define				__CHIPSETCPU_HH__

#include			"IChipsetCpu.hh"

class	ChipsetCpu : public IChipsetCpu
{
public:
  ChipsetCpu();
  virtual ~ChipsetCpu();
  /*********************/
  std::list<std::string>	putInList() = 0;
  std::list<std::string>	putInputList() = 0;
};

#endif
