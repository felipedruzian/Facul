// Felipe Barreto Druzian - Prova 2 de POO - EC UNIPAMPA BAGE 2022/2
import java.util.ArrayList;

public class PerguntaM extends Pergunta{
    private String[] alternativas;
    private int[] indices;

    public PerguntaM(String pergunta, String resposta, String[] alternativas, int[] indices) {
        this.pergunta = pergunta;
        this.resposta = resposta;
        this.alternativas = alternativas;
        this.indices = indices;
    }

    public String[] getAlternativas() {
        return alternativas;
    }

    public int[] getIndices() {
        return indices;
    }

}
