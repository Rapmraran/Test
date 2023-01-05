#include "CSLL.h"

void createList_1301213466(listLagu &L){
    first(L) = nil;
}
void createElement_1301213466(infotype laguBaru, adr &pLagu){
    pLagu = new element;
    info(pLagu).artis = laguBaru.artis;
    info(pLagu).genre = laguBaru.genre;
    info(pLagu).judul = laguBaru.judul;
    info(pLagu).playtime = 0;
}
void insertLast_1301213466(listLagu &L, adr pLagu){
    adr Q = first(L);
    if (first(L) == nil) {
        first(L) = pLagu;
        Q = first(L);
        next(Q) = first(L);
    } else {
        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        next(pLagu) = first(L);
        next(Q) = pLagu;
    }
}
void deleteFirst_1301213466(listLagu &L, adr &pLagu){
    adr Q = first(L);
    if (first(L) == nil) {
        pLagu = nil;
    } else if (next(Q) == first(L)) {
        pLagu = first(L);
        first(L) = nil;
        next(pLagu) = nil;
    } else {
        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        pLagu = first(L);
        first(L) = next(first(L));
        next(Q) = first(L);
        next(pLagu) = nil;
    }
}
void showSemuaLagu_1301213466(listLagu L) {
    adr Q = first(L);
    int n = 1;
    if (Q == nil) {
        cout << "List Kosong" << endl << endl;
    } else {
        normalShow_1301213466(L, Q, n);
    }
}
void normalShow_1301213466(listLagu L, adr Q, int n) {
    if (next(Q) == first(L)) {
        cout << "Lagu Ke " << n << endl;
        cout << "Artis    : " << info(Q).artis << endl;
        cout << "Judul    : " << info(Q).judul << endl;
        cout << "Genre    : " << info(Q).genre << endl;
        cout << "Playtime : " << info(Q).playtime << endl << endl;
    } else {
        cout << "Lagu Ke " << n << endl;
        cout << "Artis    : " << info(Q).artis << endl;
        cout << "Judul    : " << info(Q).judul << endl;
        cout << "Genre    : " << info(Q).genre << endl;
        cout << "Playtime : " << info(Q).playtime << endl << endl;
        normalShow_1301213466(L, next(Q), n+1);
    }
}
void showSemuaLaguBelakang_1301213466(listLagu L){
    adr Q = first(L);
    int n = 1;
    if (Q == nil) {
        cout << "List Kosong" << endl << endl;
    } else {
         adr prec = first(L);
         while (next(prec) != first(L)) {
            n = n + 1;
            prec = next(prec);
        }
        reverseShow_1301213466(L, Q, n);
    }
}
void reverseShow_1301213466(listLagu L, adr Q, int n) {
    if (next(Q) == first(L)) {
        cout << "Lagu Ke " << n << endl;
        cout << "Artis    : " << info(Q).artis << endl;
        cout << "Judul    : " << info(Q).judul << endl;
        cout << "Genre    : " << info(Q).genre << endl;
        cout << "Playtime : " << info(Q).playtime << endl << endl;
    } else {
        reverseShow_1301213466(L, next(Q), n-1);
        cout << "Lagu Ke " << n << endl;
        cout << "Artis    : " << info(Q).artis << endl;
        cout << "Judul    : " << info(Q).judul << endl;
        cout << "Genre    : " << info(Q).genre << endl;
        cout << "Playtime : " << info(Q).playtime << endl << endl;
    }
}
int selectMenu_1301213466(){
    cout << "====================MENU====================";
    cout << endl;
    cout << "1. Tambah lagu di akhir Playlist";
    cout << endl;
    cout << "2. Tampilkan semua isi Playlist";
    cout << endl;
    cout << "3. Tampilkan semua isi Playlist dari belakang";
    cout << endl;
    cout << "4. Hapus lagu dari depan Playlist dan Tampilkan lagu yang telah dihapus";
    cout << endl;
    cout << "0. Exit";
    cout << endl << endl;
    cout << "Masukkan menu : ";
    int masukan;
    masukan = 0;
    cin >> masukan;
    cout << endl;
    return masukan;
}

void mains_1301213466(listLagu &L, infotype &lagu) {
    int isi;
    isi = selectMenu_1301213466();
    if (isi == 0) {
        cout << "Anda telah keluar dari program" << endl;
    } else if (isi == 1) {
        int N;
        int i = 1 ;
        adr P;
        cout << "Jumlah data yang akan ditambahkan : ";
        cin >> N;
        cout << endl;
        while (i <= N){
            cout << "Data ke " << i << endl;
            cout << "Artis    : ";
            cin >> lagu.artis;
            cout << "Judul    : ";
            cin >> lagu.judul;
            cout << "Genre    : ";
            cin >> lagu.genre;
            cout << "Playtime : ";
            cin >> lagu.playtime;
            cout << endl;
            createElement_1301213466(lagu, P);
            insertLast_1301213466(L, P);
            i = i + 1;
        }
        cout << endl;
        masukAtauKeluar_1301213466(L, lagu);
    } else if (isi == 2) {
        showSemuaLagu_1301213466(L);
        masukAtauKeluar_1301213466(L, lagu);
    } else if (isi == 3) {
        showSemuaLaguBelakang_1301213466(L);
        masukAtauKeluar_1301213466(L, lagu);
    } else if (isi == 4) {
        adr P;
        deleteFirst_1301213466(L, P);
        cout << "Lagu yang dihapus adalah " << endl;
        cout << "Artis    : " << info(P).artis << endl;
        cout << "Judul    : " << info(P).judul << endl;
        cout << "Genre    : " << info(P).genre << endl;
        cout << "Playtime : " << info(P).playtime << endl << endl;
        masukAtauKeluar_1301213466(L, lagu);
    }
}
void masukAtauKeluar_1301213466(listLagu L,infotype lagu){
    string pilihan;
    cout << "Apakah anda ingin melanjutkan program ? (Y/N)" << endl;
    cout << "Pilihan anda : ";
    cin >> pilihan;
    cout << endl;
    if (pilihan == "Y") {
        mains_1301213466(L, lagu);
    } else if (pilihan == "N") {
        cout << "Anda telah keluar dari program" << endl;
    } else {
        cout << "Maaf, pilihan anda tidak tersedia dalam perintah" << endl << endl;;
        masukAtauKeluar_1301213466(L, lagu);
    }
}
