package home.parham.net;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Inet4Address;
import java.nio.charset.StandardCharsets;

/**
 * Created by parham on 10/3/14.
 */
public class Sender extends Thread {

    private NetBuffer buffer;

    public Sender() {
        super("ChatHub-Java Sender Thread");
        buffer = new NetBuffer();
    }

    @Override
    public void run() {
        try {
            DatagramSocket clientSocket = new DatagramSocket();
            clientSocket.setBroadcast(true);
            clientSocket.connect(Inet4Address.getByName("255.255.255.255"),1373);

            while (true) {
                Message message = buffer.poll();
                if (message != null) {
                    System.err.println(message.getMessage());
                    DatagramPacket packet = new DatagramPacket(message.getMessage().getBytes(StandardCharsets.US_ASCII), message.getMessage().getBytes().length);
                    clientSocket.send(packet);
                }
                Thread.sleep(1000);
            }

        } catch (IOException exception) {
            exception.printStackTrace();
        } catch (InterruptedException exception) {
            exception.printStackTrace();
        }
    }

    public boolean push(Message message) {
        return buffer.add(message);
    }

}
