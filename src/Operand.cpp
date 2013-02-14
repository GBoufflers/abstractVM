#include		"../headers/Operand.hh"

Operand::Operand()
{

}

Operand::~Operand()
{

}

std::string const			&Operand::toString() const // Renvoie une string reprensentant l'instance
{
  
}

int					Operand::getPrecision() const // Renvoie la precision du type de l'instance
{
  return (0);
}

eOperandType				Operand::getType() const// Renvoie le type de l'instance. Voir plus bas
{
  return (Int8);
}

IOperand				*Operand::operator+(const IOperand &rhs) const // Somme
{
  return (NULL);
}

IOperand				*Operand::operator-(const IOperand &rhs) const // Difference
{
  return (NULL);
}

IOperand				*Operand::operator*(const IOperand &rhs) const// Produit
{
  return (NULL);
}

IOperand				*Operand::operator/(const IOperand &rhs) const //Quotient
{
  return (NULL);
}

IOperand				*Operand::operator%(const IOperand &rhs) const // Modulo
{
  return (NULL);
}
