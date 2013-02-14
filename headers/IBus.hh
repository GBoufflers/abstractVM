#ifndef __IBUS_HH__
#define __IBUS_HH__

class	IBus
{
public:
  virtual std::stack &getMemory() const = 0;
  virtual setMemory(std::stack &) const = 0;
  virtual ~IBus();
};

#endif
