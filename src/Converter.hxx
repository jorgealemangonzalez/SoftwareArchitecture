#ifndef CONVERTER_HXX
#define CONVERTER_HXX

//#include "ConverterGroup.hxx"

class Converter{            //Generic converter
public:
    Converter():bps(128){}
    virtual ~Converter(){}
    virtual void convert(const std::string &file, const std::string &compressedFile) = 0 ;      //virtual method to be implemented in child classes
    virtual void bitRate(int bps) = 0;
    virtual std::string typeConverter() = 0;
    virtual int bpsInfo() = 0;
    
protected:
    int bps;			//bps of the audio file
    
    
};

#endif