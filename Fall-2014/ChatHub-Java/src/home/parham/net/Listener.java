package home.parham.net;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.nio.charset.StandardCharsets;

/**
 * Created by parham on 10/3/14.
 */
public class Listener extends Thread {

    private NetBuffer buffer;

    public Listener() {
        super("ChatHub-Java Listener Thread");
        buffer = new NetBuffer();
    }

    @Override
    public void run() {
        try {
            DatagramSocket serverSocket = new DatagramSocket(1373);

            while (true) {
                byte[] buff = new byte[1024];
                DatagramPacket packet = new DatagramPacket(buff, buff.length);
                serverSocket.receive(packet);
                System.err.println(packet.getSocketAddress());
                Message message = new Message();
                message.setAddress(packet.getSocketAddress());
                message.setMessage(new String(packet.getData(), StandardCharsets.US_ASCII));
                buffer.add(message);
            }

        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }

    public Message pop() {
        return buffer.poll();
    }

}
