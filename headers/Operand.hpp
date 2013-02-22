#ifndef			__OPERAND_HPP__
#define			__OPERAND_HPP__

#include		<cmath>
#include		<iostream>
#include		<iomanip>
#include		<sstream>
#include		<string>
#include		"enum.hh"
#include		"Bios.hh"
#include		"IOperand.hh"
#include		"myException.hh"

template <class T> 
class	Operand : public IOperand
{
private:
  T	  				_value;
  std::string				_svalue;
  eOperandType				_type;
  Bios					*_bios;

public:
  Operand(const std::string &value, eOperandType t);
  virtual ~Operand();

  /*************/

  std::string const			&toString() const;

  /*************/

  int					getPrecision() const;
  eOperandType				getType() const;

  /*************/

  void					setType(eOperandType type);

  /*************/

  IOperand				*operator+(const IOperand &rhs) const;
  IOperand				*operator-(const IOperand &rhs) const;
  IOperand				*operator*(const IOperand &rhs) const;
  IOperand				*operator/(const IOperand &rhs) const;
  IOperand				*operator%(const IOperand &rhs) const;
};

template <typename T>
Operand<T>::Operand(const std::string &value, eOperandType t) : _svalue(value), _type(t)
{
  _bios = new Bios();
}

template <typename T>
Operand<T>::~Operand()
{

}

  /*************/

template <typename T>
std::string const			&Operand<T>::toString() const
{
  return (this->_svalue);
}

  /*************/

template <typename T>
int					Operand<T>::getPrecision() const
{
  std::string str2;
  int	pos;

  pos = _svalue.find('.');
  str2 = this->_svalue.substr(pos, _svalue.size() - 1);
  return (str2.size() - 1);
}

template <typename T>
eOperandType				Operand<T>::getType() const
{
  return (this->_type);
}

  /*************/

template <typename T>
void					Operand<T>::setType(eOperandType type)
{
  this->_type = type;
}
  /*************/

template <typename T>
IOperand				*Operand<T>::operator+(const IOperand &rhs) const
{ 
  eOperandType				t;
  std::string				resString;  
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  long double				res, val1, val2;
  int					prec;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 + val2;
  if (this->getType() == Float || rhs.getType() == Double)
    {
      prec = this->getPrecision();
      if (rhs.getPrecision() > prec)
	prec = rhs.getPrecision();
      ss << std::fixed << std::setprecision(prec) <<  res;
    }
  else
    ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return (this->_bios->createOperand(t, ss.str()));
}

  /***************/

template <typename T>
IOperand				*Operand<T>::operator-(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;  
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  long double				res, val1, val2;
  int					prec;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 - val2;
  if (this->getType() == Float || rhs.getType() == Double)
    {
      prec = this->getPrecision();
      if (rhs.getPrecision() > prec)
	prec = rhs.getPrecision();
      ss << std::fixed << std::setprecision(prec) <<  res;
    }
  else
    ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return (this->_bios->createOperand(t, ss.str()));

}

template <typename T>
IOperand				*Operand<T>::operator*(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;  
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  long double				res, val1, val2;
  int					prec;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 * val2;
  if (this->getType() == Float || rhs.getType() == Double)
    {
      prec = this->getPrecision();
      if (rhs.getPrecision() > prec)
	prec = rhs.getPrecision();
      ss << std::fixed << std::setprecision(prec) <<  res;
    }
  else
    ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return (this->_bios->createOperand(t, ss.str()));
}

template <typename T>
IOperand				*Operand<T>::operator/(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;  
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  long double				res, val1, val2;
  int					prec;

  ss1 >> val1;
  ss2 >> val2;
  if (val2 == 0)
    throw myException("Error : division by division !", 0);
  res = val1 / val2;
  if (this->getType() == Float || rhs.getType() == Double)
    {
      prec = this->getPrecision();
      if (rhs.getPrecision() > prec)
	prec = rhs.getPrecision();
      ss << std::fixed << std::setprecision(prec) <<  res;
    }
  else
    ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return (this->_bios->createOperand(t, ss.str()));
}


template <typename T>
IOperand				*Operand<T>::operator%(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;  
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  long int				res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  if (val2 == 0)
    throw myException("Error : modulo by division !", 0);
  res = val1 % val2;
  ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return (this->_bios->createOperand(t, ss.str()));
}

template <>
inline IOperand				*Operand<float>::operator%(const IOperand &rhs) const
{
  throw myException("Error : modulo with a foat which is not a valid operation", 0);
  std::string tmp = rhs.toString();
  return NULL;
}

template <>
inline IOperand				*Operand<double>::operator%(const IOperand &rhs) const
{
  throw myException("Error : modulo with a double which is not a valid operation", 0);
  std::string tmp = rhs.toString();
  return NULL;
}

#endif
