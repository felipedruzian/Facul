public class Curso {
    private String nome;
    private long codCurso;
    private int cargaHoraria;

    public Curso(String nome, long codigo, int cargaHoraria) {
        this.nome = nome;
        this.codCurso = codigo;
        this.cargaHoraria = cargaHoraria;
    }

    public String getNome() {
        return nome;
    }

    public long getCodCurso() {
        return codCurso;
    }

    public int getCargaHoraria() {
        return cargaHoraria;
    }

    public String toString() {
        return "\nCurso: " + nome + "\nCódigo: " + String.valueOf(codCurso) + "\nCarga Horária: " + String.valueOf(cargaHoraria);
    }
}
