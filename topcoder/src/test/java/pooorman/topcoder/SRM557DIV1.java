package pooorman.topcoder;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

import pooorman.topcoder.srm557div1.FoxAndMountainEasy;

public class SRM557DIV1 {

    public FoxAndMountainEasy fox = new FoxAndMountainEasy();

    @Test
    public void foxAndMountainEasyTest() {
        String temp;
        temp = fox.possible(4, 0, 4, "UU");
        assertTrue(temp.equals("YES"));
        temp = fox.possible(4, 0, 4, "D");
        assertTrue(temp.equals("NO"));
        temp = fox.possible(4, 100000, 100000, "DDU");
        assertTrue(temp.equals("YES"));
        temp = fox.possible(4, 0, 0, "DDU");
        assertTrue(temp.equals("NO"));
        temp = fox.possible(20, 20, 20, "UDUDUDUDUD");
        assertTrue(temp.equals("YES"));
        temp = fox.possible(20, 0, 0, "UUUUUUUUUU");
        assertTrue(temp.equals("YES"));
        temp = fox.possible(20, 0, 0, "UUUUUUUUUUU");
        assertTrue(temp.equals("NO"));
    }
}
