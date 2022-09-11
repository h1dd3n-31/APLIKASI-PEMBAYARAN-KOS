#include <iostream>
#include <fstream>
#include <string>
#include "login.h"
#include "register.h"


using namespace std;

int main(){

    Login lgn;
    Registrasi rgs;
   // Pemilik pemilik;
    //User user;
    cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
    cout<<"                                                                            "<<endl;
    cout<<"                            APLIKASI PEMBAYARAN KOS                         "<<endl;
    cout<<"                  KELOMPOK TIGA MATA KULIAN PEMOGRAMAN LANJUT               "<<endl;
    cout<<"                      { Akbar Usamah } { Ahmad Ariansyah }                  "<<endl;
    cout<<"                    { Muhammad Najmi} { Prasetyo adi wibowoo}                "<<endl;
    cout<<"                                                                            "<<endl;
    cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl<<endl;
    

    cout<<" . MENU APLIKASI PEMBAYARAN KOS . \n\n";
    cout<<"   1.Registrasi \n";
    cout<<"   2.Login \n";
    cout<<"   3.Keluar \n";
    cout<<"________________________________________\n";
    cout<<"\n\n";


    int pilih;

    cout << "Masukan Menu anda : "; 
    cin >> pilih;

    cout << endl;

    switch (pilih)
    {
    case 1:

        system("clear");
        rgs.registrasi();
        cout << endl;
        main();
        break;
    
    case 2:

        system("clear");
        lgn.masuk();
        cout << endl;
        main();

    case 3:

        cout << ".... < TERIMAKASIH BANYAK >...." << endl;
        exit(0);
        break;

    
    default:
        
        cout << "....[ Silakan coba lagi ]...." << endl;
        main();
        break;

    }

    return 0;
}
