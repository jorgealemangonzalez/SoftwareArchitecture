#ifndef CONVERTER_HXX
#define CONVERTER_HXX

class Converter{            //Generic converter
public:
    Converter():bps(128){}
    virtual ~Converter(){}
    virtual void convert(const std::string &file, const std::string &compressedFile) = 0 ;      //virtual method to be implemented in child classes
    
protected:
    int bps;			//bps of the audio file
    
    
};

#endif