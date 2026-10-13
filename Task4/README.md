# Core Loop: Balatro-Like Card Game (C++)

Implementasi dummy dari materi **Design Pattern: Core Loop** dan **Chain of Responsibility**.

## Core Loop

```
Generate Hand → Play Hand → Score Hand → Check Win Condition → Earn Money
```

Urutan fase di atas adalah struktur yang tetap (invariant). Rumus skor, syarat menang, dan hadiah bisa berubah (mutable) tanpa mengubah alur loop.

## Alur Scoring (Chain of Responsibility)

```
GameManager
   ↓
ScoringRule::scoreHand(hand)
   ↓
FullHouseChecker → FlushChecker → PairChecker
   ↓
HandRank
   ↓
convertRankToScore()
   ↓
score
```

Setiap checker hanya mengecek satu aturan. Kalau tidak cocok, hand diteruskan ke checker berikutnya. Kalau tidak ada yang cocok, hasilnya `HIGH_CARD`.

## Struktur File

| File | Fungsi |
|------|--------|
| `main.cpp` | Entry point, menjalankan `GameManager` |
| `Hand.h` | Struct `Hand` (dummy, hanya `value`) |
| `GameManager.h/.cpp` | Mengatur urutan fase core loop |
| `HandGenerator.h/.cpp` | Fase Generate Hand |
| `HandPlayer.h/.cpp` | Fase Play Hand |
| `ScoringRule.h/.cpp` | Fase Score Hand, memegang chain checker |
| `BlindRule.h/.cpp` | Fase Check Win Condition |
| `RewardRule.h/.cpp` | Fase Earn Money |
| `PokerHandChecker.h/.cpp` | Abstract base class + `HandRank` + `setNext()` |
| `FullHouseChecker.h/.cpp` | Checker Full House |
| `FlushChecker.h/.cpp` | Checker Flush |
| `PairChecker.h/.cpp` | Checker Pair |

## Nilai Dummy

| `hand.value` | Hand | Skor |
|--------------|------|------|
| 7 | Full House | 25 |
| 6 | Flush | 20 |
| 2 | Pair | 10 |
| lainnya | High Card | 5 |

`HandGenerator` saat ini menghasilkan `value = 6` (Flush). Blind dianggap menang jika skor >= 5.

## Cara Compile dan Run

Butuh compiler dengan dukungan C++17.

```bash
g++ -std=c++17 -Wall *.cpp -o coreloop
./coreloop
```

Di Windows (MinGW): `coreloop.exe`.

## Contoh Output

```
=== Run Started ===
Generating cards for player...
Player selects cards to play...
Calculating hand score...
Detected FLUSH
Final score = 20
Checking blind requirement...
Result: WIN
Calculating reward...
Money gained: 20
=== Run Ended ===
```

## Pembagian Kerja

**Anggota 1: Core Loop**
`main.cpp`, `Hand.h`, `GameManager`, `HandGenerator`, `HandPlayer`, `BlindRule`, `RewardRule`

**Anggota 2: Chain of Responsibility + Scoring**
`PokerHandChecker`, `FlushChecker`, `FullHouseChecker`, `PairChecker`, `ScoringRule`
