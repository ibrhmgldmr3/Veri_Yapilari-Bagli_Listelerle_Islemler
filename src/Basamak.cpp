/**
 * @file Basamak.cpp
 * @description Basamak degerini tutan Basamak sinifi
 * @course Sakarya Üniversitesi Veri Yapilari Dersi 1-C grubu
 * @assignment 1. odev
 * @date 9.11.2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <iomanip>
#include "Basamak.hpp"
using namespace std;

    int rakam;
    //basamak işaretçisi
    Basamak *basPtr;
    //kurucu fonksiyon
    Basamak::Basamak()
    {
        rakam = 0;
        basPtr = 0;
    }
    //yokedici fonksiyon
    Basamak::~Basamak()
    {
        cout << endl
             << "Basamaklar silindi" << endl;
    }
