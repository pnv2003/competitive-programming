package CP.codetour;

import java.math.BigInteger;
import java.util.Scanner;

public class PS1757 {
    public static BigInteger phi(BigInteger n)
    {
        BigInteger result = n;
        BigInteger p = BigInteger.valueOf(2);
        while (p.multiply(p).compareTo(n) <= 0)
        {
            if (n.mod(p) == BigInteger.ZERO)
            {
                while (n.mod(p) == BigInteger.ZERO)
                    n = n.divide(p);

                result = result.subtract(result.divide(p));
            }

            p = p.add(BigInteger.ONE);
        }
        if (n.compareTo(BigInteger.ONE) > 0)
            result = result.subtract(result.divide(n));
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Integer n = scanner.nextInt();

        BigInteger val = BigInteger.ONE;
        for (Integer i = 0; i < n; ++i)
        {
            Integer v = scanner.nextInt();
            val = val.multiply(BigInteger.valueOf(v));
        }

        BigInteger ans = phi(val);
        ans = ans.mod(BigInteger.valueOf(1000000007));
        System.out.println(ans);

        scanner.close();
    }
}
