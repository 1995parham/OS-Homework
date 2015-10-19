package home.parham.gui;

import home.parham.core.Context;
import home.parham.net.Message;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by parham on 10/3/14.
 */
public class MainFrame {
    private JTextPane inputPanel;
    private JTextPane outputPanel;
    private JButton sendButton;
    private JButton exitButton;
    private JPanel contentPane;

    public static void main(String[] args) {
        JFrame frame = new JFrame("MainFrame");
        frame.setContentPane(new MainFrame().contentPane);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    public MainFrame() {
        new MessageShower(outputPanel).start();

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.exit(0);
            }
        });
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                String message = inputPanel.getText();
                Context.getInstance().getSender().push(new Message(message));
            }
        });
    }

}
