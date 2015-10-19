package home.parham.core;

import home.parham.net.Listener;
import home.parham.net.Sender;

/**
 * Created by parham on 10/3/14.
 */
public class Context {
    private static Context ourInstance = new Context();

    public static Context getInstance() {
        return ourInstance;
    }

    private Listener listener;
    private Sender sender;

    private Context() {
        listener = new Listener();
        sender = new Sender();
        listener.start();
        sender.start();
    }

    public Listener getListener() {
        return listener;
    }

    public Sender getSender() {
        return sender;
    }
}
