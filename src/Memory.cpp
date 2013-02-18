#include	"../headers/Memory.hh"

#include	<string>

Memory::Memory()
{
  std::cout << "nous sommes dans memory" << std::endl;
}

Memory::~Memory()
{

}

std::list<IOperand *>	Memory::getPile() const
{
  return(this->mem);
}

void			Memory::setPile(std::list<IOperand *> & mem)
{
  this->mem = mem;
}
