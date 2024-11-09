import org.junit.Assert;
import org.junit.jupiter.api.Test;

class ProductTest {
    Basket b = new Basket();
    Product p = new Product("123", "Marchew", 5);

    @Test
    void testAddItemToBasket() {
        b.addProduct(p);
        Assert.assertEquals("same product", b.getProducts().get(0), p);
    }

    @Test
    void testGetPrice() {
        Assert.assertEquals("5",5, p.getPrice(), 0.001);
    }

    @Test
    void testGetCode() {
        Assert.assertEquals("123","123", p.getCode());
    }

    @Test
    void testGetName() {
        Assert.assertEquals("Marchew", p.getName());
    }

    @Test
    void testGetDiscountPrice() {
        Assert.assertEquals(5, p.getDiscountPrice(), 0.001);
    }

    @Test
    void testSetDiscountPrice() {
        p.setDiscountPrice(4);
        Assert.assertEquals(4, p.getDiscountPrice(), 0.001);
    }

    @Test
    void testSetName() {
        p.setName("Cukinia");
        Assert.assertEquals("Marchew", p.getName());
    }

    @Test
    void testSetPrice() {
        p.setPrice(3);
        Assert.assertEquals(5, p.getPrice(), 0.001);
    }

    @Test
    void testSetCode() {
        p.setCode("321");
        Assert.assertEquals("123", p.getCode());
    }

}