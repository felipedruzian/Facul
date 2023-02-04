import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Inventory extends BaseItem {
    private List<Item> items = new ArrayList<>();
    
    public Inventory(Item... items) {
        super("Inventory", 0, 0);
        addItem(items);
    }

    public void addItem(Item item) {
        items.add(item);
    }

    public void addItem(Item... items) {
        this.items.addAll(Arrays.asList(items));
    }

    public void removeItem(Item item) {
        items.remove(item);
    }

    public void removeItem(Item... items) {
        this.items.removeAll(Arrays.asList(items));
    }
    
    public void removeItem(int index) {
        items.remove(index);
    }

    public void clear() {
        items.clear();
    }

    @Override
    public float getWeight() {
        float weight = 0;
        for (Item item : items) {
            weight += item.getWeight();
        }
        return weight;
    }

    @Override
    public float getValue() {
        float value = 0;
        for (Item item : items) {
            value += item.getValue();
        }
        return value;
    }

    public List<Item> getItems() {
        return items;
    }

    private String getItemsString() {
        String itemsString = "";
        for (Item item : items) {
    
            itemsString += "\n \t" + item.toString() + "\n";
        }
        return itemsString;
    }

    @Override
    public String toString() {
        return "Inventory [weight=" + getWeight() + ", value=" + getValue() + ", items= " + getItemsString() + "]";
    }

}
