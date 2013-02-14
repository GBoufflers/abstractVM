#ifndef __IIO_HH__
#define __IIO_HH__

class		IIo
{
public:
  virtual void	dump() const = 0 ;
  virtual void	print() const = 0;
  virtual ~IIo(){};
};

#endif
