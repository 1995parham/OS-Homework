package home.parham.main;

import home.parham.core.Context;
import home.parham.gui.MainFrame;

/**
 * Created by parham on 10/3/14.
 */
public class Main {
    public static void main(String[] args) {
        MainFrame.main(args);
        Context.getInstance();
    }

}
