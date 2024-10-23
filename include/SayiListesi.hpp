#ifndef SayiListesi_hpp
#define SayiListesi_hpp

#include <string>
#include <iostream>
#include "Dugum.hpp"
using namespace std;
class SayiListesi
{

    public:
    Dugum *dugumPtr;
    SayiListesi();
    ~SayiListesi();
    // yeni düğümler ekleyen fonksiyon
    void ekle(const string& );
    //sayilari .txt dosyasindan okuyan ve dugumler halinde liste haline getiren fonksiyon
    void sayilariListele();
    // dugumlerden doğru sayilara erişip yazdıran fonksiyon
    void yazdir();
    //tek deger iceren basamaklari basa alan fonksiyon
    void tekBasaAl();
    //basamaklarin siralamasini tersleyen fonksiyon
    void basTersle();
    //en buyuk sayi degerine sahip dugumu silen fonksiyon
    void enBuyukSil();
};
#endif // !1