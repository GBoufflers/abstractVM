#ifndef __ICHIPSET_HH__
#define __ICHIPSET_HH__

#include	<list>
#include	<string>
#include	<fstream>
#include	<iostream>

class	IChipset
{
public:
  virtual	int  checkComa(std::string &line) = 0;
  virtual	void checkInstruction(std::string &line) = 0;
  virtual	void traverseList() = 0;
  virtual	void parseList(std::string &line) = 0;
  virtual	void initMap() = 0;
  virtual ~IChipset(){};
};

#endif
