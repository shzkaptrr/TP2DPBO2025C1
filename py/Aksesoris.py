from PetShop import PetShop

class Aksesoris(PetShop): # inherit dari class PetShop
    # atribut
    __jenis = ""
    __bahan = ""
    __warna = ""
    
    # constructor
    def __init__(self, jenis="", bahan="", warna=""):
        self.__jenis = jenis
        self.__bahan = bahan
        self.__warna = warna
        
    # getter
    def getJenis(self): return self.__jenis
    def getBahan(self): return self.__bahan
    def getWarna(self): return self.__warna
    
    # setter
    def setJenis(self, jenis): self.__jenis = jenis
    def setBahan(self, bahan): self.__bahan = bahan
    def setWarna(self, warna): self.__warna = warna