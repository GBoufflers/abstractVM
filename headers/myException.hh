#include	"genException.hh"

#ifndef	        __MYEXCEPTION_HH__
#define		__MYEXCEPTION_HH__

class genException
{
public:
  class lexicalException : public myException
  {
  public:
    lexicalException(const char *msg, int line = 0) : myException(msg, line, NULL)
    {
      
    }
    
    virtual ~lexicalException() throw()
    {
      
    }
  };
  
  class executionException : public myException
  {
  public:
    executionException( const char *msg, std::list<std::string> *list = NULL) : myException(msg, 0, list)
    {
      
    }
    
    virtual ~executionException() throw()
    {
      
    }
  };
  
};

#endif
