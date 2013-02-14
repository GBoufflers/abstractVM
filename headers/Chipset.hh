#ifndef __CHIPSET_HH__
#define __CHIPSET_HH__

#include	"IChipset.hh"

class	Chipset : public IChipset
{
public:
  virtual ~Chipset();
  Chipset();
  std::list<string> putInList(ostream file) = 0;
};

#endif
