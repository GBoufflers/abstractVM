#include		"../headers/Operand.hh"

template <typename T>
Operand<T>::Operand()
{

}

template <typename T>
Operand<T>::~Operand()
{

}

template <typename T>
std::string const			&Operand<T>::toString() const // Renvoie une string reprensentant l'instance
{
  
}

template <typename T>
int					Operand<T>::getPrecision() const // Renvoie la precision du type de l'instance
{
  return (0);
}

template <typename T>
eOperandType				Operand<T>::getType() const// Renvoie le type de l'instance. Voir plus bas
{
  return (Int8);
}

template <typename T>
IOperand				*Operand<T>::operator+(const IOperand &rhs) const // Somme
{
  return (NULL);
}

template <typename T>
IOperand				*Operand<T>::operator-(const IOperand &rhs) const // Difference
{
  return (NULL);
}

template <typename T>
IOperand				*Operand<T>::operator*(const IOperand &rhs) const// Produit
{
  return (NULL);
}

template <typename T>
IOperand				*Operand<T>::operator/(const IOperand &rhs) const //Quotient
{
  return (NULL);
}

template <typename T>
IOperand				*Operand<T>::operator%(const IOperand &rhs) const // Modulo
{
  return (NULL);
}
