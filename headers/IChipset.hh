#ifndef __ICHIPSET_HH__
#define __ICHIPSET_HH__

class	IChipset
{
public:
  virtual std::list<string> putInList(ostream file) = 0;
  virtual ~IChipset();
};

#endif
