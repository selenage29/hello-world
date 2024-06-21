//2024 December USACO silver 2, full credit

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Match {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int k = Integer.parseInt(tokenizer.nextToken());
        tokenizer = new StringTokenizer(in.readLine());
        Map<Integer, Integer> aMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < k; i++) {
            int aval = Integer.parseInt(tokenizer.nextToken());
            aMap.put(aval, i);
        }
        List<Integer> b = new ArrayList<Integer>();
        tokenizer = new StringTokenizer(in.readLine());
        for (int i = 0; i < k; i++) {
            int bval = Integer.parseInt(tokenizer.nextToken());
            b.add(bval);
        }
        int[] c = new int[k];
        int lessFreeCnt = 0;
        int maxCvalue = 0;
        for (int i = 0; i < k; i++) {
            int bval = b.get(i);
            if (aMap.containsKey(bval)) {
                int aMapVal = aMap.get(bval);
                int shift = (aMapVal+k-i)%k;
                int cnewval = c[shift] + 1;
                c[shift] = cnewval;
                if (cnewval > maxCvalue) {
                    maxCvalue = cnewval;
                }
            } else {
                lessFreeCnt++;
            }
        }
        Collections.reverse(b);
        int[] d = new int[k];
        int maxDvalue = 0;
        for (int i = 0; i < k; i++) {
            int bval = b.get(i);
            if (aMap.containsKey(bval)) {
                int aMapVal = aMap.get(bval);
                int shift = (aMapVal+k-i)%k;
                int dnewval = d[shift] + 1;
                d[shift] = dnewval;
                if (dnewval > maxDvalue) {
                    maxDvalue = dnewval;
                }
            }
        }
        int maxvalue = Math.max(maxDvalue, maxCvalue);
        System.out.println(n - k - lessFreeCnt + maxvalue);
    }
}