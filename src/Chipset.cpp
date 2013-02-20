#include	"../headers/Chipset.hh"
#include	"../headers/myException.hh"
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
  std::cout << nbr << std::endl;
  int	a = nbr.find("-");


  (a != -1 && a != 0) ? throw myException("Erreur de syntaxe sur le nombre") : nbr = nbr;
  if (a == 0)
    nbr = nbr.substr(1, nbr.size() - 1);
  std::cout << nbr << std::endl;
  if (entier == 1)
    {
      int found = nbr.find_first_not_of("0123456789");
      (found != -1 && found != 0) ? throw myException("Erreur de syntaxe sur le nombre") : param.clear();
      return (param = nbr);
    }
  else if (entier == 0)
    {
      
    }
}

void	Chipset::checkComplex(std::string &instr, std::string &line)
{
  std::string	tmp = line.substr(0, instr.size());
  std::string	param(""), type(""), typeV(" ");
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
  c = type.size() + typeV.size() - 1;
  tmp = line.substr(c);
  c = tmp.find(')');
  tmp = tmp.substr(0, c + 1);
  std::string::iterator it = tmp.begin();
  (*it == '(' && tmp.size() >= 3) ? (param = checkParam(tmp, a)) : (throw myException("Erreur de syntaxe sur le parametre"));
  std::cout << "c'est un " << type << " qui a pour valeur " << param << std::endl;

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
  (a == -1) ? (throw myException("Synxtaxe incorrect")) : (a = a);
  if (verif[inst] == 0)
    return (checkSimple(inst, line));
  else
    return (checkComplex(inst, line));
}

void	Chipset::parseList(std::string &line)
{
  int	nb = 0;

  if((nb = this->checkComa(line, '\0')) == 1)
    return ((void)this->final.push_back(""));
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
