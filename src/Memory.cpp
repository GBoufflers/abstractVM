#include	"../headers/Memory.hh"

Memory::Memory()
{

}

Memory::~Memory()
{

}

std::stack<IOperand *>	&Memory::getPile()
{
  return (this->mem);
}

void			Memory::setPile(std::stack<IOperand *> & mem)
{
  this->mem = mem;
}
