#include <iostream>
#include <fstream>

std::string	replace_line(std::string line, std::string to_replace, std::string new_string)
{
	std::string new_line = "";
	size_t start = 0;
	size_t end = line.find(to_replace, 0);
	while (end != std::string::npos)
	{
		new_line += line.substr(start, end - start) + new_string;
		start = end + to_replace.size();
		end = line.find(to_replace, start);
	}
	if (start < line.size())
		new_line += line.substr(start, line.size());
	return (new_line);
}

int	main(int argc, char **argv) {
	if (argc < 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}
	std::ifstream	infile;
	std::ofstream	outfile;

	infile.open(argv[1], std::ios::in);
	if (!infile.is_open()) {
		std::cout << "The file has not been opened, either due to lack of permissions or because it doesn't exist!" << std::endl;
		return 2;
	}
	outfile.open((std::string)argv[1] + ".replace", std::ios::out);
	if (!outfile.is_open()) {
		std::cout << "The outfile could not be created, either due to lack of permissions or lack of space!" << std::endl;
		infile.close();
		return 2;
	}
	for (std::string line; std::getline(infile, line);)
	{
		outfile << replace_line(line, argv[2], argv[3]);
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}