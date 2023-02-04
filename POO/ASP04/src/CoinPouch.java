import java.util.LinkedList;

public class CoinPouch extends BaseItem {
    private LinkedList<Coin> coins = new LinkedList<Coin>();

    public CoinPouch() {
        super("Pouch", 0.5f, 0.5f);
    }

    @Override
    public float getWeight(){
        float weight = 0;
        for (Coin coin : coins) {
            weight += coin.getWeight()*0.5f;
        }
        return weight;
    }

    @Override
    public float getValue(){
        float value = 0;
        for (Coin coin : coins) {
            value += coin.getValue();
        }
        return value;
    }

    public int getQuantity() {
        return coins.size();
    }

    public void addCoin(Coin coin) {
        coins.add(coin);
    }

    public void removeCoin(int quantity) {
        for (int i = 0; i < quantity; i++) {
            coins.removeLast();
            // if is empty
            if (coins.isEmpty()) {
                break;
            }
        }
    }

    @Override
    public String toString() {
        return "CoinPouch [name=" + getName() + ", weight=" + getWeight() + ", value=" + getValue() + ", quantity=" + getQuantity() + "]";
    }

}
