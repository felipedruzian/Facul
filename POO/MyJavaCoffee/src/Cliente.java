import java.util.Scanner;

public class Cliente {
    private String nome;
    private long CPF;

    public void setCliente()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insira seu Nome: ");
        nome = scanner.nextLine();
        System.out.println("Insira seu CPF: ");
        CPF = scanner.nextLong();
    }

    public String getName()
    {
        return nome;
    }

    public long getCPF()
    {
        return CPF;
    }
    
}
