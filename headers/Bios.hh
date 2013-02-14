#ifndef __BIOS_HH__
#define __BIOS_HH__

#include	<string>
#include	"IBios.hh"
#include	"IOperand.hh"

class		Bios : public IBios
{
  IOperand	*(Bios::*creation[5])(const std::string &);
public:
  Bios();
  virtual ~Bios();
  
  IOperand *createInt32(const std::string & value);
  IOperand *createInt16(const std::string & value);
  IOperand *createInt8(const std::string & value);
  IOperand *createFloat(const std::string & value);
  IOperand *createDouble(const std::string & value);
  IOperand *createOperand(eOperandType type, const std::string & value);

  virtual void	initTab();
};

#endif
