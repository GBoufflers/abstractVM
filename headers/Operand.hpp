
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
  int					_prec;
  eOperandType				_type;
  Bios					*q;
public:
  Operand(const std::string &value)
  {
    std::cout << "nous avons créé une operande de valeur " << value << std::endl;
  }

  virtual ~Operand()
  {

  }

  /*************/
  std::string const			&toString() const
  {
    /*    T tmp;
	  tmp = this->_value;
    */
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
    IOperand				*n;
    eOperandType			t;

    t = this->getType();
    if (this->getType() < rhs.getType())
      t = rhs.getType();
    return(q->createOperand(Int8, "lol"));
  }

  IOperand *	Sinit(eOperandType type, const std::string &value)
  {
    
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
