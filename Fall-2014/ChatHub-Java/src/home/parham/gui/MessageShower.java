package home.parham.gui;

import home.parham.core.Context;
import home.parham.net.Message;

import javax.swing.*;

/**
 * Created by parham on 10/3/14.
 */
public class MessageShower extends Thread {

    private JTextPane outputPanel;
    private Message message = null;

    public MessageShower(JTextPane pane) {
        super("ChatHub-Java MessageShower Thread");
        outputPanel = pane;
    }

    @Override
    public void run() {
        while (true) {
            message = Context.getInstance().getListener().pop();
            if (message != null) {
                System.err.println(message.getMessage());
                SwingUtilities.invokeLater(new Runnable() {
                    @Override
                    public void run() {
                        outputPanel.setText(outputPanel.getText() + message.getAddress().toString() + " : " + message.getMessage() + "\n");
                    }
                });
            }
            try {
                Thread.sleep(1000);
            }catch(InterruptedException exception){
                exception.printStackTrace();
            }
        }
    }

}
