#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

class Ogrenci
{
private:
    string ad;
    string soyad;
    string ogrenciNo;

public:
    //Yukarıdaki değişkenler için get ve set metodları yazınız

    void setAd(string add) { ad = add; }

    string getAd() { return ad; }

    void setSoyad(string soyadd) { soyad = soyadd; }

    string getSoyad() { return soyad; }

    void setOgrenciNo(string ogrenciNoo) { ogrenciNo = ogrenciNoo; }

    string getOgrenciNo() { return ogrenciNo; }
};

int main()
{
    char devam, secim;

    while (true)
    {
        system("clear");

        cout << "\t\t====== Ogrenci Listesi ======";
        cout << "\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Ekle";
        cout << "\n \t\t\t 2. Listele";
        cout << "\n \t\t\t 3. Cikis";
        cout << "\n\n";
        cout << "\t\t\t Seciminizi yapiniz :=> ";
        cin >> secim;

        // Yapılan seçime göre uygun işlemi yap
        switch (secim)
        {
                //Ekle
            case '1':
            {
                devam = 'E';
                string girdiDizgesi; //Kullanıcıdan alınan değerler için geçici değişken
                ofstream ogrListesi; //Yazma işlemi için dosya nesnesi
                // OgrListesi.txt adlı dosyayı yazma ve sonuna ekleme kipinde açıyoruz
                ogrListesi.open("OgrListesi.txt", std::ofstream::out | std::ofstream::app);

                //Kullanıcı E ya da e yanıtını verdiği sürece yeni öğrenci ekleme
                // işlemi devam edecek
                while (devam == 'E' || devam == 'e')
                {
                    // Yeni bir öğrenci nesnesi oluşturuyoruz.
                    // Kullanıcıdan aldığımız değerleri bu nesneye atayacağız
                    Ogrenci yeniOgrenci;
                    system("clear");
                    cout << "Ogrencinin adi: ";
                    cin >> girdiDizgesi;
                    yeniOgrenci.setAd(girdiDizgesi);
                    cout << "Soyadi: ";
                    cin >> girdiDizgesi;
                    yeniOgrenci.setSoyad(girdiDizgesi);
                    cout << "Numarasi: ";
                    cin >> girdiDizgesi;
                    yeniOgrenci.setOgrenciNo(girdiDizgesi);

                    // Hatalı girdi durumunda, girdiyi gözardı edip kullanıcıyı uyarıyoruz
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Hatali giris. Tekrar denemek icin enter'a basiniz." << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

                    // Dosyaya yazmadan önce bilgileri noktalı virgülle ayırarak standartlaştırıyoruz.
                    // Okuma yaparken bu bize yardımcı olacak
                    string outStr(yeniOgrenci.getAd() + ";" + yeniOgrenci.getSoyad() + ";"
                                  + yeniOgrenci.getOgrenciNo() + ";");
                    ogrListesi << outStr << std::endl;
                    system("clear");
                    cout << "\n Yeni bir ogrenci daha eklemek ister misiniz? (E/H) ";
                    cin >> devam;
                    system("clear");
                }
                ogrListesi.close();
                break;
            }
            //Listele
            case '2':
            {
                // OgrListesi.txt dosyasına yazılmış olan öğrenci listesini
                // dosyadan okuyup her seferinde yeni bir öğrenci nesnesi
                // oluşturduktan sonra, öğrenci bilgilerini okunaklı şekilde
                // ekrana basınız

                ifstream ReadFile("OgrListesi.txt");
                if (ReadFile.is_open())
                {
                    while (!ReadFile.eof())
                    {
                        string ad, soyad, ogrNo;
                        Ogrenci yeniOgrenci;

                        getline(ReadFile, ad, ';');
                        yeniOgrenci.setAd(ad);

                        getline(ReadFile, soyad, ';');
                        yeniOgrenci.setSoyad(soyad);

                        getline(ReadFile, ogrNo, ';');
                        yeniOgrenci.setOgrenciNo(ogrNo);

                        cout << yeniOgrenci.getAd() << "  " << yeniOgrenci.getSoyad() << "  "
                             << yeniOgrenci.getOgrenciNo() << endl;
                    }
                }
                ReadFile.close();
                break;
            }

            //Çıkış
            case '3':
                // Çıkış
                exit(0);
        }
    }

    return 0;
}
