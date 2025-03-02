<?php
require("Baju.php"); // memasukkan file Baju.php
session_start();

// jika belum ada data di session, inisialisasi dengan data statis
if (!isset($_SESSION['list_baju'])) {
    $_SESSION['list_baju'] = []; // membuat array kosong untuk menyimpan objek Baju

    // data statis untuk diawal
    $dataStatis = [
        ["B001", "BajuAnjing", 150000, 10, "Pakaian", "Katun", "Biru", "Anjing", "M", "PawFashion", "foto1.png"],
        ["B002", "BajuKucing", 120000, 5, "Pakaian", "Wol", "Merah", "Kucing", "XS", "MeowStyle", "foto1.png"],
        ["B003", "BajuHamster", 90000, 20, "Pakaian", "Poliester", "Hijau", "Hamster", "L", "FurryWear", "foto1.png"],
        ["B004", "BajuIkan", 50000, 15, "Aksesoris", "Nilon", "Kuning", "Ikan", "M", "FishyStyle", "foto1.png"],
        ["B005", "BajuBurung", 80000, 8, "Pakaian", "Katil", "Putih", "Burung", "S", "WingFashion", "foto1.png"]
    ];

    // loop untuk membuat objek Baju dari data statis dan memasukkannya ke session
    foreach ($dataStatis as $data) {
        $baju = new Baju(); // buat objek Baju baru
        $baju->setId($data[0]);
        $baju->setNamaProduk($data[1]);
        $baju->setHargaProduk($data[2]);
        $baju->setStokProduk($data[3]);
        $baju->setJenis($data[4]);
        $baju->setBahan($data[5]);
        $baju->setWarna($data[6]);
        $baju->setUntuk($data[7]);
        $baju->setSize($data[8]);
        $baju->setMerk($data[9]);
        $baju->setFotoProduk($data[10]);
        $_SESSION['list_baju'][] = $baju; // tambahkan ke session
    }
}

// menangani penambahan data jika form disubmit
if (isset($_POST['tambah'])) {
    $baju = new Baju();
    $baju->setId($_POST['id']);
    $baju->setNamaProduk($_POST['namaProduk']);
    $baju->setHargaProduk($_POST['hargaProduk']);
    $baju->setStokProduk($_POST['stokProduk']);
    $baju->setJenis($_POST['jenis']);
    $baju->setBahan($_POST['bahan']);
    $baju->setWarna($_POST['warna']);
    $baju->setUntuk($_POST['untuk']);
    $baju->setSize($_POST['size']);
    $baju->setMerk($_POST['merk']);

    // ppload file fotoProduk
    $fotoProduk = $_FILES['fotoProduk']['name'];
    move_uploaded_file($_FILES['fotoProduk']['tmp_name'], "uploads/" . $fotoProduk);
    $baju->setFotoProduk($fotoProduk);

    $_SESSION['list_baju'][] = $baju;
}

// menangani penghapusan data produk
if (isset($_GET['hapus'])) {
    $index = $_GET['hapus'];
    if (isset($_SESSION['list_baju'][$index])) {
        array_splice($_SESSION['list_baju'], $index, 1);
    }
    header("Location: index.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Manajemen Produk</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f4f4f4;
        }
        h2 {
            text-align: center;
            color: #333;
        }
        .form-container {
            width: 40%;
            margin: 0 auto;
            background: white;
            padding: 20px;
            border-radius: 8px;
        }
        .form-container input, .form-container button {
            width: 100%;
            max-width: 450px;
            padding: 10px;
            margin: 8px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        .form-container button {
            background-color: #28a745;
            color: white;
            border: none;
            cursor: pointer;
            font-size: 16px;
        }
        .form-container button:hover {
            background-color: #218838;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
            background: white;
            border-radius: 8px;
            overflow: hidden;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
        }
        table th, table td {
            padding: 12px;
            border: 1px solid #ddd;
            text-align: center;
        }
        table th {
            background-color: #007bff;
            color: white;
        }
        table tr:hover {
            background-color: #f1f1f1;
        }
        .btn-hapus {
            background-color: #dc3545;
            color: white;
            padding: 6px 12px;
            text-decoration: none;
            border-radius: 5px;
        }
        .btn-hapus:hover {
            background-color: #c82333;
        }
    </style>
</head>
<body>

    <h2>Tambah Produk</h2>
    <div class="form-container">
        <form method="post" enctype="multipart/form-data">
            <input type="text" name="id" placeholder="ID Produk" required>
            <input type="text" name="namaProduk" placeholder="Nama Produk" required>
            <input type="number" name="hargaProduk" placeholder="Harga Produk" required>
            <input type="number" name="stokProduk" placeholder="Stok Produk" required>
            <input type="text" name="jenis" placeholder="Jenis" required>
            <input type="text" name="bahan" placeholder="Bahan" required>
            <input type="text" name="warna" placeholder="Warna" required>
            <input type="text" name="untuk" placeholder="Untuk" required>
            <input type="text" name="size" placeholder="Size" required>
            <input type="text" name="merk" placeholder="Merk" required>
            <input type="file" name="fotoProduk" required>
            <button type="submit" name="tambah">Tambah</button>
        </form>
    </div>

    <h2>Daftar Produk</h2>
    <table>
        <tr>
            <th>ID</th>
            <th>Nama Produk</th>
            <th>Harga Produk</th>
            <th>Stok Produk</th>
            <th>Jenis</th>
            <th>Bahan</th>
            <th>Warna</th>
            <th>Untuk</th>
            <th>Size</th>
            <th>Merk</th>
            <th>Foto Produk</th>
            <th>Aksi</th> 
        </tr>
        <?php foreach ($_SESSION['list_baju'] as $index => $baju) { ?>
            <tr>
                <td><?php echo $baju->getId(); ?></td>
                <td><?php echo $baju->getNamaProduk(); ?></td>
                <td>Rp <?php echo number_format($baju->getHargaProduk(), 0, ',', '.'); ?></td>
                <td><?php echo $baju->getStokProduk(); ?></td>
                <td><?php echo $baju->getJenis(); ?></td>
                <td><?php echo $baju->getBahan(); ?></td>
                <td><?php echo $baju->getWarna(); ?></td>
                <td><?php echo $baju->getUntuk(); ?></td>
                <td><?php echo $baju->getSize(); ?></td>
                <td><?php echo $baju->getMerk(); ?></td>
                <td><img src="uploads/<?php echo $baju->getFotoProduk(); ?>" width="80"></td>
                <td>
                    <a href="?hapus=<?php echo $index; ?>" class="btn-hapus" onclick="return confirm('Yakin ingin menghapus produk ini?');">
                        Hapus
                    </a>
                </td>
            </tr>
        <?php } ?>
    </table>

</body>
</html>
