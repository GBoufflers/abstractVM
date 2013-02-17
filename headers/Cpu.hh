#ifndef __CPU_HH__
#define __CPU_HH__

#include	<stack>
#include	<string>
#include	"ICpu.hh"

class	Cpu
{
public:
  
  virtual ~Cpu();
  Cpu();
  /*******************/
  virtual void	add();
  virtual void	sub();
  virtual void	mul();
  virtual void	div();
  virtual void	mod();
  virtual void	exit();
  virtual void	pop();
  virtual void	assert(IOperand *);
  virtual void	push(IOperand *);
};

#endif
