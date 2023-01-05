#include "menu.h"
int selectMenu()
{
    int menu;
    cout << "===================================================================================" << endl;
    cout << "==================================== MAIN MENU ====================================" << endl;

    cout <<"|"<< "  1.  Menambah Data Movie" <<"                                                        |"<< endl;
    cout <<"|"<< "  2.  Menambahkan data aktor/aktris" <<"                                              |"<< endl;
    cout <<"|"<< "  3.  Mencari data movie tertentu" <<"                                                |"<< endl;
    cout <<"|"<< "  4.  Menambahkan relasi aktor/aktris dengan movie yang dibintangi" <<"               |"<< endl;
    cout <<"|"<< "  5.  Mencari data movie yang dibintangi oleh aktor atau artis tertentu" <<"          |"<< endl;
    cout <<"|"<< "  6.  Menghapus data movie beserta relasinya" <<"                                     |"<< endl;
    cout <<"|"<< "  7.  Menghapus data aktor/aktris pada movie tertentu" <<"                            |"<< endl;
    cout <<"|"<< "  8.  Menampilkan data seluruh movie beserta aktor/aktris yang membintanginya" <<"    |"<< endl;
    cout <<"|"<< "  9.  Menghitung banyaknya movie yang dimainkan aktor/aktris tertentu" <<"            |"<< endl;
    cout <<"|"<< "  10. Menampilkan data movie paling banyak dibintangi oleh aktris " <<"               |"<< endl;
    cout <<"|"<< "  11. Exit" <<"                                                                       |"<< endl;
    cout << "===================================================================================" << endl;
    cout << "Pilih Menu : ";

    int input = 0;
    cin >> input;

    cout << endl;
    return input;
}
