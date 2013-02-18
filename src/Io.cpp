#include	"../headers/Io.hh"

Io::Io()
{

}

Io::~Io()
{

}

char		*Io::readInput(char *file)
{
  std::ifstream fichier(file, std::ios::in);
  
  if (file == NULL)
    return (NULL);
  else if(fichier)
    return (file);
  else
    std::cerr << file <<  " : no such file found " << std::endl;
}
  
  
