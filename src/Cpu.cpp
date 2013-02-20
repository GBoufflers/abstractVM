#include	"../headers/Cpu.hh"

Cpu::Cpu()
{

}

Cpu::~Cpu()
{

}

void	Cpu::exit()
{
  exit(0);
}

void	Cpu::pop()
{
  this->_mem->mFrontPop();
}

void	Cpu::dump()
{
  /*
    while (pas la fin)
    {
    get de la memory
    get back de la memory
    push frontdans la memoir
    pop back
    }
  */
}

void	Cpu::assert(IOperand *op)
{
  bool ret = op = this->_mem->mFrontGet();

  if (ret == false)
    ;
  else
    ;
}

void	Cpu::print()
{
  IOperant		*n;
  std::stringstream	ss;
  char			c;

  n = this->_mem->mFrontGet();
  if (n->getType() == Int8)
    {
      ss = n->toString();
      ss >> c;
      std::cout << c << std::endl;
    }
  else
    {
      n->setType(Int8);
      this->assert(n);
    }
}

void	Cpu::push(std::string &instruct)
{
  std::string	value;
  eOperandType	type;
  
  this->_mem->mFrontPush(createOperand(type, value));
}

void	Cpu::add()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  n1 = this->_mem->pop();
  n2 = this->_mem->mFrontGet();
  n2 = this->_mem->pop();
  n = n1 + n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::sub()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  n1 = this->_mem->pop();
  n2 = this->_mem->mFrontGet();
  n2 = this->_mem->pop();
  n = n1 - n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::mul()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  n1 = this->_mem->pop();
  n2 = this->_mem->mFrontGet();
  n2 = this->_mem->pop();
  n = n1 * n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::div()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  n1 = this->_mem->pop;
  n2 = this->_mem->mFrontGet();
  n2 = this->_mem->pop;
  n = n1 / n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::mod()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  n1 = this->_mem->pop;
  n2 = this->_mem->mFrontGet();
  n2 = this->_mem->pop;
  n = n1 % n2;
  this->_mem->mFrontPush(n);
}

void	Cpu::execInstruct()
{
  
}
