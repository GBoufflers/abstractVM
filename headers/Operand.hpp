#ifndef			__OPERAND_HH__
#define			__OPERAND_HH__

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
