#include "../template.cpp"

struct Dice {
    int U, D, L, R, F, B;
    Dice(int U, int D, int L, int R, int F, int B) :
        U(U), D(D), L(L), R(R), F(F), B(B) {}

    void rollU() {
        int buff = F;
        F = R; R = B; B = L; L = buff;
    }
    void rollD() {
        int buff = F;
        F = L; L = B; B = R; R = buff;
    }
    void rollF() {
        int buff = U;
        U = L; L = D; D = R; R = buff;
    }
    void rollB() {
        int buff = U;
        U = R; R = D; D = L; L = buff;
    }
    void rollR() {
        int buff = U;
        U = F; F = D; D = B; B = buff;
    }
    void rollL() {
        int buff = U;
        U = B; B = D; D = F; F = buff;
    }
};
