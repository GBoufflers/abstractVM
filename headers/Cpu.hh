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
  std::map<std::string, int>	mmap;
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
  int	exec(std::string func);
  void	initPtrFunc();
  void	initMap();
};

#endif
