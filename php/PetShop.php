<?php

class PetShop{
    // atibut
    private $id;
    private $namaProduk;
    private $hargaProduk;
    private $stokProduk;
    private $fotoProduk;

    // constructor
    public function __construct($id = '', $namaProduk = '', $hargaProduk = '', $stokProduk = '', $fotoProduk = '') {
        $this->id = $id;
        $this->namaProduk = $namaProduk;
        $this->hargaProduk = $hargaProduk;
        $this->stokProduk = $stokProduk;
        $this->fotoProduk = $fotoProduk;
    }

    // getter
    public function getId() {
        return $this->id;
    }
    public function getNamaProduk() {
        return $this->namaProduk;
    }
    public function getHargaProduk() {
        return $this->hargaProduk;
    }
    public function getStokProduk() {
        return $this->stokProduk;
    }
    public function getFotoProduk() {
        return $this->fotoProduk;
    }

    // setter
    public function setId($id) {
        $this->id = $id;
    }
    public function setNamaProduk($namaProduk) {
        $this->namaProduk = $namaProduk;
    }
    public function setHargaProduk($hargaProduk) {
        $this->hargaProduk = $hargaProduk;
    }
    public function setStokProduk($stokProduk) {
        $this->stokProduk = $stokProduk;
    }
    public function setFotoProduk($fotoProduk) {
        $this->fotoProduk = $fotoProduk;
    }

}

?>