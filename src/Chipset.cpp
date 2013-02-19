#include	"../headers/Chipset.hh"
#include	<algorithm>

Chipset::Chipset(std::list<std::string> &list) : file(list)
{
  initMap();
  parseList();
}

Chipset::~Chipset()
{

}

void	Chipset::initMap()
{
  this->verifInstruct["push"] = 1;
  this->verifInstruct["pop"] = 0;
  this->verifInstruct["assert"] = 1;
  this->verifInstruct["add"] = 0;
  this->verifInstruct["sub"] = 0;
  this->verifInstruct["mul"] = 0;
  this->verifInstruct["div"] = 0;
  this->verifInstruct["mod"] = 0;
  this->verifInstruct["print"] = 0;
  this->verifInstruct["exit"] = 0;
}

void Chipset::parseList()
{
  for (std::list<std::string>::const_iterator it = file.begin(); it != file.end(); ++it)
    {
      std::string tmp = *it;
      int	nb = tmp.find(")");
      std::cout << nb << std::endl;

      //std::string str2 = file.substr(0,12);
    }
   
}

std::list<std::string>	Chipset::getInstruction()
{

}
