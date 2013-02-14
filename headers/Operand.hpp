#ifndef			__OPERAND_HHP__
#define			__OPERAND_HHP__

#include		<string>
#include		"IOperand.hh"

template<class T> 
class	Operand : public IOperand
{
private:
  T					_value;
  eOperandType				_type;
public:
  Operand()
  {
    std::cout << "on est arrivé dans les operandes "  << std::endl;
  }

  virtual ~Operand()
  {

  }

  /*************/
  std::string const			&toString() const
  {

  }

  /*************/
  int					getPrecision() const
  {

  }

  eOperandType				getType() const
  {

  }

  /*************/
  IOperand				*operator+(const IOperand &rhs) const
  {

  }

  IOperand				*operator-(const IOperand &rhs) const
  {

  }

  IOperand				*operator*(const IOperand &rhs) const
  {

  }

  IOperand				*operator/(const IOperand &rhs) const
  {

  }

  IOperand				*operator%(const IOperand &rhs) const
  {

  }
};

#endif
