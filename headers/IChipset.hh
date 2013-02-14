class	IChipset
{
public:
  virtual std::list<string> putInList(ostream file) = 0;
  // 
  virtual ~IChipset();
}
