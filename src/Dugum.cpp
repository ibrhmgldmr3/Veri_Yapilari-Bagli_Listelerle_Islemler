/**
 * @file Dugum.cpp
 * @description Dugumleri olusturan fonksiyonlari iceren  Dugum Sinifi ve fonksiyonlari
 * @course Sakarya Üniversitesi Veri Yapilari Dersi 1-C grubu
 * @assignment 1. odev
 * @date 9.11.2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <string>
#include "Dugum.hpp"


using namespace std;

    Sayi *sayiPtr;
    Dugum *dugumPtr;
    // oluşturulmuş sayının düğüme eklenmesi
    Dugum::Dugum(Sayi *Ptr)
    {
        this->sayiPtr = Ptr;
        dugumPtr = 0;
    }
    // dosyadan okunan string değeri ile sayi oluşturulması
    Dugum::Dugum(const string &sayi)
    {
        Sayi *yeniSayi = new Sayi(sayi);
        sayiPtr = yeniSayi;
        dugumPtr = 0;
    }
    //Dugumdeki sayinin basamaklari ile yokedilmesi
    Dugum::~Dugum()
    {
        Sayi *Temp = sayiPtr;//ilk ptr tutucu
        while (Temp != 0)
        {
            Sayi *Sil = Temp;//karışıklık olmasın diye ayrı değere atanması
            Temp = 0;

            delete Sil;
        }
    }
