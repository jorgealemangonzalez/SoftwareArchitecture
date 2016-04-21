#ifndef CONVERTER_HXX
#define CONVERTER_HXX

class Converter{
public:
    Converter(){}
    virtual ~Converter(){}
    virtual void conver(const std::string &file, const std::string &compressedFile) = 0 ;
};

#endif