#ifndef			__IOPERAND_HH__
#define			__IOPERAND_HH__

enum		eOperandType
  {
    Int8 = 0,
    Int16 = 1,
    Int32 = 2,
    Float = 3,
    Double = 4
  };

class	IOperand
{
public:
  virtual	std::string const	&toString() const = 0; // Renvoie une string reprensentant l’instance

  virtual	int			getPrecision() const = 0; // Renvoie la precision du type de l’instance
  virtual	eOperandType		getType() const = 0; // Renvoie le type de l’instance. Voir plus bas

  virtual	IOperand		*operator+(const IOperand &rhs) const = 0; // somme
  virtual	IOperand		*operator-(const IOperand &rhs) const = 0; // difference
  virtual	IOperand		*operator*(const IOperand &rhs) const = 0; // produit
  virtual	IOperand		*operator/(const IOperand &rhs) const = 0; // quotient
  virtual	IOperand		*operator%(const IOperand &rhs) const = 0; // modulo

  virtual	~IOperand(){}
};

#endif
