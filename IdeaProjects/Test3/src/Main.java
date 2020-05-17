import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        questions2();

    }
    public static boolean isPrimeNumber(int number) {

        for (int i = 2;i <= (int)Math.sqrt(number);i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void questions1() {
        for (int i = 2;i < 100;i++) {
            if (isPrimeNumber(i)) {
                System.out.println(i);
            }
        }
    }

    public static void questions2() {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int numBitsNumber = (int)Math.log10(num) + 1;

        int newNum = 0;
        while (num != 0) {
            newNum += (int) Math.pow(10,numBitsNumber - 1) * (num % 10);

            num /= 10;
            numBitsNumber -= 1;
        }
        System.out.println(newNum);
    }

    public static void questions3() {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Double> personWeightTable = new ArrayList<>();
        while (scanner.hasNext()) {
            double personWeight = scanner.nextDouble();
            if (personWeight < 0) {
                break;
            }

        }

    }
}
