#include	"../headers/Cpu.hh"

Cpu::Cpu(std::list<std::string> &instructs) : _instruction(instructs)
{
   this->_mem = new Memory();
   initMap();
   initPtrFunc();
   execInstruct();
 }

 Cpu::~Cpu()
 {

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
    {
      std::string tmp = *it;
      std::cout << tmp << std::endl;
    }
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
    return;
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

  if (fields[1] == "int8")
    type = Int8;
  else if (fields[1] == "int16")
    type = Int16;
  else if (fields[1] == "int32")
    type = Int32;
  else if (fields[1] == "float")
    type = Float;
  else
    type = Double;
  this->_mem->mFrontPush(bios.createOperand(type, fields[2]));
}

std::vector<std::string> Cpu::split(char delim, std::string work) 
{
  std::vector<std::string> flds;
  std::string buf = "";
  work = work.data();
  size_t	i = 0;

  if (!flds.empty()) 
    flds.clear();
  while (i < work.length()) 
    {
      while (work[i] != delim && i < work.length() )
	{
	  buf += work[i];
	  i++;
	}
      flds.push_back(buf);
      buf = "";
      while (work[i] == delim && i < work.length() )
	i++;
    }
  return (flds);
}

void	Cpu::add()
{
  IOperand *n1;
  IOperand *n2;

  n1 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  n2 = this->_mem->mFrontGet();
  this->_mem->mFrontPop();
  this->_mem->mFrontPush(*n1 + *n2);
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
  this->creation[5] = &Cpu::pop;
  this->creation[6] = &Cpu::dump;
  this->creation[7] = &Cpu::print;
}

void	Cpu::initMap()
{
  this->mmap["add"] = 0;
  this->mmap["sub"] = 1;
  this->mmap["mul"] = 2;
  this->mmap["div"] = 3;
  this->mmap["mod"] = 4;
  this->mmap["pop"] = 5;
  this->mmap["dump"] = 6;
  this->mmap["print"] = 7;
}

int	Cpu::exec(std::string func, int *isDumpToDo)
{
  int		ret = -1;

  for (std::map<std::string,int>::const_iterator it = this->mmap.begin(); it != this->mmap.end(); ++it)
    {
      std::string tmp = it->first;
      if (tmp == func)
	{
	  ret = it->second;
	  if (ret == 6)
	    (*isDumpToDo) = 1;
	  (this->*creation[ret])();
	  return (ret);
	}
    }
  return (-1);
}

void	Cpu::execInstruct()
{
  int				next;
  int				isDumpToDo;
  std::string			str;
  std::vector<std::string>	fields;

  next = 0;
  isDumpToDo = 0;
  while (!(this->_instruction.empty()) && next == 0)
    {
      fields.clear();
      str.clear();
      str = this->_instruction.front();
      fields = split(' ', str);
      if (fields.front() == "exit")
	next = 1;
      else
	{
	  if (exec(fields.front(), &isDumpToDo) == -1)
	    {
	      if (fields.front() == "assert")
		this->assert(fields);
	      else
		this->push(fields);
	    }
	  this->_instruction.pop_front();
	}
    }
  if (isDumpToDo == 1)
    this->doDump();
}
