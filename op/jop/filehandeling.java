import java.io.*;
import java.util.*;

class Database {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public void addRecords() throws IOException {
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("sample.txt", true)));

        String studentname, address, s;
        int studentid, rollno, classLevel;
        float marks;
        boolean addMore = false;

        do {
            System.out.print("\nEnter Student Name: ");
            studentname = br.readLine();
            System.out.print("Student Id: ");
            studentid = Integer.parseInt(br.readLine());
            System.out.print("Roll no: ");
            rollno = Integer.parseInt(br.readLine());
            System.out.print("Address: ");
            address = br.readLine();
            System.out.print("Class: ");
            classLevel = Integer.parseInt(br.readLine());
            System.out.print("Marks : ");
            marks = Float.parseFloat(br.readLine());

            pw.println(studentname + " " + studentid + " " + rollno + " " + address + " " + classLevel + " " + marks);
            System.out.print("\nRecords added successfully!\n\nDo you want to add more records? (y/n): ");
            s = br.readLine();
            addMore = s.equalsIgnoreCase("y");

        } while (addMore);
        pw.close();
    }

    public void readRecords() throws IOException {
        try {
            BufferedReader file = new BufferedReader(new FileReader("sample.txt"));
            String record;
            while ((record = file.readLine()) != null) {
                System.out.println(record + "\n");
            }
            file.close();
        } catch (FileNotFoundException e) {
            System.out.println("\nERROR: File not Found!!!");
        }
    }

    public void searchRecords() throws IOException {
        try {
            BufferedReader file = new BufferedReader(new FileReader("sample.txt"));
            String record;
            int flag = 0;
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter an ID of the student you want to search: ");
            String searchId = sc.next();

            while ((record = file.readLine()) != null) {
                String[] line = record.split(" ");
                if (searchId.equalsIgnoreCase(line[1])) {
                    System.out.println("Record found");
                    System.out.println(record + "\n");
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                System.out.println("Record not found");
            }
            file.close();
        } catch (FileNotFoundException e) {
            System.out.println("\nERROR: File not Found!!!");
        }
    }

    public void deleteRecords() throws IOException {
        try {
            BufferedReader file1 = new BufferedReader(new FileReader("sample.txt"));
            PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("new.txt")));
            String record;
            int flag = 0;
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the student ID you want to delete: ");
            String searchId = sc.next();

            while ((record = file1.readLine()) != null) {
                String[] line = record.split(" ");
                if (!searchId.equalsIgnoreCase(line[1])) {
                    pw.println(record);
                } else {
                    System.out.println("Record found and deleted");
                    flag = 1;
                }
            }

            file1.close();
            pw.close();

            File delName = new File("sample.txt");
            File oldName = new File("new.txt");

            if (delName.delete() && oldName.renameTo(delName)) {
                System.out.println("Record deleted successfully");
            } else {
                System.out.println("Error in deletion or renaming");
            }

        } catch (FileNotFoundException e) {
            System.out.println("\nERROR: File not Found!!!");
        }
    }

    public void updateRecords() throws IOException {
        try {
            BufferedReader file1 = new BufferedReader(new FileReader("sample.txt"));
            PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("new.txt")));
            String record;
            int flag = 0;
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the student ID you want to update: ");
            String searchId = sc.next();

            while ((record = file1.readLine()) != null) {
                String[] line = record.split(" ");
                if (!searchId.equalsIgnoreCase(line[1])) {
                    pw.println(record);
                } else {
                    System.out.println("Record found");
                    System.out.print("Enter updated marks: ");
                    String updatedMarks = sc.next();
                    pw.println(line[0] + " " + line[1] + " " + line[2] + " " + line[3] + " " + line[4] + " " + updatedMarks);
                    flag = 1;
                }
            }

            file1.close();
            pw.close();

            File delName = new File("sample.txt");
            File oldName = new File("new.txt");

            if (delName.delete() && oldName.renameTo(delName)) {
                System.out.println("Record updated successfully");
            } else {
                System.out.println("Error in update or renaming");
            }

        } catch (FileNotFoundException e) {
            System.out.println("\nERROR: File not Found!!!");
        }
    }

    public void clear(String filename) throws IOException {
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
        pw.close();
        System.out.println("\nAll Records cleared successfully!");
    }
}

public class filehandeling {
    public static void main(String args[]) throws IOException {
        Database db = new Database();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.print("1. Add Records\n2. Display Records\n3. Clear All Records\n4. Search Records"
                    + "\n5. Delete Records\n6. Update Records \n7. Exit\n\nEnter your choice: ");
            int choice = sc.nextInt();
            System.out.println("");

            switch (choice) {
                case 1:
                    db.addRecords();
                    break;
                case 2:
                    db.readRecords();
                    break;
                case 3:
                    db.clear("sample.txt");
                    break;
                case 4:
                    db.searchRecords();
                    break;
                case 5:
                    db.deleteRecords();
                    break;
                case 6:
                    db.updateRecords();
                    break;
                case 7:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid Choice!");
                    break;
            }
            System.out.println("\n====================================================\n");
        }
    }
}
