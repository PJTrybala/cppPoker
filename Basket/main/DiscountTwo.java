import java.util.ArrayList;

public class DiscountTwo implements Command{
    Basket basket;

    public DiscountTwo(Basket b) {
        basket = b;
    }

    @Override
    public void execute() {
        ArrayList<Product> list = basket.getProducts();
        int discounted = list.size()/3;
        for (int i = 0; i < discounted; i++)
            list.get(i).setDiscountPrice(0);
    }

    @Override
    public void revert() {
        for (Product product : basket.getProducts())
            product.setDiscountPrice(product.getPrice());
    }
}
