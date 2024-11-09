import static java.lang.Math.round;

public class Product{
    private String code;
    private String name;
    private double price;
    private double discountPrice;

    public Product (String code, String name, double price) {
        setCode(code);
        setName(name);
        setPrice(price);
        setDiscountPrice(price);
    }

    public String getCode() {
        return code;
    }
    public String getName() {
        return name;
    }
    public double getPrice() {
        return price;
    }
    public double getDiscountPrice() {
        return discountPrice;
    }

    public void setCode(String code) {
        this.code = code;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setPrice(double p) {
        this.price = Math.round(p*100.0)/100.0;
    }
    public void setDiscountPrice(double d) {
        this.discountPrice = Math.round(d*100.0)/100.0;
    }
}
