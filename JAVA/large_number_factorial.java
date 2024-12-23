import java.math.BigInteger;
import java.util.Scanner;
public class large_number_factorial {
    public static void main(String[] args) {
        BigInteger f = new BigInteger("1");
        int n;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number:");
        n = s.nextInt();
        if(n==1){
            System.out.println(n);
        }
        long start = System.nanoTime();
        for(int i=1;i<=n;i++){
            f=f.multiply(new BigInteger(Integer.toString(i)));
        }
        long stop = System.nanoTime();
        long duration = (stop-start)/1000000;
        System.out.println(f);
        System.out.println("Execution Time: "+duration+" milliseconds");
        s.close();
    }
}
