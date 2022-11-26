public class ExcecaoAluno extends Exception {
    public ExcecaoAluno() {
        super("Aluno nao encontrado!");
    }

    public ExcecaoAluno(String msg) {
        super(msg);
    }
}
