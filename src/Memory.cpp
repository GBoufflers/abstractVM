#include	<string>
#include	"../headers/Memory.hh"
#include	"../headers/IOperand.hh"

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

bool			Memory::myStackEmpty() const
{
  return (this->mem.empty());
}

int			Memory::myStackSize() const
{
  return (this->mem.size());
}

IOperand		*Memory::mFrontPop(int pos)
{
  int	i;

  i = 1;
  if (this->myStackEmpty() == false)
    std::cout << "empty stack "<< std::endl;
  else if (this->myStackSize() < 2)
    std::cout << "stack not enough big"<< std::endl;
  else
    for (std::list<IOperand *>::iterator it = this->mem.begin(); it != this->mem.end(); ++it)
      {
	if (i == pos)
	  return (*it);
      }
}

void			Memory::mFrontPush(IOperand *n)
{
  this->mem.push_front(n);
}
