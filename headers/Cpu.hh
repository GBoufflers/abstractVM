#ifndef __CPU_HH__
#define __CPU_HH__

#include	<list>
#include	<string>
#include	"ICpu.hh"
#include	"Operand.hpp"
#include	"Memory.hh"

class	Cpu
{
  Memory		*_mem;
  std::list<string>	_res;
  std::list<string>	&_instruction;

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
