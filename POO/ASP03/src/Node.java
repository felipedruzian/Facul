public class Node<T extends Comparable<T>> {
    Node<T> leftNode;
    Node<T> rightNode;
    T data;

    //construtor
    public Node(T data) {
        this.data = data;
        leftNode = rightNode = null; //nó sem filhos
    }

    public void inserir(T data) {
        if (data.compareTo(this.data) < 0) {
            if (leftNode == null) {
                leftNode = new Node<T>(data);
            } else { //percorre a subárvore esquerda recursivamente
                leftNode.inserir(data);
            }
        } else if (data.compareTo(this.data) > 0) {
            if (rightNode == null) {
                rightNode = new Node<T>(data);
            } else { //percorre a subárvore direita recursivamente
                rightNode.inserir(data);
            }
        }
    }

    
}
