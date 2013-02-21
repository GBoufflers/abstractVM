#include	<string>
#include	"../headers/Memory.hh"
#include	"../headers/IOperand.hh"

Memory::Memory()
{

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

IOperand		*Memory::mFrontGet()
{
  if (this->myStackEmpty() == false)
    std::cout << "empty stack "<< std::endl;
  //else
  return (this->mem.front());
}

void			Memory::mFrontPop()
{
  if (this->myStackEmpty() == false)
    std::cout << "empty stack "<< std::endl;
  //else
  return (this->mem.pop_front());
}

void			Memory::mFrontPush(IOperand *n)
{
  std::cout << "on push la mere a flo" << std::endl;
  this->mem.push_front(n);
  std::cout << "c'était trpop bon" << std::endl;
  for (std::list<IOperand *>::const_iterator it = mem.begin(); it != mem.end(); ++it)
    {
      IOperand *tmp = *it;    
      std::cout << tmp->toString() << std::endl;
    }
}
