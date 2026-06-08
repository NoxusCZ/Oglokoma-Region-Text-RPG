# ⚔️ Oglokoma Region: Text RPG

![Stav Projektu](https://img.shields.io/badge/Stav_Projektu-Ve_Vývoji_(WIP)-yellow?style=for-the-badge)
![Verze](https://img.shields.io/badge/Verze-0.3.0_Pre--Alpha-green?style=for-the-badge)
![Licence](https://img.shields.io/badge/Licence-MIT-blue?style=for-the-badge)
![Jazyk](https://img.shields.io/badge/Jazyk-C%2B%2B-orange?style=for-the-badge)

Vítej, dobrodruhu! Vstupuješ do světa drsného středověku, kde o tvém osudu rozhodují jen tvá vlastní rozhodnutí, ostrost tvého meče a množství zlaťáků v kapse. **Oglokoma Region** je textové RPG, které tě vrátí ke kořenům klasických her na hrdiny.

> 🔨 **Stavba světa v plném proudu:** Vesnice Oglokoma už stojí a kováři žhaví pece. Dungeony jsou otevřené a plné monster — od obyčejných Zombie až po bosse Coinclinga. Detaily o tom, co se chystá, najdeš v sekci [Roadmapa](#-co-tě-čeká-v-budoucích-updatech).

---

## 🎭 Vyber si svůj osud

Hned na začátku se musíš rozhodnout, kým v tomto světě budeš. Každá role vyžaduje úplně jiný styl hraní:

| Třída | HP | Mana | Útok | Zlato | Styl hraní |
|---|---|---|---|---|---|
| 🗡️ **Lupič** | 25 | 10 | 35 | 10 | Rychlý a smrtící, ale křehký |
| 🔮 **Mág** | 20 | 50 | 15 | 5 | Slabý fyzicky, ale má nejvíc many na kouzla |
| 🐟 **Rybář** | 30 | 15 | 28 | 8 | Vybalancovaný bojovník |
| 🛡️ **Rytíř** | 45 | 15 | 25 | 12 | Největší HP, vydrží nejvíc ran |
| 👑 **Král** | 25 | 35 | 20 | 20 | Nejbohatší na start, ale boss ho za to potrestá |

---

## 🗡️ Bojový systém

V dungeonu si vyběreš z těchto soupeřů:

- **Jedno monstrum** — jednoduchý souboj, +5 XP za výhru
- **Dvě monstra** — musíš volit na koho útočíš, +10 XP za výhru
- **Gang monster** — 4 nepřátelé najednou, +20 XP za výhru
- **Boss: Coincling** — speciální mechanika, nedoporučuje se bez přípravy

### Monstra
| Jméno | HP | Útok |
|---|---|---|
| Zombie | 40 | 10 |
| Upír | 30 | 20 |
| Amperistha | 60 | 15 |

### V boji máš dvě možnosti:
- **Meč** — spolehlivý, žádná mana
- **Kouzlo** — vybereš konkrétní kouzlo a cíl

### Kouzla
| Kouzlo | Poškození | Cena many | Efekt |
|---|---|---|---|
| 🔥 Ohnivá koule | 25 dmg | 10 many | — |
| ⚡ Blesk | 40 dmg | 20 many | — |
| ❄️ Ledová střela | 15 dmg | 5 many | Nepřítel příští kolo neutočí |

Kouzla se musí nejdřív naučit ve vesnici.

---

## 👹 Boss: Coincling

Coincling je speciální nepřítel s unikátní mechanikou postavenou na zlatě:

- Hned na začátku ti vezme HP rovné tvému aktuálnímu zlatu
- Pak ti hodí 20 zlata (záměrně tě tím obohatí)
- Každé kolo se jeho útok počítá z tvého zlata — čím víc máš, tím víc bolí
- V závislosti na množství tvého zlata může krást max HP, léčit sebe nebo způsobit poškození oběma

---

## 🏡 Vesnice Oglokoma

Vesnice je tvé útočiště mezi výpravami. Za zlato a XP si můžeš:

- **Vylepšit brnění** — +1 armor (2 XP, 5 zlata)
- **Vylepšit meč** — +1 útok (2 XP, 5 zlata)
- **Naučit se kouzlo** — odemkne kouzla v boji, max 3 kouzla (2 XP, 5 zlata)

---

## 📈 Level up

Za výhry sbíráš XP. Jakmile dosáhneš prahu, automaticky postoupíš na vyšší level:

- +10 max HP (a HP se doplní na maximum)
- +2 útok
- Každý další level vyžaduje o 10 XP víc

---

## 🗺️ Co tě čeká v budoucích updatech?

- [ ] **💰 Loot ze soupeřů** — zlato za zabití monster
- [ ] **❤️ Léčení ve vesnici** — možnost obnovit HP za zlato
- [ ] **🏰 Více lokací** — rozšíření světa za vesnici Oglokoma
- [ ] **💾 Ukládání hry** — aby ses nemusel bát zavřít terminál

---

## ⚠️ Varování pro zbabělce!

Hra si potrpí na hrdiny. Pokud hned na úvodní obrazovce odmítneš výzvu k dobrodružství (zvolíš cokoli jiného než `y/Y`), tvůj počítač zasáhne prastará kletba. Falešný ransomware ti začne "mazat" System32, šifrovat disky a nakonec ti bez milosti natvrdo vypne PC. **Vstup jen na vlastní nebezpečí!**

---

## 🚀 Jak hru spustit

Máš odvahu? Zkompiluj hru pomocí jakéhokoli C++ kompilátoru a naskoč do příběhu:

```bash
# Zkompilování hry
g++ main.cpp -o hra

# Spuštění dobrodružství
./hra
```
