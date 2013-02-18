#include		<iostream>
#include		<sstream>
#include		<string>
#include		"../headers/Bios.hh"
#include		"../headers/IOperand.hh"
#include		"../headers/Memory.hh"
#include		<stdexcept>
#include		<vector>

int	main(int ac, char **av)
{
  Memory	a;
  Bios		b;
  std::stack<IOperand *>	lol;

  lol = a.getPile();
  lol.push(b.createOperand(Int8, "45"));
  std::cout << "dans la liste lol nous avons " << lol.size() << std::endl;
  a.setPile(lol);
  std::cout << "dans la memoire nous avons " << a.getPile().size() << std::endl;
  lol.pop();
  a.setPile(lol);
    std::cout << "dans la memoire nous avons " << a.getPile().size() << std::endl;
  return (0);
  // 
  /*  try
    {
      int a;
      int	b  = 0;
      std::cout << "on est juste avant le calcul" << std::endl;
      (b == 0) ? throw std::exception():  a = 4 / b; //Un tableau bien trop grand      
      
      
      std::cout << "on a passé cette merde ouesh" << std::endl;
    }
  catch(std::exception const& e) //On rattrape les exceptions standard de tous types
    {
      std::cout << "lol" << std::endl;
      std::cerr << "ERREUR : " << e.what() << std::endl; //On affiche la description de l'erreur
      }*/
}
