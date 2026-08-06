import java.util.Scanner;

class Car {
    String color;
    String type;

    void printColor() {
        System.out.println(this.color + " color " + this.type.toLowerCase() + " is moving");
    }
}

public class OOPS {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("How many cars do you want to create? ");
        int count = sc.nextInt();
        sc.nextLine(); // consume newline
        
        Car[] cars = new Car[count];
        
        for (int i = 0; i < count; i++) {
            System.out.println("\nEnter details for Car " + (i + 1) + ":");
            System.out.print("Enter color: ");
            String color = sc.nextLine();
            System.out.print("Enter type (Sedan/SUV/Hatchback etc.): ");
            String type = sc.nextLine();
            
            cars[i] = new Car();
            cars[i].color = color;
            cars[i].type = type;
        }
        
        System.out.println("\n--- Output ---");
        for (int i = 0; i < count; i++) {
            cars[i].printColor();
        }
        
        sc.close();
    }
}