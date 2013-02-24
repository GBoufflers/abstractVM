#ifndef __CPU_HH__
#define __CPU_HH__

#include	<list>
#include	<vector>
#include	<map>
#include	<string>
#include	"Operand.hpp"
#include	"Io.hh"
#include	"Memory.hh"

class	Cpu
{
  void					(Cpu::*creation[9])();
  Io					*_io;
  Memory				*_mem;
  std::map<std::string, int>		_mmap;
  std::map<std::string, eOperandType>	_checkType;
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
  void	pop();
  void	dump();
  void	print();

  /**************/

  void	assert(std::vector<std::string> fields);
  void	push(std::vector<std::string> fields);

  /***************/

  void	makePtrFunc(std::string &func);
  void	execInstruct();
  void	pushInList(std::string &str);
  std::vector<std::string> split(char delim, std::string work);
  int	exec(std::string func, int *isDumpToDo);
  void	initPtrFunc();
  void	initMaps();
  eOperandType	whatIsTheType(std::string func) const;
};

#endif
