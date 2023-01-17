// Felipe Barreto Druzian - Prova 2 de POO - EC UNIPAMPA BAGE 2022/2

abstract public class Pergunta {

    protected String pergunta;
    protected String resposta;
    protected int indice;


    public String getPergunta(){
        return pergunta;
    }

    public String getResposta(){
        return resposta;
    }

    public int getIndice() {
        return indice;
    }
}
