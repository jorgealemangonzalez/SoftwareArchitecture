#ifndef Mp3Converter_hxx
#define Mp3Converter_hxx

#include <vector>
#include <fstream>
#include <iostream>
#include <string.h>
#include "Exceptions.hxx"
#include "externalLibs/FraunhofferTools.hxx"
#include "Converter.hxx"

class Mp3Converter:public Converter		//Inherit converter data and methods 
{
public:   
	Mp3Converter():validBps{96,128,192,240}{
	}
	void convert(const std::string &file, const std::string &compressedFile){
		switch(bps){
		    case 96:    
		    	if(frk_MP3_compression( file.c_str() , (compressedFile  + " [96].mp3").c_str() , bps96) == -1 )throw masterDoesNotExist();	//Throw exception if the master file doesn't exists
		    	break;   //Call to external lib
		    case 128:   
		    	if(frk_MP3_compression( file.c_str() , (compressedFile  + " [128].mp3").c_str(), bps128) == -1 )throw masterDoesNotExist();	//Throw exception if the master file doesn't exists
		    	break;   //Call to external lib
		    case 192:   
		    	if(frk_MP3_compression( file.c_str() , (compressedFile + " [192].mp3").c_str(), bps192) == -1 )throw masterDoesNotExist();	//Throw exception if the master file doesn't exists
		    	break;   //Call to external lib
		    case 240:   
		    	if(frk_MP3_compression( file.c_str() , (compressedFile + " [240].mp3").c_str(), bps240) == -1 )throw masterDoesNotExist();	//Throw exception if the master file doesn't exists
		    	break;   //Call to external lib
		}
	}
	void bitRate(int bps){	//change the bit per second of the file
		if(isvalid(bps))
	    	this->bps = bps;
		else
			throw UnsupportedFormat();
		
	}

	std::string typeConverter(){ //return string of his type
		return "mp3";
	}
	int bpsInfo(){			//return his bps
		return bps;
	}

private:
    int validBps[4];	//the different bps that support the API
    
    
    bool isvalid(int bps){					//checks if bps is valid
		for(int i = 0 ; i < 4 ; ++i)
			if(validBps[i] == bps)
				return true;
		return false;
	}
};

#endif