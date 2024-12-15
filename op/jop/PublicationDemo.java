class Publication {
    String title;
    double price;
    int copies;

    Publication(String title, double price, int copies) {
        this.title = title;
        this.price = price;
        this.copies = copies;
    }

    double saleCopy() {
        return price * copies;
    }

    void displayDetails() {
        System.out.println("Title: " + title);
        System.out.println("Price: $" + price);
        System.out.println("Copies sold: " + copies);
        System.out.println("Total sales: $" + saleCopy());
    }
}

class Book extends Publication {
    String author;

    Book(String title, double price, int copies, String author) {
        super(title, price, copies);
        this.author = author;
    }

    void orderCopies(int additionalCopies) {
        copies += additionalCopies;
    }

    void displayDetails() {
        super.displayDetails();
        System.out.println("Author: " + author);
    }
}

class Magazine extends Publication {
    String currentIssue;

    Magazine(String title, double price, int copies, String currentIssue) {
        super(title, price, copies);
        this.currentIssue = currentIssue;
    }

    void orderQty(int quantity) {
        copies += quantity;
    }

    void receiveIssue(String newIssue) {
        currentIssue = newIssue;
    }

    void displayDetails() {
        super.displayDetails();
        System.out.println("Current Issue: " + currentIssue);
    }
}

public class PublicationDemo {
    public static void main(String[] args) {
        Book book1 = new Book("Java Programming", 39.99, 100, "John Doe");
        Magazine mag1 = new Magazine("Tech Today", 5.99, 200, "Sept 2024");

        System.out.println("Book Details:");
        book1.displayDetails();
        System.out.println();

        System.out.println("Magazine Details:");
        mag1.displayDetails();
        System.out.println();

        book1.orderCopies(50);
        mag1.orderQty(100);

        System.out.println("Updated Book Details:");
        book1.displayDetails();
        System.out.println();

        System.out.println("Updated Magazine Details:");
        mag1.displayDetails();
    }
}
