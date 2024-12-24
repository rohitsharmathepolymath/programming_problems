import java.util.Scanner;
public class sum_of_n_natural_number {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter a Number:");
        int n;
        long sum = 0;
        n = s.nextInt();
        long start,stop,duration;
        start = System.nanoTime();
        for ( int i = 1; i <= n; i++){
            sum = sum + i;
        }
        stop = System.nanoTime();
        duration = (stop-start)/1000000;
        System.out.println("Sum of "+n+" natural number is:"+sum);
        System.out.println("Execution time:"+duration+" Milliseconds");
        s.close();
    }
}
