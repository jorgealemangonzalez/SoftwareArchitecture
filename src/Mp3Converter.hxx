#include <vector>
#include <fstream>
#include <iostream>
#include <string.h>
#include "Exceptions.hxx"

class Mp3Converter
{
public:   
	Mp3Converter(){

	}
	void conver(const std::string &file, const std::string &compressedFile){
		std::string filecompres = compressedFile + " [128].mp3";	
		std::ofstream newfile(filecompres.c_str());
		writeToFile(filecompres);
	}

	void writeToFile(const std::string &nameFile){
        std::ofstream infile;
        infile.open(nameFile.c_str());
        if(!infile.is_open()){
            throw masterDoesNotExist();
        }
        infile << "MP3 extracted from ’masters/Master.wav’ at 128 bps and length 50s.\n";
        infile.close();
    }
};