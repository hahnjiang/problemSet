import java.util.*;

/**
 * Created by jianghan on 2017/2/20.
 */
public class M {

    int[] solve(int[] data, int goal) {
        Set<Integer> set = new HashSet<>(data.length);
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < data.length; i++) {
            set.add(data[i]);
            list.add(data[i]);
        }
        Collections.sort(list);
        for (int a = 0; a < list.size(); a++) {
            int x = goal - list.get(a);
            if (x / 2 < list.get(a)) {
                break;
            }
            for (int b = a + 1; b < list.size(); b++) {
                int c = x - list.get(b);
                if (list.get(b) < c && set.contains(c)) {
                    return new int[]{list.get(a), list.get(b), c};
                }
            }
        }
        return new int[3];
    }

    public static void main(String[] args) {

    }

}
