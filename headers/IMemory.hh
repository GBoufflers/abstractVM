class	IMemory
{
public:
  virtual std::stack &getPile() const = 0;
  virtual setPile(std::stack &)  = 0;
  virtual ~IMemory();
}
