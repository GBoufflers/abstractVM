#ifndef __CPU_HH__
#define __CPU_HH__

#include	<list>
#include	<vector>
#include	<string>
#include	"Operand.hpp"
#include	"Memory.hh"

class	Cpu
{
  void				(Cpu::*creation[9])();
  Memory			*_mem;
  std::list<std::string>	_res;
  std::list<std::string>	&_instruction;

public:
  Cpu(std::list<std::string> &);
  virtual ~Cpu();

  /*******************/
  void	add();
  void	sub();
  void	mul();
  void	div();
  void	mod();
  void	exit();
  void	pop();
  void	dump();
  void	print();

  /**************/

  void	assert(std::string &instruct);
  void	push(std::string &instruct);

  /***************/

  void	doDump();
  void	makePtrFunc(std::string &func);
  void	execInstruct();
  void	pushInList(std::string &str);
  std::vector<std::string> split(char delim, std::string work);
  void	exec(std::vector<std::string> fields);
  void	massign(IOperand *n1, IOperand *n2);
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
      n = nnew.back();
      nnew.pop_back();
      str = n->toString();
      this->pushInList(str);
    }
}

void	Cpu::doDump()
{
  for (std::list<std::string>::const_iterator it = this->_res.begin(); it != this->_res.end(); ++it)
    std::cout << *it << std::endl;
}

void	Cpu::assert(std::string &instruct)
{
  /*  IOperand *op;
      bool ret = (op = this->_mem->mFrontGet());

      if (ret == false)
      ;*/
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
}

void	Cpu::push(std::string &instruct)
{
  Bios		bios;
  std::string	value;
  eOperandType	type;
  
  this->_mem->mFrontPush(bios.createOperand(type, value));
}

std::vector<std::string> Cpu::split(char delim, std::string work) 
{
  std::vector<std::string> flds;
  work = work.data();
  std::string buf = "";
  int rep = 0;
  int i = 0;

  if (!flds.empty()) flds.clear();
  while (i < work.length()) 
    {
      if (work[i] != delim)
	buf += work[i];
      else if (rep == 1) 
	{
	  flds.push_back(buf);
	  buf = "";
	}
      else if (buf.length() > 0) 
	{
	  flds.push_back(buf);
	  buf = "";
	}
      i++;
    }
  if (!buf.empty())
    flds.push_back(buf);
  return (flds);
}

void	Cpu::massign(IOperand *n1, IOperand *n2)
{

}

void	Cpu::add()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  n = *n1 + *n2;
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

void	Cpu::sub()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  n = *n1 - *n2;
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

void	Cpu::mul()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  n = *n1 * (*n2);
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

void	Cpu::div()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  n = *n1 / *n2;
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

void	Cpu::mod()
{
  IOperand *n;
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  n = *n1 % *n2;
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(n);
}

void	Cpu::exec(std::vector<std::string> fields)
{
  if (fields[0] == "add")
    add();
  else if (fields[0] == "sub")
    sub();
  else if (fields[0] == "mul")
    mul();
  else if (fields[0] == "div")
    div();
  else if (fields[0] == "mod")
    mod();
  else if (fields[0] == "exit")
    exit();
  else if (fields[0] == "pop")
    pop();
  else if (fields[0] == "dump")
    dump();
  else if (fields[0] == "assert")
    assert(fields[1]);
  else if (fields[0] == "push")
    push(fields[1]);
  else
    print();
}

void	Cpu::execInstruct()
{
  std::string			str;
  std::vector<std::string>	fields;
  int				size;

  while (!(this->_instruction.empty()))
    {
      str = this->_instruction.front();
      fields = split(' ', str);
      size = fields.size();
      exec(fields);
      this->_instruction.pop_front();
    }
  this->doDump();
}

#endif
