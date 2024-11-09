public class DiscountThree implements Command{
    Basket basket;

    public DiscountThree(Basket b) {
        this.basket = b;
    }

    Product kubek = new Product("001","Firmowy kubek", 0);
    @Override
    public void execute() {
        if(basket.getTotal()>200) basket.addProduct(kubek);
    }

    @Override
    public void revert() {
        basket.removeProduct(kubek);
    }
}
