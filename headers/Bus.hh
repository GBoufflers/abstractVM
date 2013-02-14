#ifndef __BUS_HH__
#define __BUS_HH__

#include	"IBus.hh"

class	Bus : public IBus
{
public:
  virtual ~Bus();
  Bus();

  std::stack &getMemory() const;
  void setMemory(std::stack &); 
};

#endif
