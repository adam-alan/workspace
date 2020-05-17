import java.util.Arrays;
import java.util.Random;

public class Main{
    public static void main(String[] args) {
        int [] array1 = new int[24];
        int [][] array2 = new int[3][8];
        Random random = new Random(2);
        for (int i = 0; i < array1.length; i++) {
            array1[i] = random.nextInt(10);
        }


        System.out.println(Arrays.toString(array1));
        for (int[] iter:array2) {
            System.out.println(Arrays.toString(iter));
        }

    }

}
