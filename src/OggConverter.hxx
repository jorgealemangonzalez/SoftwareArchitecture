#ifndef OGGCONVERTER_HXX
#define OGGCONVERTER_HXX
#include "Converter.hxx"
#include "externalLibs/OggVorbisEncoder.hxx"
class OggConverter:public Converter         //inherit the data and methods from the generic converter
{
public:
    OggConverter(){}
    ~OggConverter(){}
    virtual void convert(const std::string &file, const std::string &compressedFile){       //Use the OggVorbisEnconder to compress .wav to .ogg
        std::ostringstream ss;      //get in a sting the value of the bps
        ss<<bps;
        OGG::compress( file.c_str() , (compressedFile  + " ["+ss.str()+"].ogg").c_str() , bps );     //Call to the library
    }
    void bitRate(int bps){	//change the bit per second of the file
	    this->bps = bps;
		
	}
};
#endif