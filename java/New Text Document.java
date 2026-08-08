





// Without user input
''// ============================================
// CLASS - Blueprint/template for creating Car objects
// ============================================
class Car {
    String color;
    String type;

    // ============================================
    // CONSTRUCTOR - Special method that initializes objects
    // Same name as class, no return type
    // ============================================
    Car(String color, String type) {
        this.color = color;
        this.type = type;
    }

    void printColor() {
        System.out.println(this.color);
    }
}

// ============================================
// CLASS - Main class containing program entry point
// ============================================
public class OOPS {
    public static void main(String args[]) {
        
        // ============================================
        // OBJECT - Instance of Car class created using 'new' keyword
        // car1 is an object (instance) of Car class
        // ============================================
        Car car1 = new Car("red", "Sedan");  // ← OBJECT
        
        // ============================================
        // OBJECT - Another instance of Car class
        // car2 is also an object of Car class
        // ============================================
        Car car2 = new Car("blue", "SUV");   // ← OBJECT

        car1.printColor();  // Output: red
        car2.printColor();  // Output: blue
    }
}




// with user input





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
