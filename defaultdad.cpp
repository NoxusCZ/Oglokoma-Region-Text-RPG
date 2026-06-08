#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
    int xpNaDalsiLevel;
};

struct Monstrum {
    string jmeno;
    int hp;
    int utok;
};

void zkontrolujLevelUp(Postava &hrac) {
    if (hrac.xp >= hrac.xpNaDalsiLevel) {
        hrac.level++;
        hrac.xp -= hrac.xpNaDalsiLevel;
        hrac.xpNaDalsiLevel = hrac.xpNaDalsiLevel + 10;
        hrac.maxHp += 10;
        hrac.hp = hrac.maxHp;
        hrac.utok += 2;

        cout << "\n=============================" << endl;
        cout << " nyni mas level " << hrac.level << "!" << endl;
        cout << " Tvoje stats se vylepsily" << endl;
        cout << "===============================" << endl;
    }
}

// vraci dmg, zaporny = ledova strela (zamrazi), 0 = selhal
int vyberAPoziKouzlo(Postava &hrac) {
    cout << "Vyber kouzlo:\n";
    cout << "  1) Ohniva koule  - 25 dmg  (10 many)\n";
    cout << "  2) Blesk         - 40 dmg  (20 many)\n";
    cout << "  3) Ledova strela - 15 dmg  ( 5 many) + neprite pristi kolo neutoci\n";
    cout << "Tvoje volba: ";
    int k;
    cin >> k;

    if (k == 1) {
        if (hrac.mana < 10) { cout << "Nemas dost many!\n"; return 0; }
        hrac.mana -= 10;
        cout << "Vykouzlil jsi Ohnivou kouli!" << endl;
        return 25;
    }
    if (k == 2) {
        if (hrac.mana < 20) { cout << "Nemas dost many!\n"; return 0; }
        hrac.mana -= 20;
        cout << "Povolal jsi Blesk!\n";
        return 40;
    }
    if (k == 3) {
        if (hrac.mana < 5) { cout << "Nemas dost many!\n"; return 0; }
        hrac.mana -= 5;
        cout << "Vystrelil jsi Ledovou strelu!\n";
        return -15;
    }
    cout << "Spatna volba kouzla.\n";
    return 0;
}

void bojSJednimMonstrem(Postava &hrac) {
    Monstrum moznosti[3] = {
        {"Zombie", 40, 10},
        {"Upir", 30, 20},
        {"Amperistha", 60, 15}
    };
    Monstrum souper = moznosti[rand() % 3];
    int zamrazen = 0;

    cout << "\n!!! Potkal jsi " << souper.jmeno << " (HP: " << souper.hp << ") !!!" << endl;

    while (hrac.hp > 0 && souper.hp > 0) {
        cout << "\nTvuj stav: HP " << hrac.hp << "/" << hrac.maxHp << "  Mana: " << hrac.mana << "/" << hrac.maxMana << endl;
        cout << souper.jmeno << ": HP " << souper.hp << endl;
        cout << "1) Zautocit mecem (" << hrac.utok << " dmg)" << endl;
        if (hrac.kouzla > 0)
            cout << "2) Pouzit kouzlo" << endl;
        cout << "Tvoje volba: ";
        int volba;
        cin >> volba;

        if (volba == 1) {
            souper.hp -= hrac.utok;
            cout << "Zasahujes " << souper.jmeno << " za " << hrac.utok << " dmg!" << endl;
        } else if (volba == 2 && hrac.kouzla > 0) {
            int dmg = vyberAPoziKouzlo(hrac);
            if (dmg != 0) {
                int skutecnyDmg = (dmg < 0) ? -dmg : dmg;
                souper.hp -= skutecnyDmg;
                cout << "Zasahujes " << souper.jmeno << " za " << skutecnyDmg << " dmg!" << endl;
                if (dmg < 0) zamrazen = 1;
            }
        } else {
            cout << "Nelze pouzit!" << endl;
        }

        if (souper.hp > 0) {
            if (zamrazen) {
                cout << souper.jmeno << " je zamrazen a neutoci!" << endl;
                zamrazen = 0;
            } else {
                hrac.hp -= souper.utok;
                cout << souper.jmeno << " te zasahuje za " << souper.utok << " dmg!" << endl;
            }
        }
    }

    if (hrac.hp > 0) {
        cout << "\nVyhral jsi! Ziskavas 5 XP." << endl;
        hrac.xp += 5;
    } else {
        cout << "\nByl jsi porazen..." << endl;
    }
}

void bojSeDvemaMonstry(Postava &hrac) {
    Monstrum moznosti[3] = {
        {"Zombie", 40, 10},
        {"Upir", 30, 20},
        {"Amperistha", 60, 15}
    };
    Monstrum m1 = moznosti[rand() % 3];
    Monstrum m2 = moznosti[rand() % 3];
    int zamr1 = 0;
    int zamr2 = 0;

    cout << "\n!!! Potkal jsi " << m1.jmeno << " a " << m2.jmeno << " !!!" << endl;

    while (hrac.hp > 0 && (m1.hp > 0 || m2.hp > 0)) {
        cout << "\nTvuj stav: HP " << hrac.hp << "/" << hrac.maxHp << "  Mana: " << hrac.mana << "/" << hrac.maxMana << endl;
        if (m1.hp > 0) cout << "1) " << m1.jmeno << " (HP: " << m1.hp << ")" << endl;
        if (m2.hp > 0) cout << "2) " << m2.jmeno << " (HP: " << m2.hp << ")" << endl;
        if (hrac.kouzla > 0) cout << "3) Pouzit kouzlo" << endl;
        cout << "Tvoje volba: ";
        int volba;
        cin >> volba;

        if (volba == 1 && m1.hp > 0) {
            m1.hp -= hrac.utok;
            cout << "Zasahujes " << m1.jmeno << " za " << hrac.utok << " dmg!" << endl;
        } else if (volba == 2 && m2.hp > 0) {
            m2.hp -= hrac.utok;
            cout << "Zasahujes " << m2.jmeno << " za " << hrac.utok << " dmg!" << endl;
        } else if (volba == 3 && hrac.kouzla > 0) {
            int dmg = vyberAPoziKouzlo(hrac);
            if (dmg != 0) {
                int skutecnyDmg = (dmg < 0) ? -dmg : dmg;
                int jezamrazi = (dmg < 0) ? 1 : 0;

                cout << "Na koho? (1 = " << m1.jmeno << " / 2 = " << m2.jmeno << "): ";
                int cil;
                cin >> cil;

                if (cil == 1 && m1.hp > 0) {
                    m1.hp -= skutecnyDmg;
                    cout << "Zasahujes " << m1.jmeno << " za " << skutecnyDmg << " dmg!" << endl;
                    if (jezamrazi) zamr1 = 1;
                } else if (cil == 2 && m2.hp > 0) {
                    m2.hp -= skutecnyDmg;
                    cout << "Zasahujes " << m2.jmeno << " za " << skutecnyDmg << " dmg!" << endl;
                    if (jezamrazi) zamr2 = 1;
                } else {
                    cout << "Neplatny cil!\n";
                }
            }
        } else {
            cout << "Neplatna volba!\n";
        }

        if (m1.hp > 0) {
            if (zamr1) { cout << m1.jmeno << " je zamrazen a neutoci!" << endl; zamr1 = 0; }
            else { hrac.hp -= m1.utok; cout << m1.jmeno << " te zasahuje za " << m1.utok << " dmg!" << endl; }
        }
        if (m2.hp > 0) {
            if (zamr2) { cout << m2.jmeno << " je zamrazen a neutoci!" << endl; zamr2 = 0; }
            else { hrac.hp -= m2.utok; cout << m2.jmeno << " te zasahuje za " << m2.utok << " dmg!" << endl; }
        }
    }

    if (hrac.hp > 0) {
        cout << "\nVitezstvi! Ziskavas 10 XP." << endl;
        hrac.xp += 10;
    } else {
        cout << "\nByl jsi porazen..." << endl;
    }
}

void bojSGangem(Postava &hrac) {
    Monstrum gang[4] = {
        {"Zombie", 40, 10},
        {"Zombie", 40, 10},
        {"Upir", 30, 20},
        {"Amperistha", 60, 15}
    };
    int zamr[4] = {0, 0, 0, 0};
    int pocetZivych = 4;

    cout << "\n!!! Obklicil te gang monster !!!" << endl;

    while (hrac.hp > 0 && pocetZivych > 0) {
        cout << "\n--- Tvuj stav: HP " << hrac.hp << "/" << hrac.maxHp << "  Mana: " << hrac.mana << "/" << hrac.maxMana << " ---" << endl;
        for (int i = 0; i < 4; i++) {
            if (gang[i].hp > 0)
                cout << i + 1 << ") " << gang[i].jmeno << " (HP: " << gang[i].hp << ")" << endl;
        }
        if (hrac.kouzla > 0) cout << "5) Pouzit kouzlo" << endl;
        cout << "Tvoje volba: ";
        int volba;
        cin >> volba;

        if (volba >= 1 && volba <= 4) {
            int idx = volba - 1;
            if (gang[idx].hp > 0) {
                gang[idx].hp -= hrac.utok;
                cout << "Zasahujes " << gang[idx].jmeno << " za " << hrac.utok << " dmg!" << endl;
                if (gang[idx].hp <= 0) {
                    cout << gang[idx].jmeno << " padl!" << endl;
                    pocetZivych--;
                }
            } else {
                cout << "Tohle monstrum je uz mrtve!" << endl;
            }
        } else if (volba == 5 && hrac.kouzla > 0) {
            int dmg = vyberAPoziKouzlo(hrac);
            if (dmg != 0) {
                int skutecnyDmg = (dmg < 0) ? -dmg : dmg;
                int jezamrazi = (dmg < 0) ? 1 : 0;

                cout << "Na koho (1-4)? ";
                int cil;
                cin >> cil;
                int idx = cil - 1;

                if (idx >= 0 && idx < 4 && gang[idx].hp > 0) {
                    gang[idx].hp -= skutecnyDmg;
                    cout << "Zasahujes " << gang[idx].jmeno << " za " << skutecnyDmg << " dmg!" << endl;
                    if (jezamrazi) zamr[idx] = 1;
                    if (gang[idx].hp <= 0) {
                        cout << gang[idx].jmeno << " padl!" << endl;
                        pocetZivych--;
                    }
                } else {
                    cout << "Neplatny cil!\n";
                }
            }
        } else {
            cout << "Neplatna volba!\n";
        }

        for (int i = 0; i < 4; i++) {
            if (gang[i].hp > 0) {
                if (zamr[i]) { cout << gang[i].jmeno << " je zamrazen!" << endl; zamr[i] = 0; }
                else { hrac.hp -= gang[i].utok; cout << gang[i].jmeno << " te seka za " << gang[i].utok << " dmg!" << endl; }
            }
        }
    }

    if (hrac.hp > 0) {
        cout << "\nPrezil jsi utok gangu!" << endl;
        hrac.xp += 20;
    } else {
        cout << "\nGang te premohl..." << endl;
    }
}

void bojSBossem(Postava &hrac) {
    int bossHp = 200;
    int bossZlato = 1000;
    string jmeno = "Coincling";
    int zamrazen = 0;

    cout << "\n!!! Potkal jsi bosse " << jmeno << " !!!" << endl;

    int inicialniPoskozeni = hrac.zlato;
    hrac.hp -= inicialniPoskozeni;
    cout << jmeno << " ti okamzite bere " << inicialniPoskozeni << " HP z tveho bohatstvi!\n";

    hrac.zlato += 20;
    cout << jmeno << " ti hodil 20 zlata. (Hrac ma nyni: " << hrac.zlato << " zlata)\n";

    while (hrac.hp > 0 && bossHp > 0) {
        bossZlato += (bossZlato * 0.1);
        int bonusUtok = bossZlato / 10;
        int poskozeni = (hrac.zlato / 5) + bonusUtok;

        if (hrac.zlato >= 50) {
            bossHp -= 20;
            hrac.hp -= 20;
            cout << "!!! Podlaha se utrhla pod vahou zlata! Oba ztracite 20 HP !!!" << endl;
        } else if (hrac.zlato >= 40) {
            hrac.maxHp -= 10;
            cout << "Coincling ti ukradl 10 max HP!" << endl;
        } else if (hrac.zlato >= 30) {
            bossHp += 10;
            cout << "Coincling se ozdravil o 10 HP!" << endl;
        } else if (hrac.zlato >= 20) {
            hrac.maxHp -= 10;
            cout << "Coincling ti ukradl 10 max HP!" << endl;
        } else if (hrac.zlato >= 10) {
            bossHp += 10;
            cout << "Coincling se ozdravil o 10 HP!" << endl;
        }

        cout << "\nBoss HP: " << bossHp << "  Tvoje HP: " << hrac.hp << "/" << hrac.maxHp << "  Mana: " << hrac.mana << "/" << hrac.maxMana << endl;

        if (zamrazen) {
            cout << jmeno << " je zamrazen a neutoci!" << endl;
            zamrazen = 0;
        } else {
            hrac.hp -= poskozeni;
            cout << jmeno << " utoci! Zpusobil ti " << poskozeni << " poskozeni." << endl;
        }

        if (hrac.hp <= 0) break;

        cout << "1) Utocit mecem" << endl;
        if (hrac.kouzla > 0) cout << "2) Pouzit kouzlo" << endl;
        cout << "Tvoje volba: ";
        int volba;
        cin >> volba;

        if (volba == 1) {
            bossHp -= hrac.utok;
            cout << "Zasahujes bosse za " << hrac.utok << " dmg!" << endl;
        } else if (volba == 2 && hrac.kouzla > 0) {
            int dmg = vyberAPoziKouzlo(hrac);
            if (dmg != 0) {
                int skutecnyDmg = (dmg < 0) ? -dmg : dmg;
                bossHp -= skutecnyDmg;
                cout << "Zasahujes bosse za " << skutecnyDmg << " dmg!" << endl;
                if (dmg < 0) zamrazen = 1;
            }
        }
    }

    if (hrac.hp > 0) cout << "\nPorazil jsi Coinclinga a ziskal jsi jeho poklad!" << endl;
    else cout << "\nByl jsi Coinclingem znicen..." << endl;
}

int main() {
    srand(time(0));
    char vstup;
    int vyber;
    int vybermista;

    Postava hrac;
    hrac.kouzla = 0;
    hrac.armor = 0;

    cout << "------------- Ahoj, vitej v me hre! -------------\n";
    cout << "Chces zacit? (y/y): ";
    cin >> vstup;

    if (vstup != 'y' && vstup != 'Y') {
        cout << "Tak priste!" << endl;
        return 0;
    }

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
    } else if (vyber == 2) {
        hrac.jmeno = "Mag";
        hrac.maxHp = hrac.hp = 20;
        hrac.maxMana = hrac.mana = 50;
        hrac.utok = 15;
        hrac.zlato = 5;
    } else if (vyber == 3) {
        hrac.jmeno = "Rybar";
        hrac.maxHp = hrac.hp = 30;
        hrac.maxMana = hrac.mana = 15;
        hrac.utok = 28;
        hrac.zlato = 8;
    } else if (vyber == 4) {
        hrac.jmeno = "Rytir";
        hrac.maxHp = hrac.hp = 45;
        hrac.maxMana = hrac.mana = 15;
        hrac.utok = 25;
        hrac.zlato = 12;
    } else if (vyber == 5) {
        hrac.jmeno = "Kral";
        hrac.maxHp = hrac.hp = 25;
        hrac.maxMana = hrac.mana = 35;
        hrac.utok = 20;
        hrac.zlato = 20;
    } else {
        cout << "\nNespravna volba! Zvol cislo 1-5.\n";
        return 0;
    }

    hrac.level = 1;
    hrac.xp = 0;
    hrac.xpNaDalsiLevel = 10;

    while (hrac.hp > 0) {
        cout << "\n======================================";
        cout << "\nMuzes jit do dungeonu nebo do vesnice. \nCo si vyberes? (1 = vesnice / 2 = dungeon): ";
        cin >> vybermista;
        cout << " \n \n";

        if (vybermista == 1) {
            cout << "------------- Vitej ve vesnici Oglokoma -----------\n";
            cout << "HP: " << hrac.hp << "/" << hrac.maxHp << ", Zlato: " << hrac.zlato << ", Mana: " << hrac.mana << "/" << hrac.maxMana << ", Utok: " << hrac.utok << ", Zkusenosti: " << hrac.xp << ", Level: " << hrac.level << endl;
            cout << "\n";
            cout << "1) Upgradeovat armor (2 XP, 5 zlata)\n";
            cout << "2) Upgradeovat mec (2 XP, 5 zlata)\n";
            cout << "3) Naucit se kouzlo [" << hrac.kouzla << "/3] (2 XP, 5 zlata)\n";
            cout << "Tvoje volba: ";
            cin >> vyber;

            if (vyber == 1) {
                if (hrac.zlato >= 5 && hrac.xp >= 2) {
                    hrac.zlato -= 5;
                    hrac.xp -= 2;
                    hrac.armor += 1;
                    cout << "Armor byl vylepsen!\n";
                } else {
                    cout << "Nemas dost zlata nebo XP!\n";
                }
            } else if (vyber == 2) {
                if (hrac.zlato >= 5 && hrac.xp >= 2) {
                    hrac.zlato -= 5;
                    hrac.xp -= 2;
                    hrac.utok += 1;
                    cout << "Mec byl vylepsen!\n";
                } else {
                    cout << "Nemas dost zlata nebo XP!\n";
                }
            } else if (vyber == 3) {
                if (hrac.kouzla < 3 && hrac.zlato >= 5 && hrac.xp >= 2) {
                    hrac.kouzla++;
                    hrac.zlato -= 5;
                    hrac.xp -= 2;
                    cout << "Naucils se nove kouzlo! [" << hrac.kouzla << "/3]\n";
                } else if (hrac.kouzla >= 3) {
                    cout << "Uz znas vsechna kouzla!\n";
                } else {
                    cout << "Nemas dost zdroju!\n";
                }
            }

        } else if (vybermista == 2) {
            cout << "------------- Dungeon -----------\n";
            cout << "HP: " << hrac.hp << "/" << hrac.maxHp << ", Zlato: " << hrac.zlato << ", Mana: " << hrac.mana << "/" << hrac.maxMana << ", Utok: " << hrac.utok << endl;
            cout << "\n";
            cout << "1) Jedno monstrum\n";
            cout << "2) Dve monstra\n";
            cout << "3) Gang monster\n";
            cout << "4) Boss: Coincling (nedoporucuje se!)\n";
            cout << "Tvoje volba: ";
            cin >> vyber;

            switch (vyber) {
                case 1:
                    cout << "Bojujes s jednim monstrem!\n";
                    bojSJednimMonstrem(hrac);
                    zkontrolujLevelUp(hrac);
                    break;
                case 2:
                    cout << "Bojujes se dvema monstry!\n";
                    bojSeDvemaMonstry(hrac);
                    zkontrolujLevelUp(hrac);
                    break;
                case 3:
                    cout << "Bojujes s gangem monster!\n";
                    bojSGangem(hrac);
                    zkontrolujLevelUp(hrac);
                    break;
                case 4:
                    cout << "Postavil ses Coinclingovi!\n";
                    cout << "Hodne stesti!\n";
                    bojSBossem(hrac);
                    zkontrolujLevelUp(hrac);
                    break;
                default:
                    cout << "Nespravna volba v dungeonu.\n";
                    break;
            }
        }
    }

    cout << "\n=== GAME OVER ===" << endl;
    return 0;
}
