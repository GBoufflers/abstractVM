#ifndef __CHIPSET_HH__
#define __CHIPSET_HH__

#include	"IChipset.hh"
#include	<map>

class	Chipset : public IChipset
{
  std::list<std::string> final;
  std::list<std::string> &file;
  std::map<std::string, int>	verifInstruct;
public:
  Chipset(std::list<std::string> &list);
  virtual ~Chipset();
  virtual void parseList();
  virtual std::list<std::string>	getInstruction();
  virtual void initMap();
};

#endif
