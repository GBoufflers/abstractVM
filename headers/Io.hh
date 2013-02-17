#ifndef __IO_HH__
#define __IO_HH__

#include	"IIo.hh"

class		Io : public IIo
{
public:
  virtual ~Io();
  Io();
  
  /*  virtual void	dump() const = 0 ;
      virtual void	print() const = 0;  */
  virtual std::ostream readInput();
};

#endif
