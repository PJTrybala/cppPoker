import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;

public class Basket {

    private int basket_id;
    private double total = 0;
    private double discountedTotal = 0;
    private ArrayList<Product> products = new ArrayList<>();

    public Basket (int basket_id) {
        setBasket_id(basket_id);
    }

    public Basket () {
        Random random = new Random();
        setBasket_id(random.ints(1000, 9999).findFirst().getAsInt());
    }

    private void setBasket_id(int basket_id) {
        this.basket_id = basket_id;
    }

    public void addProduct(Product p) {
        this.products.add(p);
        total += p.getPrice();
    }

    public void removeProduct(Product p) {
        this.products.remove(p);
        this.total -= p.getPrice();
    }

    public int getBasket_id() {
        return basket_id;
    }

    public double getTotal() {
        return total;
    }

    public double getDiscountedTotal() {
        return discountedTotal;
    }

    public ArrayList<Product> getProducts() {
        return products;
    }

    public void listProducts() {
        System.out.println("Zawartość twojego koszyka:");
        for (Product p : products) {
            System.out.print(p.getCode()+", ");
            System.out.print(p.getName()+", ");
            System.out.println(p.getDiscountPrice());
        }
        System.out.println();
    }

    public ArrayList<Product> sortPrice() {
        Collections.sort(this.products, Comparator.comparingDouble(Product::getDiscountPrice));
        return this.products;
    }

    public ArrayList<Product> sortName() {
        Collections.sort(this.products, Comparator.comparing(Product::getName));
        return this.products;
    }

    public ArrayList<Product> returnSorted() {
        ArrayList<Product> list = new ArrayList<>(products);
        Collections.sort(list, Comparator.comparing(Product::getDiscountPrice));
        return list;
    }

    public Product findCheapest() {
        return returnSorted().get(0);
    }

    public Product findMostExpensive() {
        return returnSorted().get(products.size() - 1);
    }

    public ArrayList<Product> findNCheapest(int n) {
        ArrayList<Product> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(returnSorted().get(i));
        }
        return list;
    }

    public ArrayList<Product> findNMostExpensive(int n) {
        ArrayList<Product> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            list.add(returnSorted().get(products.size() - i));
        }
        return list;
    }

}
