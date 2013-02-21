#include	"../headers/Bios.hh"
#include	"../headers/enum.hh"
#include	"../headers/Operand.hpp"

#define		Int8	char
#define		Int16	signed short
#define		Int32	signed int
#define		Double	double
#define		Float	float

Bios::Bios()
{
  initTab();

}

Bios::~Bios()
{

}

void		Bios::initTab()
{
  this->creation[0] = &Bios::createInt8;
  this->creation[1] = &Bios::createInt16;
  this->creation[2] = &Bios::createInt32;
  this->creation[3] = &Bios::createFloat;
  this->creation[4] = &Bios::createDouble;
}

IOperand *	Bios::createInt8(const std::string & value)
{
  return (new Operand<Int8>(value));
}

IOperand *	Bios::createInt16(const std::string & value)
{
  return (new Operand<Int16>(value));
}

IOperand *	Bios::createInt32(const std::string & value)
{
  return (new Operand<Int32>(value));
}

IOperand *	Bios::createFloat(const std::string & value)
{
  return (new Operand<Float>(value));
}

IOperand *	Bios::createDouble(const std::string & value)
{
  return (new Operand<Double>(value));
}

IOperand *	Bios::createOperand(eOperandType type, const std::string &value)
{
  if (type >= 0 && type <= 4)
    return ((this->*creation[type])(value));
  return NULL;
}
