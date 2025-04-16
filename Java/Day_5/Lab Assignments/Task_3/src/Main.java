
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

class JMovingRedPoint extends JShape implements Runnable {
    private int xSpeed = 7;
    private int ySpeed = 7;
    private final int BALL_SIZE = 10;

    public JMovingRedPoint() {
        super(50, 50);
    }

    @Override
    public void draw(Graphics g) {
        g.setColor(Color.RED);
        g.fillOval(x, y, BALL_SIZE, BALL_SIZE);
    }

    @Override
    public void run() {
        while (true) {

            x += xSpeed;
            y += ySpeed;

            // Bounce the ball when it hits the edges
            if (x <= 0 || x + BALL_SIZE >= 500) {
                xSpeed = -xSpeed;
            }
            if (y <= 0 || y + BALL_SIZE >= 300) {
                ySpeed = -ySpeed;
            }

            try {
                Thread.sleep(15);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class RedPointFrame extends JFrame {
    private JMovingRedPoint movingRedPoint;

    public RedPointFrame() {
        setTitle("Moving Red Point");
        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        getContentPane().setBackground(Color.CYAN);

        movingRedPoint = new JMovingRedPoint();
        new Thread(movingRedPoint).start();

        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                movingRedPoint.draw(g);
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
        SwingUtilities.invokeLater(RedPointFrame::new);
    }
}
