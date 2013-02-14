#ifndef __IBUS_HH__
#define __IBUS_HH__

#include	<stack>
#include	<string>

class	IBus
{
public:
  virtual std::stack<std::string> &getMemory() const = 0;
  virtual void setMemory(std::stack<std::string> &) = 0;
  virtual ~IBus();
};

#endif
