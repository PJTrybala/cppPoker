import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BasketTest {
    @Test
    void testNewBasketExists() {
        Basket b = new Basket();
        assertNull(b);
    }
    @Test
    void testNewBasket() {
        Basket b = new Basket();
        assertNotNull(b);
    }

    @Test
    void testAddProductExists() {
        Product p = new Product("123", "Marchew", 5);
        assertNull(p);
    }

    @Test
    void testAddProduct() {
        Product p = new Product("123", "Marchew", 5);
        assertNotNull(p);
    }

    @Test
    void testAddItemToBasketWrong() {
        Basket b = new Basket();
        Product p = new Product("123", "Marchew", 5);
        b.addProduct(p);

        assertEquals(p, b.getProducts().get(0));
    }

    @Test
    void testAddItemToBasket() {
        Basket b = new Basket();
        Product carrot = new Product("123", "Marchew", 5);
        Product potato = new Product("123", "Ziemniak", 5);
        b.addProduct(carrot);
        assertEquals(potato, b.getProducts().get(0));
    }

}