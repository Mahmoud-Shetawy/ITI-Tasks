import javax.swing.*;
import java.awt.*;

abstract class JShape {
    protected int x, y;

    public JShape(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public abstract void draw(Graphics g);
}

class JHelloWorldShape extends JShape implements Runnable {
    private int speed = 5;  // Speed of movement
    private int frameWidth; // Width of the JFrame

    public JHelloWorldShape(int x, int y, int frameWidth) {
        super(x, y);
        this.frameWidth = frameWidth;
    }

    @Override
    public void draw(Graphics g) {
        g.setColor(Color.BLACK);
        g.setFont(new Font("Arial", Font.BOLD, 20));
        g.drawString("Hello World", x, y);
    }

    @Override
    public void run() {
        while (true) {
            x += speed;
            if (x > frameWidth) {
                x = -100; // Reset to the left when out of bounds
            }
            try {
                Thread.sleep(50); // Control speed of movement
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class HelloWorldFrame extends JFrame {
    private JHelloWorldShape helloWorldShape;

    public HelloWorldFrame() {
        setTitle("Hello World Moving");
        setSize(500, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        getContentPane().setBackground(Color.CYAN);

        helloWorldShape = new JHelloWorldShape(10, 120, getWidth());
        new Thread(helloWorldShape).start();

        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                helloWorldShape.draw(g);
                repaint();
            }
        };

        panel.setOpaque(false);
        add(panel);
        setVisible(true);
    }
}

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(HelloWorldFrame::new);
    }
}
