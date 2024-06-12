package CP.codetour;

import java.math.BigInteger;
import java.util.Scanner;

public class CT1836 {
    public static BigInteger fact(BigInteger n)
    {
        BigInteger res = BigInteger.ONE, i;
        for (i = BigInteger.TWO; i.compareTo(n) <= 0; i = i.add(BigInteger.ONE))
            res = res.multiply(i);
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Integer t = scanner.nextInt();
        BigInteger p = scanner.nextBigInteger();

        for (Integer i = 0; i < t; ++i)
        {
            BigInteger n = scanner.nextBigInteger();

            BigInteger num = fact(n.multiply(BigInteger.TWO));
            BigInteger den = fact(n);
            den = den.multiply(den);
            den = den.multiply(BigInteger.TWO);
            
            BigInteger ans = num.divide(den).mod(p);
            System.out.println(ans);
        }

        scanner.close();

    }
}
