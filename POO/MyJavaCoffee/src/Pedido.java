import java.util.Scanner;

public class Pedido {
    private String Nome;
    private long CPF;
    private String Endereco;
    private int Quantidade;
    private double ValorSF;
    private double ValorT;
    private int P=0, M=0, G=0;


    public void setEndereco(Cliente c)
    {
        Scanner scanner = new Scanner(System.in);
        Nome = c.getName();
        CPF = c.getCPF();
        System.out.println("Insira seu Endereco: ");
        Endereco = scanner.nextLine();
    }
    
    public void setQuantPedido(Produto p)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insira quantidade de pacotes que deseja: ");
        Quantidade = scanner.nextInt();
        ValorSF = Quantidade * p.getPreco();
    }

    public void getDadosPedido()
    {
        System.out.println("Nome do Cliente: " + Nome + ". CPF: " + CPF);
        System.out.println("Endereco: " + Endereco);
        System.out.println("Numero de Pacotes de Cafe MyJava Encomendados: " + String.valueOf(Quantidade) + " - R$ " + String.valueOf(ValorSF));
        setEmbalagens(Quantidade);
        System.out.println("Embalagens usadas: ");
        System.out.println(String.valueOf(G) + " Grande - R$ " + String.valueOf(3.0 * G));
        System.out.println(String.valueOf(M) + " Media - R$ " + String.valueOf(2.0 * M));
        System.out.println(String.valueOf(P) + " Pequena - R$ " + String.valueOf(1.2 * P));
        ValorT = ValorSF + (G*3.0)+(M*2.0)+(P*1.2);
        System.out.println("Seu custo total é: R$ " + String.valueOf(ValorT));
    }

    //embalagens
    private void setEmbalagens(int q)
    {
        q = Quantidade;

        while (q != 0) {
            if (q >= 20)
            {
                G++;
                q = q-20;
            }else if (q >= 10)
            {
                M++;
                q = q-10;
            }else if(q >= 5)
            {
                P++;
                q = q-5;
            }else if(q < 5)
            {
                P++;
                q = q - q;
            }
        }

    }

}
