#ifndef __IO_HH__
#define __IO_HH__

#include	"IIo.hh"

class		Io : public IIo
{
  std::list<std::string>	content;
public:
  virtual ~Io();
  Io();

  virtual void	readInput(char *file);
  virtual void	putFileInList(std::ifstream &file);
  virtual void	putInputInList();
};

#endif


