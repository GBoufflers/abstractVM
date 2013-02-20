#ifndef __CPU_HH__
#define __CPU_HH__

#include	<list>
#include	<string>
#include	"Operand.hpp"
#include	"Memory.hh"

class	Cpu
{
  Memory		*_mem;
  std::list<std::string>	_res;
  std::list<std::string>	&_instruction;

public:
  Cpu(std::list<std::string> &);
  virtual ~Cpu();

  /*******************/
  template <typename T>
  void	add();
  template <typename T>
  void	sub();
  template <typename T>
  void	mul();
  template <typename T>
  void	div();
  template <typename T>
  void	mod();
  void	exit();
  void	pop();
  void	dump();
  void	assert(IOperand *op);
  void	push(std::string &instruct);
  void	print();
  void	doDump();
  void	makePtrFunc(std::string &func);
  void	execInstruct();
  void	pushInList(std::string &str);
};

Cpu::Cpu(std::list<std::string> &instructs) : _instruction(instructs)
{

}

Cpu::~Cpu()
{

}

void	Cpu::exit()
{
  exit();
}

void	Cpu::pop()
{
  this->_mem->mFrontPop();
}

void	Cpu::pushInList(std::string &str)
{
  this->_res.push_front(str);
}

void	Cpu::dump()
{
  std::string		str;
  std::list<IOperand *>	nnew;
  IOperand		*n;

  nnew = this->_mem->getPile();
  while (!nnew.empty())
    {
      n = nnew.back();//get back de la memory
      nnew.pop_back();//pop back
      str = n->toString();
      this->pushInList(str);
    }
}

void	Cpu::doDump()
{
  for (std::list<std::string>::const_iterator it = this->_res.begin(); it != this->_res.end(); ++it)
    std::cout << *it << std::endl;
}

void	Cpu::assert(IOperand *op)
{
  bool ret = op = this->_mem->mFrontGet();

  if (ret == false)
    ;
}

void	Cpu::print()
{
  std::string		str;
  IOperand		*n;
  std::stringstream	ss;

  n = this->_mem->mFrontGet();
  if (n->getType() == Int8)
    {
      str = n->toString();
      this->pushInList(str);
    }
  else
    {
      n->setType(Int8);
      this->assert(n);
    }
}

void	Cpu::push(std::string &instruct)
{
  Bios		bios;
  std::string	value;
  eOperandType	type;
  
  this->_mem->mFrontPush(bios.createOperand(type, value));
}

template <typename T>
void	Cpu::add()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n = new Operand<T>;
  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

template <typename T>
void	Cpu::sub()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n = new Operand<T>;
  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

template <typename T>
void	Cpu::mul()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n = new Operand<T>;
  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

template <typename T>
void	Cpu::div()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n = new Operand<T>;
  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

template <typename T>
void	Cpu::mod()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n = new Operand<T>;
  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}



void	Cpu::makePtrFunc(std::string &func)
{

}

void	Cpu::execInstruct()
{
  /*  std::vector<std::string>	fields;
      int			size;

      this->initMap();
      while (!(this->_instruction.empty()))
      {
      split(fields, this->_instruction.front(), is_any_of( "," ));
      size = fields.size();
      if (size == 1)
      makePtrFunc(fields.front());
      this->_instruction.pop_front();
      }
      this->doDump();*/
}

#endif
