import java.util.LinkedList;

public class CoinPouch extends BaseItem {
    private LinkedList<Coin> coins;

    public CoinPouch() {
        super("Pouch", 0.5f, 0.5f);
        coins = new LinkedList<Coin>();
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
            coins.removeFirst();
        }
    }

    @Override
    public String toString() {
        return "CoinPouch [name=" + getName() + ", weight=" + getWeight() + ", value=" + getValue() + ", quantity=" + getQuantity() + "]";
    }

}
