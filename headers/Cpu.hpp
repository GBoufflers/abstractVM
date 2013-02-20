#ifndef __CPU_HH__
#define __CPU_HH__

#include	<list>
#include	<vector>
#include	<map>
#include	<string>
#include	"Operand.hpp"
#include	"Memory.hh"

class	Cpu
{
  void					(Cpu::*creation[9])();
  Memory				*_mem;
  std::multimap<std::string, int>	mmap;
  std::list<std::string>		_res;
  std::list<std::string>		&_instruction;

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

  void	assert(std::vector<std::string> fields);
  void	push(std::vector<std::string> fields);

  /***************/

  void	doDump();
  void	makePtrFunc(std::string &func);
  void	execInstruct();
  void	pushInList(std::string &str);
  std::vector<std::string> split(char delim, std::string work);
  int	exec(std::string func, std::vector<std::string> fields);
  void	initPtrFunc();
  void	initMap();
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

void	Cpu::assert(std::vector<std::string> fields)
{ 
  IOperand	*op;
  Bios		*bios;
  eOperandType	type;
  bool		ret;
  
  bios = new Bios;
  if (fields[1] == "Int8")
    type = Int8;
  else if (fields[1] == "Int16")
    type = Int16;
  else if (fields[1] == "Int32")
    type = Int32;
  else if (fields[1] == "Float")
    type = Float;
  else
    type = Double;
  op = bios->createOperand(type, fields[2]);
  ret = (op == this->_mem->mFrontGet());
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
}

void	Cpu::push(std::vector<std::string> fields)
{
  Bios		bios;
  eOperandType	type;
  
  if (fields[1] == "Int8")
    type = Int8;
  else if (fields[1] == "Int16")
    type = Int16;
  else if (fields[1] == "Int32")
    type = Int32;
  else if (fields[1] == "Float")
    type = Float;
  else
    type = Double;
  this->_mem->mFrontPush(bios.createOperand(type, fields[2]));
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

void	Cpu::initPtrFunc()
{
  this->creation[0] = &Cpu::add;
  this->creation[1] = &Cpu::sub;
  this->creation[2] = &Cpu::mul;
  this->creation[3] = &Cpu::div;
  this->creation[4] = &Cpu::mod;
  this->creation[5] = &Cpu::exit;
  this->creation[6] = &Cpu::pop;
  this->creation[7] = &Cpu::dump;
  this->creation[8] = &Cpu::print;
}

void	Cpu::initMap()
{
  this->mmap.insert(std::pair<std::string ,int>("add", 0));
  this->mmap.insert(std::pair<std::string ,int>("sub", 1));
  this->mmap.insert(std::pair<std::string ,int>("mul", 2));
  this->mmap.insert(std::pair<std::string ,int>("div", 3));
  this->mmap.insert(std::pair<std::string ,int>("mod", 4));
  this->mmap.insert(std::pair<std::string ,int>("exit", 5));
  this->mmap.insert(std::pair<std::string ,int>("pop", 6));
  this->mmap.insert(std::pair<std::string ,int>("dump", 7));
  this->mmap.insert(std::pair<std::string ,int>("print", 8));
}

int	Cpu::exec(std::string func, std::vector<std::string> fields)
{
  std::multimap<std::string,int>::iterator it;
  int		ret = -1;

  func = fields.front();
  for (it = this->mmap.begin(); it != this->mmap.end(); ++it)
    {
      if ((*it).first == func)
	{
	  ret = (*it).second;
	  (this->*creation[ret])();
	  return (ret);
	}
    }
  return (-1);
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
      if (exec(fields.front(), fields) == -1)
	{
	  if (fields.front() == "assert")
	    this->assert(fields);
	  else
	    this->push(fields);
	}
      this->_instruction.pop_front();
    }
  this->doDump();
}

#endif
