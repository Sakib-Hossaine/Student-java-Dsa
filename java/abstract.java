abstract class Shape {
    String color;

    Shape(String color) {        // constructor allowed
        this.color = color;
    }

    abstract double area();      // must be implemented by subclass

    void display() {
        System.out.println(color + " shape with area " + area());
    }
}

class Circle extends Shape {
    double radius;

    Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }

    @Override
    double area() {
        return Math.PI * radius * radius;
    }
}

public class Main {
    public static void main(String[] args) {
        Shape s = new Circle("Red", 5);
        s.display();             // Red shape with area 78.539...
    }
}
