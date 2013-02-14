#ifndef __ICHIPSET_HH__
#define __ICHIPSET_HH__

#include	<list>
#include	<string>
#include	<fstream>
#include	<ostream>

class	IChipset
{
public:
  virtual std::list<std::string> putInList(std::ifstream file) = 0;
  virtual ~IChipset();
};

#endif
