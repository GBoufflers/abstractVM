#ifndef __IBUSMEM_HH__
#define __IBUSMEM_HH__

#include	<stack>
#include	<string>

class	IBusMem
{
public:
  /*  virtual std::stack<std::string> &getMemory() const;
      virtual void setMemory(std::stack<std::string> &) = 0;*/
  virtual ~IBusMem(){};
};

#endif
