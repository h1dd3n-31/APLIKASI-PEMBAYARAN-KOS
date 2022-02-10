#ifndef PERCOBAAN_LOGIN_H
#define PERCOBAAN_LOGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "owner.h"
#include <stdlib.h>


using namespace std;


class Login{
public:
    
        
    string username, password,posisi, un, pw, ps, akses, nama, status;
    string kamar, pribadiNama, pribadiAlamat, pribadiUsername, pribadiPassword, pribadiNomor;
    int hitung, count, tanyaMenu, nominal, lama;
    //User user;
    //Objek objek;

    Pemilik pemilik;

    void masuk(){

        cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"                                                                            "<<endl;
        cout<<"                            APLIKASI PEMBAYARAN KOS                         "<<endl;
        cout<<"                          SILAKAN LOGIN  DI BAWAH INI                        "<<endl;
        cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl<<endl;

        try
        {

            ifstream read("login.txt");

            if(read.is_open()){

                cout << "Masukan Username anda : "; cin >> username;
                cout << "Masukan Password anda: "; cin >> password;
                //cout << "Masukan Posisi anda: "; cin >> posisi;
            


                while (read >> un >> pw >> ps)
                {
                    
                    if (un == username && pw == password &&  ps == "admin")
                    {

                        hitung = 1;
                        akses = ps;
                        nama = un;
                       
                    } else if (un == username && pw == password &&  ps == "user"){

                        hitung = 1;
                        akses = ps; 
                        nama = un;
                    }
                    

                    if (un == username && pw == password && ps == "admin"){
                        cout << "\nHello  " << un << " anda login sebagai " << ps << endl << endl;
                        system("clear");
                    } else if (un == username && pw == password && ps == "user")
                        cout << "\nHello  " << un << " anda login sebagai " << ps << endl << endl;
                        system("clear");
                    }
                
                

            } else {
                throw("Tidak bisa membuka Database!");
            }
                  

            read.close();

            //system("clear");
            if (hitung == 1)
            {
                if (akses == "admin")
                {
                    
                    pemilik.Data();
                    
                    //pemilik.tampilData();
                } else if(akses == "user"){
                    
                    
                    TampilUser();
                    
                }
            } else
            {
                system("clear");
                cout << "\n....<USERNAME ATAU PASSWORD ANDA SALAH>....\n";
                masuk();
                
            }

            
            hitung = 0;
            

        }
        catch(const char *error)
        {

            cout << error << endl;
            cout << ".... < Anda Harus Register Terlebih dahulu >...." << endl;

        }
    }


    void TampilUser(){
        
        try
        {

            cout<<" . MENU USER . \n\n";
            cout<<"   1. Bayar Kos \n";
            cout<<"   2. Keluar \n";
            cout<<"________________________________________\n";
            cout<<"\n\n";


        
            cout << "Masukan Menu anda : ";
            cin >> tanyaMenu;

            if (tanyaMenu == 1)
            {
                string nomor;
                cout << "Masukan Nomor kamar anda : "; cin >> nomor;

                ifstream pribadi("dataPribadi.txt");
            
                if (pribadi.is_open())
                {
                    
                    while (pribadi >> pribadiNama >> pribadiAlamat >> pribadiUsername >> pribadiPassword >> pribadiNomor)
                    
                    {

                        if (pribadiUsername == username && pribadiNomor == nomor)
                        {

                            cout << "=========================" << endl;
                            cout << "Masukan lama pemakaian : ";
                            cin >> lama;

                            cout << "=========================" << endl;
                            cout << "Masukan Uang anda : ";
                            cin >> nominal;

                            cout << "=========================" << endl;

                            int harga = 150000;
                            int total = harga * lama;
                            status = "Terverifikasi";
                            
                            if ( nominal <= total && nominal == total)
                            {
                                ofstream file("DataPembayaran.txt", ios::app);
                                file << pribadiNomor << ' ' << pribadiNama << ' ' << pribadiAlamat << ' ' << status;
                                file << endl;
                                file.close();

                                cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
                                cout<<"                                                           "<<endl;
                                cout<<"                    PEMBAYARAN ANDA BERHASIL               "<<endl;
                                cout<<"                 =============================             "<<endl;
                                cout<<"   HARGA KOS             = Rp.150.000                                 "<<endl;
                                cout<<"   JUMLAH YANG DI BAYAR  = "<< nominal <<endl;
                                cout<<"   WAKTU PEMAKAIAN KOS   = "<< lama << " bulan" <<endl;
                                cout<<"   TOTAL PEMBAYARAN      = "<< total   <<endl;
                                cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl<<endl;
                            } else {

                                cout << "uang anda kurang" << endl << endl;
                             
                            }

                            TampilUser();
                            //cout << "Pembayaran anda sudah berhasil" << endl;
        
                        } else if (pribadiUsername == username && pribadiNomor != nomor){
                            
                            cout << "No kamar anda salah, silakan coba lagi!" << endl;
                            system("clear");
                            TampilUser();
                        }   

                    }   

                    pribadi.close();

                } else {
                    throw("Tidak bisa membuka Database!");
                }


            } else if(tanyaMenu == 2){
                
                throw("Program Keluar");

            } else{
                cout << "salah input menu, silakan ulang";
                TampilUser();
            }

        }
        catch(const char *error)
        {
            std::cerr << error << '\n';
        }
        
    } 

};



#endif /* MY_CLASS_H */