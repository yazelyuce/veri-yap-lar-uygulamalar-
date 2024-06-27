#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Hasta sınıfı
class Hasta {
public:
    string adSoyad;
    int acilDurumPuani;
    int yas;
    string cinsiyet;
    double oncelikPuani;

    // Öncelik puanı hesaplama fonksiyonu
    void oncelikPuaniHesapla() {
        oncelikPuani = acilDurumPuani * 2; // Acil durum puanının 2 katı öncelik puanına eklenir

        // 18 yaşından küçük veya 65 yaşından büyükse ek puan
        if (yas < 18 || yas > 65) {
            oncelikPuani += 10;
        }

        // Cinsiyete göre öncelik puanı (örneğin kadınlara ek puan)
        if (cinsiyet == "K" || cinsiyet == "k") {
            oncelikPuani += 5;
        }
    }

    // Karşılaştırma operatörü tanımı, öncelik sırasını belirlemek için kullanılacak
    bool operator<(const Hasta& hasta) const {
        return oncelikPuani < hasta.oncelikPuani;
    }
};

int main() {
    priority_queue<Hasta> kuyruk;

    while (true) {
        cout << "\n--- Hastane Otomasyonu ---\n";
        cout << "1. Yeni Hasta Ekle\n";
        cout << "2. Hasta Tedavisi\n";
        cout << "3. Kuyruktaki Hastalari Listele\n";
        cout << "4. Cikis\n";

        int secim;
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
            case 1: {
                Hasta hasta;
                cout << "Hasta Bilgilerini Girin:\n";
                cout << "Ad Soyad: ";
                cin >> hasta.adSoyad;
                cout << "Acil Durum Puani: ";
                cin >> hasta.acilDurumPuani;
                cout << "Yas: ";
                cin >> hasta.yas;
                cout << "Cinsiyet (E/K): ";
                cin >> hasta.cinsiyet;

                // Öncelik puanını hesapla
                hasta.oncelikPuaniHesapla();

                kuyruk.push(hasta);
                cout << "Yeni hasta eklendi.\n";
                break;
            }
            case 2: {
                if (kuyruk.empty()) {
                    cout << "Kuyruk bos, tedavi edilecek hasta yok.\n";
                } else {
                    cout << "En yuksek oncelikli hasta tedavi ediliyor...\n";
                    cout << "Hasta Ad Soyad: " << kuyruk.top().adSoyad << ", Acil Durum Puani: " << kuyruk.top().acilDurumPuani << ", Yas: " << kuyruk.top().yas << ", Cinsiyet: " << kuyruk.top().cinsiyet << ", Oncelik Puani: " << kuyruk.top().oncelikPuani << endl;
                    kuyruk.pop();
                    cout << "Hasta tedavi edildi.\n";
                }
                break;
            }
            case 3: {
                if (kuyruk.empty()) {
                    cout << "Kuyruk bos.\n";
                } else {
                    cout << "Kuyruktaki Hastalar:\n";
                    priority_queue<Hasta> temp = kuyruk; // Kuyruğu bozmamak için geçici bir kuyruk oluşturuyoruz
                    while (!temp.empty()) {
                        cout << "Ad Soyad: " << temp.top().adSoyad << ", Acil Durum Puani: " << temp.top().acilDurumPuani << ", Yas: " << temp.top().yas << ", Cinsiyet: " << temp.top().cinsiyet << ", Oncelik Puani: " << temp.top().oncelikPuani << endl;
                        temp.pop();
                    }
                }
                break;
            }
            case 4:
                cout << "Otomasyondan cikis yapildi.\n";
                return 0;
            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
        }
    }

    return 0;
}
