#ifndef CONVERTER_HXX
#define CONVERTER_HXX

class Converter{            //Generic converter
public:
    Converter(){}
    virtual ~Converter(){}
    virtual void convert(const std::string &file, const std::string &compressedFile) = 0 ;      //virtual method to be implemented in child classes
};

#endif