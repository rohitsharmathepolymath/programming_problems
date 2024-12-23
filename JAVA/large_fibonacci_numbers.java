import java.math.BigInteger;
import java.util.*;

public class large_fibonacci_numbers {
	public static void main(String[] args) {
		BigInteger a= new BigInteger("1");
		BigInteger b= new BigInteger("1");
		BigInteger c=new BigInteger("0");
		Scanner s= new Scanner(System.in);
		System.out.println("Enter a number:");
        int n= s.nextInt();

		long startTime = System.nanoTime();
		for(int i=0;i<n-2;i++) {
			c=a.add(b);
			a=b;
			b=c;
		}
		long endTime = System.nanoTime();
		long duration = endTime - startTime;
		System.out.println("Execution time: " +(duration/1000000) + " milliseconds");
		//System.out.println(c);
		System.out.println(c.toString().length());
		s.close();
	}
}
