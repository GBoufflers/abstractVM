#include	"../headers/Io.hh"

Io::Io()
{

}

Io::~Io()
{

}

void	Io::putFileInList(std::ifstream &file)
{
  if(file)
    {
      std::string	content;
      while(std::getline(file, content))
	{
	  this->content.push_back(content);
	  std::cout << content << std::endl;
	}
    }
}

void	Io::putInputInList()
{
  std::string	input_line;
  while(input_line != ";;") 
    {
      getline(std::cin, input_line);
      std::cout << input_line << std::endl;
    }
}

void	Io::readInput(char *file)
{
  std::ifstream fichier(file, std::ios::in);

  if (file == NULL)
    putInputInList();
  else if(fichier)
    putFileInList(fichier);
  else
    std::cerr << file <<  " : no such file found " << std::endl;
}
  
  
