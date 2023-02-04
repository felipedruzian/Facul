import java.security.SecureRandom;

public class App {
    public static void main(String[] args) throws Exception {
        Tree<Integer> tree = new Tree<Integer>();
        SecureRandom random = new SecureRandom();
        int [] values = new int[] { 27, 13, 6, 17, 42, 33, 48 };

        System.out.println("Inserindo os seguintes valores: ");

        for (int i = 0; i < 7; i++) {
            //int value = random.nextInt(100);
            System.out.printf("%d ", values[i]);
            tree.inserirNode(values[i]);
        }

        System.out.println("\n\nPreorder traversal\n");
        tree.preOrderTraversal();

        System.out.println("\n\nInorder traversal\n");
        tree.inOrderTraversal();

        System.out.println("\n\nPostorder traversal\n");
        tree.postOrderTraversal();

        System.out.println();
    }
}
