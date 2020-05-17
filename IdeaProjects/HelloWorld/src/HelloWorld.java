import java.time.Instant;
import java.util.ArrayList;

public class HelloWorld {

    public static ArrayList<Integer> getFactor(int num) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                result.add(i);
            }
        }
        return result;
    }

    public static void breakDown(int num, ArrayList<Integer> result, ArrayList<Integer> factor) {
        if (num == 1){
            System.out.println(result);
            return;
        }
        if (num < 1) {
            return;
        }
        for (int iter:factor) {
           if (iter == 1 && result.contains(1)) {
               continue;
           }
           ArrayList<Integer> newResult = (ArrayList<Integer> )(result.clone());
           newResult.add(iter);
           breakDown(num/iter,newResult,factor);
        }
    }
/*
    public static void main(String[] args) {
        breakDown(8, new ArrayList<>(), getFactor(8));
    }

 */


}
