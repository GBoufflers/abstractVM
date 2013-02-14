#ifndef __BIOS_HH__
#define __BIOS_HH__

#include	"IBios.hh"

class		Bios : public IBios
{
public:
  Bios();
  virtual ~Bios();
  
  IOperand *createInt32(const std::string & value);
  IOperand *createInt16(const std::string & value);
  IOperand *createInt8(const std::string & value);
  IOperand *createFloat(const std::string & value);
  IOperand *createDouble(const std::string & value);
  IOperand *createOperand(eOperandType type, const std::string & value);
};

#endif
