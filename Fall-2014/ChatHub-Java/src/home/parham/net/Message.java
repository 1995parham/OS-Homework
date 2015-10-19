package home.parham.net;

import java.net.SocketAddress;

/**
 * Created by parham on 10/3/14.
 */
public class Message {
    private String message;
    private SocketAddress address;

    public Message(String message){
        this.setMessage(message);
    }

    public Message(){};

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public SocketAddress getAddress() {
        return address;
    }

    public void setAddress(SocketAddress address) {
        this.address = address;
    }
}
