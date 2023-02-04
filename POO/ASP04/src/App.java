import java.util.Scanner;

// peso e valor total de um inventario de RPG com itens de vários tipos com implementação
// do padrão Composite (Composite Pattern) (ou pelo menos tentei xd)
// Felipe Barreto Druzian 04/02/2023


public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Inventory inventory = new Inventory();
        CoinPouch coinPouch = new CoinPouch();

        int option;
        do {
            System.out.println("\n------// Welcome to the inventory manager! //------");
            System.out.println("1 - Add item");
            System.out.println("2 - Remove item");
            System.out.println("3 - Show inventory");
            System.out.println("4 - Clear inventory");
            System.out.println("5 - Exit");
            System.out.println("Please select an option:");
            option = scanner.nextInt();
            switch (option) {
                case 1:
                    int option1;
                    do {
                        System.out.println();
                        System.out.println("1 - Add coin pouch");
                        System.out.println("2 - Add coin");
                        System.out.println("3 - Add sword");
                        System.out.println("4 - Add potion");
                        System.out.println("5 - Exit");
                        System.out.println("Please select an option:");
                        option1 = scanner.nextInt();
                        switch (option1) {
                            case 1:
                            System.out.println();
                            if (inventory.getItems().contains(coinPouch)){
                                    System.out.println("You already have a coin pouch!");
                                    break;
                                }else {
                                    inventory.addItem(coinPouch);
                                    System.out.println("Coin pouch added!");
                                }
                                break;
                            case 2:
                                System.out.println();
                                if (inventory.getItems().contains(coinPouch)){
                                    coinPouch.addCoin(new Coin());
                                    System.out.println("Coin added!");
                                }
                                else
                                System.out.println("You don't have a coin pouch!");
                                
                                break;
                            case 3:
                                scanner.nextLine();
                                System.out.println("Please enter the sword name:");
                                String swordName = scanner.nextLine();
                                System.out.println("Please enter the sword weight:");
                                float swordWeight = scanner.nextFloat();
                                System.out.println("Please enter the sword value:");
                                float swordValue = scanner.nextFloat();
                                System.out.println("Please enter the sword damage:");
                                float swordDamage = scanner.nextFloat();
                                System.out.println("Please enter the sword durability:");
                                float swordDurability = scanner.nextFloat();

                                Sword sword = new Sword(swordName, swordWeight, swordValue, swordDamage, swordDurability);
                                inventory.addItem(sword);
                                break;
                            case 4:
                                scanner.nextLine();
                                System.out.println("Please enter the potion name:");
                                String potionName = scanner.nextLine();
                                System.out.println("Please enter the potion value:");
                                float potionValue = scanner.nextFloat();
                                System.out.println("Please enter the potion health restore:");
                                float potionHealth = scanner.nextFloat();
                                System.out.println("Please enter the potion mana restore:");
                                float potionMana = scanner.nextFloat();

                                Potion potion = new Potion(potionName, potionValue, potionHealth, potionMana);
                                inventory.addItem(potion);
                                break;
                            case 5:
                                break;
                            default:
                                System.out.println("Invalid option!");
                                break;
                        }
                    }
                    while (option1 != 5);
                    break;
                    
                case 2:
                    int option2;
                    do {
                        System.out.println("1 - Remove coin");
                        System.out.println("2 - Remove by index");
                        System.out.println("3 - Exit");
                        System.out.println("Please select an option:");
                        option2 = scanner.nextInt();
                        switch (option2) {
                            case 1:
                                System.out.println("Amount of coins to remove: ");
                                int amount = scanner.nextInt();
                                if (inventory.getItems().contains(coinPouch)){
                                    coinPouch.removeCoin(amount);
                                    System.out.println("Coin removed!");
                                }
                                else
                                    System.out.println("You don't have a coin pouch!");
                                break;
                            case 2:
                                System.out.println("Please enter the index:");
                                int index = scanner.nextInt();
                                inventory.removeItem(index);
                                break;
                            case 3:
                                break;
                            default:
                                System.out.println("Invalid option!");
                                break;
                        }
                    }while(option2 != 3);
                    break;
                
                case 3:
                    System.out.println();
                    System.out.println(inventory);
                    break;
                case 4:
                    inventory.clear();
                    System.out.println("Inventory cleared!");
                    break;
                case 5:
                    inventory.clear();
                    scanner.close();
                    System.out.println("Goodbye!");

                    break;
            
                default:
                    break;
            }
        }while (option != 5);


        
    }
}
