#ifndef __IBUS_HH__
#define __IBUS_HH__

class	IBus
{
public:
  virtual std::stack &getMemory() const = 0;
  virtual void setMemory(std::stack &) = 0;
  virtual ~IBus();
};

#endif
