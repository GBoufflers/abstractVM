#include	"../headers/Chipset.hh"
#include	"../headers/myException.hh"
#include	<algorithm>

Chipset::Chipset(std::list<std::string> &list) : file(list)
{
  initMap();
  traverseList();
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

void	Chipset::checkSimple(std::string &instr, std::string &line)
{
  std::string	tmp = line.substr(0, instr.size());
  int		a = 0;
  try
    {
      (tmp != instr) ? (throw myException("Erreur de syntaxe sur l'instruction")) : tmp.clear();
      tmp = line.substr(instr.size(), line.size() - instr.size());
      a = checkComa(tmp, ' ');
      (a == 0) ? throw myException("Erreur de syntaxe après l'instruction") : final.push_back(instr);
    }
  catch ( const std::exception & e ) { std::cerr << e.what();}
}

void	Chipset::checkInstruction(std::string &line)
{
  int	a = -1, b = 0;
  std::string	inst;

  try
    {
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
    }
  catch ( const std::exception & e ) { std::cerr << e.what();}
  
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
