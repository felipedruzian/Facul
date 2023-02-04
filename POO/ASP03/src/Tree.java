import java.util.LinkedList;
import java.util.Queue;

public class Tree<T extends Comparable<T>> {

    private Node<T> root;
    private LinkedList<T> order = new LinkedList<T>();

    //construtor
    public Tree() {
        root = null;
    }

    
    public void inserirNode(T data) {
        if (root == null) {
            root = new Node<T>(data);
        } else {
            root.inserir(data);
        }
    }

    public Node<T> getRoot() {
        return root;
    }

    /*
     * 
     private int depth(Node<T> node) {
         if (node == null) {
             return 0;
            } else {
                return node.getDepth();
            }
        }
    */


    public void preOrderTraversal() {
        preOrderHelper(root);
    }

    private void preOrderHelper(Node<T> node) {
        if (node == null) {
            return;
        }
        order.add(node.getData());
        //System.out.printf("%s ", node.getData());
        preOrderHelper(node.getLeft());
        preOrderHelper(node.getRight());
    }
    
    public void inOrderTraversal() {
        inOrderHelper(root);
    }

    private void inOrderHelper(Node<T> node) {
        if (node == null) {
            return;
        }
        inOrderHelper(node.getLeft());
        order.add(node.getData());
        //System.out.printf("%s ", node.getData());
        inOrderHelper(node.getRight());
    }

    public void postOrderTraversal() {
        postOrderHelper(root);
    }

    private void postOrderHelper(Node<T> node) {
        if (node == null) {
            return;
        }
        postOrderHelper(node.getLeft());
        postOrderHelper(node.getRight());
        order.add(node.getData());
        //System.out.printf("%s ", node.getData());
    }

    public String getList() {
        return order.toString();
    }

    public void cleanList() {
        order.clear();
    }


    public void levelOrderTraversal() {
        Queue<Node<T>> queue = new LinkedList<Node<T>>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node<T> node = queue.remove();
            System.out.printf("%s ", node.getData());
            if (node.getLeft() != null) {
                queue.add(node.getLeft());
            }
            if (node.getRight() != null) {
                queue.add(node.getRight());
            }
        }
    }
    

}
