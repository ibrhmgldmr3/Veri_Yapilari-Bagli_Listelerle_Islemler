/**
 * @file SayilarListesi.cpp
 * @description Sayilarla alakali islemleri yapan sinif ve ona ait fonksiyonlar
 * @course Sakarya universitesi Veri Yapilari Dersi 1-C grubu
 * @assignment 1. odev
 * @date 9.11.2023
 * @author İbrahim Guldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "SayiListesi.hpp"

using namespace std;
//SayiListesi kurucusu ve yokedicisi
    SayiListesi::SayiListesi()
    {
        dugumPtr = 0;
    }
    SayiListesi::~SayiListesi()
    {
        while (dugumPtr != 0)
        {
            cout << "------------------------------------------------------------------------------" << endl;
            Dugum *silinecekDugum = dugumPtr;
            dugumPtr = dugumPtr->dugumPtr;
            delete silinecekDugum;
            cout << "------------------------------------------------------------------------------" << endl;
        }
        cout << "\nSayiListesi Nesnesi yok edildi!" << endl;
        system("PAUSE");
        system("CLS");
    }
    // yeni duğumler ekleyen fonksiyon
    void SayiListesi::ekle(const string &ekSay)
    {
        // eklenecek sayinin tanımlanması
        Dugum *yeniDugum = new Dugum(ekSay);

        // eğer başlangıç duğumu yoksa eklenmesi
        if (dugumPtr == 0)
        {
            dugumPtr = yeniDugum;
            return;
        }
        // geçici bir duğumle sona ekleme işlemi
        Dugum *temp = dugumPtr;
        while (temp->dugumPtr != 0)
        {
            temp = temp->dugumPtr;
        }
        temp->dugumPtr = yeniDugum;
    }
    //.txt dosyasindan okunan değerleri duğumlere atayip sayilistesinde bağlama
    void SayiListesi::sayilariListele()
    {
        string oku = "";
        ifstream dosya;
        dosya.open("sayilar.txt");
        while (dosya >> oku)
        {
            ekle(oku);
        }
        dosya.close();
    }
    // dugumlerden doğru sayilara erişip yazdıran fonksiyon
    void SayiListesi::yazdir()
    {
        Dugum *oku = dugumPtr;

        while (oku != 0)
        {
           oku->sayiPtr->sayiGoster(oku->sayiPtr);
           oku=oku->dugumPtr;
        }
    }
    //tek rakamlari basa alan fonksiyon her bir dugum için ayri ayri
    void SayiListesi::tekBasaAl()
    {
        Dugum *Temp = dugumPtr;
        while (Temp != 0)
        {
            Temp->sayiPtr->tekBasaAl();
            Temp = Temp->dugumPtr;
        }
    }
    //basamaklarin yerlerini tersleyen fonksiyon
    void SayiListesi::basTersle()
    {
        Dugum *Temp = dugumPtr;
        while (Temp != 0)
        {
            Temp->sayiPtr->basTersle();
            Temp = Temp->dugumPtr;
        }
    }
    //en buyuk sayi degerine sahip dugumu silen fonksiyon
    void SayiListesi::enBuyukSil()
    {
        //ilk dugumun kontrol edilmesi
        if(dugumPtr==0)
        {
            cout<<"Herhangi bir dugum yok"<<endl<<endl;
            return;
        }
        //listede sadece 1 eleman mi var onun kontrol edilmesi
            //varsa sadece onun silinmesi
        if (dugumPtr->dugumPtr == 0)
        {
            delete dugumPtr;
            dugumPtr=0;
            return;
        }

        Dugum *Temp = dugumPtr; //gecici dugum arama için
        Dugum *Onceki = 0;      //bi onceki dugumu tutabilmek icin
        Dugum *EnBuyukDugum = 0;//en buyuk dugumu tutan isaretci

        //kontrol islemleri icin ilk sayi atanmasi
        int EnBuyuk = stoi(Temp->sayiPtr->sayiOlustur());

        while (Temp != 0)
        {
            //kontrol edilen sayimiz
            int KontSayi = 0;
            if (Temp->dugumPtr != 0)//eger sonraki dugum varsa onun verisinin atanmasi  
                KontSayi = stoi(Temp->dugumPtr->sayiPtr->sayiOlustur());
            else//yoksa 0 atanması
                KontSayi=0;
            //en buyuk dugum ile kontrol edilen dugumun karsilastirilmasi
            if (KontSayi >= EnBuyuk) // eger buyukse verilerin atanması
            {
                Onceki = Temp;
                EnBuyuk = KontSayi;
                EnBuyukDugum = Temp->dugumPtr;
            }
            if (EnBuyukDugum == 0)//en buyuk dugum bossa ilk deger atanmasi
            {
                EnBuyukDugum = Temp;
            }

            Temp = Temp->dugumPtr;
        }
        cout<<"\n En buyuk: "<<EnBuyukDugum<<endl;
        if (EnBuyukDugum != 0 )//en buyuk dugum bos degilse silinme islemine girilmesi
        {
            if (Onceki != 0)//oncekinin deger kontrolu //bossa ilk dugumdur
            {
                Onceki->dugumPtr = EnBuyukDugum->dugumPtr;
            }
            else
            {
                dugumPtr = EnBuyukDugum->dugumPtr;
            }
            delete EnBuyukDugum;
        }
    }
