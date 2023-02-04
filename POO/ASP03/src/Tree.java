public class Tree<T extends Comparable<T>> {

    private Node<T> root;

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
    
    public void preOrderTraversal() {
        preOrderHelper(root);
    }

    private void preOrderHelper(Node<T> node) {
        if (node == null) {
            return;
        }
        System.out.printf("%s ", node.data);
        preOrderHelper(node.leftNode);
        preOrderHelper(node.rightNode);
    }

    public void inOrderTraversal() {
        inOrderHelper(root);
    }

    private void inOrderHelper(Node<T> node) {
        if (node == null) {
            return;
        }
        inOrderHelper(node.leftNode);
        System.out.printf("%s ", node.data);
        inOrderHelper(node.rightNode);
    }

    public void postOrderTraversal() {
        postOrderHelper(root);
    }

    private void postOrderHelper(Node<T> node) {
        if (node == null) {
            return;
        }
        postOrderHelper(node.leftNode);
        postOrderHelper(node.rightNode);
        System.out.printf("%s ", node.data);
    }

}
