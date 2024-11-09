import org.junit.Assert;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

class FullBasketTest {
    Basket basket = new Basket();
    Product banana = new Product("999", "Banana", 2.20);
    Product strawberry = new Product("123", "Strawberry", 2.00);
    Product smartphone = new Product("534", "Smartphone", 499.00);
    Product cup = new Product("745", "Paper cup", 1.00);

    Product orange = new Product("554", "Orange", 3.50);
    Product pineapple = new Product("926", "Pineapple", 7.00);

    Product avocado = new Product("654", "Avocado", 6.50);
    Product zucchini = new Product("263", "Zucchini", 3.00);


    @Test
    void testSum() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);

        Assert.assertEquals(525,basket.getTotal(),0.001);
    }

    @Test
    void testFindCheapestProduct() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);

        Assert.assertEquals(banana, basket.findCheapest());
    }

    @Test
    void testFindNCheapestProducts() {
        ArrayList<Product> list = new ArrayList<>();
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);
        Assert.assertEquals(list,basket.findNCheapest(4));
    }

    @Test
    void testFindMostExpensiveProduct() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);
        Assert.assertEquals(banana,basket.findMostExpensive());
    }

    @Test
    void testFindNMostExpensiveProducts() {
        ArrayList<Product> list = new ArrayList<>();
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);
        Assert.assertEquals(list,basket.findNMostExpensive(4));
    }

    @Test
    void testSortName() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);
        basket.sortName();
        Assert.assertSame(avocado.getName(),basket.getProducts().get(1).getName());
    }

    @Test
    void testSortPrice() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);
        basket.sortPrice();
        Assert.assertEquals(basket.findCheapest().getPrice(),basket.getProducts().get(0).getPrice(),0.001);
    }

}