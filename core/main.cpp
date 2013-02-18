#include		<sstream>


#include		"../headers/IOperand.hh"
#include		"../headers/Io.hh"
#include		"../headers/myException.hh"



void	avm(char *file)
{
  Io	a;

  a.readInput(file);
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

  /*  try
    {
      int a;
      int	b  = 1;
      std::cout << "on est juste avant le calcul" << std::endl;
      
      (b == 0) ? throw myException("nous avons une valeur qui est egale à 0"):  a = 4 / b; //Un tableau bien trop grand      
      std::cout << a << std::endl;
    }
  catch ( const std::exception & e )
    {
      std::cerr << e.what() << "\n";
      }*/ 
