#include		"../headers/Operand.hh"

template <class T>
Operand<T>::Operand()
{
  //  std::cout << "lol on est la " << std::endl;
}

template <class T>
Operand<T>::~Operand()
{

}

template <class T>
std::string const			&Operand<T>::toString() const // Renvoie une string reprensentant l'instance
{
  
}

template <class T>
int					Operand<T>::getPrecision() const // Renvoie la precision du type de l'instance
{
  return (0);
}

template <class T>
eOperandType				Operand<T>::getType() const// Renvoie le type de l'instance. Voir plus bas
{
  return (Int8);
}

template <class T>
IOperand				*Operand<T>::operator+(const IOperand &rhs) const // Somme
{
  return (NULL);
}

template <class T>
IOperand				*Operand<T>::operator-(const IOperand &rhs) const // Difference
{
  return (NULL);
}

template <class T>
IOperand				*Operand<T>::operator*(const IOperand &rhs) const// Produit
{
  return (NULL);
}

template <class T>
IOperand				*Operand<T>::operator/(const IOperand &rhs) const //Quotient
{
  return (NULL);
}

template <class T>
IOperand				*Operand<T>::operator%(const IOperand &rhs) const // Modulo
{
  return (NULL);
}
