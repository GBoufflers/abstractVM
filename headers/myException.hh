#ifndef __MYEXCEPTION_HH__
#define __MYEXCEPTION_HH__

#include	<stdexcept>
#include	<sstream>

class myException : public std::exception
{
  std::string msg;
public:
  myException( const char * Msg, int line)
  {
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
