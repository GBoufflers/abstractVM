#include		<iostream>
#include		<sstream>
#include		<string>
#include		"../headers/Bios.hh"
#include		"../headers/IOperand.hh"
#include		<tuple>

int	main(int ac, char **av)
{
  Bios	a;

  a.createOperand(Int8, "lol");
  return (0);
}
