#ifndef Basamak_hpp
#define  Basamak_hpp
#include <iostream>
class Basamak
{
    public:
    //tuttuğu basamak değeri
    int rakam;
    //basamak işaretçisi
    Basamak *basPtr;
    //kurucu ve yokedici fonksiyon
    Basamak();
    ~Basamak();
};
#endif