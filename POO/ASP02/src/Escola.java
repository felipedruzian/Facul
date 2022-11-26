import java.util.LinkedList;

public class Escola {
    private String nome;
    private String telefone;
    private LinkedList<Aluno> alunos = new LinkedList<Aluno>();
    private LinkedList<Instrutor> instrutores = new LinkedList<Instrutor>();
    private LinkedList<Turma> turmas = new LinkedList<Turma>();

    public Escola(String nome, String telefone) {
        this.nome = nome;
        this.telefone = telefone;
    }

    public String getNome() {
        return nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void addAluno(Aluno aluno) {
        alunos.add(aluno);
    }

    public void addInstrutor(Instrutor instrutor) {
        instrutores.add(instrutor);
    }

    public void addTurma(Turma turma) {
        turmas.add(turma);
    }


    public void buscarAlunos(long mat) throws ExcecaoAluno {
        for (Aluno aluno : alunos) {
            if (aluno.getMatricula() == mat) {
                System.out.println("---//---");
                System.out.println("Aluno encontrado: " + aluno.getNome());
                System.out.println("Matrícula: " + aluno.getMatricula());
                System.out.println("---//---");
                return;
            }
        }
        throw new ExcecaoAluno();
    }

    public void buscarInstrutores(long cod) throws ExcecaoInstrutor {
        for (Instrutor instrutor : instrutores) {
            if (instrutor.getCodInstrutor() == cod) {
                System.out.println("---//---");
                System.out.println("Instrutor encontrado: " + instrutor.getNome());
                System.out.println("Código: " + instrutor.getCodInstrutor());
                System.out.println("---//---");
                return;
            }
        }
        throw new ExcecaoInstrutor();
    }

    public void buscarTurmas(long cod) throws ExcecaoTurma {
        for (Turma turma : turmas) {
            if (turma.getCodTurma() == cod) {
                turma.toString();
                return;
            }
        }
        throw new ExcecaoTurma();
    }


    public String buscarCodInstrutores(long cod) {
        String nomeInstrutor="";
        for (Instrutor instrutor : instrutores) {
            if (instrutor.getCodInstrutor() == cod) {
                nomeInstrutor = instrutor.getNome();
            }
        }
        return nomeInstrutor;
    }

    public String buscarMatrAluno(long mat) {
        String nomeAluno="";
        for (Aluno aluno : alunos) {
            if (aluno.getMatricula() == mat) {
                nomeAluno = aluno.getNome();
            }
        }
        return nomeAluno;
    }

    public void listarTurmas(long cod){
        for (Turma turma : turmas) {
            if (turma.getCodTurma() == cod) {
                turma.listarTurma();
                return;
            }
        }
        System.out.println("\nTurma não encontrada.\n");
        return;
    }

    
}
