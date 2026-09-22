# Task 2 -- Develop Your Own Core Loop

> **PENTING:** Kode & penjelasan di bawah ini pakai contoh generik
> "turn-based mini combat" karena aku belum tau konsep game pretest kamu
> yang asli. Ganti `SimpleActionHandler` / `SimpleCombatResolver` /
> `SimpleProgressionRule` dengan mekanik game kamu sendiri, lalu update
> jawaban reflection di bawah supaya sesuai game asli kamu.

## Cara compile & run
```
g++ -std=c++17 *.cpp -o game
./game
```

## Step 1 -- Core Loop
1. Player selects action
2. System resolves combat (hitung damage)
3. Reward dihitung & game state (score, HP) di-update
4. Check win/lose condition
5. Repeat

## Step 2 -- Invariants
1. Urutan 5 langkah di atas tidak boleh ditukar -- misalnya reward tidak
   bisa dihitung sebelum damage diketahui.
2. Komponen yang wajib selalu ada: satu `IActionHandler`, satu
   `ICombatResolver`, satu `IProgressionRule`, dan state HP/score di
   `GameSession`.
3. Kalau urutan ditukar (misalnya update HP sebelum resolve damage),
   damage yang dihitung jadi tidak konsisten dengan HP yang tersisa saat itu.

## Step 3 -- Elemen Mutable
1. **Damage multiplier** (`SimpleCombatResolver`) -- bisa naik/turun untuk
   tuning balance tanpa mengubah urutan loop.
2. **Reward formula** (`SimpleProgressionRule`) -- cara score dihitung dari
   damage bisa diganti kapan saja.
3. **Biaya HP per ronde** (di `GameSession::StartGame`, bisa dipindah jadi
   parameter) -- besarannya bisa disesuaikan untuk mengubah tingkat
   kesulitan tanpa mengubah struktur fase.

## Step 4 -- Reflection

**1. Apa invariant structure game ini?**
Urutan fase pada `GameSession::StartGame()`: player action -> resolve
combat -> hitung reward & update state -> cek game over -> repeat. Urutan
ini konsisten setiap ronde terlepas dari mekanik konkret di baliknya.

**2. Apa bagian yang mutable?**
Implementasi konkret di balik tiap interface -- cara aksi dipilih
(`IActionHandler`), rumus damage (`ICombatResolver`), dan rumus reward
(`IProgressionRule`) -- beserta angka-angka tuning seperti damage
multiplier dan biaya HP per ronde.

**3. Kalau mau nambah fitur baru, class mana yang berubah?**
Tergantung fiturnya: fitur combo/skill baru cukup ubah/tambah implementasi
`ICombatResolver`; sistem reward baru (misal combo bonus) cukup ubah
`IProgressionRule`. `GameSession` sendiri tidak perlu diubah selama fitur
baru masih mengikuti kontrak interface yang sama.

**4. Kalau urutan loop diubah, apa yang rusak?**
Misalnya kalau HP dikurangi sebelum damage dihitung, reward yang didapat
bisa dihitung dari kondisi game yang sudah tidak akurat, dan pengecekan
game over bisa salah menghentikan game sebelum aksi ronde itu benar-benar
selesai diproses.
