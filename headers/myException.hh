#ifndef __MYEXCEPTION_HH__
#define __MYEXCEPTION_HH__

#include	<stdexcept>
#include	<sstream>
#include	<iostream>
#include	<list>
#include	<string>

class myException : public std::exception
{
  std::string msg;
public:
  myException(int line = 0, const char * Msg, std::list<std::string> *instr = NULL)
  {
    if (instr)
      {
	for (std::list<std::string>::const_iterator it = instr->begin(); it != instr->end(); ++it)
	    std::cout << *it << std::endl;
      }
    std::ostringstream oss;
    if (line != 0)
      oss <<  Msg << " à la ligne " << line << std::endl;
    else
      oss << Msg << std::endl;
    this->msg = oss.str();
  }
  
  virtual ~myException() throw()
  {
    
  }
  
  virtual const char * what() const throw()
  {
    return this->msg.c_str();
  }
};

#endif
