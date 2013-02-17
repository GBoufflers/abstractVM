#include	"../headers/Bios.hh"

#define		Int8	char
#define		Int16	signed short
#define		Int32	signed int
#define		Double	double
#define		Float	float

Bios::Bios()
{
  initTab();
  std::cout << "on est dans le bios" << std::endl;
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
  return (new Operand<Int8>());
}

IOperand *	Bios::createInt16(const std::string & value)
{
  return (new Operand<Int16>());
}

IOperand *	Bios::createInt32(const std::string & value)
{
  return (new Operand<Int32>());
}

IOperand *	Bios::createFloat(const std::string & value)
{
  return (new Operand<Float>());
}

IOperand *	Bios::createDouble(const std::string & value)
{
  return (new Operand<Double>());
}

IOperand *	Bios::createOperand(eOperandType type, const std::string &value)
{
  int		a = 0;

  if (type >= 0 && type <= 4)
    return ((this->*creation[type])(value));
}

IOperand *Bios::Sinit(eOperandType type, const std::string &value)
{
  Bios a;

  a.createOperand(type, value);
}
