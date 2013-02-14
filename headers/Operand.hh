#ifndef			__OPERAND_HH__
#define			__OPERAND_HH__

#include		"IOperand.hh"
 
class	Operand : public IOperand
{
public:
  Operand();
  ~Operand();
  /*************/
  std::string const			&toString() const // Renvoie une string reprensentant l'instance
  /*************/
  int					getPrecision() const // Renvoie la precision du type de l'instance
  eOperandType				getType() const // Renvoie le type de l'instance. Voir plus bas
  /*************/
  IOperand				*operator+(const IOperand &rhs) const; // Somme
  IOperand				*operator-(const IOperand &rhs) const; // Difference
  IOperand				*operator*(const IOperand &rhs) const; // Produit
  IOperand				*operator/(const IOperand &rhs) const; // Quotient
  IOperand				*operator%(const IOperand &rhs) const; // Modulo
}

#endif
