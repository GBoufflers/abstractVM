#ifndef			__OPERAND_HPP__
#define			__OPERAND_HPP__

#include		<iostream>
#include		<sstream>
#include		<string>
#include		"enum.hh"
#include		"Bios.hh"
#include		"IOperand.hh"

template<class T> 
class	Operand : public IOperand
{
private:
  T	  				_value;
  std::string				const & _svalue;
  int					_prec;
  eOperandType				_type;
  Bios					*_bios;

public:
  Operand(const std::string &value) : _svalue(value)
  {
    std::cout << "nous avons créé une operande de valeur " << value << std::endl;
  }

  virtual ~Operand()
  {

  }

  /*************/
  std::string const			&toString() const
  {
    return (this->_svalue);
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
    eOperandType			t;
    std::string l;
    T					val1, val2;

    l = "lol";
    t = this->getType();
    if (this->getType() < rhs.getType())
      t = rhs.getType();
    //    l = rhs.toString();
    //    return(this->_bios->createOperand(t, l));
  }

  /***************/

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
