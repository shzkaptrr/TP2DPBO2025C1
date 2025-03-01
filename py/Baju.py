from Aksesoris import Aksesoris

class Baju(Aksesoris): # inherit dari class Aksesoris
    # atribut
    __untuk = ""
    __size = ""
    __merk = ""
    
    # constructor
    def __init__(self, untuk="", size="", merk=""):
        self.__untuk = untuk
        self.__size = size
        self.__merk = merk
        
    # getter
    def getUntuk(self): return self.__untuk
    def getSize(self): return self.__size
    def getMerk(self): return self.__merk
    
    # setter
    def setUntuk(self, untuk): self.__untuk = untuk
    def setSize(self, size): self.__size = size
    def setMerk(self, merk): self.__merk = merk