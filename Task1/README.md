# Task 1 -- Building a Balatro-Like Run

## Cara compile & run
```
g++ -std=c++17 *.cpp -o run
./run
```

## Struktur file
| File | Peran |
|---|---|
| `TurnInput.h` | Struct data hasil input per ronde |
| `IInputGenerator.h` | Interface generator input |
| `ManualInputGenerator.h/.cpp` | Implementasi awal (fixed value) |
| `RandomInputGenerator.h/.cpp` | Implementasi Modifikasi 1 |
| `IScoringRule.h` | Interface penghitung base score |
| `BasicScoringRule.h/.cpp` | Implementasi scoring |
| `IRewardRule.h` | Interface penghitung reward |
| `BasicRewardRule.h/.cpp` | Reward = base score (versi awal) |
| `ModifiedRewardRule.h/.cpp` | Implementasi Modifikasi 2 |
| `ShopSystem.h/.cpp` | Cetak tawaran shop |
| `RunSession.h/.cpp` | Orkestrator, urutan fase tetap |
| `main.cpp` | Wiring: bikin instance konkret & inject ke RunSession |

## Reflection

**1. Apa invariant structure dalam program ini?**
Urutan enam fase di dalam `RunSession::StartRun()`: generate input -> compute
base score -> compute reward -> update money -> shop phase -> advance round.
Urutan ini tetap sama di setiap ronde dan tidak boleh berubah walau
implementasi di baliknya diganti.

**2. Bagian mana yang mutable?**
Implementasi konkret di balik tiap interface: cara input dihasilkan
(`ManualInputGenerator` vs `RandomInputGenerator`), rumus scoring
(`BasicScoringRule`), dan rumus reward (`BasicRewardRule` vs
`ModifiedRewardRule`). Semua ini bisa diganti tanpa mengubah urutan fase.

**3. Kenapa RunSession tidak berubah waktu InputGenerator diganti?**
Karena `RunSession` hanya bergantung pada interface `IInputGenerator`, bukan
pada kelas konkretnya. `RunSession` memanggil `m_inputGen->Generate()` tanpa
peduli objek di baliknya `ManualInputGenerator` atau `RandomInputGenerator`.
Penggantian implementasi cukup dilakukan di `main.cpp`, tempat objek konkret
dibuat dan di-inject lewat constructor.

**4. Apa yang terjadi kalau scoring logic dipindah ke dalam RunSession?**
`RunSession` jadi tahu detail cara menghitung skor, sehingga setiap kali
aturan skor berubah, kelas orkestrator ini ikut harus diubah. Ini melanggar
prinsip pemisahan tanggung jawab, membuat `RunSession` sulit diuji secara
terpisah, dan menghilangkan kemampuan menukar strategi skor secara dinamis
seperti yang dilakukan lewat `IScoringRule` saat ini.
