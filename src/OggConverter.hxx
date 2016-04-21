#ifndef OGGCONVERTER_HXX
#define OGGCONVERTER_HXX
#include "Converter.hxx"
#include "externalLibs/OggVorbisEncoder.hxx"
class OggConverter:public Converter
{
public:
    OggConverter(){}
    ~OggConverter(){}
    virtual void convert(const std::string &file, const std::string &compressedFile){
        OGG::compress( file.c_str() , (compressedFile  + " [128].ogg").c_str() , 128 );
    }
};
#endif