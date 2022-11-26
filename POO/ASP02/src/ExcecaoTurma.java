public class ExcecaoTurma extends Exception {
    public ExcecaoTurma() {
        super("Turma nao encontrada!");
    }

    public ExcecaoTurma(String msg) {
        super(msg);
    }
}
