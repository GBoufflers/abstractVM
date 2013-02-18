#ifndef __IBIOS_HH__
#define __IBIOS_HH__

#include	<string>
#include	"IOperand.hh"

class		IBios
{
  virtual IOperand *createInt32(const std::string & value) = 0;
  virtual IOperand *createInt16(const std::string & value) = 0;
  virtual IOperand *createInt8(const std::string & value) = 0;
  virtual IOperand *createFloat(const std::string & value) = 0;
  virtual IOperand *createDouble(const std::string & value) = 0;
public:
  virtual ~IBios() {};
  virtual IOperand *createOperand(eOperandType type, const std::string & value) = 0;

  virtual void	initTab() = 0;
};

#endif
