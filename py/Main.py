from Baju import Baju  # mengimpor kelas Baju dari file Baju.py

# list untuk menyimpan objek Baju
list_baju = []

# header untuk tabel / nam akolom
headers = ["ID", "Nama Produk", "Harga Produk", "Stok Produk", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk"]

# data_statis adalah list berisi data awal untuk diisi ke list_baju
data_statis = [
    ("B001", "BajuAnjing", 150000, 10, "Pakaian", "Katun", "Biru", "Anjing", "M", "PawFashion"),
    ("B002", "BajuKucing", 120000, 5, "Pakaian", "Wol", "Merah", "Kucing", "XS", "MeowStyle"),
    ("B003", "BajuHamster", 90000, 20, "Pakaian", "Poliester", "Hijau", "Hamster", "L", "FurryWear"),
    ("B004", "BajuIkan", 50000, 15, "Aksesoris", "Nilon", "Kuning", "Ikan", "M", "FishyStyle"),
    ("B005", "BajuBurung", 80000, 8, "Pakaian", "Katil", "Putih", "Burung", "S", "WingFashion")
]

# looping untuk setiap data dalam data_statis
for d in data_statis:
    oBaju = Baju()            
    oBaju.setId(d[0])        
    oBaju.setNamaProduk(d[1])  
    oBaju.setHargaProduk(d[2])
    oBaju.setStokProduk(d[3])  
    oBaju.setJenis(d[4])      
    oBaju.setBahan(d[5])      
    oBaju.setWarna(d[6])       
    oBaju.setUntuk(d[7])      
    oBaju.setSize(d[8])        
    oBaju.setMerk(d[9])        
    list_baju.append(oBaju) # masukkan objek ke dalam list_baju  

print("1. Tambah Baju\n2. Tampilkan Baju\n3. Keluar")
print("Format tambah baju: id, namaProduk, hargaProduk, stokProduk, jenis, bahan, warna, untuk, size, merk")

while True:
    req = int(input())
    
    if req == 1:
        # data adalah input dari user
        data = input().split() # memakai split agar bisa diinput 1 baris
        id, namaProduk, hargaProduk, stokProduk, jenis, bahan, warna, untuk, size, merk = data
        
        oBaju = Baju() # membuat objek Baju
        oBaju.setId(id)
        oBaju.setNamaProduk(namaProduk)
        oBaju.setHargaProduk(int(hargaProduk))
        oBaju.setStokProduk(int(stokProduk))
        oBaju.setJenis(jenis)
        oBaju.setBahan(bahan)
        oBaju.setWarna(warna)
        oBaju.setUntuk(untuk)
        oBaju.setSize(size)
        oBaju.setMerk(merk)
        list_baju.append(oBaju)  # masukan objek ke dalam list_baju
        
        print("Data ditambahkan")
    
    elif req == 2:
        # list kosong bernama panjang_kolom yang menyimpan lebar/jumlah karakter
        panjang_kolom = []
        for header in headers: # looping untuk setiap header dalam headers
            panjang_kolom.append(len(header)) # tambahkan panjang header ke panjang_kolom
        
        # memperbarui panjang_kolom jika ada data yang lebih panjang
        for baju in list_baju: # looping untuk setiap baju dalam list_baju
            baris_list_baju = [ # baris_list_baju adl list yang berisi data atribut, mengambil data dari objek baju 
                baju.getId(), 
                baju.getNamaProduk(),
                str(baju.getHargaProduk()), # hmengubah hargaProduk ke string
                str(baju.getStokProduk()), # mengubah stokProduk ke string
                baju.getJenis(),
                baju.getBahan(),
                baju.getWarna(),
                baju.getUntuk(),
                baju.getSize(),
                baju.getMerk()
            ]
            for i in range(len(baris_list_baju)): # looping untuk setiap elemen dalam baris_list_baju
                # jika panjang elemen lebih besar dari panjang_kolom, maka panjang_kolom adalah len(baris_list_baju)
                if len(baris_list_baju[i]) > panjang_kolom[i]:
                    panjang_kolom[i] = len(baris_list_baju[i])
        
        # mencettak tabel
        line = "+" # awal garis
        for w in panjang_kolom: # looping untuk setiap elemen dalam panjang_kolom
            line += "-" * (w + 2) + "+" # mengubah line menjadi kombinasi "-" dan "+"
        print(line) # mencetak line
        
        # mencetak header 
        header_line = "|" # awal header
        for i in range(len(headers)): # looping untuk setiap elemen dalam headers
            header_line += " " + headers[i].ljust(panjang_kolom[i]) + " |" #  header_line adlah kombinasi " ",  "|", dan nama kolom itu sendiri
        print(header_line) # cetak header_line
        print(line)  # cetak garis horizontal lagi
        
        # mencetak isi tabel
        for baju in list_baju: # looping untuk setiap baju dalam list_baju
            baris_list_baju = [ # baris_list_baju adl list yang berisi data atribut, mengambil data dari objek baju
                baju.getId(),
                baju.getNamaProduk(),
                str(baju.getHargaProduk()), # mengubah hargaProduk ke string
                str(baju.getStokProduk()), # mengubah stokProduk ke string
                baju.getJenis(),
                baju.getBahan(),
                baju.getWarna(),
                baju.getUntuk(),
                baju.getSize(),
                baju.getMerk()
            ]
            # mncetak isi tabel dengan format 
            garis_baris = "|" # awal baris
            for i in range(len(baris_list_baju)): # looping untuk setiap elemen dalam baris_list_baju
                garis_baris += " " + baris_list_baju[i].ljust(panjang_kolom[i]) + " |" # garis_baris adlah kombinasi " ",  "|", dan elemen baris_list_baju itu sendiri
            print(garis_baris) # cetak garis_baris
        print(line)  # cetak garis horixontal untuk footer
    
    elif req == 3:
        break  # exit
    
    else:
        print("Pilihan tidak ada")
