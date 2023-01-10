import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Conversor extends JFrame {
    private static final int width = 300;
    private static final int height = 200;

    private JLabel CelsiusLabel, FahrenheitLabel;
    private JTextField CelsiusField, FahrenheitField;
    private JButton limpar, converter;
    private JPanel central;

    // grau Fahrenheit p/ Celsius: °C = ((°F – 32) × 5) / 9
    private static double FtoC(double f) {
        return ((f - 32) * 5) / 9;
    }

    // grau Celsius p/ grau Fahrenheit: °F = ((°C × 9) / 5) + 32
    private static double CtoF(double c) {
        return ((c * 9) / 5) + 32;
    }

    public Conversor() {
        super("Conversor");
        setSize(width, height);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container conteudo = getContentPane();

        conteudo.setLayout(new GridLayout(3, 2, 5, 5));
        conteudo.setBackground(Color.YELLOW);

        conteudo.add(CelsiusLabel = new JLabel("Celsius: "));
        conteudo.add(CelsiusField = new JTextField(5));
        conteudo.add(FahrenheitLabel = new JLabel("Fahrenheit: "));
        conteudo.add(FahrenheitField = new JTextField(5));
        conteudo.add(limpar = new JButton("Limpar"));
        conteudo.add(converter = new JButton("Converter"));

        // botao limpar
        limpar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                CelsiusField.setText("");
                FahrenheitField.setText("");
            }
        });

        // botao converter
        converter.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String celsius = CelsiusField.getText();
                String fahrenheit = FahrenheitField.getText();

                if (celsius.equals("") && fahrenheit.equals("")) {
                    JOptionPane.showMessageDialog(null, "Digite algum valor para conversão!");
                } else if (!celsius.equals("") && !fahrenheit.equals("")) {
                    JOptionPane.showMessageDialog(null, "Digite apenas um valor para conversão!");
                } else if (!celsius.equals("")) {
                    try {
                        Double.parseDouble(celsius);
                        double c = Double.parseDouble(celsius);
                        FahrenheitField.setText(String.format("%.2f", CtoF(c)));
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(null, "Digite um valor numérico para conversão!");
                        return;
                    }
                } else {
                    try {
                        Double.parseDouble(fahrenheit);
                        double f = Double.parseDouble(fahrenheit);
                        CelsiusField.setText(String.format("%.2f", FtoC(f)));
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(null, "Digite um valor numérico para conversão!");
                        return;
                    }
                }
            }
        });

        setVisible(true);
    }

    public static void main(String[] args) {
        Conversor frame = new Conversor();
    }
}