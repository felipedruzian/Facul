import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.LinkedList;


public class Turma {
    private long codTurma;
    private DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
    private Date dataIni;
    private Date dataFim;
    private Curso curso;
    private LinkedList<Aluno> alunos = new LinkedList<Aluno>();
    private LinkedList<Instrutor> instrutores = new LinkedList<Instrutor>();

    public Turma(long codTurma, String dataIni, String dataFim, Curso curso) {
        this.codTurma = codTurma;
        this.curso = curso;
        try {
            this.dataIni = dateFormat.parse(dataIni);
            this.dataFim = dateFormat.parse(dataFim);
        } catch (Exception e) {
            System.out.println("Erro ao converter data");
        }
    }

    public String getDataIni() {
        return "Data de inicio: " + dateFormat.format(dataIni);
    }

    public String getDataFim() {
        return "Data de fim: " + dateFormat.format(dataFim);
    }

    public long getCodTurma() {
        return codTurma;
    }

    public String getCurso() {
        return curso.toString();
    }
    
    public void addAluno(Aluno aluno) {
        alunos.add(aluno);
    }

    public void addInstrutor(Instrutor instrutor) {
        instrutores.add(instrutor);
    }

    public void listarTurma() {
        sortInstrutores();
        sortAlunos();
        System.out.println("\n---//---\n");
        toString();
        for (Instrutor instrutor : instrutores) {
            System.out.println(instrutor.toString());
        }
        for (Aluno aluno : alunos) {
            System.out.println(aluno.toString());
        }
        System.out.println("\n---//---\n");
    }

    private void sortAlunos() {
        for (int i = 0; i < alunos.size(); i++) {
            for (int j = 0; j < alunos.size() -1; j++) {
                if (alunos.get(j).getNome().compareTo(alunos.get(j+1).getNome()) > 0) {
                    Aluno aux = alunos.get(j);
                    alunos.set(j, alunos.get(j+1));
                    alunos.set(j+1, aux);
                }
            }
        }
    }

    private void sortInstrutores() {
        for (int i = 0; i < instrutores.size(); i++) {
            for (int j = 0; j < instrutores.size() -1; j++) {
                if (instrutores.get(j).getNome().compareTo(instrutores.get(j+1).getNome()) > 0) {
                    Instrutor aux = instrutores.get(j);
                    instrutores.set(j, instrutores.get(j+1));
                    instrutores.set(j+1, aux);
                }
            }
        }
    }

    public String toString() {
        return "\n---//---\n" + "Turma: " + String.valueOf(codTurma) + curso.toString() + "\nData de inicio: " + dateFormat.format(dataIni) + "\nData de fim: " + dateFormat.format(dataFim) + "\n---//---\n";
    }
}
