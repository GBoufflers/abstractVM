#ifndef __MYERROR_HH__
#define __MYERROR_HH__

#include	<stdexcept>

class myException : public std::exception
{
  std::string msg;
public:
  myException( const char * Msg)
  {
    std::ostringstream oss;
    oss << "Erreur : " << Msg << std::endl;
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
