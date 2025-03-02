<?php
require("PetShop.php"); // inherit dari class PetShop
class Aksesoris extends PetShop {
    // atribut
    private $jenis;
    private $bahan;
    private $warna;

    // constructor
   
    public function __construct($jenis = '', $bahan = '', $warna = '') {
        $this->jenis = $jenis;
        $this->bahan = $bahan;
        $this->warna = $warna;
    }

    // getter
    public function getJenis() {
        return $this->jenis;
    }
    public function getBahan() {
        return $this->bahan;
    }
    public function getWarna() {
        return $this->warna;
    }

    // setter
    public function setJenis($jenis) {
        $this->jenis = $jenis;
    }
    public function setBahan($bahan) {
        $this->bahan = $bahan;
    }
    public function setWarna($warna) {
        $this->warna = $warna;
    }

}
?>