
#include		<sstream>


#include		"../headers/IOperand.hh"
#include		"../headers/Io.hh"
#include		"../headers/Chipset.hh"
#include		"../headers/myException.hh"



void	avm(char *file)
{
  Io	a(file);

  std::list<std::string> lol = a.getList();
  Chipset	b(lol);
}

int	main(int ac, char **av)
{
  if (ac != 1 && ac != 2)
    {
    std::cerr << "Usage : ./avm | ./avm file" << std::endl;
    return (0);
    }
  (ac == 2) ? avm(av[1]) : avm(NULL);
}
