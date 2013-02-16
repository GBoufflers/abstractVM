#ifndef			__OPERAND_HPP__
#define			__OPERAND_HPP__

#include		<iostream>
#include		<sstream>
#include		<string>
#include		"Bios.hh"
#include		"IOperand.hh"

template<class T> 
class	Operand : public IOperand
{
private:
  Bios					b;
  std::string  				_value;
  int					_prec;
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

  template <typename U>
  std::string				NumberToString(U Number)
  {
    std::stringstream ss;

    ss << Number;
    return (ss.str());
  }

  template <typename U>
  U					StringToNumber(const std::string &Text)
  {                               
    std::stringstream ss(Text);
    U result;

    if (!(ss >> result))
      result = 0; // a changer par une exception je pense
  }

  /*************/
  int					getPrecision() const
  {
    return (_prec);
  }

  eOperandType				getType() const
  {
    return (this->_type);
  }

  /*************/
  IOperand				*operator+(const IOperand &rhs) const
  {
    /*
      IOperand				*n;
      eOperandType			tmp;

      tmp = this->getType();
      if (this->getType() < rhs.getType())
      tmp = rhs.getType();
    */
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
