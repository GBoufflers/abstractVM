#ifndef				__ICHIPSETCPU_HH__
#define				__ICHIPSETCPU_HH__

#include	<list>
#include	<string>

class	IChipsetCpu
{
public:
  virtual std::list<std::string> putInList() = 0;
  virtual std::list<std::string> putInputList() = 0;
  /***********************/
  virtual ~IChipsetCpu(){};
};

#endif
