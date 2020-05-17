import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        JFrame jFrame = new JFrame("鼠标事件监听");
        JButton jButton1 = new JButton("Clicked me!");
        JButton jButton2 = new JButton("nmsl!");

        jButton1.addMouseListener(new Event());
        jFrame.add(jButton1);
        jFrame.add(jButton2);

        jButton1.setVisible(true);
        jButton2.setVisible(true);
        jFrame.setLayout(new GridBagLayout());
        jFrame.setSize(800,480);
        jFrame.setLocation(400,300);
        jFrame.setVisible(true);

    }
}
