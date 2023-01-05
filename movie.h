#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define nextRelasi(L) (L)->nextRelasi
#define first(L) ((L).first)
#define last(L) ((L).last)
#define aktor(P) (P)->aktor
#define prev(P) (P)->prev
#define mov(P) (P)->mov
#define null NULL

struct infotypeMovie
{
    string iedr;
    string namaFilm;
    int tahunRilis;
};
typedef struct elmMov *adrMov;
typedef struct elmRelasi *adrRelasi;
typedef struct elmAktor *adrAktor;

struct elmMov
{
   infotypeMovie info;
   adrMov next;
   adrRelasi nextRelasi;
};

struct listMov
{
    adrMov first;
    adrMov last;

};

struct elmRelasi
{
    adrAktor aktor;
    adrRelasi next;
};

struct infotypeAktor
{
    string id;
    string namaAktor;
    string genderAktor;
    int jumMov;
};

struct elmAktor
{
    infotypeAktor info;
    adrAktor next;
    adrAktor prev;
};

struct listAktor
{
    adrAktor first;
    adrAktor last;
};

struct listRelasi
{
    adrRelasi first;
};

void createListMovie(listMov &LM);
void createListAktor(listAktor &LA);
adrAktor createElmAktor(infotypeAktor data);
adrMov createElmMovie(infotypeMovie data);
void createElmRelasi(adrMov m,adrAktor a,adrRelasi &R);

void addMovie(listMov &LM, adrMov P);
void addAktor(listAktor &LA, adrAktor P);
void insertLastRelasi(listRelasi &LR, adrRelasi R);

void showMovie(listMov LM);
void showAktor(listAktor LA);

adrMov findMov(listMov LM, string iedr);
adrAktor findAktor(listAktor LA, string id);


void deleteFirstMov(listMov &LM, adrMov P);
void deleteLastMov(listMov &LM, adrMov P);
void deleteAfterMov(adrMov P, adrMov prec);
void deleteMov(listMov &LA, string iedr);
void deleteAktorDiMovie(adrMov &m, adrRelasi &r);

void deleteFirstRelasi(adrMov &m, adrRelasi P );
void deleteLastRelasi(adrMov &m, adrRelasi P);
void deleteAfterRelasi(adrRelasi &r, adrRelasi &prec);

infotypeMovie inputMov(string namaFilm, int tahunRilis);
infotypeAktor inputAktor(string namaAktor, string genderAktor);
void createRelasi(adrMov m, adrAktor a);
void showMovieDanAktor(listMov LM, string iedr);
void showAllMovieAktor(listMov LM, listAktor LA);
void countMovieByAktor(adrAktor a);
void MovieWithMostAktris(listAktor LA, listMov LM);

adrRelasi findRelasi(adrMov m, string id);
void aktorWithMovie(listMov LM, adrAktor a);






#endif // MOVIE_H_INCLUDED
