public class DiscountOne implements Command {
Basket basket;

public DiscountOne(Basket b) {
    basket = b;
}
    @Override
    public void execute() {
        if (basket.getTotal()>300) {
            for (Product product : basket.getProducts())
                product.setDiscountPrice(product.getPrice()*0.95);
        }
    }


    @Override
    public void revert() {
        for (Product product : basket.getProducts())
            product.setDiscountPrice(product.getDiscountPrice()/0.95);
    }
}
