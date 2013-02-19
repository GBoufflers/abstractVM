#include	"../headers/Cpu.hh"

Cpu::Cpu()
{

}

Cpu::~Cpu()
{

}

void	Cpu::add(IOperand *n1, IOperand *n2)
{
  IOperand *n;

  n = n1 + n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::sub(IOperand *n1, IOperand *n2)
{
  IOperand *n;

  n = n1 - n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::mul(IOperand *n1, IOperand *n2)
{
  IOperand *n;

  n = n1 * n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::div(IOperand *n1, IOperand *n2)
{
  IOperand *n;

  n = n1 / n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::mod(IOperand *n1, IOperand *n2)
{
  IOperand *n;

  n = n1 % n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::exit()
{
  exit (0);
}

void	Cpu::pop()
{
  this->_mem->mFrontPop();
}

void	Cpu::assert(IOperand *op)
{

}

void	Cpu::push(IOperand *op)
{

}
