import java.util.*;

public class Solution {
    public static void main(String[] args) {
        var a = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
        var iterator = a.listIterator();
        while (iterator.hasNext()) {
            var i = iterator.nextIndex();
            var x = iterator.next();
            x += i;
            iterator.set(x);
        }
        a.forEach(System.out::println);
    }
}