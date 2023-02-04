public class Node<T extends Comparable<T>> {
    
    private T data;
    private Node<T> left;
    private Node<T> right;
    private int depth;

    //construtor
    public Node(T data) {
        this.data = data;
        left = null;
        right = null;
        depth = 0;
    }

    public int getDepth() {
        return depth;
    }

    public void setDepth(int depth) {
        this.depth = depth;
    }
    
    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public Node<T> getLeft() {
        return left;
    }

    public void setLeft(Node<T> left) {
        this.left = left;
    }

    public Node<T> getRight() {
        return right;
    }

    public void setRight(Node<T> right) {
        this.right = right;
    }

    public void inserir(T data) {
        if (data.compareTo(this.data) < 0) {
            if (left == null) {
                left = new Node<T>(data);
            } else { //percorre a subárvore esquerda recursivamente
                left.inserir(data);
            }
        } else if (data.compareTo(this.data) > 0) {
            if (right == null) {
                right = new Node<T>(data);
            } else { //percorre a subárvore direita recursivamente
                right.inserir(data);
            }
        }
    }

    
}
