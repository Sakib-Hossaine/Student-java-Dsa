abstract class Animal {
    public void walk() {
        // Default implementation (can be empty or provide a generic message)
    }
}

class Horse extends Animal {
    @Override
    public void walk() {
        System.out.println("Walks on 4 legs");
    }
}

class Chicken extends Animal {
    @Override
    public void walk() {
        System.out.println("Walks on 2 legs");
    }
}

public class OOPS {
    public static void main(String args[]) {
        // Creating objects
        Animal horse = new Horse();
        Animal chicken = new Chicken();
        
        // Calling walk() method - polymorphism in action
        horse.walk();   // Output: Walks on 4 legs
        chicken.walk(); // Output: Walks on 2 legs
        
        // You can also use an array of Animal references
        Animal[] animals = {new Horse(), new Chicken(), new Horse()};
        for (Animal animal : animals) {
            animal.walk();
        }
    }
}
