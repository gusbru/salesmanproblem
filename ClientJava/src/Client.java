import java.io.*;
import java.net.*;

public class Client
{
    public static void main(String args[])
    {
        String ip = "127.0.0.1";
        int port = 61234;

        try {
            Socket socket = new Socket(ip, port);
            ObjectOutputStream transmission = new ObjectOutputStream(socket.getOutputStream());
            BufferedReader inputMsg = new BufferedReader(new InputStreamReader(System.in));
            String msg;

            do
            {
                msg = inputMsg.readLine();
                transmission.writeObject(msg);
                transmission.flush();
            } while(!msg.toUpperCase().equals("FIM"));

            transmission.close();
            socket.close();
        } catch (Exception error)
        {
            System.err.println("" + error);
        }

    }
}
