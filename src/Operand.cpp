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

}

eOperandType				Operand::getType() const// Renvoie le type de l'instance. Voir plus bas
{

}

IOperand				*Operand::operator+(const IOperand &rhs) const // Somme
{

}

IOperand				*Operand::operator-(const IOperand &rhs) const // Difference
{

}

IOperand				*Operand::operator*(const IOperand &rhs) const// Produit
{

}

IOperand				*Operand::operator/(const IOperand &rhs) const //Quotient
{

}

IOperand				*Operand::operator%(const IOperand &rhs) const // Modulo
{

}
