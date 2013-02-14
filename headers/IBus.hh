class	IBus
{
public:
  virtual std::stack &getMemory() const = 0;
  virtual setMemory(std::stack &) const = 0;
  virtual ~IBus();
}
