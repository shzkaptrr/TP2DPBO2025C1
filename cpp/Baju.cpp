#include <bits/stdc++.h>
#include "Aksesoris.cpp" // include file parentnya yaitu Aksesoris.cpp
using namespace std;

class Baju : public Aksesoris{ // inherit dari class Aksesoris

    private:
        string untuk;
        string size;
        string merk;

    // constructor
    public:
        // contructors
        Baju(){
            this->untuk = "";
            this->size = "";
            this->merk = "";
        }

        Baju(string untuk, string size, string merk){
            this->untuk = untuk;
            this->size = size;
            this->merk = merk;
        }
    
        // Getter
        string get_untuk() const { return this->untuk; }
        string get_size() const { return this->size; }
        string get_merk() const { return this->merk; }

        // Setter
        void set_untuk(string untuk){
            this->untuk = untuk;
        }
        void set_size(string size){
            this->size = size;
        }
        void set_merk(string merk){
            this->merk = merk;
        }

        // method mendapatkan panjang untuk
        int get_length_untuk() const { return untuk.length(); }
        // method mendapatkan panjang size
        int get_length_size() const { return size.length(); }
        // method mendapatkan panjang merk
        int get_length_merk() const { return merk.length();}
        


        // destructor
        ~Baju(){
            
        }


};