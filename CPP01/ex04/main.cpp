#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool	replace(std::string &content, std::ofstream& outFile,
							std::string s1, std::string s2){
	if (s1 == ""){
		std::cerr << "The search string must not be empty." << std::endl;
		return false;
	}
	std::string::size_type pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos){
		content.erase(pos, s1.size());
		content.insert(pos, s2);
		pos += s2.size();
	}
	outFile << content;
	return true;
}

int main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Enter the appropriate arguments" << std::endl;
		return 1;
	}
	std::ifstream inFile(argv[1]);
	if (!inFile.is_open()){
		std::cerr << "Could not open the file: " << std::string(argv[1]) << std::endl;
		return 1;
	}
	std::string outFileName = std::string(argv[1]) + ".replace";
	std::ofstream outFile(outFileName.c_str());
	if (!outFile.is_open()){
		std::cerr << "Could not open the output file !" << std::endl;
		inFile.close();
		return 1;
	}
	std::stringstream iss;
	iss << inFile.rdbuf();
	std::string content = iss.str();
	if (!replace(content, outFile, std::string(argv[2]), std::string(argv[3])))
		return 1;
	inFile.close();
	outFile.close();
}
