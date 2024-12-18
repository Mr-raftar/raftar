import java.util.Scanner;


class Employee   {
    protected String empName;
    protected String empId;
    protected String address;
    protected String mailId;
    protected String mobileNo;
    public Employee(String empName, String empId, String address, String mailId, String mobileNo)   {
        this.empName = empName;
        this.empId = empId;
        this.address = address;
        this.mailId = mailId;
        this.mobileNo = mobileNo;
    }
    
    public void displayDetails()      {
        System.out.println("Employee Name: " + empName);
        System.out.println("Employee ID: " + empId);
        System.out.println("Address: " + address);
        System.out.println("Email ID: " + mailId);
        System.out.println("Mobile No: " + mobileNo);
    }
}

class Programmer extends Employee   {
    private double basicPay;
    public Programmer(String empName, String empId, String address, String mailId, String mobileNo, double basicPay)     {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }
    public void generatePaySlip()   {
        double da = 0.97 * basicPay;
        double hra = 0.10 * basicPay;
        double pf = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;
        double grossSalary = basicPay + da + hra;
        double netSalary = grossSalary - (pf + staffClubFund);
        System.out.println("\n=== Programmer Pay Slip ===");
        displayDetails();
        System.out.printf("Basic Pay: %.2f\n", basicPay);
        System.out.printf("DA: %.2f\n", da);
        System.out.printf("HRA: %.2f\n", hra);
        System.out.printf("PF: %.2f\n", pf);
        System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
        System.out.printf("Gross Salary: %.2f\n", grossSalary);
        System.out.printf("Net Salary: %.2f\n", netSalary);
    }
}

class TeamLead extends Employee    {
    private double basicPay;
    public TeamLead(String empName, String empId, String address, String mailId, String mobileNo, double basicPay)   {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }
    public void generatePaySlip()   {
        double da = 0.97 * basicPay;
        double hra = 0.10 * basicPay;
        double pf = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;
        double grossSalary = basicPay + da + hra;
        double netSalary = grossSalary - (pf + staffClubFund);

        System.out.println("\n=== Team Lead Pay Slip ===");
        displayDetails();
        System.out.printf("Basic Pay: %.2f\n", basicPay);
        System.out.printf("DA: %.2f\n", da);
        System.out.printf("HRA: %.2f\n", hra);
        System.out.printf("PF: %.2f\n", pf);
        System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
        System.out.printf("Gross Salary: %.2f\n", grossSalary);
        System.out.printf("Net Salary: %.2f\n", netSalary);
    }
}

class AssistantProjectManager extends Employee {
    private double basicPay;
    public AssistantProjectManager(String empName, String empId, String address, String mailId, String mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }
    public void generatePaySlip() {
        double da = 0.97 * basicPay;
        double hra = 0.10 * basicPay;
        double pf = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;
        double grossSalary = basicPay + da + hra;
        double netSalary = grossSalary - (pf + staffClubFund);
        System.out.println("\n=== Assistant Project Manager Pay Slip ===");
        displayDetails();
        System.out.printf("Basic Pay: %.2f\n", basicPay);
        System.out.printf("DA: %.2f\n", da);
        System.out.printf("HRA: %.2f\n", hra);
        System.out.printf("PF: %.2f\n", pf);
        System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
        System.out.printf("Gross Salary: %.2f\n", grossSalary);
        System.out.printf("Net Salary: %.2f\n", netSalary);
    }
}

class ProjectManager extends Employee   {
    private double basicPay;
    public ProjectManager(String empName, String empId, String address, String mailId, String mobileNo, double basicPay)   {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }
    public void generatePaySlip()   {
        double da = 0.97 * basicPay;
        double hra = 0.10 * basicPay;
        double pf = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;

        double grossSalary = basicPay + da + hra;
        double netSalary = grossSalary - (pf + staffClubFund);
        System.out.println("\n=== Project Manager Pay Slip ===");
        displayDetails();
        System.out.printf("Basic Pay: %.2f\n", basicPay);
        System.out.printf("DA: %.2f\n", da);
        System.out.printf("HRA: %.2f\n", hra);
        System.out.printf("PF: %.2f\n", pf);
        System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
        System.out.printf("Gross Salary: %.2f\n", grossSalary);
        System.out.printf("Net Salary: %.2f\n", netSalary);
    }
}

public class CompanyPaySlip   {
    public static void main(String[] args)  {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter details for Programmer:");
        System.out.print("Name: ");
        String programmerName = scanner.nextLine();
        System.out.print("Employee ID: ");
        String programmerId = scanner.nextLine();
        System.out.print("Address: ");
        String programmerAddress = scanner.nextLine();
        System.out.print("Email ID: ");
        String programmerEmail = scanner.nextLine();
        System.out.print("Mobile No: ");
        String programmerMobile = scanner.nextLine();
        System.out.print("Basic Pay: ");
        double programmerBP = scanner.nextDouble();
        scanner.nextLine(); 

        Programmer programmer = new Programmer(programmerName, programmerId, programmerAddress, programmerEmail, programmerMobile, programmerBP);
        programmer.generatePaySlip();

        
        System.out.println("Enter details for Team Lead:");
        System.out.print("Name: ");
        String teamLeadName = scanner.nextLine();
        System.out.print("Employee ID: ");
        String teamLeadId = scanner.nextLine();
        System.out.print("Address: ");
        String teamLeadAddress = scanner.nextLine();
        System.out.print("Email ID: ");
        String teamLeadEmail = scanner.nextLine();
        System.out.print("Mobile No: ");
        String teamLeadMobile = scanner.nextLine();
        System.out.print("Basic Pay: ");
        double teamLeadBP = scanner.nextDouble();
        scanner.nextLine(); 

        TeamLead teamLead = new TeamLead(teamLeadName, teamLeadId, teamLeadAddress, teamLeadEmail, teamLeadMobile, teamLeadBP);
        teamLead.generatePaySlip();

        
        System.out.println("Enter details for Assistant Project Manager:");
        System.out.print("Name: ");
        String apmName = scanner.nextLine();
        System.out.print("Employee ID: ");
        String apmId = scanner.nextLine();
        System.out.print("Address: ");
        String apmAddress = scanner.nextLine();
        System.out.print("Email ID: ");
        String apmEmail = scanner.nextLine();
        System.out.print("Mobile No: ");
        String apmMobile = scanner.nextLine();
        System.out.print("Basic Pay: ");
        double apmBP = scanner.nextDouble();
        scanner.nextLine(); 
        AssistantProjectManager apm = new AssistantProjectManager(apmName, apmId, apmAddress, apmEmail, apmMobile, apmBP);
        apm.generatePaySlip();

        
        System.out.println("Enter details for Project Manager:");
        System.out.print("Name: ");
        String pmName = scanner.nextLine();
        System.out.print("Employee ID: ");
        String pmId = scanner.nextLine();
        System.out.print("Address: ");
        String pmAddress = scanner.nextLine();
        System.out.print("Email ID: ");
        String pmEmail = scanner.nextLine();
        System.out.print("Mobile No: ");
        String pmMobile = scanner.nextLine();
        System.out.print("Basic Pay: ");
        double pmBP = scanner.nextDouble();
        scanner.nextLine(); 
        ProjectManager pm = new ProjectManager(pmName, pmId, pmAddress, pmEmail, pmMobile, pmBP);
        pm.generatePaySlip();
        scanner.close();
    }
}
