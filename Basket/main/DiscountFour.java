import java.io.InputStream;
import java.util.Scanner;

public class DiscountFour implements Command {
    Basket basket;
    Product product;

    public DiscountFour(Basket b) {
        basket = b;
    }

    @Override
    public void execute() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Podaj ID produktu, który chcesz przecenić: ");
        String id = scanner.next();
        scanner.close();
        for (Product p : basket.getProducts()) {
            if (p.getCode().equals(id)) {
                p.setDiscountPrice(p.getPrice()*0.7);
            }
        }
    }

    @Override
    public void revert() {
        product.setDiscountPrice(product.getDiscountPrice()/0.7);
    }
}
