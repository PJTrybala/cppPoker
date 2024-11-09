public class Main {
    public static void main(String[] args) {
        Basket basket = new Basket();

        Product banana = new Product("999", "Banana", 2.20);
        Product strawberry = new Product("123", "Strawberry", 2.00);
        Product smartphone = new Product("534", "Smartphone", 499.00);
        Product cup = new Product("745", "Paper cup", 1.00);

        Product orange = new Product("554", "Orange", 499.00);
        Product pineapple = new Product("926", "Pineapple", 1.00);

        Product a = new Product("654", "A", 499.00);
        Product ze = new Product("263", "Ze", 1.00);

        basket.addProduct(banana);
        basket.addProduct(strawberry);
        basket.addProduct(smartphone);
        basket.addProduct(cup);
        basket.addProduct(orange);
        basket.addProduct(pineapple);
        basket.addProduct(a);
        basket.addProduct(ze);

        basket.listProducts();
        basket.sortPrice();

        basket.listProducts();

        basket.sortName();

        basket.listProducts();

        basket.sortPrice();

        basket.listProducts();

        DiscountOne applyDiscountOne = new DiscountOne(basket);
        DiscountTwo applyDiscountTwo = new DiscountTwo(basket);
        DiscountThree applyDiscountThree = new DiscountThree(basket);
        DiscountFour applyDiscountFour = new DiscountFour(basket);

        ApplyButton applyOne = new ApplyButton(applyDiscountOne);
        ApplyButton applyTwo = new ApplyButton(applyDiscountTwo);
        ApplyButton applyThree = new ApplyButton(applyDiscountThree);
        ApplyButton applyFour = new ApplyButton(applyDiscountFour);

        applyOne.press();
        basket.listProducts();
        applyTwo.press();
        basket.listProducts();
        applyThree.press();

        basket.listProducts();

        System.out.println(basket.findCheapest());
        System.out.println(basket.findMostExpensive());
        System.out.println(basket.findNCheapest(4));
        System.out.println(basket.findNMostExpensive(4));


    }
}
