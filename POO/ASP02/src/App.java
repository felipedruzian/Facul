import java.util.Scanner;


public class App {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        String nome, telefone;
        int key;

        System.out.print("Digite o nome da escola: ");
        nome = scan.nextLine();
        System.out.print("Digite o telefone da escola: ");
        telefone = scan.nextLine();
        Escola escola = new Escola(nome, telefone);

        do {
            System.out.println("Escola " + escola.getNome() + " - Tel: " + escola.getTelefone());
            System.out.println("MENU:");
            System.out.println("1 - Cadastrar aluno");
            System.out.println("2 - Cadastrar instrutor");
            System.out.println("3 - Cadastrar turma");
            System.out.println("4 - Buscar aluno");
            System.out.println("5 - Buscar instrutor");
            System.out.println("6 - Buscar turma");
            System.out.println("7 - Listar turma");
            System.out.println("8 - Sair");
            System.out.print("Digite a opção desejada: ");
            key = scan.nextInt();
            scan.nextLine();
            switch (key) {
                case 1:
                    String nomeAluno;
                    long matrAluno;
                    System.out.print("Digite o nome do aluno: ");
                    nomeAluno = scan.nextLine();
                    System.out.print("Digite a matrícula do aluno: ");
                    matrAluno = scan.nextLong();
                    scan.nextLine();
                    Aluno aluno = new Aluno(nomeAluno, matrAluno);
                    escola.addAluno(aluno);
                break;

                case 2:
                    String nomeInstrutor;
                    long codInstrutor;
                    System.out.print("Digite o nome do instrutor: ");
                    nomeInstrutor = scan.nextLine();
                    System.out.print("Digite o código do instrutor: ");
                    codInstrutor = scan.nextLong();
                    scan.nextLine();
                    Instrutor instrutor = new Instrutor(nomeInstrutor, codInstrutor);
                    escola.addInstrutor(instrutor);
                break;

                case 3:
                    System.out.print("Digite o codigo da turma: ");
                    long codTurma = scan.nextLong();
                    scan.nextLine();
                    System.out.print("Digite data de inicio da turma: ");
                    String dataIni = scan.nextLine();
                    System.out.print("Digite data de termino da turma: ");
                    String dataFim = scan.nextLine();
                    System.out.print("Digite o nome do curso: ");
                    String nomeCurso = scan.nextLine();
                    System.out.print("Digite o codigo do curso: ");
                    long codCurso = scan.nextLong();
                    scan.nextLine();
                    System.out.print("Digite a carga horaria do curso: ");
                    int cargaHoraria = scan.nextInt();
                    scan.nextLine();
                    Curso curso = new Curso(nomeCurso, codCurso, cargaHoraria);
                    Turma turma = new Turma(codTurma, dataIni, dataFim, curso);

                    boolean flag = true;
                    do {
                        System.out.print("Digite o codigo do instrutor: ");
                        long codInstr = scan.nextLong();
                        scan.nextLine();
                        String nomeInstr = escola.buscarCodInstrutores(codInstr);
                        if (nomeInstr != "") {
                            Instrutor instr = new Instrutor(nomeInstr, codInstr);
                            turma.addInstrutor(instr);
                        } else {
                            System.out.println("Instrutor não encontrado");
                            System.out.println("Digite o nome do Instrutor para cadastra-lo: ");
                            nomeInstr = scan.nextLine();
                            Instrutor instr = new Instrutor(nomeInstr, codInstr);
                            escola.addInstrutor(instr);
                            turma.addInstrutor(instr);
                        }
                        System.out.print("Deseja adicionar mais um instrutor? (1 - Sim / 2 - Não): ");
                        int op = scan.nextInt();
                        scan.nextLine();
                        if (op == 2) {
                            flag = false;
                        }
                    }while(flag == true);
                    
                    boolean flag2 = true;
                    do {
                        System.out.print("Digite a matricula do aluno: ");
                        long matrAlunoTurma = scan.nextLong();
                        scan.nextLine();
                        String nomeAlunoTurma = escola.buscarMatrAluno(matrAlunoTurma);
                        if (nomeAlunoTurma != "") {
                            Aluno alunoTurma = new Aluno(nomeAlunoTurma, matrAlunoTurma);
                            turma.addAluno(alunoTurma);
                        } else {
                            System.out.println("Aluno não encontrado");
                            System.out.println("Digite o nome do Aluno para cadastra-lo: ");
                            nomeAlunoTurma = scan.nextLine();
                            Aluno alunoTurma = new Aluno(nomeAlunoTurma, matrAlunoTurma);
                            escola.addAluno(alunoTurma);
                            turma.addAluno(alunoTurma);
                        }
                        System.out.print("Deseja adicionar mais um aluno? (1 - Sim / 2 - Não): ");
                        int op = scan.nextInt();
                        scan.nextLine();
                        if (op == 2) {
                            flag2 = false;
                        }
                    }while(flag2 == true);
                    escola.addTurma(turma);
                break;

                case 4:
                try {
                    long matrAlunoBusca;
                    System.out.print("Digite a matricula do aluno: ");
                    matrAlunoBusca = scan.nextLong();
                    scan.nextLine();
                    escola.buscarAlunos(matrAlunoBusca);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
                break;

                case 5:
                try {
                    long codInstrutorBusca;
                    System.out.print("Digite o codigo do instrutor: ");
                    codInstrutorBusca = scan.nextLong();
                    scan.nextLine();
                    escola.buscarInstrutores(codInstrutorBusca);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
                break;

                case 6:
                try {
                    long codTurmaBusca;
                    System.out.print("Digite o codigo da turma: ");
                    codTurmaBusca = scan.nextLong();
                    scan.nextLine();
                    escola.buscarTurmas(codTurmaBusca);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
                break;

                case 7:
                try {
                    long codTurmaBusca;
                    System.out.print("Digite o codigo da turma: ");
                    codTurmaBusca = scan.nextLong();
                    scan.nextLine();
                    escola.listarTurmas(codTurmaBusca);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
                break;

                default:
                    System.out.println("Opção inválida!");
                break;

                case 8:
                    System.out.println("Saindo...");
                    scan.close();
                break;
            }
        } while (key != 8);
            
            
    }
}
