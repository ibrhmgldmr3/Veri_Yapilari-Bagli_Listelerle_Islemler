
/**
 * @file Sayi.cpp
 * @description Sayi sinifi ve onun duzenleyen fonksiyonlarini iceren dosya
 * @course Sakarya Üniversitesi Veri Yapilari Dersi 1-C grubu
 * @assignment 1. odev
 * @date 9.11.2023
 * @author İbrahim Güldemir ibrahim.guldemir@ogr.sakarya.edu.tr
 */

#include <iomanip>
#include <iostream>
#include <string>
#include "Sayi.hpp"

using namespace std;

    Basamak *Bas;

    Sayi::Sayi(const string &ekSay)
    {
        // tanımlamalar (soruna yol açamsın diye 0 değeri atanır)
        Bas = 0;
        int sayi=stoi(ekSay);
        for (int i = 0; i < ekSay.length(); i++)
        {
            Basamak *yeniBas = new Basamak();
            yeniBas->rakam= sayi%10 ;
            sayi=sayi/10;
            if (Bas == 0)
            {
                Bas = yeniBas; // İlk basamak ataması eğer yoksa
            }
            else
            {
                // Listenin başına gelen basamagi etkleme
                yeniBas->basPtr=Bas;
                Bas=yeniBas;
            }
            
        }
    }
    Sayi::Sayi()
    {
        Bas = 0;
    }

    Sayi::~Sayi()
    {
        Basamak *basTemp = Bas;
        while (basTemp != 0) // sayinin basamaklarini sil
        {
            Basamak *silBas = basTemp;
            basTemp = basTemp->basPtr;
            delete silBas;
        }
        cout << "\nNesne yok edildi!" << endl<<endl;
    }

    //sayilari string degerler olarak alan ve stringlerde toplama islemi yaptirarak butunleyen fonksiyon
    string Sayi::sayiOlustur()
    {
        Basamak *temp = Bas;

        string sayiStr = "";
        while (temp != 0)
        {
            string rakam = to_string(temp->rakam);
            sayiStr = sayiStr + rakam;
            temp = temp->basPtr;
        }
        string sayi = sayiStr;
        return sayi;
    }
    
    // tek rakamları başa taşıyan fonksiyon
    void Sayi::tekBasaAl()
    {
        Basamak *onceki = 0;
        Basamak *Temp = Bas;
        Basamak *yeniBas = 0;
        Basamak *yeniBasSon = 0;

        while (Temp != 0)
        {
            if (Temp->rakam % 2 == 1) // Tek rakamı başa taşı
            {
                if (onceki != 0)//eger baslangictaki temp degeri tekse ve onceki basamak ptr 0 ise ilk degerinin atanmasi
                {
                    onceki->basPtr = Temp->basPtr;
                }
                else //degilse de Bas degerinin degismesi
                {
                    Bas = Temp->basPtr;
                }

                if (yeniBas == 0)//eger 0 ise ilk degerin atanmasi
                {
                    yeniBas = Temp;
                    yeniBasSon = Temp;
                }
                else//degilse de degerlerin atanmasi
                {
                    yeniBasSon->basPtr = Temp;
                    yeniBasSon = Temp;
                }
            }
            else //eger onceki bos ise deger atanmasi
            {
                onceki = Temp;
            }
            Temp = Temp->basPtr;
        }

        if (yeniBas != 0)//baslangic ptr degistirilmesi
        {
            yeniBasSon->basPtr = Bas;
            Bas = yeniBas;
        }
    }

    // Basamakları tersleyen fonksiyon
    void Sayi::basTersle()
    {
        Basamak *Temp = Bas;
        Basamak *SonBas = 0;

        while (Temp != 0)
        {
            Basamak *temp2 = Temp->basPtr;// tempin sonraki değerini tutan işaretçi
            Temp->basPtr = SonBas;// Tempin sonrakini SonBas a eşitleyerek önceki değeri atamış oluyoruz
            SonBas = Temp;// sonbas a şu anki temp değerini atayarak önceki olarak kullanıyoruz
            Temp = temp2; // temp in sonraki adresine geçmesi
        }
        Bas = SonBas;
       }

    // sayinin icerdigi basamak adedini bulan fonksiyon
    int Sayi::basamakAdet()
    {
        int adet = 0;
        //eger "Bas" degeri 0sa 0 degeri dondurur
        if (Bas == 0)
            return 0;
        //basamak burada tek tek gezilerek hesaplanir
        Basamak *Temp = Bas;
        while (Temp != 0)
        {
            adet++;
            Temp = Temp->basPtr;
        }
        return adet;
    }
    //sayilari istenilen şekilde gösterme
    void Sayi::sayiGoster(Sayi *sayi)
    {

            Sayi *oku = sayi;
            Basamak* gecici=oku->Bas;
            cout << "###############     ";
            for (int i = 0; i < oku->basamakAdet(); i++)
            {
            cout << setw(7)<<"   *******   ";
            }
            cout<<endl;
            cout << "#"<<setw(13)<<sayi << "#    ";

            for (int i = 0; i < oku->basamakAdet(); i++)
            {
                string basAdres=to_string(reinterpret_cast<intptr_t>(gecici));
                cout << "    * " << setw(3) <<hex<< stoi(basAdres.substr(basAdres.length() - 3, 3)) << " *  ";
                gecici=gecici->basPtr;
            }
            gecici=sayi->Bas;
            cout << endl<< "#-------------#     ";
            for (int i = 0; i < oku->basamakAdet(); i++)
            {
                cout << setw(8) << "   *******   ";
            }
            cout << endl;
            cout << "#" << setw(13) << oku->sayiOlustur() << setw(6) << "#       ";

            for (int i = 0; i < oku->basamakAdet(); i++)
            {
                cout << " *  " << gecici->rakam << "  *     ";
                
                gecici=gecici->basPtr;
            }
            cout << endl<< "###############     ";
            for (int i = 0; i < oku->basamakAdet(); i++)
            {
                cout << setw(8) << "   *******   ";
            }
            cout << endl<<endl;
    }