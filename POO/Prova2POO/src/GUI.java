// Felipe Barreto Druzian - Prova 2 de POO - EC UNIPAMPA BAGE 2022/2

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GUI extends JFrame implements ActionListener {
    
    private JButton buttonResp;
    private JButton buttonNext;
    private String pergunta;
    private String tipoPergunta;

    public GUI(){
        //Janela
        Container container = getContentPane();
        setSize(600,400);
        setResizable(false);
        setTitle("Questionário Java - Prova 2 POO");
        
        //FlowLayout flowLayout = new FlowLayout();
        GridLayout gridLayout = new GridLayout(5,1,150,10);
        container.setLayout(gridLayout);


        //Adicionando os painéis ao container //ifs para cada painel
        container.add(Painel0());
        container.add(Painel1()); 
        container.add(Painel0());
        container.add(Painel2());
        container.add(Painel5());
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    }

    private JPanel Painel0(){
        JPanel painel0 = new JPanel();
        painel0.setLayout(new GridLayout(1,1,5,5));
        painel0.setBorder(BorderFactory.createLineBorder(Color.GREEN));

        JLabel espaco = new JLabel("  ");
        JLabel tab = new JLabel("    ");
        espaco.setBorder(BorderFactory.createLineBorder(Color.PINK));
        tab.setBorder(BorderFactory.createLineBorder(Color.cyan));

        painel0.add(espaco);

        return painel0;
    }
    
    private JPanel Painel1(){ // Pergunta e tipo de pergunta
        JPanel painel1 = new JPanel();
        painel1.setLayout(new GridLayout(3,1,5,5));
        painel1.setBorder(BorderFactory.createLineBorder(Color.RED));

        JLabel pergunta = new JLabel();
        pergunta.setText("Pergunta xesq dele vrau ambicious?"); //pergunta 
        pergunta.setHorizontalAlignment(JLabel.CENTER);
        pergunta.setBorder(BorderFactory.createLineBorder(Color.RED));

        JLabel tipoPergunta = new JLabel("Pergunta de texto (T)"); //tipoPergunta if...
        tipoPergunta.setHorizontalAlignment(JLabel.CENTER);
        tipoPergunta.setBorder(BorderFactory.createLineBorder(Color.RED));

        JLabel tab = new JLabel("    ");
        tab.setBorder(BorderFactory.createLineBorder(Color.cyan));

        painel1.add(tipoPergunta);
        painel1.add(tab);
        painel1.add(pergunta);

        return painel1;
    }

    public void setPergunta(String pergunta, String tipoPergunta){
        this.pergunta = pergunta;
        this.tipoPergunta = tipoPergunta;
    }

    private JPanel Painel2(){
        JPanel painel2 = new JPanel();
        //painel2.setLayout(new GridLayout(1,3,5,5));
        painel2.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        JLabel tipoTN = new JLabel("(T/N) Texto ou Numérico: ");
        tipoTN.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        JTextField resposta = new JTextField();
        resposta.setColumns(40);
        //resposta.setBounds(50, 50, 100, 90);
        //resposta.addActionListener(this);
        //getText();???
        
        painel2.add(tipoTN);        
        painel2.add(resposta);

        return painel2;
    }

    private JPanel Painel3(){
        JPanel painel3 = new JPanel();
        //painel3.setLayout(new GridLayout(1,6,5,5));
        painel3.setBorder(BorderFactory.createLineBorder(Color.BLUE));

        JLabel tipoU = new JLabel("(U) Única escolha: ");
        tipoU.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        JRadioButton resposta1 = new JRadioButton("Resposta 1");
        JRadioButton resposta2 = new JRadioButton("Resposta 2");
        JRadioButton resposta3 = new JRadioButton("Resposta 3");
        JRadioButton resposta4 = new JRadioButton("Resposta 4");
        resposta1.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        resposta2.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        resposta3.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        resposta4.setBorder(BorderFactory.createLineBorder(Color.BLUE));
        ButtonGroup bg=new ButtonGroup();
        bg.add(resposta1);
        bg.add(resposta2);
        bg.add(resposta3);
        bg.add(resposta4);

        JLabel espaco = new JLabel("  ");
        espaco.setBorder(BorderFactory.createLineBorder(Color.PINK));

        painel3.add(tipoU);
        painel3.add(espaco);
        painel3.add(resposta1);
        painel3.add(resposta2);
        painel3.add(resposta3);
        painel3.add(resposta4);

        return painel3;
    }

    private JPanel Painel4(){
        JPanel painel4 = new JPanel();
        //painel4.setLayout(new GridLayout(1,6,5,5));
        painel4.setBorder(BorderFactory.createLineBorder(Color.YELLOW));

        JLabel tipoM = new JLabel("(M) Múltipla escolha: ");
        tipoM.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        JCheckBox checkbox1 = new JCheckBox("Resposta 1");
        JCheckBox checkbox2 = new JCheckBox("Resposta 2");
        JCheckBox checkbox3 = new JCheckBox("Resposta 3");
        JCheckBox checkbox4 = new JCheckBox("Resposta 4");
        checkbox1.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        checkbox2.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        checkbox3.setBorder(BorderFactory.createLineBorder(Color.GREEN));
        checkbox4.setBorder(BorderFactory.createLineBorder(Color.GREEN));

        painel4.add(tipoM);
        painel4.add(checkbox1);
        painel4.add(checkbox2);
        painel4.add(checkbox3);
        painel4.add(checkbox4);

        return painel4;
    }

    private JPanel Painel5(){ //Resposta correta e Botoes
        JPanel painel5 = new JPanel();
        painel5.setLayout(new GridLayout(1,2,5,5));
        painel5.setBorder(BorderFactory.createLineBorder(Color.PINK));

        JPanel painel5_1 = new JPanel();
        JPanel painel5_2 = new JPanel();

        Botoes();
        
        //painel5_1.add(new JLabel("Resposta correta: "));
        painel5.add(painel5_1);
        painel5_2.add(buttonResp);
        painel5_2.add(buttonNext);
        painel5.add(painel5_2);

        return painel5;
    }

    private void Botoes(){ //Botões
        buttonResp = new JButton("Verificar Resposta");
        buttonResp.addActionListener(this);
        buttonResp.setMnemonic(KeyEvent.VK_ENTER);
        buttonResp.setActionCommand("disable");

        buttonNext = new JButton("Próxima Pergunta");
        buttonNext.addActionListener(this);
        buttonNext.setMnemonic(KeyEvent.VK_ENTER);
        buttonNext.setActionCommand("enable");
        buttonNext.setEnabled(false);
    }


    private void Questionario(){
        ArrayList<Pergunta> perguntas = new ArrayList<>();        
        ArrayList<String> tipoPerguntas = new ArrayList<>();        

        File questionario = new File("questionario.txt");
        Scanner user = new Scanner(System.in);
        
        try {
            Scanner sc = new Scanner(questionario);

            while (sc.hasNextLine()) {
                String data = sc.nextLine();

                if (data.compareTo("T") == 0) { //if para pergunta tipo T

                    tipoPerguntas.add(data);
                    PerguntaT perguntaT = new PerguntaT(sc.nextLine(), sc.nextLine());
                    perguntas.add(perguntaT);
                }

                if (data.compareTo("U") == 0) {

                    tipoPerguntas.add(data);
                    String p = sc.nextLine();
                    String  r="";
                    String[] a = new String[3];
                    data = sc.nextLine();
                    for (int i = 0; i < 4; i++) {
                        
                        if (data.startsWith("+")){
                            r = data.substring(2);
                        }
                        if (data.startsWith("-")){
                            a[i] = data.substring(2);
                        }
                    }
                    data = sc.nextLine();

                    PerguntaU perguntaU = new PerguntaU(p, r, a[1], a[2], a[3]);
                    perguntas.add(perguntaU);

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
        if ("disable".equals(event.getActionCommand())) {
            buttonNext.setEnabled(true);
        } else {
            buttonResp.setEnabled(true);
            buttonNext.setEnabled(false);
        }
    }

    public static void main(String[] args) {
        GUI app = new GUI();
        app.setLocationRelativeTo(null);
    }
}
