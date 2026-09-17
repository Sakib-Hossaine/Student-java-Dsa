// Abstract class — can have state + partial implementation
abstract class Vehicle {
    int speed;
    abstract void accelerate();
    void stop() { System.out.println("Stopped"); }
}

// Interface — pure contract (Java 8+ allows default methods)
interface Electric {
    void charge();
    default void ecoMode() { System.out.println("Eco mode on"); }
}

class Tesla extends Vehicle implements Electric {
    @Override void accelerate() { System.out.println("Accelerating silently"); }
    @Override public void charge() { System.out.println("Charging battery"); }
}

public class Main {
    public static void main(String[] args) {
        Tesla t = new Tesla();
        t.accelerate();   // Accelerating silently
        t.charge();       // Charging battery
        t.ecoMode();      // Eco mode on
        t.stop();         // Stopped
    }
}
