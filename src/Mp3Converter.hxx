#include <vector>
#include <fstream>
#include <iostream>
#include <string>

class Mp3Converter
{
public:   
	Mp3Converter(){

	}
	void conver(const std::string &file, const std::string &compressedFile){
		std::string filecompres = compressedFile + " [128].mp3";	
		std::ofstream newfile(filecompres.c_str());
	}
};