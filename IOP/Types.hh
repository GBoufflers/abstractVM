#ifndef			__TYPES_HH__
#define			__TYPES_HH__

#include		<iostream>
#include		<string>
#include		"IOperand.hh"

namespace	Types
{
  class		Int8 : public IOperand
  {
  private:
    eOperandType			_type;
  public:
    Int8();
    virtual	~Int8();
    /***********************/
    virtual	std::string const	&toString() const;
    /***********************/
    virtual	int			getPrecision() const;
    virtual	eOperandType		getType() const;
    /***********************/
    virtual	IOperand		*operator+(const IOperand &rhs) const;
    virtual	IOperand		*operator-(const IOperand &rhs) const;
    virtual	IOperand		*operator*(const IOperand &rhs) const;
    virtual	IOperand		*operator/(const IOperand &rhs) const;
    virtual	IOperand		*operator%(const IOperand &rhs) const;
  };

  class		Int16 : public IOperand
  {
  private:
    eOperandType			_type;
  public:    
    Int16();
    virtual	~Int16();
    /***********************/
    virtual	std::string const	&toString() const;
    /***********************/
    virtual	int			getPrecision() const;
    virtual	eOperandType		getType() const;
    /***********************/
    virtual	IOperand		*operator+(const IOperand &rhs) const;
    virtual	IOperand		*operator-(const IOperand &rhs) const;
    virtual	IOperand		*operator*(const IOperand &rhs) const;
    virtual	IOperand		*operator/(const IOperand &rhs) const;
    virtual	IOperand		*operator%(const IOperand &rhs) const;
  };

  class		Int32 : public IOperand
  {
  private:
    eOperandType			_type;
  public:
    Int32();
    virtual	~Int32();
    /***********************/
    virtual	std::string const	&toString() const;
    /***********************/
    virtual	int			getPrecision() const;
    virtual	eOperandType		getType() const;
    /***********************/
    virtual	IOperand		*operator+(const IOperand &rhs) const;
    virtual	IOperand		*operator-(const IOperand &rhs) const;
    virtual	IOperand		*operator*(const IOperand &rhs) const;
    virtual	IOperand		*operator/(const IOperand &rhs) const;
    virtual	IOperand		*operator%(const IOperand &rhs) const;
  };

  class		Double : public IOperand
  {
  private:
    eOperandType			_type;
  public:
    Double();
    virtual	~Double();
    /***********************/
    virtual	std::string const	&toString() const;
    /***********************/
    virtual	int			getPrecision() const;
    virtual	eOperandType		getType() const;
    /***********************/
    virtual	IOperand		*operator+(const IOperand &rhs) const;
    virtual	IOperand		*operator-(const IOperand &rhs) const;
    virtual	IOperand		*operator*(const IOperand &rhs) const;
    virtual	IOperand		*operator/(const IOperand &rhs) const;
    virtual	IOperand		*operator%(const IOperand &rhs) const;
  };

  class		Float : public IOperand
  {
  private:
    eOperandType			_type;
  public:
    Float();
    virtual ~Float();
    /***********************/
    virtual	std::string const	&toString() const;
    /***********************/
    virtual	int			getPrecision() const;
    virtual	eOperandType		getType() const;
    /***********************/
    virtual	IOperand		*operator+(const IOperand &rhs) const;
    virtual	IOperand		*operator-(const IOperand &rhs) const;
    virtual	IOperand		*operator*(const IOperand &rhs) const;
    virtual	IOperand		*operator/(const IOperand &rhs) const;
    virtual	IOperand		*operator%(const IOperand &rhs) const;
  };
}

#endif
