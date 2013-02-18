#include	"../headers/Memory.hh"

#include	<string>

Memory::Memory()
{
  std::cout << "nous sommes dans memory" << std::endl;
}

Memory::~Memory()
{

}

std::stack<IOperand *>	Memory::getPile() const
{
  return(this->mem);
}

void			Memory::setPile(std::stack<IOperand *> & mem)
{
  this->mem = mem;
}
