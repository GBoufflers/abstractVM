#ifndef __IIO_HH__
#define __IIO_HH__

#include	<iostream>
#include	<fstream>
#include	<list>

class		IIo
{
public:
  /*  virtual void	dump() const = 0 ;
      virtual void	print() const = 0;*/
  virtual void	readInput(char *file) = 0;
  virtual void  putFileInList(std::ifstream &file) = 0;
  virtual void  putInputInList() = 0;
  virtual ~IIo(){};
};

#endif
