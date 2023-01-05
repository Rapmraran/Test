#ifndef CSLL_H_INCLUDED
#define CSLL_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define nil NULL

struct infotype {
    string artis;
    string judul;
    string genre;
    int playtime;
};


typedef struct element *adr;
struct element {
    infotype info;
    adr next;
};

struct listLagu {
    adr first;
};

void createList_1301213466(listLagu &L);
void createElement_1301213466(infotype laguBaru, adr &pLagu);
void insertLast_1301213466(listLagu &L, adr pLagu);
void deleteFirst_1301213466(listLagu &L, adr &pLagu);

void showSemuaLagu_1301213466(listLagu L);
void normalShow_1301213466(listLagu L, adr Q, int n);

void showSemuaLaguBelakang_1301213466(listLagu L);
void reverseShow_1301213466(listLagu L, adr Q, int n);

int selectMenu_1301213466();

void mains_1301213466(listLagu &L, infotype &lagu);
void masukAtauKeluar_1301213466(listLagu L,infotype lagu);


#endif // CSLL_H_INCLUDED
