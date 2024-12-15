import java.util.Scanner;

abstract class Shape {
    protected double dimension1;
    protected double dimension2;

    public void inputDimensions() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first dimension: ");
        dimension1 = scanner.nextDouble();
        System.out.print("Enter the second dimension: ");
        dimension2 = scanner.nextDouble();
    }

    public abstract double computeArea();
}

class Triangle extends Shape {
    public double computeArea() {
        return 0.5 * dimension1 * dimension2;
    }
}

class Rectangle extends Shape {
    @Override
    public double computeArea() {
        return dimension1 * dimension2;
    }
}

public class ShapeAreaCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Choose shape to calculate area:");
        System.out.println("1. Triangle");
        System.out.println("2. Rectangle");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();
        Shape shape;

        if (choice == 1) {
            shape = new Triangle();
            System.out.println("You chose Triangle.");
        } else {
            shape = new Rectangle();
            System.out.println("You chose Rectangle.");
        }

        shape.inputDimensions();
        double area = shape.computeArea();
        System.out.printf("The area of the shape is: %.2f\n", area);
        scanner.close();
    }
}
