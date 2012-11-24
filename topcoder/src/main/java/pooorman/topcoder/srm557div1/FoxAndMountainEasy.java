package pooorman.topcoder.srm557div1;

public class FoxAndMountainEasy {

    public String possible(int n, int h0, int hn, String history) {
        int gUp = 0, gDown = 0;
        if (h0 > hn) {
            gDown = h0 - hn;
        } else {
            gUp = hn - h0;
        }
        n = n - Math.abs(h0 - hn);
        if (n % 2 == 1) {
            return "NO";
        }
        gUp += n / 2;
        gDown += n / 2;
        int h = Math.min(h0, hn);
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < history.length(); i++) {
            char ch = history.charAt(i);
            if (ch == 'U') {
                gUp--;
                h++;
            }
            if (ch == 'D') {
                gDown--;
                h--;
            }
            if (h < min) {
                min = h;
            }
        }

        if (gUp >= 0 && gDown >= 0 && gUp + min >= 0) {
            return "YES";
        }
        return "NO";
    }

    public static void main(String[] args) {
        FoxAndMountainEasy fox = new FoxAndMountainEasy();
        String temp;
        temp = fox.possible(4, 0, 4, "UU");
        System.out.println(temp);
        // assertTrue(temp.equals("YES"));
        temp = fox.possible(4, 0, 4, "D");
        System.out.println(temp);
        // assertTrue(temp.equals("NO"));
        temp = fox.possible(4, 100000, 100000, "DDU");
        System.out.println(temp);
        // assertTrue(temp.equals("YES"));
        temp = fox.possible(4, 0, 0, "DDU");
        System.out.println(temp);
        // assertTrue(temp.equals("NO"));
        temp = fox.possible(20, 20, 20, "UDUDUDUDUD");
        System.out.println(temp);
        // assertTrue(temp.equals("YES"));
        temp = fox.possible(20, 0, 0, "UUUUUUUUUU");
        System.out.println(temp);
        // assertTrue(temp.equals("YES"));
        temp = fox.possible(20, 0, 0, "UUUUUUUUUUU");
        System.out.println(temp);
        // assertTrue(temp.equals("NO"));

    }
}
