#include <bits/stdc++.h>
#include "Baju.cpp"

using namespace std;

int main() {
    list<Baju> daftar_baju; // list untuk menyimpan objek Baju
    string id, namaProduk, jenis, bahan, warna, untuk, size, merk; // variabel untuk menyimpan input dari user
    int hargaProduk, stokProduk, req; // variabel untuk menyimpan input dari user

     // variabel untuk menyimpan panjang maksimum
    int max_id = 0, max_nama = 0, max_harga = 0, max_stok = 0;
    int max_jenis = 0, max_bahan = 0, max_warna = 0, max_untuk = 0, max_size = 0, max_merk = 0;
    
    // data statis dengan membuat vector dua dimensi 
    vector<vector<string>> data_statis = { 
        {"B0", "BajuAnjing", "150000", "10", "Pakaian", "Katun", "Biru", "Anjing", "M", "PawFashion"},
        {"B0", "BajuKucing", "120000", "5", "Pakaian", "Wol", "Merah", "Kucing", "S", "MeowStyle"},
        {"B0", "BajuHamster", "90000", "20", "Pakaian", "Poliester", "Hijau", "Hamster", "L", "FurryWear"},
        {"B0", "BajuIkan", "50000", "15", "Aksesoris", "Nilon", "Kuning", "Ikan", "M", "FishyStyle"},
        {"B0", "BajuBurung", "80000", "8", "Pakaian", "Katil", "Putih", "Burung", "S", "WingFashion"}
    };

    // memasukkan data statis ke list daftar_baju
    for (auto &d : data_statis) { // looping setiap baris data (d) dalam data_statis, membuat objek oBaju dan memasukkan data ke dalamnya
        Baju oBaju; // objek Baju
        oBaju.set_id(d[0]); 
        oBaju.set_namaProduk(d[1]);
        oBaju.set_hargaProduk(stoi(d[2])); // konversi string ke int
        oBaju.set_stokProduk(stoi(d[3]));  // konversi string ke int
        oBaju.set_jenis(d[4]);
        oBaju.set_bahan(d[5]);
        oBaju.set_warna(d[6]);
        oBaju.set_untuk(d[7]);
        oBaju.set_size(d[8]);
        oBaju.set_merk(d[9]);

        daftar_baju.push_back(oBaju); // memasukkan objek oBaju ke list daftar_baju
    }

    // memperbarui panjang maks berdasarkan data statis
    for (const auto &baju : daftar_baju) {
        max_id = max(max_id, (int)baju.get_id().length());
        max_nama = max(max_nama, (int)baju.get_namaProduk().length());
        max_harga = max(max_harga, (int)to_string(baju.get_hargaProduk()).length());
        max_stok = max(max_stok, (int)to_string(baju.get_stokProduk()).length());
        max_jenis = max(max_jenis, (int)baju.get_jenis().length());
        max_bahan = max(max_bahan, (int)baju.get_bahan().length());
        max_warna = max(max_warna, (int)baju.get_warna().length());
        max_untuk = max(max_untuk, (int)baju.get_untuk().length());
        max_size = max(max_size, (int)baju.get_size().length());
        max_merk = max(max_merk, (int)baju.get_merk().length());
    }    
   
    cout << "1. Tambah Baju\n2. Tampilkan Baju\n3. Keluar" << endl;
    cout << "Format tambah baju : id, namaProduk, hargaProduk, stokProduk, jenis, bahan, warna, untuk, size, merk\n";

    while(true){
        cin >> req;

        if(req == 1) {
            // mengambil input dari user
            cin >> id >> namaProduk >> hargaProduk >> stokProduk >> jenis >> bahan >> warna >> untuk >> size >> merk;

            // buat objek Baju dengan setter
            Baju oBaju; // objek Baju
            oBaju.set_id(id);
            oBaju.set_namaProduk(namaProduk);
            oBaju.set_hargaProduk(hargaProduk);
            oBaju.set_stokProduk(stokProduk);
            oBaju.set_jenis(jenis);
            oBaju.set_bahan(bahan);
            oBaju.set_warna(warna);
            oBaju.set_untuk(untuk);
            oBaju.set_size(size);
            oBaju.set_merk(merk);

            // masukkan ke list
            daftar_baju.push_back(oBaju);
            
            // update panjang maksimumm setiap atribut berdasarkan inputan tambah
            max_id = max(max_id, (int)id.length());
            max_nama = max(max_nama, (int)namaProduk.length());
            max_harga = max(max_harga, (int)to_string(hargaProduk).length());
            max_stok = max(max_stok, (int)to_string(stokProduk).length());
            max_jenis = max(max_jenis, (int)jenis.length());
            max_bahan = max(max_bahan, (int)bahan.length());
            max_warna = max(max_warna, (int)warna.length());
            max_untuk = max(max_untuk, (int)untuk.length());
            max_size = max(max_size, (int)size.length());
            max_merk = max(max_merk, (int)merk.length());

            cout << "Data ditambahkan" << endl;
        }
        else if(req == 2) {
            // header atas
            if(max_id <= 2) max_id = 3; // buat id produk
            cout << "+";
            for(int i = 0; i < max_id+1; i++) cout << "-";
            cout << "+";
            if(max_nama <= 11) max_nama = 12; // buat nama produk
            for(int i = 0; i < max_nama; i++) cout << "-";
            cout << "+";
            if(max_harga <= 12) max_harga = 13; // buat harga produk
            for(int i = 0; i < max_harga; i++) cout << "-";
            cout << "+";
            if(max_stok <= 11) max_stok = 12; // buat stok produk
            for(int i = 0; i < max_stok; i++) cout << "-";
            cout << "+";
            if(max_jenis <= 5) max_jenis = 6; // buat jenis
            for(int i = 0; i < max_jenis+1; i++) cout << "-";
            cout << "+";
            if(max_bahan <= 5) max_bahan = 6; // buat bahan
            for(int i = 0; i < max_bahan+1; i++) cout << "-";
            cout << "+";
            if(max_warna <= 5) max_warna = 6; // buat warna
            for(int i = 0; i < max_warna+1; i++) cout << "-";
            cout << "+";
            if(max_untuk <= 5) max_untuk = 6; // buat untuk
            for(int i = 0; i < max_untuk+1; i++) cout << "-";
            cout << "+";
            if(max_size <= 4) max_size = 5; // buat size
            for(int i = 0; i < max_size+1; i++) cout << "-";
            cout << "+";
            if(max_merk <= 4) max_merk = 5; // buat merk
            for(int i = 0; i < max_merk+1; i++) cout << "-";
            cout << "+";

            // nama kolom
            cout << endl;
            cout << "|ID";
            if(max_id <= 2) cout << " ";
            else for(int i = 0; i < max_id - 1; i++) cout << " ";
            cout << "|";
            cout << "Nama Produk";
            if(max_nama <= 11) cout << " ";
            else for(int i = 0; i < max_nama - 11; i++) cout << " ";
            cout << "|";
            cout << "Harga Produk";
            if(max_harga <= 12) cout << " ";
            else for(int i = 0; i < max_harga - 12; i++) cout << " ";
            cout << "|";
            cout << "Stok Produk";
            if(max_stok <= 11) cout << " ";
            else for(int i = 0; i < max_stok - 11; i++) cout << " ";
            cout << "|";
            cout << "Jenis";
            if(max_jenis <= 5) cout << " ";
            else for(int i = 0; i < max_jenis - 4; i++) cout << " ";
            cout << "|";
            cout << "Bahan";
            if(max_bahan <= 5) cout << " ";
            else for(int i = 0; i < max_bahan - 4; i++) cout << " ";
            cout << "|";
            cout << "Warna";
            if(max_warna <= 5) cout << " ";
            else for(int i = 0; i < max_warna - 4; i++) cout << " ";
            cout << "|";
            cout << "Untuk";
            if(max_untuk <= 5) cout << " ";
            else for(int i = 0; i < max_untuk - 4; i++) cout << " ";
            cout << "|";
            cout << "Size";
            if(max_size <= 4) cout << " ";
            else for(int i = 0; i < max_size - 3; i++) cout << " ";
            cout << "|";
            cout << "Merk";
            if(max_merk <= 4) cout << " ";
            else for(int i = 0; i < max_merk - 3; i++) cout << " ";
            cout << "|";
            cout << endl;
            
            // header bawah
            if(max_id <= 2) max_id = 3; // buat id produk
            cout << "+";
            for(int i = 0; i < max_id+1; i++) cout << "-";
            cout << "+";
            if(max_nama <= 11) max_nama = 12; // buat nama produk
            for(int i = 0; i < max_nama; i++) cout << "-";
            cout << "+";
            if(max_harga <= 12) max_harga = 13; // buat harga produk
            for(int i = 0; i < max_harga; i++) cout << "-";
            cout << "+";
            if(max_stok <= 11) max_stok = 12; // buat stok produk
            for(int i = 0; i < max_stok; i++) cout << "-";
            cout << "+";
            if(max_jenis <= 5) max_jenis = 6; // buat jenis
            for(int i = 0; i < max_jenis+1; i++) cout << "-";
            cout << "+";
            if(max_bahan <= 5) max_bahan = 6; // buat bahan
            for(int i = 0; i < max_bahan+1; i++) cout << "-";
            cout << "+";
            if(max_warna <= 5) max_warna = 6; // buat warna
            for(int i = 0; i < max_warna+1; i++) cout << "-";
            cout << "+";
            if(max_untuk <= 5) max_untuk = 6; // buat untuk
            for(int i = 0; i < max_untuk+1; i++) cout << "-";
            cout << "+";
            if(max_size <= 4) max_size = 5; // buat size
            for(int i = 0; i < max_size+1; i++) cout << "-";
            cout << "+";
            if(max_merk <= 4) max_merk = 5; // buat merk
            for(int i = 0; i < max_merk+1; i++) cout << "-";
            cout << "+" << endl;

            // isi kolomnya
            for(const auto &baju : daftar_baju){
                cout << "|" << baju.get_id();
                if(max_id <= 2) max_id = 3;
                for(int i = 0; i < max_id - baju.get_length_id()+1; i++) cout << " ";
                
                cout << "|" << baju.get_namaProduk();
                if(max_nama <= 11) max_nama = 12;
                for(int i = 0; i < max_nama - baju.get_length_namaProduk(); i++) cout << " ";
                
                cout << "|" << baju.get_hargaProduk();
                //cout << "1. Harga: " << baju.get_hargaProduk() << " (Panjang: " << baju.get_length_hargaProduk() << ")" << endl;
                if(max_harga <= 12) max_harga = 13;
                for(int i = 0; i < max_harga - baju.get_length_hargaProduk(); i++) cout << " ";
            
                cout << "|" << baju.get_stokProduk();
                if(max_stok <= 11) max_stok = 12;
                for(int i = 0; i < max_stok - baju.get_length_stokProduk(); i++) cout << " ";

                cout << "|" << baju.get_jenis();
                if(max_jenis <= 5) max_jenis = 6;
                for(int i = 0; i < max_jenis - baju.get_length_jenis()+1; i++) cout << " ";

                cout << "|" << baju.get_bahan();
                if(max_bahan <= 5) max_bahan = 6;
                for(int i = 0; i < max_bahan - baju.get_length_bahan()+1; i++) cout << " ";
                
                cout << "|" << baju.get_warna();
                if(max_warna <= 5) max_warna = 6;
                for(int i = 0; i < max_warna - baju.get_length_warna()+1; i++) cout << " ";
                
                cout << "|" << baju.get_untuk();
                if(max_untuk <= 5) max_untuk = 6;
                for(int i = 0; i < max_untuk - baju.get_length_untuk()+1; i++) cout << " ";
                
                cout << "|" << baju.get_size();
                if(max_size <= 4) max_size = 5;
                for(int i = 0; i < max_size - baju.get_length_size()+1; i++) cout << " ";
                
                cout << "|" << baju.get_merk();
                if(max_merk <= 4) max_merk = 5;
                for(int i = 0; i < max_merk - baju.get_length_merk()+1; i++) cout << " ";
                
                cout << "|" << endl;

                
            }

            // footer
            if(max_id <= 2) max_id = 3; // buat id produk
            cout << "+";
            for(int i = 0; i < max_id+1; i++) cout << "-";
            cout << "+";
            if(max_nama <= 11) max_nama = 12; // buat nama produk
            for(int i = 0; i < max_nama; i++) cout << "-";
            cout << "+";
            if(max_harga <= 12) max_harga = 13; // buat harga produk
            for(int i = 0; i < max_harga; i++) cout << "-";
            cout << "+";
            if(max_stok <= 11) max_stok = 12; // buat stok produk
            for(int i = 0; i < max_stok; i++) cout << "-";
            cout << "+";
            if(max_jenis <= 5) max_jenis = 6; // buat jenis
            for(int i = 0; i < max_jenis+1; i++) cout << "-";
            cout << "+";
            if(max_bahan <= 5) max_bahan = 6; // buat bahan
            for(int i = 0; i < max_bahan+1; i++) cout << "-";
            cout << "+";
            if(max_warna <= 5) max_warna = 6; // buat warna
            for(int i = 0; i < max_warna+1; i++) cout << "-";
            cout << "+";
            if(max_untuk <= 5) max_untuk = 6; // buat untuk
            for(int i = 0; i < max_untuk+1; i++) cout << "-";
            cout << "+";
            if(max_size <= 4) max_size = 5; // buat size
            for(int i = 0; i < max_size+1; i++) cout << "-";
            cout << "+";
            if(max_merk <= 4) max_merk = 5; // buat merk
            for(int i = 0; i < max_merk+1; i++) cout << "-";
            cout << "+" << endl;

        }
        else if(req == 3){
            break;
        }
        else {
            cout << "Pilihan tidak ada" << endl;
            break;
        }
    }

    return 0;
}
