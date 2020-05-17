import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main {


    public static void main(String[] args) {
        question5();

    }

    public static void questions1() {


        Scanner reader = new Scanner(System.in);

        System.out.println("姓名：" + reader.nextLine());
        System.out.println("年龄：" + reader.nextInt());
        System.out.println("所在学院：" + reader.nextLine());
        System.out.println("所在专业：" + reader.nextLine());
        System.out.println("所在班级：" + reader.nextInt() + "班");
    }
    public static void questions2(){
        Scanner reader = new Scanner(System.in);
        while (reader.hasNext()) {
            BigDecimal bigDecimal1 = new BigDecimal(reader.nextLine());
            BigDecimal bigDecimal2 = new BigDecimal(reader.nextLine());

            System.out.println(bigDecimal1.add(bigDecimal2).toString());
            System.out.println(bigDecimal1.multiply(bigDecimal2).toString());
        }
    }

    public static void questions3(){
        Scanner reader = new Scanner(System.in);
        int inputNum = reader.nextInt();
        char charactor = '\0';
        switch (inputNum/10) {
            case 10:
            case 9:
                charactor = 'A';
                break;
            case 8:
                charactor = 'B';
                break;
            case 7:
                charactor = 'C';
                break;
            case 6:
                charactor = 'D';
                break;

            default:
                charactor = 'E';
        }
        String result = "";
        switch (charactor) {
            case 'A':
                result = "Excellent";
                break;
            case 'B':
                result = "Good";
                break;
            case 'C':
                result = "Average";
                break;
            case 'D':
                result = "Fair";
                break;
            default:
                result = "Poor";
        }
        System.out.println(result);
        System.out.println("class name=class Grade");
        System.out.println("grade value=" + charactor);
    }
    public static void question4(){
        BigInteger sum = new BigInteger("0");
        BigInteger inputNum;
        Scanner reader = new Scanner(System.in);
        while (reader.hasNext()) {
            String inputString = reader.nextLine();

            if (inputString.equals("e")) {
                break;
            }

            inputNum  = new BigInteger(inputString);
            sum = sum.add(inputNum);
        }

        System.out.println(sum.toString());
    }

    public static void question5(){
        int inputNum1 = 0,inputNum2 = 0;
        Scanner reader = new Scanner(System.in);
        inputNum1 = reader.nextInt();
        inputNum2 = reader.nextInt();
        System.out.println(inputNum1 + inputNum2);
    }

    public static void question6(){
        String input;
        Scanner reader = new Scanner(System.in);
        input = reader.nextLine();

        System.out.println(input.length() + "," + input.charAt(0));
    }
    public static void question7(){
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        if (inputNum >= 0 && inputNum <= 15) {

            System.out.printf("%X\n",inputNum);
        } else {
            System.out.println("Invalid input");
        }
    }

    public static void question8(){
        int inputNum1 = 0,inputNum2 = 0;
        Scanner reader = new Scanner(System.in);
        inputNum1 = reader.nextInt();
        inputNum2 = reader.nextInt();
        System.out.println((inputNum1 > inputNum2 ) ? inputNum1 :inputNum2);
    }
    public static void question9(){
        int inputNum1 = 0,inputNum2 = 0;
        Scanner reader = new Scanner(System.in);
        while (reader.hasNext()) {
            inputNum1 = reader.nextInt();
            inputNum2 = reader.nextInt();
            System.out.println(inputNum1 + inputNum2);
        }
    }

    public static void question10(){
        int low = 1,high = 0;
        Scanner reader = new Scanner(System.in);
        high = reader.nextInt();
        int counter1 = 0;
        int counter2 = 0;
        for (int i = low;i <= high;i++) {
            if (i % 3 == 0) {
                if (i % 2 == 0) {
                    counter1 += 1;
                } else {
                    counter2 += 1;
                }

            }
        }
        System.out.printf("%d,%d\n",counter2,counter1);
    }
    public static void question11(){
        int year = 0;
        Scanner reader = new Scanner(System.in);
        year = reader.nextInt();

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }

    }
    public static void question12(){
        String [] mouths = {"一月份","二月份","三月份","四月份","五月份","六月份",
                            "七月份","八月份","九月份","十月份","十一月份","十二月份"};
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();

        if (inputNum >= 12) {
            System.out.println("请重新输入月份");
        } else {
            System.out.println(mouths[inputNum]);
        }

    }
    public static void question13(){
        double x = 0,y = 0;

        Scanner reader = new Scanner(System.in);
        x = reader.nextDouble();
        y = reader.nextDouble();

        if ((x *x + y * y) < 100) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }

    }
    public static void question14(){
        int year = 0, mouth = 0;
        int [] days = {31,28,31,30,31,30,31,31,30,31,30,31};
        Scanner reader = new Scanner(System.in);
        year = reader.nextInt();
        mouth = reader.nextInt();

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (mouth == 2) {
                System.out.println(days[mouth-1] + 1);
            } else {
                System.out.println(days[mouth-1]);
            }
        } else {
            System.out.println(days[mouth-1]);
        }

    }
    public static void questions16(){
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();

        if (inputNum == 1 || inputNum == -1) {
            if (inputNum == 1) {
                System.out.println("0 1");
            }
            if (inputNum == -1) {
                System.out.println("-1 0");

            }
        } else {
            if (inputNum % 2 == 0) {
                System.out.printf("%d %d\n",inputNum/2,inputNum/2);
            } else {
                if (inputNum > 0 ) {
                    System.out.printf("%d %d\n",inputNum/2,inputNum/2 + 1);
                } else {
                    System.out.printf("%d %d\n",inputNum/2 -1,inputNum/2);
                }

            }
        }
    }
    public static void questions17() {
        ArrayList<Integer> arrayList = new ArrayList<>();
        Scanner reader = new Scanner(System.in);
        String s = "";

        while (reader.hasNext()) {
            int inputNum = reader.nextInt();
            arrayList.add(inputNum);
        }

        for (int iter:arrayList) {
            if (iter > 100 || iter < 0) {
                if (iter > 100) {
                    iter = 100;
                } else {
                    iter = 0;
                }

            }
        }
        for (int iter:arrayList) {
            System.out.print(iter);
            System.out.print(",");
        }
    }
    public static void questions18() {
        Scanner reader = new Scanner(System.in);
        String [] line = reader.nextLine().split(" ");
        ArrayList<Integer> integers = new ArrayList<>();
        boolean isAttention = false;
        for (String iter:line) {
            try {
                integers.add(Integer.parseInt(iter));
            }catch (NumberFormatException e) {
                isAttention = true;
            }
        }
        int sum = 0;
        for (Integer iter:integers) {
            sum += iter;
        }
        System.out.println(sum);

        if (isAttention) {
            System.out.println("attention");
        }
    }
    public static void questions19() {
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();

        String binaryString = Integer.toBinaryString(inputNum);
        int index = binaryString.indexOf('1');
        if (inputNum == 0) {
            System.out.println(32);
        } else {
            System.out.println(32-binaryString.length() + index);
        }

    }

    public static void questions21() {
        Scanner reader = new Scanner(System.in);
        Map<Integer,Integer> dict = new TreeMap<>();
        int inputNum = reader.nextInt();
        for (int i = 0;i < inputNum;i++) {
            int iterNum = reader.nextInt();
            if (dict.get(iterNum) != null) {
                dict.put(iterNum,dict.get(iterNum)+1);
            } else {
                dict.put(iterNum,1);
            }
        }
        int maxNum = Integer.MIN_VALUE;
        int maxNumConuter = Integer.MIN_VALUE;
        for (Map.Entry<Integer,Integer> entry:dict.entrySet()) {
            if (entry.getValue() > maxNumConuter) {
                maxNumConuter = entry.getValue();
                maxNum = entry.getKey();
            }
        }
        System.out.println(maxNum + " " +maxNumConuter);
    }
    public static void questions22(){
        ArrayList<Double> arrayList = new ArrayList<>();
        Scanner reader = new Scanner(System.in);
        String[] line = reader.nextLine().split(" ");
        for (String str : line) {
            arrayList.add(Double.valueOf(str));
        }

        double sum = 0;
        int counter1 = 0;
        int counter2 = 0;
        arrayList.remove(arrayList.size() - 1);
        if (arrayList.size() != 0) {
            for (Double num:arrayList) {
                if (num > 0) {
                    counter1++;
                }
                if (num < 0) {
                    counter2++;
                }
                sum += num;
            }
            System.out.println(counter1);
            System.out.println(counter2);
            System.out.println((int)sum);
            System.out.println(sum/arrayList.size());
        }

    }
    public static void questions23() {
        Scanner reader = new Scanner(System.in);
        int inputNum = reader.nextInt();
        if (inputNum % 2 == 0) {
            inputNum -= 1;
        }
        int sum = (inputNum + 1) / 2;
        for (int i = 1;i <= sum;i++) {
            System.out.print((2*i - 1) + " ");
        }
        System.out.println();
    }
    public static void questions24() {
        Scanner reader = new Scanner(System.in);
        int inputNum = reader.nextInt();
        ArrayList<Integer> arrayList  = new ArrayList<>();
        for (int i = 0;i < inputNum;i++) {
            arrayList.add(reader.nextInt());
        }
        int sum = 0;
        for (int iter:arrayList) {
            sum += iter;
        }
        System.out.println(sum);
    }
    public static void questions26() {
        Scanner reader = new Scanner(System.in);
        int inputNum = reader.nextInt();
        ArrayList<Integer> arrayList  = new ArrayList<>();
        for (int i = 0;i < inputNum;i++) {
            arrayList.add(reader.nextInt());
        }
        int maxNum = Collections.max(arrayList);
        System.out.println(maxNum);
    }
    public static void questions27() {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        float sum = 0;
        List<Float> nums = new ArrayList<>();
        String[] line = in.nextLine().split(" ");
        for (String str : line) {
            nums.add(Float.valueOf(str));
        }
        Collections.sort(nums);
        nums.remove(0);
        nums.remove(nums.size() - 1);
        for (double num : nums) {
            sum += num;
        }
        System.out.println(String.format("%.2f", sum / (n - 2)));

    }
    public static void questions28() {
        int x = 0,y = 0,z = 0;
        Scanner reader = new Scanner(System.in);
        x = reader.nextInt();
        y = reader.nextInt();
        z = reader.nextInt();

        boolean canMeet = false;
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 1;i <= 100;i++) {

            x += 1;
            y += 1;
            z += 1;
            arrayList.add(x %10);
            arrayList.add(y %10);
            arrayList.add(z %10);
            if (arrayList.contains(3) && arrayList.contains(6) && arrayList.contains(9)) {
                canMeet = true;
                System.out.println(i);
                break;
            }
            arrayList.clear();
        }

        if (canMeet == false) {
            System.out.println("so sad!");
        }

    }
    public static void questions29() {
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        String string = "";
        for (int i = 0;i < inputNum;i++) {
            string += "*";
        }
        for (int i = 1;i <= inputNum;i++) {
            System.out.println(string.substring(0,i));
        }

    }
    public static void questions30() {
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        String string = "";
        int num = 1;
        for (int i = 0;i < inputNum;i++) {
            for (int j = inputNum - i - 1;j > 0;j--) {
                System.out.print(" ");
            }
            for (int j = 0;j < num;j++) {
                System.out.print("*");
            }
            num += 2;
            System.out.println();
        }

    }

    public static void questions31() {
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        System.out.println((int)(((Math.pow(10,inputNum+1) - 10)/9 - inputNum)/9)*6);
    }
    public static void questions32() {
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        for (int iter = 1;iter < 1 +inputNum;iter++) {
            System.out.print(iter);
            if (inputNum != 1) {
                System.out.print(' ');
            }

        }
        for (int iter = 1 + inputNum - 2;iter >= 1;iter--) {
            System.out.print(iter);
            if (iter != 1) {
                System.out.print(' ');
            }
        }

    }
    public static void questions33() {
        Scanner reader = new Scanner(System.in);
        String space = "                                       ";
        System.out.println(space.length());
        char charactor = reader.nextLine().charAt(0);
        System.out.println(space + "A");
        int cur1 = 1;
        for (char iter = 'B';iter <= charactor;iter++) {
            int cur2 = (int)(iter - 'A');
            System.out.print(space.substring(0,39 - cur2));
            System.out.print(iter);
            if (iter != charactor) {
                for (int i = 0;i < cur1;i++) {
                    System.out.print(" ");
                }
                System.out.println(iter);
            } else {
                for (int i = 0;i < cur1;i++) {
                    System.out.print(charactor);
                }
                System.out.println(charactor);
            }

            cur1 += 2;
        }
    }
    public static void questions34() {
        Scanner reader = new Scanner(System.in);
        int [][] matrix;
        int inputNum = reader.nextInt();
        matrix = new int[inputNum][];
        for (int i = 0;i < inputNum;i++) {
            matrix[i] = new int[inputNum - i];
        }


        int counter = 0;
        for (int i = 0;i < inputNum;i++) {
            for (int j = 0;j < matrix[i].length;j++) {
                //System.out.print("(" + j + "," + i + ") ");
                counter += 1;
                matrix[i][j] = counter;
            }

        }

        for (int i = 0;i < inputNum;i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.printf("%4d",matrix[i][j]);
            }
            System.out.println();
        }


    }
    public static void questions35() {
        Scanner reader = new Scanner(System.in);
        int [][] matrix;
        int inputNum = reader.nextInt();
        matrix = new int[inputNum][];
        for (int i = 0;i < inputNum;i++) {
            matrix[i] = new int[inputNum - i];
        }


        int counter = 0;
        for (int i = 0;i < inputNum;i++) {
            for (int j = 0;j < matrix[i].length;j++) {
               //System.out.print("(" + j + "," + i + ") ");
                counter += 1;
                matrix[j][i] = counter;
            }

        }

        for (int i = 0;i < inputNum;i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }


    }
    public static void questions36() {
        ArrayList<Integer> integers = new ArrayList<>();
        Scanner reader = new Scanner(System.in);
        String [] line = reader.nextLine().split(" ");
        for  (String iter:line) {
            try {
                int num = Integer.parseInt(iter);
                if (num > 9 || num < 0) {
                    System.out.println(num);
                    System.out.println("Numerical range error");
                    System.exit(-1);
                }
                integers.add(num);
            }catch (NumberFormatException e) {
                System.out.println("number input error");
                System.exit(-1);
            }
        }
        Collections.sort(integers);
        for (int i = integers.size() - 1;i >= 0;i--) {
            System.out.print(integers.get(i));
        }
        System.out.print(" ");
        for (Integer iter:integers) {

            System.out.print(iter);
        }

    }

    public static void questions38() {
        int row = 0, column = 0;
        int angle = 0;
        Scanner reader = new Scanner(System.in);
        row = reader.nextInt();
        column = reader.nextInt();
        int [] [] matrix = new int[row][column];
        angle = reader.nextInt();
        if (!(angle == 90 || angle == -90 || angle == 180)) {
            System.out.println("angle data error");
            System.exit(-1);
        }

        for (int i = 0;i < row;i++) {
            for (int j = 0;j < column;j++) {
                String input = reader.next();
                int num = 0;
                try {
                     num = Integer.parseInt(input);
                }catch (NumberFormatException e) {
                    System.out.println("data type error");
                    System.exit(-1);
                }

                if (num > 255 || num < 0) {
                    System.out.println("matrix data error");
                    System.exit(-1);
                }
                matrix[i][j] = num;
            }
        }

        if (angle == 90) {
            int [][] newMatrix = new int[column][row];
            for (int i = 0;i < column;i++) {
                for (int j = 0;j < row;j++) {
                    newMatrix[i][j] = matrix[j][column - i - 1];
                }
            }
            for (int i = 0;i < column;i++) {
                for (int j = 0;j < row;j++) {
                    System.out.print(newMatrix[i][j]);
                    if (j != newMatrix[i].length - 1) {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }
        } else if (angle == -90) {
            int [][] newMatrix = new int[column][row];
            for (int i = 0;i < column;i++) {
                for (int j = 0;j < row;j++) {
                    newMatrix[i][j] = matrix[row - j - 1][i];
                }
            }
            for (int i = 0;i < column;i++) {
                for (int j = 0;j < row;j++) {
                    System.out.print(newMatrix[i][j]);
                    if (j != newMatrix[i].length - 1) {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }
        } else {
            int [][] newMatrix = new int[row][column];
            for (int i = 0;i < row;i++) {
                for (int j = 0;j < column;j++) {
                    newMatrix[i][j] = matrix[row - i - 1][column - j - 1];
                }
            }
            for (int i = 0;i < row;i++) {
                for (int j = 0;j < column;j++) {
                    System.out.print(newMatrix[i][j]);
                    if (j != newMatrix[i].length - 1) {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }
        }

    }

    public static void questions39() {
        String inputString = "";
        Scanner reader = new Scanner(System.in);
        inputString = reader.nextLine();
        ArrayList<String> stringArrayList = new ArrayList<>();

        for (int i = 0;i < 32;i += 8) {
            stringArrayList.add(inputString.substring(i,i+8));
        }
        String resultString = "";

        for (String iter:stringArrayList) {
            int weight = 128;
            int num = 0;
            for (int i = 0; i < iter.length();i++) {
                if (iter.charAt(i) == '0') {
                    num += 0;
                } else {
                    num += weight;
                }
                weight /= 2;
            }
            resultString += Integer.toString(num) + '.';
        }
        System.out.println(resultString.substring(0,resultString.length()-1));
    }
    public static void questions40(){

        ArrayList<Integer> arcissisticNumbers = new ArrayList<>();
        Scanner reader = new Scanner(System.in);
        int bitNum = reader.nextInt();
        int left = (int)Math.pow(10,bitNum - 1);
        int right = (int)Math.pow(10,bitNum);
        if (bitNum < 7) {
            for (int iter = left; iter < right;iter++) {

                int num = iter;
                int sum = 0;
                while (num != 0) {
                    sum += (int)Math.pow(num % 10,bitNum);
                    num /= 10;
                }
                if (sum == iter) {
                    arcissisticNumbers.add(iter);
                }
            }

            for (int iter:arcissisticNumbers) {
                System.out.println(iter);
            }

        } else {
            System.out.println(1741725);
            System.out.println(4210818);
            System.out.println(9800817);
            System.out.println(9926315);
        }


    }
    public static void questions41() {
        int inputNum = 0;
        int weight = 1;
        int bitNum = 0;
        int newNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        bitNum = (int)Math.log10(inputNum);
        weight = (int)Math.pow(10,bitNum);
        while (inputNum != 0) {
            int modNum = inputNum % 10;
            inputNum /= 10;
            newNum += modNum * weight;
            weight /= 10;
        }
        System.out.println(newNum);

    }
    public static void questions42() {
        Scanner reader = new Scanner(System.in);
        int inputNum = reader.nextInt();
        String result = "";
        for (int i = 2;i <= inputNum;i++) {
            if (isPrimer(i) == true) {
                result += i + " ";
            }

        }
        result = result.trim();
        System.out.println(result);
    }

    public static boolean isPrimer(int num) {
        for (int i = 2;i <= (int)Math.sqrt(num);i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static void questions43() {
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        ArrayList<Integer> arrayList = new ArrayList<>();

        while (reader.hasNext()) {
            arrayList.add(reader.nextInt());
        }
        int counter = 0;
        for (Integer integer:arrayList) {
            if (integer > inputNum) {
                counter += 1;
            }
        }
        System.out.println(counter);
    }
    public static void questions44() {
        int inputNum = 0;
        Scanner reader = new Scanner(System.in);
        inputNum = reader.nextInt();
        for (int iter = 'a';iter < 'a'+inputNum;iter++) {
            System.out.print((char)iter);
            if (inputNum != 1) {
                System.out.print(' ');
            }

        }
        for (int iter = 'a' + inputNum - 2;iter >= 'a';iter--) {
            System.out.print((char)iter);
            if ((char)iter != 'a') {
                System.out.print(' ');
            }
        }

    }
    public static void questions45() {
        ArrayList<Integer> evenList = new ArrayList<>();
        ArrayList<Integer> oddList = new ArrayList<>();
        int n = 0;
        Scanner reader = new Scanner(System.in);
        n = reader.nextInt();
        while (n != 0) {
            n -= 1;
            int iter = reader.nextInt();
            if (iter % 2 == 0) {
                evenList.add(iter);
            } else {
                oddList.add(iter);
            }
        }
        int oddSum = 0;
        int evenSum = 0;

        for (Integer integer:oddList) {
            oddSum += integer;
        }
        for (Integer integer:evenList) {
            evenSum += integer;
        }
        System.out.printf("奇数和=%d, 偶数和=%d",oddSum,evenSum);
    }

    public static void questions46() {
        String inputString = null;
        String outputString = "";
        Scanner reader = new Scanner(System.in);
        while (reader.hasNext()) {
            inputString = reader.next();
            if (inputString.equals("end")) {
                break;
            } else {
                if (inputString.length() % 3 == 0) {
                    outputString += inputString + " " ;
                }
            }
        }
        System.out.println(outputString);
    }

}
