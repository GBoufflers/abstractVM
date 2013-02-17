#include		<iostream>
#include		<sstream>
#include		<string>
#include		"../headers/Bios.hh"
#include		"../headers/IOperand.hh"

int	main(int ac, char **av)
{
  Bios	a;

  a.createOperand(Int8, "lol");
  return (0);
}
