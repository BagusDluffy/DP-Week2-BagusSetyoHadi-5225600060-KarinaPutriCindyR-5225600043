#pragma once

// Struct data murni (POD). Ini bukan class ber-behavior, cuma wadah data
// hasil dari IInputGenerator. Sengaja dipisah biar IScoringRule bisa
// nerima ini tanpa perlu tau siapa yang bikin.
struct TurnInput {
    int value; // nilai kartu/angka input untuk ronde ini
};
