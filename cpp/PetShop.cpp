#include <bits/stdc++.h>
using namespace std;

class PetShop{

    private:
        string id;
        string namaProduk;
        int hargaProduk;
        int stokProduk;

    // constructor
    public:
        // contructors
        PetShop(){
            this->id = "";
            this->namaProduk = "";
            this->hargaProduk = 0;
            this->stokProduk = 0;
        }

        PetShop(string id, string namaProduk, int hargaProduk, int stokProduk){
            this->id = id;
            this->namaProduk = namaProduk;
            this->hargaProduk = hargaProduk;
            this->stokProduk = stokProduk;
        }
    
        // Getter
        string get_id() const { return this->id; }
        string get_namaProduk() const { return this->namaProduk; }  // Perbaikan
        int get_hargaProduk() const { return this->hargaProduk; }
        int get_stokProduk() const { return this->stokProduk; }

        // Setter
        void set_id(string id) { this->id = id; }
        void set_namaProduk(string namaProduk) { this->namaProduk = namaProduk; }  // Perbaikan
        void set_hargaProduk(int hargaProduk) { this->hargaProduk = hargaProduk; }
        void set_stokProduk(int stokProduk) { this->stokProduk = stokProduk; }

        // method mendapatkan panjang id
        int get_length_id() const { return id.length(); }

        // method mendapatkan panjang namaProduk
        int get_length_namaProduk() const { return namaProduk.length(); }

        // method mendapatkan panjang hargaProduk
        int get_length_hargaProduk() const { 
            if (hargaProduk < 10) return 1;
            else if (hargaProduk < 100) return 2;
            else if (hargaProduk < 1000) return 3;
            else if (hargaProduk < 10000) return 4;
            else if(hargaProduk < 100000) return 5;
            else if(hargaProduk < 1000000) return 6;
            else if(hargaProduk < 10000000) return 7;
            else if(hargaProduk < 100000000) return 8;
            else if(hargaProduk < 1000000000) return 9;
            else return 10; 
            
        }

        // method mendapatkan panjang stokProduk
        int get_length_stokProduk() const { 
            if (stokProduk < 10) return 1;
            else if (stokProduk < 100) return 2;
            else if (stokProduk < 1000) return 3;
            else if (stokProduk < 10000) return 4;
            else if(stokProduk < 100000) return 5;
            else if(stokProduk < 1000000) return 6;
            else if(stokProduk < 10000000) return 7;
            else if(stokProduk < 100000000) return 8;
            else if(stokProduk < 1000000000) return 9;
            else return 10; 
        }
        // destructor
        ~PetShop(){

        }

};