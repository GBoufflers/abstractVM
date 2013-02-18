#ifndef __IO_HH__
#define __IO_HH__

#include	"IIo.hh"

class		Io : public IIo
{
public:
  virtual ~Io();
  Io();

  virtual char	* readInput(char *file);
};

#endif


