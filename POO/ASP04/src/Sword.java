public class Sword extends BaseItem{
    private float damage;
    private float durability;

    public Sword(String name, float weight, float value, float damage, float durability) {
        super(name, weight, value);
        this.damage = damage;
        this.durability = durability;
    }

    public float getDamage() {
        return damage;
    }

    public float getDurability() {
        return durability;
    }

    @Override
    public String toString() {
        return "Sword [name=" + getName() + ", weight=" + getWeight() + ", value=" + getValue() + ", damage=" + damage + ", durability=" + durability + "]";
    }
    
}

