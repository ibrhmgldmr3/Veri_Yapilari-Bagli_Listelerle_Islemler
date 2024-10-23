#ifndef Dugum_hpp
#define Dugum_hpp

#include <string>
#include "Sayi.hpp"
using namespace std;
class Dugum
{
public:
    Dugum* dugumPtr;
    Sayi * sayiPtr;
    // oluşturulmuş sayının düğüme eklenmesi
    Dugum(Sayi*);
    // dosyadan okunan string değer ile sayi oluşturulması
    Dugum(const string&);
    //Yokedici fonksiyon
    ~Dugum();
};
#endif // !1