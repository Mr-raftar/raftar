import java.util.*;  
interface vehicle{ 
 	void gear_change(int gear_no);  	
    void speed_up(int speedx);  	
    void apply_brakes(int c); 
    } 

class bicycle implements vehicle{ 
 	int gear=0, speed=0; 
 	Scanner sc=new Scanner(System.in); 
 
 	public void gear_change(int gear_no){ 
 	 	if(gear_no>0 && gear_no<=7){ 
 	 	 	gear=gear_no; 
 	 	 	System.out.println("Gear Change Successfully to "+gear_no); 
 	 	} 
 	 	else       System.out.println("Gear is not in range"); 
} 
public void speed_up(int speedx){  	if((speed+speedx)>1 && (speed+speedx)<20){ 
	 	 	speed=speed+speedx; 
	 	System.out.println("Speed is changed to "+speedx); 
}
else 
	 	System.out.println("Speed is minimum"); 
} public void apply_brakes(int c){ 
 	    if(c==1){ 
 	 	gear=0;  	 	speed=0; 
 	 	System.out.println("Bicycle is stopped"); 
 	    } 
 	    else  
 	       System.out.println("\n"); 
 	 	} 
} 	 
 
 
class bike implements vehicle{ 
 	int gear=0, speed=0; 
 	Scanner sc=new Scanner(System.in); 
 
 	public void gear_change(int gear_no){ 
 	 	if(gear_no>0 && gear_no<=4){ 
 	 	 	gear=gear_no; 
 	 	 	System.out.println("Gear Change Successfully to "+gear_no); 
 	 	} 
 	 	else 
	 	 	System.out.println("Gear is not in range"); 
} 
public void speed_up(int speedx){ 
 	if((speed+speedx)>20 && (speed+speedx)<100){  	speed=speed+speedx; System.out.println("Speed is changed to "+speedx); 
} 
else 
	 	System.out.println("Speed is minimum"); 
}
 	public void apply_brakes(int c){  	    if(c==1){ 
 	 	gear=0;  	 	speed=0; 
 	 	System.out.println("Bike is stopped"); 
 	    }  	    else  
 	       System.out.println("\n"); 
 	 	} 
} 	 
 
 
class car implements vehicle{ 
 	int gear=0, speed=0; 
 	Scanner sc=new Scanner(System.in); 
 
 	public void gear_change(int gear_no){ 
 	 	if(gear_no>0 && gear_no<=5){ 
 	 	 	gear=gear_no; 
 	 	 	System.out.println("Gear Change Successfully to "+gear_no); 
 	 	} 
	 	else 
	 	 	System.out.println("Gear is not in range"); 
} 
public void speed_up(int speedx){ if((speed+speedx)>1 && (speed+speedx)<150){ speed=speed+speedx; 
	 	System.out.println("Speed is change to "+speedx); 
} 
else 
	 	System.out.println("Speed is minimum"); 
 	} 
 	 	public void apply_brakes(int c){  	    if(c==1){ 
 	 	gear=0;  	 	speed=0; 
 	 	System.out.println("Car is stopped"); 
 	    } 
 	    else  
 	       System.out.println("\n"); 
 	 	} 
} 	 
 
public class inheritance {  	
    public static void main(String [] args){ 
 	 	Scanner sc=new Scanner(System.in);  	 	
        int gear, speed, ch, c; 
 	 	do{ 
 	 	    System.out.print("Enter your choice \n1.Bicycle 2.Bike 3.Car 4.Exit\n choice: "); 
 	 	ch=sc.nextInt(); 
 	 	switch(ch){  	 	    case 1:{ 
	 	bicycle b=new bicycle(); 
 	System.out.println("Enter the gear to change");  
    	gear=sc.nextInt(); 
	 	b.gear_change(gear); 
System.out.println("Enter the speed to be change"); 
speed=sc.nextInt(); 
b.speed_up(speed); 
System.out.println("Do you want to stop the vehicle:\n 1.Yes 2.No"); 
c=sc.nextInt(); 
b.apply_brakes(c); 
 	 	break;  	 	    }  	 	case 2:{ 
 	 	   bike b=new bike(); 
 	 	System.out.println("Enter the gear to change"); 
 	 	gear=sc.nextInt(); 
 	 	b.gear_change(gear); 
 	 	System.out.println("Enter the speed to be change"); 
 	 	speed=sc.nextInt(); 
 	 	b.speed_up(speed); 
 	 	System.out.println("Do you want to stop the vehicle:\n 1.Yes 2.No"); 
 	 	c=sc.nextInt(); 
 	 	b.apply_brakes(c); 
 	 	break; 
 	 	} 
 	 	case 3:{ 
 	 	   car b=new car(); 
 	 	System.out.println("Enter the gear to change"); 
 	 	gear=sc.nextInt(); 
 	 	b.gear_change(gear); 
 	 	System.out.println("Enter the speed to be change");  	speed=sc.nextInt(); 
	 	b.speed_up(speed); 
	 	System.out.println("Do you want to stop the vehicle:\n 1.Yes 2.No"); 
	 	c=sc.nextInt(); 
b.apply_brakes(c); 
break; 
 
 	 	} 
 	 	} 
 	 	}while(ch!=4); 
    } 
}
 	 	 
