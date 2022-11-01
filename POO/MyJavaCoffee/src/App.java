public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        Cliente cliente = new Cliente();
        Produto cafe = new Produto();
        Pedido pedido = new Pedido();

        cliente.setCliente();
        pedido.setEndereco(cliente);
        pedido.setQuantPedido(cafe);
        pedido.getDadosPedido();
    }
}
