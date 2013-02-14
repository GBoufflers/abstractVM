#ifndef __BUS_HH__
#define __BUS_HH__

#include	"IBus.hh"

class	Bus : public IBus
{
public:
  virtual ~Bus();
  Bus();

  std::stack<std::string> &getMemory() const;
  void setMemory(std::stack<std::string> &); 
};

#endif
