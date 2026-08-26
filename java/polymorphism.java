class Animal {
    void sound() { System.out.println("Some sound"); }
}

class Dog extends Animal {
    void sound() { System.out.println("Bark"); }
}

class Cat extends Animal {
    void sound() { System.out.println("Meow"); }
}
// A parent class reference variable can take many forms — it can refer to objects from different child/subclasses.
//Polymorphism is a core concept in object-oriented programming (OOP). The word itself means "many forms" 
public class Main {
    public static void main(String[] args) {
        Animal a;          // Parent reference
        a = new Dog();     // Refers to Dog object
        a.sound();         // Output: Bark

        a = new Cat();     // Refers to Cat object
        a.sound();         // Output: Meow
    }
}
