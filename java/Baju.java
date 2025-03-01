public class Baju extends Aksesoris{ // inherit dari class Aksesoris
    // atribut
    private String untuk;
    private String size;
    private String merk;

    // constructor

    public Baju(){

    }
    
    public Baju(String untuk, String size, String merk){
        this.untuk = untuk;
        this.size = size;
        this.merk = merk;
    }

    // getter
    public String getUntuk() { return this.untuk; }
    public String getSize() { return this.size; }
    public String getMerk() { return this.merk; }

    // setter
    public void setUntuk(String untuk) { this.untuk = untuk; }
    public void setSize(String size) { this.size = size; }
    public void setMerk(String merk) { this.merk = merk; }




}