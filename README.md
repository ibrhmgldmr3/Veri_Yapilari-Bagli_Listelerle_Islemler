# Veri Yapıları Ödevi – Bağlı Listelerle İşlemler (2023‑2024 Güz Dönemi)

> Sakarya Üniversitesi Bilgisayar Mühendisliği – **Veri Yapıları** dersi proje ödevi  
> **Geliştirici:** İbrahim Güldemir  
> **Repo:** <https://github.com/ibrhmgldmr3/Veri_Yapilari-Bagli_Listelerle_Islemler>

---

## İçerik

- [Proje Hakkında](#proje-hakkında)
- [Özellikler](#özellikler)
- [Teknolojiler](#teknolojiler)
- [Kurulum](#kurulum)
- [Çalıştırma](#çalıştırma)
- [Kullanım Örneği](#kullanım-örneği)
- [Dizin Yapısı](#dizin-yapısı)
- [İletişim](#iletişim)

---

## Proje Hakkında

Bu proje, **bağlı liste (linked list)** veri yapısının tekil (singly), çift yönlü (doubly) ve dairesel (circular) türevlerini **C++** ile uygulayarak ekleme, silme, arama, ters çevirme ve sıralı ekleme gibi temel işlemleri test etmeyi amaçlar.  

Arayüz, **konsol tabanlı interaktif menü** ve/veya `Komutlar.txt` dosyasından toplu işlem okuma seçenekleri sunar.

---

## Özellikler

| İşlev | Açıklama |
| ----- | -------- |
| **Düğüm Ekleme** | Baş / son / belirli index’e ekleme |
| **Düğüm Silme**  | Değer veya index’e göre silme |
| **Arama (Search)** | O(n) doğrusal arama, bulunan düğümün adresi & index’i |
| **Ters Çevirme (Reverse)** | Tek geçişte listeyi terse çevirme |
| **Sıralı Ekleme** | Artan / azalan sıraya göre uygun pozisyona ekleme |
| **Dairesel Liste** | Son düğümün `next` işaretçisi başa bağlanır |
| **İstatistikler** | Düğüm sayısı, ilk / son eleman, boş kontrolü |
| **Toplu İşlem**  | `Komutlar.txt` dosyasındaki komutları ardışık yürütme |

---

## Teknolojiler

| Katman | Yığın / Araçlar |
| ------ | -------------- |
| **Dil**| **C++17** |
| **Derleme** | GNU `g++` (Makefile) |
| **Test** | `<cassert>` bazlı basit birim testleri, `valgrind` |
| **CI** | GitHub Actions (Ubuntu build) |

---

## Kurulum

### 1. Depoyu klonla

```bash
git clone https://github.com/ibrhmgldmr3/Veri_Yapilari-Bagli_Listelerle_Islemler.git
cd Veri_Yapilari-Bagli_Listelerle_Islemler
```

### 2. Derle

```bash
make              # Makefile varsayılan hedef: ./bin/list_demo
```

---

## Çalıştırma

```bash
./bin/list_demo                 # Etkileşimli menü
./bin/list_demo Komutlar.txt    # Dosya tabanlı komut yürütme
```

---

## Kullanım Örneği

```text
---- Bağlı Liste Menüsü ----
1) Başa Ekle
2) Sona Ekle
3) Index'e Ekle
4) Sil
5) Ara
6) Listeyi Yazdır
0) Çıkış
Seçim: 1
Değer: 15
[Eklendi] 15 başa eklendi.
```

---

## Dizin Yapısı

```text
Veri_Yapilari-Bagli_Listelerle_Islemler/
├── include/            # Liste sınıfı başlık dosyaları
├── src/                # Kaynak kod
├── bin/                # Derlenmiş çıktılar
├── tests/              # (isteğe bağlı) test kodları
├── Komutlar.txt        # Örnek komut seti
├── Makefile
└── README.md
```

---

## İletişim

| Kanal   | Bilgi |
| ------- | ----- |
| E‑posta | ibrahimguldemir123@gmail.com |
| LinkedIn| <https://www.linkedin.com/in/ibrhmgldmr/> |
| GitHub  | <https://github.com/ibrhmgldmr3> |

---

> **Katkı & Sorular:** Issue veya Pull Request açarak katkıda bulunabilirsin.  
> Projeyi faydalı bulduysan ⭐ vererek destek olmayı unutma!
