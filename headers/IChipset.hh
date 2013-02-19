#ifndef __ICHIPSET_HH__
#define __ICHIPSET_HH__

#include	<list>
#include	<string>
#include	<fstream>
#include	<iostream>

class	IChipset
{
public:
  virtual	void parseList() = 0;
  virtual	std::list<std::string>	getInstruction() = 0;
  virtual	void initMap() = 0;
  virtual ~IChipset(){};
};

#endif
