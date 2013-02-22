#ifndef __BIOS_HH__
#define __BIOS_HH__

#include	<string>
#include	"IBios.hh"
#include	"enum.hh"

class		Bios : public IBios
{
  IOperand *createInt32(const std::string & value);
  IOperand *createInt16(const std::string & value);
  IOperand *createInt8(const std::string & value);
  IOperand *createFloat(const std::string & value);
  IOperand *createDouble(const std::string & value);
  IOperand *(Bios::*creation[5])(const std::string &);
public:
  Bios();
  virtual ~Bios();

  IOperand *createOperand(eOperandType type, const std::string & value);
  void	   checkFlowian(const std::string &svalue, long double max, long double min);
  virtual void	initTab();
};

#endif
