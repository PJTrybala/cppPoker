import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

class BasketDiscountsTest {

    private final InputStream systemIn = System.in;
    private final PrintStream systemOut = System.out;

    private ByteArrayInputStream testIn;
    private ByteArrayOutputStream testOut;

    Basket basket = new Basket();
    Product banana = new Product("999", "Banana", 2.20);
    Product strawberry = new Product("123", "Strawberry", 2.00);
    Product smartphone = new Product("534", "Smartphone", 499.00);
    Product cup = new Product("745", "Paper cup", 1.00);

    Product orange = new Product("554", "Orange", 3.50);
    Product pineapple = new Product("926", "Pineapple", 7.00);

    Product avocado = new Product("654", "Avocado", 6.50);
    Product zucchini = new Product("263", "Zucchini", 3.00);

    DiscountOne applyDiscountOne = new DiscountOne(basket);
    DiscountTwo applyDiscountTwo = new DiscountTwo(basket);
    DiscountThree applyDiscountThree = new DiscountThree(basket);
    DiscountFour applyDiscountFour = new DiscountFour(basket);

    ApplyButton applyOne = new ApplyButton(applyDiscountOne);
    ApplyButton applyTwo = new ApplyButton(applyDiscountTwo);
    ApplyButton applyThree = new ApplyButton(applyDiscountThree);
    ApplyButton applyFour = new ApplyButton(applyDiscountFour);


    @Test
    void testDiscountOne() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);


        applyOne.press();

        Assert.assertEquals(basket.getDiscountedTotal(),basket.getTotal()*0.95,0.001);

    }

    @Test
    void testDiscountOneWithSmallerTotal() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);


        applyOne.press();

        Assert.assertEquals(basket.getDiscountedTotal(),basket.getTotal()*0.95,0.001);

    }

    @Test
    void testDiscountTwo() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);

        applyTwo.press();

        Assert.assertEquals(basket.findCheapest().getDiscountPrice(), 0);
    }

    @Test
    void testDiscountTwoWithOnlyTwoItems() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);

        applyTwo.press();

        Assert.assertEquals(basket.findCheapest().getDiscountPrice(), 0);
    }

    @Test
    void testDiscountThree() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);

        applyThree.press();

        Assert.assertEquals("Firmowy kubek",basket.findCheapest().getName());
    }

    @Test
    void testDiscountThreeButWithLess() {
        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(avocado);
        basket.addProduct(zucchini);

        applyThree.press();

        Assert.assertEquals("Firmowy kubek",basket.findCheapest().getName());
    }

    @Before
    public void setUpOutput() {
        testOut = new ByteArrayOutputStream();
        System.setOut(new PrintStream(testOut));
    }

    private void provideInput(String data) {
        testIn = new ByteArrayInputStream(data.getBytes());
        System.setIn(testIn);
    }

    private String getOutput() {
        return testOut.toString();
    }

    @After
    public void restoreSystemInputOutput() {
        System.setIn(systemIn);
        System.setOut(systemOut);
    }

    @Test
    void testDiscountFour() {

        final String testString = "999";
        provideInput(testString);

        applyFour.press();
        Assert.assertEquals(banana.getDiscountPrice(),banana.getPrice()*0.7,0.001);
    }

    @Test
    void testDiscountFourButWrongId() {

        final String testString = "123";
        provideInput(testString);

        applyFour.press();
        Assert.assertEquals(banana.getDiscountPrice(),banana.getPrice()*0.8,0.001);
    }

}