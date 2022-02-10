#ifndef PERCOBAAN_REGISTER_H
#define PERCOBAAN_REGISTER_H
#include <iostream>
#include <fstream>
// #include <ifstream>
// #include <ofstream>
#include <string>

using namespace std;

class Registrasi{
    
public:   
    void registrasi(){

        cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"                                                                            "<<endl;
        cout<<"                            APLIKASI PEMBAYARAN KOS                         "<<endl;
        cout<<"                   SILAKAN MELAKUKAN REGISTRASI DI BAWAH INI                "<<endl;
        cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl<<endl;

        string nama, alamat, username, password,no_kamar, posisi;

        cout << "Masukan Nama Lengkap anda : "; cin >> nama;
        cout << endl;
        cout << "Masukan Alamat anda : "; cin >> alamat;
        cout << endl;
        cout << "Masukan Username anda : "; cin >> username; //getline(cin, username);
        cout << endl;
        cout << "Masukan Password anda : "; cin >> password; //getline(cin, password);
        cout << endl;
        cout << "Masukan No_Kamar anda : "; cin >> no_kamar; //getline(cin, password);
        cout << endl;
        cout << "Masukan Posisi anda : "; cin >> posisi; //getline(cin, password);

        
        ofstream file("login.txt", ios::app);
        file << username << ' ' << password << ' ' << posisi;
        file << endl;
        file.close();

        ofstream file1;
        file1.open("dataPribadi.txt", ios::app);
        file1 << nama << ' '<< alamat << ' ' << username << ' ' << password << ' ' << no_kamar;
        file1 << endl;
        file1.close();

    }



};





#endif /* MY_CLASS_H */