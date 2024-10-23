#ifndef Sayi_hpp
#define Sayi_hpp
#include <string>
#include "Basamak.hpp"
using namespace std;
class Sayi
{
public:
    Basamak *Bas;
    //kurucular ve yikicilar
    Sayi(const string&);
    Sayi();
    ~Sayi();

    //sayilari string olarak butunlestirip gosteren fonksiyon
    string sayiOlustur();
    //tek degere sahip basamaklari basa alan fonksiyon
    void tekBasaAl();
    // Basamakları tersleyen fonksiyon
    void basTersle();
    //basamak adedini bulan fonksiyon
    int basamakAdet();
    //sayialrin istenilen formatta yazdirilmasi
    void sayiGoster(Sayi* Sayi);

};
#endif // !1