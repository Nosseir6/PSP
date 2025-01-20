package clase.ejercicio1;

import java.util.concurrent.ArrayBlockingQueue;

public class Productor extends Thread{
    private Queue queue = new Queue();

    public Productor(Queue cola)
    {
        this.queue = cola;
    }

    public void run()
    {
        for (int i = 0; i < 10; i++){
            int num = (int) (Math.random() * 10);
            try {
                queue.put(num);
                System.out.println("Productor produjo: "+num);
                Thread.sleep(500);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
