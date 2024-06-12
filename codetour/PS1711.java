package CP.codetour;

import java.math.BigInteger;
import java.util.Scanner;

public class PS1711 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger n = scanner.nextBigInteger();
        
        BigInteger sum = n.multiply(n).
                           multiply(n).
                           add(n).
                           divide(BigInteger.valueOf(2)).
                           mod(BigInteger.valueOf(2027));
        System.out.println(sum);
        scanner.close();
    }
}
