#include <bits/stdc++.h>
#include "PetShop.cpp" // include file parentnya yaitu PetShop.cpp
using namespace std;

class Aksesoris : public PetShop{   // inherit dari class PetShop

    private:
        string jenis;
        string bahan;
        string warna;

    // constructor
    public:
        // contructors
        Aksesoris(){
            this->jenis = "";
            this->bahan = "";
            this->warna = "";
        }

        Aksesoris(string jenis, string bahan, string warna){
            this->jenis = jenis;
            this->bahan = bahan;
            this->warna = warna;
        }
    
        // Getter
        string get_jenis() const { return this->jenis;}
        string get_bahan() const { return this->bahan; }
        string get_warna() const { return this->warna; }

        // Setter
        void set_jenis(string jenis){
            this->jenis = jenis;
        }
        void set_bahan(string bahan){
            this->bahan = bahan;
        }
        void set_warna(string warna){
            this->warna = warna;
        }

        // method mendapatkan max panjang jenis
        int get_length_jenis() const { return jenis.length(); }
        // method mendapatkan max panjang bahan
        int get_length_bahan() const { return bahan.length(); }
        // method mendapatkan max panjang warna
        int get_length_warna() const { return warna.length(); }

        // destructor
        ~Aksesoris(){
            
        }


};