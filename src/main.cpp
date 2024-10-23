/**
 * @file main.cpp
 * @description Programimizin ana govdesi. Olusturdugumuz siniflarla islemleri burada gercekliyoruz
 * @course Sakarya Üniversitesi Veri Yapilari Dersi 1-C grubu
 * @assignment 1. odev
 * @date 9.11.2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */

#include <iostream>
#include "SayiListesi.hpp"
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{   
    //Sayilari tutacak SayiListesi'nin olusturulmasi
    SayiListesi * Deneme=new SayiListesi();
    int secim=0;
    //sayilar.txt dosyasindaki sayilarin iceri aktarilmasi
    Deneme->sayilariListele();
    // ilk kez olusturulduktan sonra yazdirilmalari
    Deneme->yazdir();
    //dongu icinde islemlerin yapilmasi
    while(secim!=4)
    {  
        cout << ":1: Tek Basamaklari Basa Al"<<endl;
        cout << ":2: Basamaklari Tersle" << endl;
        cout << ":3: En Buyuk Cikar" << endl;
        cout << ":4: Cikis" << endl;
        cin>>secim;
        if(secim==1)
        {
            Deneme->tekBasaAl();
            Deneme->yazdir();
        }
        else if(secim==2)
        {
            Deneme->basTersle();
            Deneme->yazdir();
        }
        else if(secim==3)
        {
            Deneme->enBuyukSil();
            Deneme->yazdir();
        }
        else if(secim==4)
        {
            break;
        }
        else
        {
            cout<<"Gecersiz deger girildi!"<<endl;
        }
    }
    delete Deneme;

}
