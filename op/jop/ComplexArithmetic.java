import java.util.Scanner;
class Complex 
  {
    private double real;
    private double imag;

    public Complex() 
   {
        this.real = 0;
        this.imag = 0;
    }
    public Complex(double r, double i)
     {
        this.real = r;
        this.imag = i;
    }
    
    public void display() 
     {
        if (imag >= 0)
         {
            System.out.println(real + " + " + imag + "i");
        } else 
          {
            System.out.println(real + " - " + -imag + "i");
        }
    }
    public Complex add(Complex c)
     {
        return new Complex(this.real + c.real, this.imag + c.imag);
    }
    public Complex subtract(Complex c) 
    {
        return new Complex(this.real - c.real, this.imag - c.imag);
    }
    public Complex multiply(Complex c) 
       {
        return new Complex(this.real * c.real - this.imag * c.imag,
                           this.real * c.imag + this.imag * c.real);
    }
    public Complex divide(Complex c)   
      {
        double denominator = c.real * c.real + c.imag * c.imag;
        if (denominator == 0)
           {
            throw new ArithmeticException("Division by zero error!");
        }
        return new Complex((this.real * c.real + this.imag * c.imag) / denominator,
                           (this.imag * c.real - this.real * c.imag) / denominator);
    }
}
public class ComplexArithmetic 
  {
    public static void main(String[] args) 
      {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the real and imaginary parts of the first complex number: ");
        double r1 = scanner.nextDouble();
        double i1 = scanner.nextDouble();

        
        System.out.print("Enter the real and imaginary parts of the second complex number: ");
        double r2 = scanner.nextDouble();
        double i2 = scanner.nextDouble();

       
        Complex c1 = new Complex(r1, i1);
        Complex c2 = new Complex(r2, i2);
        
        Complex sum = c1.add(c2);
        Complex difference = c1.subtract(c2);
        Complex product = c1.multiply(c2);
        Complex quotient;
        try {
            quotient = c1.divide(c2);
            System.out.print("Quotient: ");
            quotient.display();
        } 
          catch (ArithmeticException e)
          {
            System.out.println(e.getMessage());
        }
        System.out.print("Sum: ");        
        sum.display();
        System.out.print("Difference: ");
        difference.display();
        System.out.print("Product: ");
        product.display();
        scanner.close();
    }
}

