#include <iostream>
#include <string.h>
#include <fstream>

bool	replace(std::ifstream& inFile, std::ofstream& outFile,
							std::string s1, std::string s2){
	if (!inFile.is_open() || !outFile.is_open()){
		std::cerr << "Could not open the file" << std::endl;
			return false;
	}
	std::string line;
	while (std::getline(inFile, line, '\n')){
		std::string::size_type s1Pos = line.find(s1);
		if (s1Pos != std::string::npos)
			outFile << line.substr(0, s1Pos) << s2 << 
					line.substr(s1Pos + s1.size(), line.size()) << "\n";
		else
			outFile << line << "\n";
	}
	return true;
}

int main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Enter the appropriate arguments" << std::endl;
		return 1;
	}
	std::ifstream inFile(argv[1]);
	std::string outFileName = std::string(argv[1]) + ".replace";
	std::ofstream outFile(outFileName.c_str());
	if (!replace(inFile, outFile, std::string(argv[2]), std::string(argv[3])))
		return 1;
	outFile.close();
}
