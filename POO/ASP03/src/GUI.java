import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;

public class GUI extends JFrame implements TreeSelectionListener{

    private Container janela;
    private GridLayout gridLayout;

    private JPanel options;
    private JTree jTree;

    DefaultMutableTreeNode root;
    

    Tree<Integer> tree = new Tree<Integer>();
    

    public GUI() {
        janela = getContentPane();
        setSize(600,400);
        //setResizable(false);
        setTitle("AVL Tree GUI Test");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        gridLayout = new GridLayout(1,0);
        janela.setLayout(gridLayout);
        
        root = new DefaultMutableTreeNode("null");
        jTree = new JTree(root);


        
        //Create the scroll pane and add the tree to it. 
        JScrollPane treeView = new JScrollPane(jTree);

        options = new JPanel();
        options.setLayout(new GridLayout(8,1));
        
        JLabel addLabel = new JLabel("Add a node:");
        JTextField addField = new JTextField();
        JButton addButton = new JButton("Add");

        addButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (addField.getText().equals("")) {
                    return;
                }
                addNode(root, addField.getText());
                tree.inserirNode(Integer.parseInt(addField.getText()));
                addField.setText("");
                jTree.updateUI();
            }
        });

        JLabel travLabel = new JLabel("Choose a traversal method:");
        JButton preButton = new JButton("Preorder traversal");
        JButton inButton = new JButton("Inorder traversal");
        JButton posButton = new JButton("Postorder traversal");
        JLabel travResponse = new JLabel("Response: ");

        preButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                tree.cleanList();
                tree.preOrderTraversal();
                travResponse.setText("Response: " + tree.getList());
                janela.validate();
            }
        });

        inButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                tree.cleanList();
                tree.inOrderTraversal();
                travResponse.setText("Response: " + tree.getList());
                janela.validate();
            }
        });

        posButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                tree.cleanList();
                tree.postOrderTraversal();
                travResponse.setText("Response: " + tree.getList());
                janela.validate();
            }
        });


        options.add(addLabel);
        options.add(addField);
        options.add(addButton);
        options.add(travLabel);
        options.add(preButton);
        options.add(inButton);
        options.add(posButton);
        options.add(travResponse);
        
        //Add the scroll panes to a split pane.
        JSplitPane splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT);
        splitPane.setTopComponent(treeView);
        splitPane.setBottomComponent(options);

        Dimension minimumSize = new Dimension(100, 50);
        options.setMinimumSize(minimumSize);
        treeView.setMinimumSize(minimumSize);
        splitPane.setDividerLocation(200); 
        splitPane.setPreferredSize(new Dimension(600, 400));

        
        janela.add(splitPane);

        setLocationRelativeTo(null);
        setVisible(true);
    }


    private void addNode(DefaultMutableTreeNode node, String value) {
        if (node.getUserObject().equals("null")) {
            node.setUserObject(value);
            node.add(new DefaultMutableTreeNode("rightNull"));
            node.add(new DefaultMutableTreeNode("leftNull"));
            return;
        } else if (node.getUserObject().equals("rightNull")) {
            node.setUserObject(value);
            node.add(new DefaultMutableTreeNode("rightNull"));
            node.add(new DefaultMutableTreeNode("leftNull"));
            return;
        } else if (node.getUserObject().equals("leftNull")) {
            node.setUserObject(value);
            node.add(new DefaultMutableTreeNode("rightNull"));
            node.add(new DefaultMutableTreeNode("leftNull"));
            return;
        } else {
            if (Integer.parseInt(value) > Integer.parseInt(node.getUserObject().toString())) {
                addNode((DefaultMutableTreeNode) node.getChildAt(0), value);
            } else {
                addNode((DefaultMutableTreeNode) node.getChildAt(1), value);
            }
        }
    }

    /** Required by TreeSelectionListener interface. */
    public void valueChanged(TreeSelectionEvent e) {}

}
