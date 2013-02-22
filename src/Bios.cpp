#include	"../headers/Bios.hh"
#include	"../headers/enum.hh"
#include	"../headers/Operand.hpp"

// #define		Int8	char
// #define		Int16	signed short
// #define		Int32	signed int
// #define		Double	double
// #define		Float	float

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
  eOperandType	t = Int8;
  return (new Operand<char>(value, t));
}

IOperand *	Bios::createInt16(const std::string & value)
{
  eOperandType	t = Int16;
  return (new Operand<signed short>(value, t));
}

IOperand *	Bios::createInt32(const std::string & value)
{
  eOperandType	t = Int32;
  return (new Operand<signed int>(value, t));
}

IOperand *	Bios::createFloat(const std::string & value)
{
  eOperandType	t = Float;
  return (new Operand<float>(value, t));
}

IOperand *	Bios::createDouble(const std::string & value)
{
  eOperandType	t = Double;
  return (new Operand<double>(value, t));
}

IOperand *	Bios::createOperand(eOperandType type, const std::string &value)
{
  //  std::cout << value << std::endl;
  if (type >= 0 && type <= 4)
    return ((this->*creation[type])(value));
  return NULL;
}
