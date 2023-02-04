public class BaseItem implements Item{

    private String name;
    private float weight;
    private float value;

    public BaseItem(String name, float weight, float value) {
        this.name = name;
        this.weight = weight;
        this.value = value;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public float getWeight() {
        return weight;
    }

    @Override
    public float getValue() {
        return value;
    }
    
    @Override
    public String toString() {
        return "BaseItem [name=" + name + ", weight=" + weight + ", value=" + value + "]";
    }

}
