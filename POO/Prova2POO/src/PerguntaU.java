// Felipe Barreto Druzian - Prova 2 de POO - EC UNIPAMPA BAGE 2022/2
import java.util.ArrayList;

public class PerguntaU extends Pergunta {
    private ArrayList<String> alternativas;

    public PerguntaU(String pergunta, String resposta, String a1, String a2, String a3, int indice) {
        this.pergunta = pergunta;
        this.resposta = resposta;
        alternativas = new ArrayList<String>();
        alternativas.add(a1);
        alternativas.add(a2);
        alternativas.add(a3);
        this.indice = indice;
    }

    public ArrayList<String> getAlternativas() {
        return alternativas;
    }
}
