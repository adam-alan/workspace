import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

public class JsonEncodeDemo {
    public static void main(String[] args)
    {
        try
        {
            Socket socket = new Socket("localhost",10000);
        }
        catch (UnknownHostException  unknownHostException)
        {
            System.out.println("dsd");
        }
        catch (IOException ioException)
        {
            System.out.println("ff");
        }

    }
}
