import java.util.Scanner;
public class ExceptionHandlingDemo {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            while (true) {
                try {
                    System.out.print("Enter the first number (Num1) or type 'exit' to quit: ");
                    String num1Input = scanner.nextLine();
                    if (num1Input.equalsIgnoreCase("exit")) {
                        break; 
                    }
                    System.out.print("Enter the second number (Num2): ");
                    String num2Input = scanner.nextLine();
                    if (num2Input.equalsIgnoreCase("exit")) {
                        break; 
                    }
                    
                    int num1 = Integer.parseInt(num1Input);
                    int num2 = Integer.parseInt(num2Input);
                    
                    
                    int result = num1 / num2;
                    System.out.println("Result of Num1 / Num2: " + result);
                }
                catch (NumberFormatException e) {
                    System.out.println("Error: Invalid input. Please enter valid integers.");
                    
                } catch (ArithmeticException e) {
                    System.out.println("Error: Division by zero is not allowed.");
                    
                } catch (ArrayIndexOutOfBoundsException e) {
                    System.out.println("Error: Array index out of bounds."); 
                    
                } catch (Exception e) {
                    System.out.println("An unexpected error occurred: " + e.getMessage());
                }
            }
            
        }
        System.out.println("Program exited. Goodbye!");
    }
}
