public class Potion extends BaseItem {
    private float health;
    private float mana;
    private boolean isFull;
    private String nameEmpty = "Empty Potion";

    public Potion(String name, float value, float health, float mana) {
        super(name, 5.0f, value);
        this.health = health;
        this.mana = mana;
        this.isFull = true;
    }

    public boolean isFull() {
        return isFull;
    }

    public void setFull(boolean isFull) {
        this.isFull = isFull;
    }

    @Override
    public float getWeight() {
        if (isFull) {
            return super.getWeight();
        } else {
            return 0.1f;
        }
    }

    @Override
    public float getValue() {
        if (isFull) {
            return super.getValue();
        } else {
            return 0.5f;
        }
    }

    @Override
    public String getName() {
        if (isFull) {
            return super.getName();
        } else {
            return nameEmpty;
        }
    }

    public float getHealth() {
        if (isFull) {
            return health;
        } else {
            return 0;
        }
    }

    public float getMana() {
        if (isFull) {
            return mana;
        } else {
            return 0;
        }
    } 

    @Override
    public String toString() {
        return "Potion [name=" + getName() + ", weight=" + getWeight() + ", value=" + getValue() + ", health=" + health + ", mana=" + mana + ", isFull=" + isFull + "]";
    }
    
}
