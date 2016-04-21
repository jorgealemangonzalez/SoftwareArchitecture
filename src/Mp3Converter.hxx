#include <vector>
#include <fstream>
#include <iostream>
#include <string.h>
#include "Exceptions.hxx"
#include "externalLibs/FraunhofferTools.hxx"

class Mp3Converter
{
public:   
	Mp3Converter(){

	}
	void conver(const std::string &file, const std::string &compressedFile){
		std::string filecompres = compressedFile + " [128].mp3";            //put the bps of the file
		frk_MP3_compression( file.c_str() , filecompres.c_str(), bps128);   //Call to external lib
	}
};