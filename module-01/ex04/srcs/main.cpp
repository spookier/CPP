#include <string>
#include <iostream>
#include <fstream>


void find_and_replace(std::string line, const std::string &s1, const std::string &s2)
{
	size_t pos = line.find(s1);
	
    while (pos != std::string::npos)
	{
        line.erase(pos, toReplace.length());
        str.insert(pos, replaceWith);
        pos = str.find(toReplace, pos + replaceWith.length());
    }
	return(line);
}

int main(int argc, char **argv)
{
	std::string 	program_name;
	std::string 	s1;
	std::string 	s2;
	std::fstream	file;
	std::string 	line;
	
	if (argc < 4)
	{
		std::cout << "Invalid number of arguments!\n";
		return(1);
	}

	program_name	= argv[1];
	s1				= argv[2];
	s2				= argv[3];

	file.open("sample_text.txt", std::ios::in | std::ios::out);
	if(file.is_open())
	{
		while (std::getline(file, line))
		{
			find_and_replace(line, s1, s2);
		}

		file.close();
	}
	else
		std::cout << "File failed to open\n";
	return(0);

}