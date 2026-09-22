#pragma once

// Bukan interface (cuma satu implementasi diminta di spec), tapi tetap
// dipisah jadi class sendiri supaya RunSession tidak tau detail shop.
class ShopSystem {
public:
    // Menampilkan tawaran shop untuk ronde ini. Hardcoded, boleh simple.
    void OfferItem(int roundNumber);
};
