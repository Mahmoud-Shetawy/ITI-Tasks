import javax.swing.*;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.Date;

abstract class JShape {
    protected int x, y;

    public JShape(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public abstract void draw(Graphics g);
}

class JDateTimeShape extends JShape implements Runnable {
    private String currentTime;
    private final SimpleDateFormat formatter = new SimpleDateFormat("MMM dd, yyyy hh:mm:ss a");

    public JDateTimeShape(int x, int y) {
        super(x, y);
        updateTime();
    }

    private void updateTime() {
        currentTime = formatter.format(new Date());
    }

    @Override
    public void draw(Graphics g) {
        g.setColor(Color.BLACK);
        g.setFont(new Font("Arial", Font.BOLD, 16));
        g.drawString(currentTime, x, y);
    }

    @Override
    public void run() {
        while (true) {
            updateTime();
            try {
                Thread.sleep(1000); // Update every second
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class DateTimeFrame extends JFrame {
    private JDateTimeShape dateTimeShape;

    public DateTimeFrame() {
        setTitle("Hello World Frame");
        setSize(400, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        getContentPane().setBackground(Color.CYAN);

        dateTimeShape = new JDateTimeShape(120, 120);
        new Thread(dateTimeShape).start();

        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                dateTimeShape.draw(g);
                repaint(); // Keep repainting to reflect time updates
            }
        };

        panel.setOpaque(false);
        add(panel);
        setVisible(true);
    }
}

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(DateTimeFrame::new);
    }
}
