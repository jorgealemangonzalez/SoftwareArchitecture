#ifndef OGGCONVERTER_HXX
#define OGGCONVERTER_HXX
#include "Converter.hxx"
class OggConverter:public Converter
{
public:
    OggConverter(){}
    ~OggConverter(){}
    virtual void convert(const std::string &file, const std::string &compressedFile){
        
    }
};
#endif