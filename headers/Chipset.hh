#ifndef __CHIPSET_HH__
#define __CHIPSET_HH__

#include	"IChipset.hh"
#include	<map>

class	Chipset : public IChipset
{
  std::list<std::string> final;
  std::list<std::string> &file;
  std::map<std::string, int>	verif;
public:
  Chipset(std::list<std::string> &list);
  virtual ~Chipset();
  virtual void traverseList();
  virtual void parseList(std::string &line);
  virtual void initMap();
  virtual int  checkComa(std::string &line, char c);
  virtual void checkInstruction(std::string &line);
  virtual void checkSimple(std::string &instr, std::string &line);;
};

#endif
