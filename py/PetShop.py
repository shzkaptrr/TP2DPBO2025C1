class PetShop:
    # atribut
    __id = ""
    __namaProduk = ""
    __hargaProduk = 0
    __stokProduk = 0
    
    # constructor
    def __init__(self, id="", namaProduk="", hargaProduk=0, stokProduk=0):
        self.__id = id
        self.__namaProduk = namaProduk
        self.__hargaProduk = hargaProduk
        self.__stokProduk = stokProduk
        
    # getter
    def getId(self): return self.__id
    def getNamaProduk(self): return self.__namaProduk
    def getHargaProduk(self): return self.__hargaProduk
    def getStokProduk(self): return self.__stokProduk
    
    # setter
    def setId(self, id): self.__id = id
    def setNamaProduk(self, namaProduk): self.__namaProduk = namaProduk
    def setHargaProduk(self, hargaProduk): self.__hargaProduk = hargaProduk
    def setStokProduk(self, stokProduk): self.__stokProduk = stokProduk