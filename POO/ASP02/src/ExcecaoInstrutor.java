public class ExcecaoInstrutor extends Exception {
    public ExcecaoInstrutor() {
        super("Instrutor nao encontrado!");
    }

    public ExcecaoInstrutor(String msg) {
        super(msg);
    }
}
