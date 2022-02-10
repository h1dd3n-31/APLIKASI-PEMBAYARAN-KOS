#ifndef PERCOBAAN_OWNER_H
#define PERCOBAAN_OWNER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
//#include "template.h"

using namespace std;

class Pemilik{
    public:


        string nk, nm, al, st, coba_aja;
        string no_kamar,nama,alamat,status, line;
        int tanya, pointer;

        void Data(){
            
            cout<<" . MENU ADMIN. \n\n";
            cout<<"   1. Cek Tagihan \n";
            cout<<"   2. Keluar \n";
            cout<<"________________________________________\n";
            cout<<"\n\n";

            cout << "Masukan Menu Admin : ";
            cin >> tanya;

            system("clear");

            ifstream DataPembayaran("DataPembayaran.txt");
            try
            {
                if (tanya == 1)
                {
                    if (DataPembayaran.is_open())
                    {

                        cout << "======================================================" << endl;
                        cout<<"                                                        "<<endl;
                        cout<<"                DAFTAR PEMBAYARAN CUSTOMER              "<<endl;
                        cout<<"                  APLIKASI PEMBAYARAN KOS               "<<endl;
                        cout<<"                                                        "<<endl;
                        cout << "======================================================" << endl;
                        while(DataPembayaran >> nk >> nm >> al >> st)
                        {
                                                        
                            cout << "| " << nk << " | " <<  nm << " | " <<  al << "       | " << st << " |" << endl;
   
                        }

                        cout << "======================================================" << endl;
                        cout << endl << endl;

                        DataPembayaran.close();
                        Data();
                      

                    } else {
                        throw("Database anda tidak ada data atau belum di buat");
                    }
                } else if( tanya == 2){
                    throw("Program Keluar");
                } else {
                    cout << "Yang anda masukan salah!";
                    Data();
                }
            
               system("clear");
            }
            catch(const char* error)
            {
            cout << error << endl;
            }

            DataPembayaran.close();

            
            
            
        }



};

#endif
