#include <iostream>

#include "movie.h"

#include "menu.h"

using namespace std;

int main() {
  listMov LM;
  listAktor LA;
  // infotypeMovie infoA;
  // infotypeAktor infoB;
  adrMov m;
  adrAktor a;
  adrRelasi R;
  createListAktor(LA);
  createListMovie(LM);
  infotypeMovie movie;
  infotypeAktor aktor;
  int pilihan = 0;
  char kembali = 'Y';
  pilihan = selectMenu();

  while (pilihan != 0 && kembali == 'Y' || kembali == 'y') {
    switch (pilihan) {
    case 1: {
      cout << "Berapa banyak data Movie yang akan dimasukan? : ";
      int banyakData;
      cin >> banyakData;
      for (int i = 0; i < banyakData; i++) {
        cout << "input data ke: " << i + 1 << endl;
        cout << "Masukan IEDR film : ";
        cin >> movie.iedr;
        cout << "Masukan judul film : ";
        cin >> movie.namaFilm;
        cout << "Masukan tahun rilis film : ";
        cin >> movie.tahunRilis;

        m = createElmMovie(movie);
        addMovie(LM, m);
      }

      break;
    }
    case 2: {
      cout << "Berapa banyak data aktor/aktris yang akan dimasukan? : ";
      int banyakData;
      cin >> banyakData;
      for (int i = 0; i < banyakData; i++) {
        cout << "input data ke: " << i + 1 << endl;
        cout << "Masukan id aktor/aktris : ";
        cin >> aktor.id;
        cout << "Masukan nama aktor/aktris : ";
        cin >> aktor.namaAktor;
        cout << "Masukan gender aktor/aktris [L/P] : ";
        cin >> aktor.genderAktor;
        aktor.jumMov = 0;
        a = createElmAktor(aktor);
        addAktor(LA, a);
      }
      break;
    }
    case 3: {
      int cariTahun;
      cout << "Mencari data movie tertentu dari Tahun Rilis : ";
      cin >> cariTahun;
      adrMov p = first(LM);
      while (p != NULL) {
        if (info(p).tahunRilis == cariTahun) {
          cout << "Film : " << info(p).namaFilm << endl;
          cout << "Tahun Rilis : " << info(p).tahunRilis << endl;
          cout << "---------------------------------------------------------" << endl;
        }
        p = next(p);
      }

      break;
    }
    case 4: {
      cout << "Menambahkan Relasi aktor/aktris dengan Movie" << endl;
      cout << "masukan iedr movie: ";
      cin >> movie.iedr;
      m = findMov(LM, movie.iedr);
      cout << "masukan id aktor: ";
      cin >> aktor.id;
      a = findAktor(LA, aktor.id);
      if (a != NULL && m != NULL) {
        createRelasi(m, a);
        cout << "BERHASIL menambahkan " << info(a).namaAktor << " ke film " << info(m).namaFilm << endl;
      } else {
        cout << "Data movie atau aktor tidak ditemukan" << endl;
      }
      break;
    }
    case 5: {
      cout << "Mencari data movie yang dibintangi aktor/aktris : " << endl;
      cout << "Masukan ID Aktor/Aktris : ";
      cin >> aktor.id;
      a = findAktor(LA, aktor.id);
      aktorWithMovie(LM,a);
      break;
    }
    case 6: {
      string iedr;
      cout << "Menghapus data Movie dan Relasinya" << endl;
      cout << "Masukan IEDR Movie: ";
      cin >> iedr;

      deleteMov(LM, iedr);
      cout << "Film dengan "<< iedr << " Sudah terhapus beserta relasinya";

      break;
    }
    case 7: {
      cout << "Menghapus data aktor/aktris pada movie tertentu" << endl;

      cout << "masukan iedr movie: ";
      cin >> movie.iedr;
      m = findMov(LM, movie.iedr);
      cout << "masukan id aktor yang akan dihapus: ";
      cin >> aktor.id;
      a = findAktor(LA, aktor.id);
      adrRelasi r = findRelasi(m, aktor.id);
      if (a != NULL && m != NULL && r != NULL) {
        deleteAktorDiMovie(m, r);

      } else {
        cout << "Data movie atau aktor tidak ditemukan" << endl;
      }

      break;
    }
    case 8: {
      cout << "Menampilkan data seluruh movie dan aktor yang membintanginya";
      cout << endl;
      showAllMovieAktor(LM, LA);
      break;
    }

    case 9: {
      cout << "Meghitung banyaknya movie yang dibintangi aktor/aktris" << endl;
      cout << "Masukan id Aktor: ";
      cin >> aktor.id;
      adrAktor a = findAktor(LA, aktor.id);
      cout << "Banyak nya movie yang dimainkan Aktor/Aktris: " << info(a).jumMov << endl;
      break;
    }
    case 10: {
      cout << "Menampilkan data movie yang paling banyak dibintangin oleh aktris" << endl;

      MovieWithMostAktris(LA, LM);
      break;

    }
    case 11: {
      cout << " EXIT " << endl;
      break;
    }
    }

    cout << "Kembali ke Menu Utama? [y/n] ";
    cin >> kembali;
    if (kembali == 'y' || kembali == 'Y') {
      pilihan = selectMenu();
    } else {
      pilihan = 0;
      cout << "=================================================================================" << endl;
      cout << "=======================           SAMPAI JUMPA!           =======================" << endl;
      cout << "=================================================================================" << endl;
    }
  }
  return 0;
}
