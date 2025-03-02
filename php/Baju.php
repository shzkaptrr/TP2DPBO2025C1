<?php
require("Aksesoris.php"); // inherit dari class Aksesoris
class Baju extends Aksesoris {
    private $untuk;
    private $size;
    private $merk;

    // constructor
    
    public function __construct($untuk = '', $size = '', $merk = '') {
        $this->untuk = $untuk;
        $this->size = $size;
        $this->merk = $merk;
    }

    // getter
    public function getUntuk() {
        return $this->untuk;
    }
    public function getSize() {
        return $this->size;
    }
    public function getMerk() {
        return $this->merk;
    }

    // setter
    public function setUntuk($untuk) {
        $this->untuk = $untuk;
    }
    public function setSize($size) {
        $this->size = $size;
    }
    public function setMerk($merk) {
        $this->merk = $merk;
    }

}
?>