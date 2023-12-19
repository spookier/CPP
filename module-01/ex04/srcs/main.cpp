#include <string>
#include <iostream>
#include <fstream>

void find_and_replace(const std::string& line, const std::string& s1, const std::string& s2, std::string& new_line)
{
    size_t startPos;
	size_t foundPos;

	startPos = 0;
    
	foundPos = line.find(s1, startPos);								// Find the first occurrence of s1

	if (foundPos != std::string::npos)								// If we found s1 in the string
	{
		new_line.append(line, startPos, foundPos - startPos);		// Append everything from startPos to foundPos
		new_line.append(s2);
		startPos = foundPos + s1.length();
	}
	else															// If we didn't find s1 in the string
	{
		new_line.append(line, startPos);							// Append everything
	}
}

int check_args(std::string program_name, std::string s1, std::string s2)
{
	if (program_name.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Invalid arguments!\n" << std::endl;
		return(1);
	}
	return(0);
}

int main(int argc, char **argv)
{
	std::string 	filename;
	std::string 	s1;
	std::string 	s2;
	std::string 	line;
	std::string		new_filename;
	std::string		new_line;
	std::ifstream	file;												// Only reading permissions
	std::ofstream	new_file;											// Only writing permissions

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments!\n";
		return(1);
	}

	filename		= argv[1];
	s1				= argv[2];
	s2				= argv[3];
	if(check_args(filename, s1, s2) == 1)
		return(1);

	new_filename = filename + ".replace";
	
	new_file.open(new_filename.c_str());							// Create the new file 	
	if(!new_file.is_open())
	{
		std::cout << "File failed to create" << std::endl;
		return(1);
	}

	file.open(filename.c_str(), std::ios::in | std::ios::out);
	if(file.is_open())
	{
		while (std::getline(file, line))
		{
			new_line.clear();
			find_and_replace(line, s1, s2, new_line);
			new_file << new_line << std::endl;
		}
		file.close();
		new_file.close();
	}
	else
	{
		std::cout << "File failed to open" << std::endl;
		return(1);
	}
	return(0);
}
