// Felipe Barreto Druzian - Prova 2 de POO - EC UNIPAMPA BAGE 2022/2

//import java.util.Locale;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GUI extends JFrame implements ActionListener {

    //Locale localeBr = new Locale("pt", "BR");
    
    private Container janela;
    private GridLayout gridLayout;
    
    private JPanel p0_1;
    private JPanel p0_2;
    private JPanel p1;
    private JPanel p2;
    private JPanel p3;
    private JPanel p4;
    private JPanel p5;

    private JTextField resposta;
    private JRadioButton resposta1;
    private JRadioButton resposta2;
    private JRadioButton resposta3;
    private JRadioButton resposta4;
    private JCheckBox checkbox1;
    private JCheckBox checkbox2;
    private JCheckBox checkbox3;
    private JCheckBox checkbox4;
    private JCheckBox checkbox5;

    private JLabel hitOrMiss;
    private JLabel resp;
    private JButton buttonResp;
    private JButton buttonNext;

    private ArrayList<Pergunta> perguntas;
    private ArrayList<String> tipoPerguntas;
    private ArrayList<String> aU;
    private int contador=0;
    private int numPs=0;
    private int acertos=0;


    public GUI(){
        janela = getContentPane();
        setSize(600,400);
        setResizable(false);
        setTitle("Questionário Java - Prova 2 POO");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        gridLayout = new GridLayout(5,1,10,10);
        //cardLayout = new CardLayout();
        //montaJanela = new JPanel(gridLayout);
        janela.setLayout(gridLayout);

        questionario();
        montaPaineis();
        montaJanela();
    }

    private void montaPaineis(){
        p0_1 = Painel0();
        p0_2 = Painel0();
        p1 = Painel1(perguntas.get(contador).getPergunta(), tipoPerguntas.get(contador));

        p2 = Painel2();
        p3 = Painel3(aU);
        p4 = Painel4();

        p5 = Painel5(); 
    }

    private void montaJanela(){

        janela.removeAll();
        if (tipoPerguntas.get(contador).compareTo("T")==0){
            janela.add(p0_1);
            janela.add(p1);
            janela.add(p0_2);
            janela.add(p2);
            janela.add(p5);
        }
        else if(tipoPerguntas.get(contador).compareTo("U")==0){
            janela.add(p0_1);
            janela.add(p1);
            janela.add(p0_2);
            janela.add(p3);
            janela.add(p5);
        }
        else if(tipoPerguntas.get(contador).compareTo("M")==0){
            janela.add(p0_1);
            janela.add(p1);
            janela.add(p0_2);
            janela.add(p4);
            janela.add(p5);
        }
    }

    private JPanel Painel0(){
        JPanel painel0 = new JPanel();
        painel0.setLayout(new GridLayout(1,1,5,5));
        //painel0.setBorder(BorderFactory.createLineBorder(Color.GREEN));

        JLabel espaco = new JLabel("  ");
        //espaco.setBorder(BorderFactory.createLineBorder(Color.PINK));

        painel0.add(espaco);
        return painel0;
    }

    private JPanel Painel1(String p, String tipoP){ // Pergunta e tipo de pergunta

        JPanel painel1 = new JPanel();
        painel1.setLayout(new GridLayout(3,1,5,5));
        //painel1.setBorder(BorderFactory.createLineBorder(Color.RED));

        JLabel pergunta = new JLabel();
        pergunta.setText(p); //pergunta 
        pergunta.setHorizontalAlignment(JLabel.CENTER);
        //pergunta.setBorder(BorderFactory.createLineBorder(Color.RED));

        JLabel tipoPergunta = new JLabel(); //tipoPergunta if...
        if (tipoP.equals("T")){
            tipoPergunta.setText("Pergunta de Texto (T)");
        }else
        if (tipoP.equals("U")){
            tipoPergunta.setText("Pergunta de Única Escolha (U)");
        }else
        if (tipoP.equals("M")){
            tipoPergunta.setText("Pergunta de Múltipla Escolha (M)");
        }else
        if(tipoP.equals("N")){
            tipoPergunta.setText("Pergunta Numérica (N)");
        }


        tipoPergunta.setHorizontalAlignment(JLabel.CENTER);
        //tipoPergunta.setBorder(BorderFactory.createLineBorder(Color.RED));

        JLabel tab = new JLabel("    ");
        //tab.setBorder(BorderFactory.createLineBorder(Color.cyan));

        painel1.add(tipoPergunta);
        painel1.add(tab);
        painel1.add(pergunta);
        return painel1;
    }


    private JPanel Painel2(){ //Tipo T ou N
        JPanel painel2 = new JPanel();
        //painel2.setLayout(new GridLayout(1,3,5,5));
        //painel2.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        JLabel tipoTN = new JLabel("(T/N) Texto ou Numérico: ");
        //tipoTN.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        resposta = new JTextField();
        resposta.setColumns(40);
        
        painel2.add(tipoTN);        
        painel2.add(resposta);
        return painel2;
    }

    private JPanel Painel3(ArrayList<String> alts){ //Tipo U
        JPanel painel3 = new JPanel();
        //painel3.setLayout(new GridLayout(1,6,5,5));
        //painel3.setBorder(BorderFactory.createLineBorder(Color.BLUE));

        JLabel tipoU = new JLabel("(U) Única escolha: ");
        //tipoU.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        resposta1 = new JRadioButton(alts.get(0));
        resposta2 = new JRadioButton(alts.get(1));
        resposta3 = new JRadioButton(alts.get(2));
        resposta4 = new JRadioButton(alts.get(3));
        //resposta1.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        //resposta2.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        //resposta3.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        //resposta4.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        ButtonGroup bg=new ButtonGroup();
        bg.add(resposta1);
        bg.add(resposta2);
        bg.add(resposta3);
        bg.add(resposta4);

        JLabel espaco = new JLabel("  ");
        //espaco.setBorder(BorderFactory.createLineBorder(Color.PINK));

        painel3.add(tipoU);
        painel3.add(espaco);
        painel3.add(resposta1);
        painel3.add(resposta2);
        painel3.add(resposta3);
        painel3.add(resposta4);
        return painel3;
    }

    private JPanel Painel4(){ //Tipo M
        JPanel painel4 = new JPanel();
        //painel4.setLayout(new GridLayout(1,6,5,5));
        //painel4.setBorder(BorderFactory.createLineBorder(Color.YELLOW));

        JLabel tipoM = new JLabel("(M) Múltipla escolha: ");
        //tipoM.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        checkbox1 = new JCheckBox("Resposta 1");
        checkbox2 = new JCheckBox("Resposta 2");
        checkbox3 = new JCheckBox("Resposta 3");
        checkbox4 = new JCheckBox("Resposta 4");
        checkbox5 = new JCheckBox("Resposta 5");
        //checkbox1.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        //checkbox2.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        //checkbox3.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        //checkbox4.setBorder(BorderFactory.createLineBorder(Color.GREEN));

        painel4.add(tipoM);
        painel4.add(checkbox1);
        painel4.add(checkbox2);
        painel4.add(checkbox3);
        painel4.add(checkbox4);
        painel4.add(checkbox5);
        return painel4;
    }

    private JPanel Painel5(){ //Resposta correta e Botoes
        JPanel painel5 = new JPanel();
        painel5.setLayout(new GridLayout(1,2,5,5));
        //painel5.setBorder(BorderFactory.createLineBorder(Color.PINK));

        JPanel painel5_1 = new JPanel();
        JPanel painel5_2 = new JPanel();

        Botoes();
        Gabarito();
        
        painel5.add(painel5_1);
        painel5.add(resp);
        painel5.add(hitOrMiss);
        painel5_2.add(buttonResp);
        painel5_2.add(buttonNext);
        painel5.add(painel5_2);
        return painel5;
    }

    private void Gabarito(){
        resp = new JLabel(" ");
        hitOrMiss = new JLabel(" ");
    }

    private void Botoes(){ //Botões
        buttonResp = new JButton("Verificar Resposta");
        buttonResp.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if(tipoPerguntas.get(contador).compareTo("T") == 0){ 
                    if(resposta.getText().compareTo(perguntas.get(contador).getResposta()) == 0){
                        hitOrMiss.setText("Resposta Correta!");
                        resp.setText("Resposta: " + perguntas.get(contador).getResposta());
                        acertos++;
                    }else{
                        hitOrMiss.setText("Resposta Errada!");
                        resp.setText("Resposta: " + perguntas.get(contador).getResposta());
                    }
                }
                    
                if(tipoPerguntas.get(contador).compareTo("U") == 0) {
                    if(resposta1.isSelected() && perguntas.get(contador).getResposta().compareTo(aU.get(0)) == 0){
                        hitOrMiss.setText("Resposta Correta!");
                        resp.setText("Resposta: " + perguntas.get(contador).getResposta());
                        acertos++;
                    }else if(resposta2.isSelected() && perguntas.get(contador).getResposta().compareTo(aU.get(1)) == 0){
                        hitOrMiss.setText("Resposta Correta!");
                        resp.setText("Resposta: " + perguntas.get(contador).getResposta());
                        acertos++;
                    }else if(resposta3.isSelected() && perguntas.get(contador).getResposta().compareTo(aU.get(2)) == 0){
                        hitOrMiss.setText("Resposta Correta!");
                        resp.setText("Resposta: " + perguntas.get(contador).getResposta());
                        acertos++;
                    }else if(resposta4.isSelected() && perguntas.get(contador).getResposta().compareTo(aU.get(3)) == 0){
                        hitOrMiss.setText("Resposta Correta!");
                        resp.setText("Resposta: " + perguntas.get(contador).getResposta());
                        acertos++;
                    }else{
                        hitOrMiss.setText("Resposta Errada!");
                        resp.setText("Resposta: " + perguntas.get(contador).getResposta());
                    }
                }
                
                
                buttonResp.setEnabled(false);
                buttonNext.setEnabled(true);
            }
        });

        
        buttonNext = new JButton("Próxima Pergunta");
        buttonNext.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
            
                contador++;

                if(contador == numPs){
                    JOptionPane.showMessageDialog(null, "Você acertou " + acertos + " de " + numPs + " perguntas!");
                    System.exit(0);
                }

                montaPaineis();
                montaJanela();
                
                if(contador+1 == numPs){
                    buttonNext.setText("Finalizar");
                }
                
            }
        });

    }


    private void questionario(){
        perguntas = new ArrayList<>();        
        tipoPerguntas = new ArrayList<>();        

        File questionario = new File("questionario.txt");
        Scanner user = new Scanner(System.in);
        
        try {
            Scanner sc = new Scanner(questionario);

            while (sc.hasNextLine()) {
                String data = sc.nextLine();

                if (data.compareTo("T") == 0) { //if para pergunta tipo T

                    tipoPerguntas.add(data);
                    data = sc.nextLine();
                    String r = sc.nextLine();
                    PerguntaT perguntaT = new PerguntaT(data, r);
                    perguntas.add(perguntaT);
                    numPs++;
                }

                if (data.compareTo("U") == 0) {

                    tipoPerguntas.add(data);
                    String p = sc.nextLine();
                    String  r="";
                    int n=0;
                    aU = new ArrayList<String>();
                    for (int i = 0; i < 4; i++) {
                        data = sc.nextLine();
                        
                        if (data.startsWith("+")){
                            r = data.substring(2);
                            aU.add(data.substring(2));
                            n=i;
                        }
                        if (data.startsWith("-")){
                            aU.add(data.substring(2));
                        }
                    }
                    PerguntaU perguntaU = new PerguntaU(p, r, aU.get(0), aU.get(1), aU.get(2), n);
                    perguntas.add(perguntaU);
                    numPs++;
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


    public void actionPerformed(ActionEvent event) { 

    }

}
