#ifndef __ICPU_HH__
#define __ICPU_HH__

#include	<stack>
#include	<string>
#include	"IOperand.hh"

class	ICpu
{
public:
  
  virtual ~ICpu(){};
  /*******************/
  virtual void	add() = 0;
  virtual void	sub() = 0;
  virtual void	mul() = 0;
  virtual void	div() = 0;
  virtual void	mod() = 0;
  virtual void	exit() = 0;
  virtual void	pop() = 0;
  virtual void	assert(IOperand *) = 0;
  virtual void	push(IOperand *) = 0;
};

#endif
