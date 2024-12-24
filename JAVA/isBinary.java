import java.util.Scanner;
public class isBinary {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int[] a = new int[100];
        int n;
        boolean flag;
        flag = true;
        System.err.println("Enter the length of the Binary Number:");
        n= s.nextInt();
        System.out.println("Enter the binary number by giving spave between each:");
        for(int i =  0; i<n;i++){
            a[i]=s.nextInt();
            if(a[i]>1 || a[i]<0){
                flag= false;
            }
        }
        if(flag){
            System.out.println("The entered value is binary.");
        }else{
            System.out.println("Its not a binary number.");
        }
        s.close();
    }
}
