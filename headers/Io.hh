#ifndef __IO_HH__
#define __IO_HH__

#include	"IIo.hh"
#include	<map>

class		Io : public IIo
{
  std::list<std::string>	content;
  char		*_file;
public:
  virtual ~Io();
  Io(char *file);

  virtual void	readInput();
  virtual void	putFileInList(std::ifstream &file);
  virtual void	putInputInList();
  virtual std::list<std::string> getList();
};

#endif


