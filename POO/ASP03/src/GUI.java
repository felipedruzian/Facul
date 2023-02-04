import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.JFrame;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;

public class GUI extends JFrame implements TreeSelectionListener{

    private Container janela;
    private GridLayout gridLayout;

    private JPanel TreePanel;

    Tree<Integer> tree = new Tree<Integer>();
    

    public GUI() {
        janela = getContentPane();
        setSize(600,400);
        setResizable(false);
        setTitle("AVL Tree GUI Test");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        //gridLayout = new GridLayout(5,1,10,10);
        //janela.setLayout(gridLayout);

        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void createTree() {
        DefaultMutableTreeNode top = new DefaultMutableTreeNode();
    }



    @Override
    public void valueChanged(TreeSelectionEvent e) {
        // TODO Auto-generated method stub
        
    }
    

    public static void main(String[] args) {
        GUI gui = new GUI();
    }
}
