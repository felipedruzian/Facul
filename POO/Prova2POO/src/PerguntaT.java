// Felipe Barreto Druzian - Prova 2 de POO - EC UNIPAMPA BAGE 2022/2

public class PerguntaT extends Pergunta{

    private String resposta;

    PerguntaT(String pergunta, String resposta){
        this.pergunta = pergunta;
        this.resposta = resposta;
    }

    /*public void setResposta(String resposta){
        this.resposta = resposta;
    }*/

    public String getResposta(){
        return resposta;
    }
}
