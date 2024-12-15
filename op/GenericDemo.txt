import java.util.Scanner;

class IntegerPropertyChecker {
    public boolean isEven(int number) {
        return number % 2 == 0;
    }
    public boolean isOdd(int number) {
        return number % 2 != 0;
    }
    public boolean isPrime(int number) {
        if (number <= 1) return false;
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    public boolean isPalindrome(int number) {
        String str = Integer.toString(number);
        String reversed = new StringBuilder(str).reverse().toString();
        return str.equals(reversed);
    }
    public void checkProperties() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter an integer to check its properties (type 'exit' to quit):");

        while (true) {
            String input = scanner.nextLine();
            if (input.equalsIgnoreCase("exit")) break;
            try {
                int number = Integer.parseInt(input);
                System.out.println(number + " is Even: " + isEven(number));
                System.out.println(number + " is Odd: " + isOdd(number));
                System.out.println(number + " is Prime: " + isPrime(number));
                System.out.println(number + " is Palindrome: " + isPalindrome(number));
            } catch (NumberFormatException e) {
                System.out.println("Please enter a valid integer.");
            }
        }
        scanner.close();
    }
}

public class GenericDemo {
    public static void main(String[] args) {
        IntegerPropertyChecker checker = new IntegerPropertyChecker();
        checker.checkProperties();
    }
}

