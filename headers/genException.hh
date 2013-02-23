#ifndef __GENEXCEPTION_HH__
#define __GENEXCEPTION_HH__

#include	<stdexcept>
#include	<sstream>
#include	<iostream>
#include	<list>
#include	<string>

class genException : public std::exception
{
protected:
  std::string msg;
  const char *_Msg;
  int	&_line;
  std::list<std::string> *_instr;

public:
  genException(const char *Msg, int line = 0, std::list<std::string> *instr = NULL) :_Msg(Msg), _line(line), _instr(instr)
  {
    aff();
  }

  virtual ~genException() throw(){}

  virtual void aff()  throw()
  {
     if (_instr)
      {
	for (std::list<std::string>::const_iterator it = _instr->begin(); it != _instr->end(); ++it)
	  std::cout << *it << std::endl;
      }
    std::ostringstream oss;
    if (_line != 0)
      oss <<  _Msg << " à la ligne " << _line << std::endl;
    else
      oss << _Msg << std::endl;
    this->msg = oss.str();
  }
  
  virtual const char * what() const throw()
  {
    return this->msg.c_str();
  }

  
};

#endif
