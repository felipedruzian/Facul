public class Aluno extends Pessoa {
    private long matricula;

    public Aluno(String nome, long matricula) {
        super(nome);
        this.matricula = matricula;
    }

    public long getMatricula() {
        return matricula;
    }

    public String toString() {
        return "\nAluno: " + getNome() + "\nMatrícula: " + String.valueOf(matricula);
    }
}
