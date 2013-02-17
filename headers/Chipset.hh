#ifndef __CHIPSET_HH__
#define __CHIPSET_HH__

#include	"IChipset.hh"

class	Chipset : public IChipset
{
  std::ifstream	file;
  std::list<std::string> instruction;
public:
  Chipset();
  virtual ~Chipset();
  virtual void readFile();
  virtual void readInput();
  virtual std::list<std::string>	getInstruction();
};

#endif
