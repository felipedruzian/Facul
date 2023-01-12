// Felipe Barreto Druzian - Prova 2 de POO - EC UNIPAMPA BAGE 2022/2

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class App {
    
    public static void main(String[] args) throws Exception {
        PerguntaT perguntaT;

        try {
            File questionario = new File("questionario.txt");
            Scanner sc = new Scanner(questionario);
            Scanner user = new Scanner(System.in);


            while (sc.hasNextLine()) {
                String data = sc.nextLine();
                

                if (data.compareTo("T") == 0) { //if para pergunta tipo T

                    perguntaT = new PerguntaT(sc.nextLine(), sc.nextLine());
                    System.out.println(perguntaT.getPergunta());
                    
                    System.out.print("R: ");
                    String resp = user.nextLine();
                    if (resp.compareTo(perguntaT.getResposta())==0) {
                        System.out.println("Resposta CORRETA! ");
                    }else{
                        System.out.println("Resposta ERRADA! ");
                        System.out.println("Resposta certa: " + perguntaT.getResposta());
                    }
                }

                //if para outras perguntas
                //classes de outras perguntas a serem implementadas

            }

        sc.close();
        user.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }
}
