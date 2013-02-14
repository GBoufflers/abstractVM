#ifndef __BUSMEM_HH__
#define __BUSMEM_HH__

#include	"IBusMem.hh"

class	busMem : public IBusMem
{
public:
  busMem();
  virtual ~busMem();

  /*  std::stack<std::string> &getMemory() const;
      void setMemory(std::stack<std::string> &); */
};

#endif
