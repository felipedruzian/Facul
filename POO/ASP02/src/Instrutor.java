public class Instrutor extends Pessoa {
    private long codigo;

    public Instrutor(String nome, long codigo) {
        super(nome);
        this.codigo = codigo;
    }

    public long getCodInstrutor() {
        return codigo;
    }

    public String toString() {
        return "\nInstrutor: " + getNome() + "\nCódigo: " + String.valueOf(codigo);
    }
}
