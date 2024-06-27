#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Randevu sınıfı
class Randevu {
public:
    string tarihSaat;
    string doktor;
    string poliklinik;

    // Randevu bilgilerini yazdırma fonksiyonu
    void yazdir() const {
        cout << "Tarih/Saat: " << tarihSaat << ", Doktor: " << doktor << ", Poliklinik: " << poliklinik << endl;
    }
};

int main() {
    stack<Randevu> randevuStack;
    stack<Randevu> iptalEdilenRandevular; // İptal edilen randevuları saklamak için stack

    while (true) {
        cout << "\n--- MHRS Otomasyonu ---\n";
        cout << "1. Randevu Al\n";
        cout << "2. Randevu Iptal Et\n";
        cout << "3. Randevuyu Geri Al\n";
        cout << "4. Cikis\n";

        int secim;
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
            case 1: {
                Randevu randevu;
                cout << "Randevu Bilgilerini Girin:\n";
                cout << "Tarih/Saat: ";
                cin >> randevu.tarihSaat;
                cout << "Doktor: ";
                cin >> randevu.doktor;
                cout << "Poliklinik: ";
                cin >> randevu.poliklinik;
                randevuStack.push(randevu);
                cout << "Randevu alindi.\n";
                break;
            }
            case 2: {
                if (randevuStack.empty()) {
                    cout << "Iptal edilecek randevu yok.\n";
                } else {
                    Randevu iptalEdilenRandevu = randevuStack.top();
                    iptalEdilenRandevular.push(iptalEdilenRandevu);
                    randevuStack.pop();
                    cout << "Randevu iptal edildi.\n";
                }
                break;
            }
            case 3: {
                if (iptalEdilenRandevular.empty()) {
                    cout << "Geri alinacak randevu yok.\n";
                } else {
                    Randevu geriAlinanRandevu = iptalEdilenRandevular.top();
                    iptalEdilenRandevular.pop();
                    cout << "Geri alinan randevu:\n";
                    geriAlinanRandevu.yazdir();
                    cout << "Randevu geri alindi.\n";
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
