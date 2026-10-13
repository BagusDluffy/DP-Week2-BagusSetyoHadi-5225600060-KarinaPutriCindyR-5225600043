# Design Pattern Demo (C++)

Tiga contoh program C++ yang masing-masing berdiri sendiri (punya `main.cpp` sendiri):

| Folder | Isi | Sumber |
|--------|-----|--------|
| `1_ChainOfResponsibility/` | Sistem support ticket dengan Chain of Responsibility | PDF *Chain of Responsibility in C++ and Command Pattern* |
| `2_CommandPattern/` | Player, Command, dan InputHandler dengan Command Pattern | PDF *Chain of Responsibility in C++ and Command Pattern* |
| `3_BalatroCoreLoop/` | Core loop game kartu ala Balatro dengan checker FlushChecker dan StraightChecker | PDF *Balatro* (class diagram) dan materi Core Loop |

## 1. Chain of Responsibility (Support Ticket)

Satu request melewati beberapa handler. Setiap handler menangani atau meneruskan ke handler berikutnya.

```
BasicSupport → TechnicalSupport → Manager
```

| Request | Ditangani oleh |
|---------|----------------|
| `password` | BasicSupport |
| `software` | TechnicalSupport |
| `billing` | Manager |
| `network` | tidak ada (`No handler could process the request.`) |

File: `SupportRequest.h`, `SupportHandler.h/.cpp` (abstract handler), `BasicSupport`, `TechnicalSupport`, `Manager`, `main.cpp`

## 2. Command Pattern

Perilaku dibungkus menjadi object sehingga bisa disimpan, dikirim, dan dieksekusi belakangan.

```
Invoker (InputHandler) → Command → Receiver (Player)
```

File: `Command.h` (interface), `Player.h/.cpp` (receiver), `MoveCommand.h`, `AttackCommand.h`, `InputHandler.h/.cpp` (invoker), `main.cpp`

`main.cpp` menunjukkan dua cara pakai: eksekusi langsung lewat `InputHandler`, dan eksekusi dari `std::vector<Command*>`.

## 3. Balatro Core Loop

```
Generate Hand → Play Hand → Score Hand → Check Win Condition → Earn Money
```

Scoring memakai Chain of Responsibility:

```
GameManager → ScoringRule::scoreHand(hand) → FlushChecker → StraightChecker → HandRank → score
```

| `hand.value` | Hand | Skor |
|--------------|------|------|
| 6 | Flush | 20 |
| 5 | Straight | 15 |
| lainnya | High Card | 5 |

`HandGenerator` masih dummy dan selalu menghasilkan `value = 6` (Flush). Blind menang jika skor >= 5.

File: `main.cpp`, `Hand.h`, `GameManager`, `HandGenerator`, `HandPlayer`, `ScoringRule`, `BlindRule`, `RewardRule`, `PokerHandChecker`, `FlushChecker`, `StraightChecker`

## Cara Compile dan Run

Butuh compiler dengan dukungan C++17. Jalankan di dalam masing-masing folder:

```bash
cd 1_ChainOfResponsibility
g++ -std=c++17 -Wall *.cpp -o app
./app
```

Ulangi dengan folder `2_CommandPattern` dan `3_BalatroCoreLoop`. Di Windows (MinGW) jalankan `app.exe`.

## Contoh Output

**1_ChainOfResponsibility**
```
BasicSupport handled the password issue.
BasicSupport passed the request.
TechnicalSupport handled the software issue.
BasicSupport passed the request.
TechnicalSupport passed the request.
Manager handled the billing issue.
BasicSupport passed the request.
TechnicalSupport passed the request.
Manager passed the request.
No handler could process the request.
```

**2_CommandPattern**
```
--- Direct execution via InputHandler ---
Player moves
Player attacks
--- Stored commands (queue) ---
Player moves
Player moves
Player attacks
```

**3_BalatroCoreLoop**
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

**Anggota 1:** `README.md`, `1_ChainOfResponsibility/`, `2_CommandPattern/`

**Anggota 2:** `3_BalatroCoreLoop/`
