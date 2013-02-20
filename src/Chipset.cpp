#include	"../headers/Chipset.hh"
#include	"../headers/myException.hh"
#include	"../headers/Cpu.hpp"
#include	<algorithm>

Chipset::Chipset(std::list<std::string> &list) : file(list)
{
  initMap();
  try
    {
      traverseList();
    }
  catch ( const std::exception & e ) { std::cerr << e.what();}
}

Chipset::~Chipset()
{

}

void	Chipset::initMap()
{
  this->verif["push"] = 1;
  this->verif["pop"] = 0;
  this->verif["assert"] = 1;
  this->verif["add"] = 0;
  this->verif["dump"] = 0;
  this->verif["sub"] = 0;
  this->verif["mul"] = 0;
  this->verif["div"] = 0;
  this->verif["mod"] = 0;
  this->verif["print"] = 0;
  this->verif["exit"] = 0;
  this->verifC["int8"] = 1;
  this->verifC["int16"] = 1;
  this->verifC["int32"] = 1;
  this->verifC["double"] = 0;
  this->verifC["float"] = 0;
}

int	Chipset::checkComa(std::string &line, char c)
{
  int	a = 0, b = 0;

  if ((a = line.find(";")) == -1)
    return (-1);
  std::string tmp = line.substr(0, a + 1);
  const char *str = tmp.c_str();
  a = 0;
  while (str[a] && str[a] != ';')
    {
      if (str[a] != ';' && str[a] != c)
	return (0);
      a++;
    }
  return (1);
}

std::string	&Chipset::checkParam(std::string &param, int entier)
{
  std::string	nbr = param.substr(1, param.size() - 2);
  std::string	sav(nbr);
  int	a = nbr.find("-"), b = 0;


  (a != -1 && a != 0) ? throw myException("Erreur de syntaxe sur le nombre") : nbr = nbr;
  if (a == 0)
    nbr = nbr.substr(1, nbr.size() - 1);
  if (entier == 1)
    {
      int found = nbr.find_first_not_of("0123456789");
      (found != -1 && found != 0) ? throw myException("Erreur de syntaxe sur le nombre") : param.clear();
      return (param = sav);
    }
  else if (entier == 0)
    {
      int found = nbr.find_first_not_of("0123456789.");
      (found != -1 && found != 0) ? throw myException("Erreur de syntaxe sur le nombre") : param.clear();
      a = nbr.find(".");
      (a == -1) ? throw myException("Erreur : la valeur du type n'est pas respectée") : b = nbr.rfind(".");
      (a != b) ? throw myException("Erreur : la valeur du type n'est pas respectée") : (a = b);
      ((a == 0 || a == (nbr.size() - 1))) ? throw myException("Erreur : la valeur du type n'est pas respectée") : param = sav;
      return (param);
    }
}

void	Chipset::checkComplex(std::string &instr, std::string &line)
{
  std::string	param(""), type(""), typeV(" "), tmp(line.substr(0, instr.size()));
  int		a = 0, b = 0, c = 0;

  (tmp != instr) ? (throw myException("Erreur de syntaxe sur l'instruction")) : tmp.clear();  //l'instruction est vérifié 
  for (std::map<std::string, int>::const_iterator it = verifC.begin(); it != verifC.end(); ++it)
    {
      if ((a = line.find(it->first)) != -1)
	{
	  type = it->first; a = it->second ; break;
	}
      b++;
    }
  (type == "") ? (throw myException("Erreur : le type n'existe pas")) : tmp = line.substr(instr.size(), type.size() + 1);
  typeV.append(type);
  (tmp != typeV) ? (throw myException("Erreur de syntaxe sur le type")) : tmp.clear();
  c = instr.size() + typeV.size();
  tmp = line.substr(c);
  c = tmp.find(')');
  tmp = tmp.substr(0, c + 1);
  std::string::iterator it = tmp.begin();
  (*it == '(' && tmp.size() >= 3) ? (param = checkParam(tmp, a)) : (throw myException("Erreur de syntaxe sur le parametre"));
  a = typeV.size() + instr.size() + tmp.size() + 2;
  type = line.substr(a, line.size() - a);
  a = checkComa(type, ' ');
  (a == 0) ? throw myException("Erreur de syntaxe après l'instruction") : line.clear();
}

void	Chipset::checkSimple(std::string &instr, std::string &line)
{
  std::string	tmp = line.substr(0, instr.size());
  int		a = 0;

  (tmp != instr) ? (throw myException("Erreur de syntaxe sur l'instruction")) : tmp.clear();
  tmp = line.substr(instr.size(), line.size() - instr.size());
  a = checkComa(tmp, ' ');
  (a == 0) ? throw myException("Erreur de syntaxe après l'instruction") : final.push_back(instr);
}

void	Chipset::checkInstruction(std::string &line)
{
  int	a = -1, b = 0;
  std::string	inst;

  for (std::map<std::string, int>::const_iterator it = verif.begin(); it != verif.end(); ++it)
    {
      if ((a = line.find(it->first)) != -1)
	{
	  inst = it->first; break;
	}
      b++;
    }
  //  std::cout << line << std::endl;
  (a == -1) ? (throw myException("Synxtaxe incorrect")) : (a = a);
  if (verif[inst] == 0)
    return (checkSimple(inst, line));
  else
    {
      checkComplex(inst, line);
      std::cout << line << std::endl;
      return ;
    }
}

void	Chipset::parseList(std::string &line)
{
  int	nb = 0;

  
  if((nb = this->checkComa(line, '\0')) == 1)
    return((void)this->final.push_back(""));//return ((void)this->final.push_back(""));
  checkInstruction(line);
}

void Chipset::traverseList()
{
  for (std::list<std::string>::const_iterator it = file.begin(); it != file.end(); ++it)
    {
      std::string tmp = *it;      
      this->parseList(tmp);
    }
}
