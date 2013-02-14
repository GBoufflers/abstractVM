#ifndef __MEMORY_HH__
#define __MEMORY_HH__

#include	"IMemory.hh"

class	Memory : public IMemory
{
public:
  Memory();
  virtual ~Memory();

  /*  virtual std::stack<std::string> &getPile() const;
      virtual void setPile(std::stack<std::string> &);*/
};

#endif
