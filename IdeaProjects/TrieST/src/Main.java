import java.util.Iterator;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        TrieST<Integer> trieST = new TrieST<>();
        trieST.put("11111",50000);
        Iterable<String> iterable = trieST.keysThatMatch("11...");
        Iterator<String> iterator = iterable.iterator();
        while (iterator.hasNext()){
            System.out.println(iterator.next());
        }
    }

}
