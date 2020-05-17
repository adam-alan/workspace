import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        question2();
    }

    static void question1(){
        Scanner reader = new Scanner(System.in);
        int num = reader.nextInt();
        int reverseNum = 0;
        while (num != 0) {
            reverseNum = reverseNum * 10 + num % 10;
            num /= 10;
        }
        System.out.println(reverseNum);
        reader.close();
    }

    static void question2() {
        Scanner reader = new Scanner(System.in);
        ArrayList<Integer> integers = new ArrayList<>();
        while (true) {
            int num = reader.nextInt();
            if (num < 0) {
                break;
            }
            integers.add(num);
        }
        System.out.println(Collections.max(integers));
        System.out.println(Collections.min(integers));
        reader.close();
    }


}


class Circle{
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }

    public double getPerimeter(){
        return 2 * Math.PI * radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }
}

class Sphere extends Circle{
    Sphere(double radius) {
        super(radius);
    }

    public double getSuperficialArea(){
        return super.getRadius() * super.getRadius() * Math.PI * 4;
    }
    public double getVolumn() {
        return super.getRadius() * super.getRadius() * super.getRadius() * Math.PI * 4 / 3;
    }
}

