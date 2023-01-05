#include "movie.h"

void createListMovie(listMov &LM)
{
    first(LM) = NULL;
    last(LM) = NULL;
};

void createListAktor(listAktor &LA)
{
    first(LA) = NULL;
    last(LA) = NULL;
};

adrMov createElmMovie(infotypeMovie data)
{
    adrMov P = new elmMov;
    info(P) = data;
    nextRelasi(P) = NULL;
    next(P) = NULL;
    return P;
};

adrAktor createElmAktor(infotypeAktor data)
{
    adrAktor P = new elmAktor;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
};


void addMovie(listMov &LM, adrMov P)
{
    if(first(LM) == NULL){
        first(LM) = P;
        nextRelasi(first(LM)) = NULL;
    }else if(next(first(LM)) == NULL){
        next(first(LM)) = P;
        last(LM) = P;
    }
    else{
       next(last(LM)) = P;
       nextRelasi(last(LM)) = NULL;
       last(LM) = P;
    }
};

void addAktor(listAktor &LA, adrAktor P)
{
    if(first(LA) == NULL){
        first(LA) = P;
        next(P) = first(LA);
        prev(P) = last(LA);
        last(LA) = P;
    }
    // cek satu elemen
    else if(first(LA) == last(LA)){
        last(LA) = P;
        next(first(LA)) = P;
        prev(P) = first(LA);
        next(P) = first(LA);
    }

    else{
        next(P) = first(LA);
        prev(P) = last(LA);
        next(last(LA)) = P;
        prev(first(LA)) = P;
        last(LA) = P;
    }

};

void insertLastRelasi(listRelasi &LR, adrRelasi R)
{
    if(first(LR) == NULL){
        first(LR) = R;
    }
    else{
        adrRelasi Q = first(LR);
        while (next(Q) != NULL)
        {
            Q =next(Q);
        }
        next(Q) = R;

    }
};

void showMovie(listMov LM)
{
    adrMov X;
    X = first(LM);
    while(X != NULL){
        cout << info(X).namaFilm << " ";
        cout << info(X).tahunRilis << " ";
        X = next(X);
        cout << endl;
    }
    cout << endl;
};
void showAktor(listAktor LA)
{
    adrAktor Y;
    Y = first(LA);
    if(first(LA) == NULL){
        cout << "List Kosong"<< endl;
    }
    else{
        while(next(Y) != first(LA)){
            cout << info(Y).namaAktor << " ";
            cout << info(Y).genderAktor << " ";
            Y = next(Y);
            cout<<endl;
            }
        cout << info(Y).namaAktor << " ";
        cout << info(Y).genderAktor << " ";
        cout<<endl;
        }
};

infotypeMovie inputMov(string namaFilm, int tahunRilis)
{
    infotypeMovie data;
    data.namaFilm = namaFilm;
    data.tahunRilis = tahunRilis;
    return data;
};
infotypeAktor inputAktor(string namaAktor, int genderAktor)
{
    infotypeAktor data;
    data.namaAktor = namaAktor;
    data.genderAktor = genderAktor;
    return data;
};

adrMov findMov(listMov LM, string iedr)
{
    adrMov Q;
    Q = first(LM);
    while(Q!= NULL){
        if(info(Q).iedr == iedr){
            return Q;
        }
        Q = next(Q);
    }
    return NULL;

};

adrAktor findAktor(listAktor LA, string id)
{
    adrAktor Q;
    Q = first(LA);
    do{
        if(info(Q).id == id){
            return Q;
        }
        Q = next(Q);
    }while(Q != first(LA));
    return NULL;
};

void createRelasi(adrMov m, adrAktor a){
    adrRelasi nr, newr;
    nr = nextRelasi(m);

    newr = new elmRelasi;

    if(nr == NULL){
        next(newr) = NULL;
        aktor(newr) = a;
        nextRelasi(m) = newr;
    }else{
        while(next(nr) != NULL){
            nr = next(nr);
        }
        aktor(newr) = a;
        next(nr) = newr;
        next(newr) = NULL;
    }
    info(a).jumMov += 1;

}

void showMovieDanAktor(listMov LM, string iedr){
    adrMov m = findMov(LM, iedr);
    adrRelasi R = nextRelasi(m);
    if(R == NULL){
        cout << "tidak ada" << endl;
    }else{
        cout << "Movie: " << "========== "<< info(m).namaFilm <<" =========="<< endl;
        cout << "Aktor: ";
        while(R != NULL){
            cout << info(aktor(R)).namaAktor << ", ";
            R = next(R);

        }
        cout << endl;
    }
}

void deleteFirstMov(listMov &LM, adrMov P)
{
    if(first(LM) == NULL){
        cout << "LIST KOSONG" << endl;
    }
    else{
        first(LM) = next(P);
        nextRelasi(P) = NULL;
        next(P) = NULL;
    }


};
void deleteLastMov(listMov &LM, adrMov P)
{
    if(first(LM) == NULL){
        cout << "LIST KOSONG" << endl;
    }
    else{
    adrMov Q;
        while( Q != last(LM)){
            Q = next(Q);
            next(Q) = P;
            next(P) = NULL;
            nextRelasi(P) = NULL;
        }
    }
};

void deleteAfterMov(adrMov P, adrMov prec)
{
    P = next(prec);
    next(prec) = next(P);
    next(P) = NULL;
    nextRelasi(P) = NULL;
};

void deleteMov(listMov &LM, string iedr)
{
    adrMov m = findMov(LM, iedr);

    if(m == NULL){
        cout << "Film tidak ditemukan!" << endl;
    }
    else if(m == first(LM)){
        deleteFirstMov(LM, m);
    }
    else if( m == last(LM)){
        deleteLastMov(LM,m);
    }
    else{
        deleteAfterMov(m, m);
    }
};

void showAllMovieAktor(listMov LM, listAktor LA)
{
    adrMov M;
    M = first(LM);
    while(M != NULL){
        showMovieDanAktor(LM, info(M).iedr);
        M = next(M);
    }
    cout << endl;

};

void deleteFirstRelasi(adrMov &m, adrRelasi P){
    P = nextRelasi(m);
    nextRelasi(m) = next(P);
    next(P) = NULL;
    aktor(P) = null;
}

void deleteLastRelasi(adrMov &m, adrRelasi P){
    adrRelasi Q;
    Q = nextRelasi(m);

    while(Q != NULL){
        Q = next(Q);
    }
    next(Q) = NULL;
    aktor(Q) = null;
}

void deleteAfterRelasi(adrRelasi &r, adrRelasi &prec){
    r = next(prec);
    next(prec) = next(r);
    next(r) = NULL;
    aktor(r) = null;
}

adrRelasi findRelasi(adrMov m, string id){
    adrRelasi r = nextRelasi(m);
    while(r != null){
        if(info(aktor(r)).id == id){
            return r;
        }
        r = next(r);
    };
    return null;
}

void deleteAktorDiMovie(adrMov &m, adrRelasi &r)
{
    adrRelasi firstR, lastR, prec;
    firstR = nextRelasi(m);
    prec = nextRelasi(m);
    lastR = nextRelasi(m);

    if(r != NULL){
        info(aktor(r)).jumMov -= 1;
        if(r == firstR){
        deleteFirstRelasi(m, r);
    }else if(r == lastR){
        while(lastR != null){
            lastR = next(lastR);
        }
        deleteLastRelasi(m,r);
    }else{
        while(next(prec) != r){
            prec = next(prec);
        }
        deleteAfterRelasi(r,prec);
    }
    }else{
        cout << "tidak ada relasi" << endl;
    }
};

void MovieWithMostAktris(listAktor LA, listMov LM)
{
    adrMov m = first(LM);
    int tempJml = 0;
    adrMov mHasil;

    while(m != null){
        int jml = 0;
        adrRelasi r = nextRelasi(m);
        while(r != null && info(aktor(r)).genderAktor == "P"){
            jml += 1;
            if(jml > tempJml){
                tempJml = jml;
                mHasil = m;
            }
            r = next(r);
        }
        m = next(m);
    }
    cout << "film dengan aktris terbanyak: " << info(mHasil).namaFilm << endl;

};


void aktorWithMovie(listMov LM, adrAktor a){
    cout << "aktor: " << info(a).namaAktor << " bermain di film: " << endl;
    adrMov m = first(LM);
    while(m != null){
        adrRelasi r = nextRelasi(m);
        while(r != null){
            if(aktor(r) == a){
                cout << "  " << info(m).namaFilm << " ,";
            }
            r = next(r);
        }
        m = next(m);
    }
}
