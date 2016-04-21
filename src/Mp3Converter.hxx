#include <vector>
#include <fstream>
#include <iostream>
#include <string.h>
#include "Exceptions.hxx"
#include "externalLibs/FraunhofferTools.hxx"

class Mp3Converter
{
public:   
	Mp3Converter():bps(128),validBps{96,128,192,240}{
	}
	void conver(const std::string &file, const std::string &compressedFile){
		//std::string filecompres = compressedFile + " ["+ std::to_string(bps) +"].mp3";            //put the bps of the file
		switch(bps){
		    case 96:    frk_MP3_compression( file.c_str() , (compressedFile  + " [96].mp3").c_str() , bps96);break;   //Call to external lib
		    case 128:   frk_MP3_compression( file.c_str() , (compressedFile  + " [128].mp3").c_str(), bps128);break;   //Call to external lib
		    case 192:   frk_MP3_compression( file.c_str() , (compressedFile + " [192].mp3").c_str(), bps192);break;   //Call to external lib
		    case 240:   frk_MP3_compression( file.c_str() , (compressedFile + " [240].mp3").c_str(), bps240);break;   //Call to external lib
		}
	}
	void bitRate(int bps){	//change the bit per second of the file
		if(isvalid(bps))
	    	this->bps = bps;
		else
			throw UnsupportedFormat();
		
	}
private:
    int bps;
    int validBps[4];
    
    
    bool isvalid(int bps){					//checks if bps is valid
		for(int i = 0 ; i < 4 ; ++i)
			if(validBps[i] == bps)
				return true;
		return false;
	}
};