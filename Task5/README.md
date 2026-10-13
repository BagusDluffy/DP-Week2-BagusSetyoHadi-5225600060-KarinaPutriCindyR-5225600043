# Balatro-Like Card Game (C++)

Prototype game kartu ala Balatro yang menerapkan tiga konsep design pattern dalam satu proyek:

1. **Core Loop**: urutan fase gameplay yang tetap
2. **Chain of Responsibility**: pengecekan jenis hand secara berurutan
3. **Command Pattern**: aksi pemain dibungkus jadi object

## 1. Core Loop

```
Generate Hand → Play Hand → Score Hand → Check Win Condition → Earn Money
```

`GameManager::runSession()` menjalankan fase-fase tersebut. Urutan fase adalah bagian yang tetap (invariant), sedangkan rumus skor, syarat menang, dan hadiah bisa berubah (mutable).

## 2. Chain of Responsibility (Hand Checker)

`ScoringRule` memegang chain checker. Setiap checker menangani hand yang cocok dengan aturannya, kalau tidak cocok diteruskan ke checker berikutnya.

```
FlushChecker → StraightChecker → (tidak ada yang cocok: HIGH_CARD)
```

`PokerHandChecker` adalah abstract base class yang menyimpan `nextChecker` dan `setNext()`. Hasil chain berupa `HandRank`, lalu `convertRankToScore()` mengubahnya jadi skor.

| `hand.value` | Hand | Skor |
|--------------|------|------|
| 6 | Flush | 20 |
| 5 | Straight | 15 |
| lainnya | High Card | 5 |

## 3. Command Pattern (Play Hand)

Fase Play Hand tidak dipanggil langsung, tetapi lewat command:

```
InputHandler (Invoker) → PlayHandCommand (Command) → HandPlayer (Receiver)
```

- `Command.h`: interface dengan `execute()`
- `PlayHandCommand.h`: command yang memanggil `HandPlayer::playHand()`
- `InputHandler`: invoker, hanya tahu cara menjalankan command

## Alur Lengkap

```
GameManager
   ├─ HandGenerator::generateHand()  → Hand
   ├─ InputHandler → PlayHandCommand → HandPlayer::playHand()
   ├─ ScoringRule::scoreHand(hand)   → FlushChecker → StraightChecker → HandRank → score
   ├─ BlindRule::checkBlind(score)   → win / lose
   └─ RewardRule::earnMoney(win, score)
```

## Struktur File

| File | Fungsi |
|------|--------|
| `main.cpp` | Entry point |
| `Hand.h` | Struct `Hand` (dummy, hanya `value`) |
| `GameManager.h/.cpp` | Mengatur urutan core loop |
| `HandGenerator.h/.cpp` | Fase Generate Hand (dummy, selalu `value = 6`) |
| `HandPlayer.h/.cpp` | Fase Play Hand (receiver) |
| `ScoringRule.h/.cpp` | Fase Score Hand, memegang chain checker |
| `BlindRule.h/.cpp` | Fase Check Win Condition (menang jika skor >= 5) |
| `RewardRule.h/.cpp` | Fase Earn Money |
| `PokerHandChecker.h/.cpp` | Abstract handler + `HandRank` + `setNext()` |
| `FlushChecker.h/.cpp` | Concrete handler Flush |
| `StraightChecker.h/.cpp` | Concrete handler Straight |
| `Command.h` | Interface Command |
| `PlayHandCommand.h` | Concrete command Play Hand |
| `InputHandler.h/.cpp` | Invoker |

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

**Anggota 1:** Core Loop: `README.md`, `main.cpp`, `Hand.h`, `GameManager`, `HandGenerator`, `HandPlayer`, `BlindRule`, `RewardRule`

**Anggota 2:** Chain of Responsibility dan Command Pattern: `PokerHandChecker`, `FlushChecker`, `StraightChecker`, `ScoringRule`, `Command.h`, `PlayHandCommand.h`, `InputHandler`
