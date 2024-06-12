package CP.codetour;

import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Scanner;

public class PS1723 {
    public static String s;
    public static BigInteger b, sum;
    public static LinkedList<Character> t;

    public static void backtrack(Integer idx)
    {
        if (idx == s.length())
        {
            BigInteger num = BigInteger.ZERO;
            for (Character character : t) {
                num = num.multiply(BigInteger.valueOf(10));
                Integer val = character - '0';
                num = num.add(BigInteger.valueOf(val));
            }
            if (num.compareTo(b) != 1)
                sum = sum.add(num);
            return;
        }

        t.addFirst(s.charAt(idx));
        backtrack(idx + 1);
        t.removeFirst();

        t.addLast(s.charAt(idx));
        backtrack(idx + 1);
        t.removeLast();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Integer q = Integer.parseInt(scanner.nextLine());
        t = new LinkedList<Character>();

        for (Integer i = 0; i < q; ++i)
        {
            sum = BigInteger.ZERO;
            t.clear();

            s = scanner.nextLine();
            b = scanner.nextBigInteger();

            t.addLast(s.charAt(0));
            backtrack(1);

            BigInteger ans = sum.mod(BigInteger.valueOf(1000000007));
            System.out.println(ans);
        }
        scanner.close();
    }
}
