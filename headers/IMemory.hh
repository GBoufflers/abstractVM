#ifndef __IMEMORY_HH__
#define __IMEMORY_HH__

#include	<stack>
#include	<string>

class	IMemory
{
public:
  virtual ~IMemory() {};
  virtual std::stack<std::string> &getPile() const = 0;
  virtual void setPile(std::stack<std::string> &)  = 0;
};

#endif
