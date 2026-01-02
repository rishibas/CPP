#include <iostream>
#include <string.h>
#include <fstream>

bool	copyTextFile(std::ifstream& inFile, std::ofstream& outFile){
	std::string line;
	
	if (!inFile.is_open() || !outFile.is_open()){
		std::cerr << "Could not open the file" << std::endl;
			return false;
	}
	while (std::getline(inFile, line, '\n'))
		outFile << line << "\n";
	return true;


}

int main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Enter the appropriate arguments" << std::endl;
		return 1;
	}
	std::ifstream inFile(argv[1]);
	std::string outFileName = std::string(argv[1]) + ".replace";
	std::ofstream outFile(outFileName);
	if (!copyTextFile(inFile, outFile))
		return 1;
	outFile.close();
}
