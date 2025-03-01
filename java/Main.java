import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        LinkedList<Baju> list_baju = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);

        // data statis dalam array dua dimensi
        Object[][] dataStatis = {
            {"B001", "BajuAnjing", 150000, 10, "Pakaian", "Katun", "Biru", "Anjing", "M", "PawFashion"},
            {"B002", "BajuKucing", 120000, 5, "Pakaian", "Wol", "Merah", "Kucing", "S", "MeowStyle"},
            {"B003", "BajuHamster", 90000, 20, "Pakaian", "Poliester", "Hijau", "Hamster", "L", "FurryWear"},
            {"B004", "BajuIkan", 50000, 15, "Aksesoris", "Nilon", "Kuning", "Ikan", "M", "FishyStyle"},
            {"B005", "BajuBurung", 80000, 8, "Pakaian", "Katil", "Putih", "Burung", "S", "WingFashion"}
        };

        for (Object[] d : dataStatis) {
            // konstruktor Baju hanya menerima tiga parameter (untuk, size, merk) indeks 7, 8, dan 9
            Baju oBaju = new Baju((String) d[7], (String) d[8], (String) d[9]);
            oBaju.setId((String) d[0]);
            oBaju.setNamaProduk((String) d[1]);
            oBaju.setHargaProduk((int) d[2]); // casting / mengubah tipenya ke int
            oBaju.setStokProduk((int) d[3]); // casting / mengubah tipenya ke int
            oBaju.setJenis((String) d[4]);
            oBaju.setBahan((String) d[5]);
            oBaju.setWarna((String) d[6]);
            list_baju.add(oBaju); // tambahkan ke list list_baju
        } 
        System.out.println("1. Tambah Baju\n2. Tampilkan Baju\n3. Keluar");
        System.out.println("Format tambah baju : id, namaProduk, hargaProduk, stokProduk, jenis, bahan, warna, untuk, size, merk");

        while (true) {
            int req = scanner.nextInt();
            scanner.nextLine(); 

            if (req == 1) {  
                // mengambil input dari user, ini agar bisa 1 baris inputan          
                String id = scanner.next();
                String nama = scanner.next();
                int harga = scanner.nextInt();
                int stok = scanner.nextInt();
                String jenis = scanner.next();
                String bahan = scanner.next();
                String warna = scanner.next();
                String untuk = scanner.next();
                String size = scanner.next();
                String merk = scanner.next();

                Baju oBaju = new Baju(); // buat objek baru
                // set atribut 
                oBaju.setId(id);
                oBaju.setNamaProduk(nama);
                oBaju.setHargaProduk(harga);
                oBaju.setStokProduk(stok);
                oBaju.setJenis(jenis);
                oBaju.setBahan(bahan);
                oBaju.setWarna(warna);
                oBaju.setUntuk(untuk);
                oBaju.setSize(size);
                oBaju.setMerk(merk);
                // masukkan ke list
                list_baju.add(oBaju);
                System.out.println("Data ditambahkan");
            } 
            else if (req == 2) {
                printTabel(list_baju);
               
            } 
            else if (req == 3) {
                break;
            }
            else {
                System.out.println("Pilihan tidak ada");
            }
        }
        scanner.close();
    }

    // prosedur untuk menampilkan tabelnya
    public static void printTabel(LinkedList<Baju> list_baju) {
        // tentukan panjang maksimum untuk setiap kolom
        // adalah membuat array yang berisi 10 elemen yang berisi panjang maksimum dari setiap kolom
        int[] maxLengths = new int[10];
        // adalah membuat array yang berisi string yang akan menjadi header(nama kolom)
        String[] headers = {"ID", "Nama Produk", "Harga Produk", "Stok Produk", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk"};
        
        // looping untuk mengisi panjang maksimum setiap kolom
        for (int i = 0; i < headers.length; i++) {
            maxLengths[i] = headers[i].length(); // inisialisasi dengan panjang nama kolom
        }
        // looping untuk mengisi panjang maksimum setiap kolom
        for (Baju baju : list_baju) {
            // membandingkan nilai yang sudah ada di maxLengths[0] dengan panjang atribut baru, menggunakan Math.max(a, b)
            maxLengths[0] = Math.max(maxLengths[0], baju.getId().length()); 
            maxLengths[1] = Math.max(maxLengths[1], baju.getNamaProduk().length());
            maxLengths[2] = Math.max(maxLengths[2], String.valueOf(baju.getHargaProduk()).length());
            maxLengths[3] = Math.max(maxLengths[3], String.valueOf(baju.getStokProduk()).length());
            maxLengths[4] = Math.max(maxLengths[4], baju.getJenis().length());
            maxLengths[5] = Math.max(maxLengths[5], baju.getBahan().length());
            maxLengths[6] = Math.max(maxLengths[6], baju.getWarna().length());
            maxLengths[7] = Math.max(maxLengths[7], baju.getUntuk().length());
            maxLengths[8] = Math.max(maxLengths[8], baju.getSize().length());
            maxLengths[9] = Math.max(maxLengths[9], baju.getMerk().length());
        }

        // menentukan format output 
        // %s berarti mencetak sebuah string, angka diantaranya menunjukan lebar kolom yang akan dicetak, kanya pakai maxLengths
        // (-) berarti string dicetak rata kiri
        String format = "| %-" + maxLengths[0] + "s | %-" + maxLengths[1] + "s | %-" + maxLengths[2] + "s | %-" + maxLengths[3] + "s | %-" + maxLengths[4] + "s | %-" + maxLengths[5] + "s | %-" + maxLengths[6] + "s | %-" + maxLengths[7] + "s | %-" + maxLengths[8] + "s | %-" + maxLengths[9] + "s |\n";

        // header
        printGarisHorizontal(maxLengths); // cetak garis horizontal bagian atas tabe
        System.out.printf(format, (Object[]) headers); // cetak header
        printGarisHorizontal(maxLengths); // cetak garis horizontal bagian tengah tabel

        // isi tabel
        for (Baju baju : list_baju) {
            System.out.printf(format,
                baju.getId(), baju.getNamaProduk(), baju.getHargaProduk(), baju.getStokProduk(),
                baju.getJenis(), baju.getBahan(), baju.getWarna(), baju.getUntuk(),
                baju.getSize(), baju.getMerk()
            );
        }
        printGarisHorizontal(maxLengths); // cetak garis horizontal bagian bawah tabel
    }

    // prosedur untuk mencetak garis horizontal
    public static void printGarisHorizontal(int[] maxLengths) {
        System.out.print("+");
        for (int len : maxLengths) {
            // cetak '-' sebanyak (len + 2) kali menggunakan loop for
            for (int i = 0; i < len + 2; i++) {
                System.out.print("-");
            }
            System.out.print("+");
        }
        System.out.println();
    }

}
