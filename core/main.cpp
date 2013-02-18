#include		<iostream>
#include		<sstream>
#include		<string>
#include		"../headers/Bios.hh"
#include		"../headers/IOperand.hh"
#include		"../headers/Memory.hh"
#include		"../headers/myException.hh"
#include		<stdexcept>
#include		<vector>

int	main(int ac, char **av)
{
  Memory	a;
  Bios		b;
  std::list<IOperand *>	lol;

  lol = a.getPile();
  lol.push_back(b.createOperand(Int8, "45"));
  std::cout << "dans la liste lol nous avons " << lol.size() << std::endl;
  a.setPile(lol);
  std::cout << "dans la memoire nous avons " << a.getPile().size() << std::endl;
  lol.pop_back();
  a.setPile(lol);
  std::cout << "dans la memoire nous avons " << a.getPile().size() << std::endl;
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
}
