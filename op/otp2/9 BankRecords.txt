import java.util.Scanner;

class Customer {
    private String customerName;
    private int customerAge;

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerAge(int customerAge) {
        this.customerAge = customerAge;
    }

    public int getCustomerAge() {
        return customerAge;
    }
}

abstract class Account {
    protected double balance;
    protected int accountId;
    protected String accountType;
    protected Customer customer;

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return balance;
    }

    public void setAccountId(int accountId) {
        this.accountId = accountId;
    }

    public int getAccountId() {
        return accountId;
    }

    public void setAccountType(String accountType) {
        this.accountType = accountType;
    }

    public String getAccountType() {
        return accountType;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public Customer getCustomer() {
        return customer;
    }

    public abstract boolean withdraw(double amount);
}

class SavingsAccount extends Account {
    private double minimumBalance = 1000;
    private double dailyWithdrawalLimit = 20000;

    public boolean withdraw(double amount) {
        if ((balance - amount) >= minimumBalance && amount <= dailyWithdrawalLimit) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
}

class Bank {
    private Scanner sc = new Scanner(System.in);
    private SavingsAccount account;

    public void createAccount() {
        account = new SavingsAccount();
        Customer customer = new Customer();

        sc.nextLine();

        System.out.print("Enter your name: ");
        customer.setCustomerName(sc.nextLine());

        System.out.print("Enter your age: ");
        int age = sc.nextInt();
        while (age < 18) {
            System.out.print("Minimum age to create an account is 18. Enter valid age: ");
            age = sc.nextInt();
        }
        customer.setCustomerAge(age);

        System.out.print("Enter account ID: ");
        account.setAccountId(sc.nextInt());

        System.out.print("Enter initial balance (minimum Rs.1000): ");
        double initialBalance = sc.nextDouble();
        while (initialBalance < 1000) {
            System.out.print("Initial balance must be at least Rs.1000. Enter valid balance: ");
            initialBalance = sc.nextDouble();
        }
        account.setBalance(initialBalance);

        System.out.print("Enter account type (Savings/Current): ");
        account.setAccountType(sc.next());

        account.setCustomer(customer);
        System.out.println("Account created successfully!\n");
    }

    public void displayAccountInfo() {
        if (account == null) {
            System.out.println("No account found. Please create an account first.");
            return;
        }
        Customer customer = account.getCustomer();
        System.out.println("Account Information:");
        System.out.println("Customer Name: " + customer.getCustomerName());
        System.out.println("Customer Age: " + customer.getCustomerAge());
        System.out.println("Account ID: " + account.getAccountId());
        System.out.println("Account Type: " + account.getAccountType());
        System.out.println("Balance: " + account.getBalance());
    }

    public void depositMoney() {
        if (account == null) {
            System.out.println("No account found. Please create an account first.");
            return;
        }
        System.out.print("Enter amount to deposit: ");
        double depositAmount = sc.nextDouble();
        account.setBalance(account.getBalance() + depositAmount);
        System.out.println("Amount deposited successfully! Current balance: " + account.getBalance());
    }

    public void withdrawMoney() {
        if (account == null) {
            System.out.println("No account found. Please create an account first.");
            return;
        }
        System.out.print("Enter amount to withdraw (Daily limit Rs.20000): ");
        double withdrawAmount = sc.nextDouble();
        if (account.withdraw(withdrawAmount)) {
            System.out.println("Withdrawal successful! Current balance: " + account.getBalance());
        } else {
            System.out.println("Withdrawal failed! Either insufficient balance or daily limit exceeded.");
        }
    }

    public void checkBalance() {
        if (account == null) {
            System.out.println("No account found. Please create an account first.");
            return;
        }
        System.out.println("Current balance: " + account.getBalance());
    }
}

public class BankRecords {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Bank bank = new Bank();
        int choice;

        do {
            System.out.println("\n--- Banking System Menu ---");
            System.out.println("1. Create Account");
            System.out.println("2. Display Account Information");
            System.out.println("3. Check Balance");
            System.out.println("4. Deposit Money");
            System.out.println("5. Withdraw Money");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    bank.createAccount();
                    break;
                case 2:
                    bank.displayAccountInfo();
                    break;
                case 3:
                    bank.checkBalance();
                    break;
                case 4:
                    bank.depositMoney();
                    break;
                case 5:
                    bank.withdrawMoney();
                    break;
                case 6:
                    System.out.println("Exiting... Thank you for using our banking system.");
                    break;
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        } while (choice != 6);

        sc.close();
    }
}
