public class PetShop{
    private String id;
    private String namaProduk;
    private int hargaProduk;
    private int stokProduk;

    // constructor
    public PetShop(){
        
    }
    public PetShop(String id, String namaProduk, int hargaProduk, int stokProduk){
        this.id = id;
        this.namaProduk = namaProduk;
        this.hargaProduk = hargaProduk;
        this.stokProduk = stokProduk;
    }

    // getter
    public String getId() { return this.id; }
    public String getNamaProduk() { return this.namaProduk; }
    public int getHargaProduk() { return this.hargaProduk; }
    public int getStokProduk() { return this.stokProduk; }

    // setter
    public void setId(String id) { this.id = id; }
    public void setNamaProduk(String namaProduk) { this.namaProduk = namaProduk; }
    public void setHargaProduk(int hargaProduk) { this.hargaProduk = hargaProduk; }
    public void setStokProduk(int stokProduk) { this.stokProduk = stokProduk; }




}