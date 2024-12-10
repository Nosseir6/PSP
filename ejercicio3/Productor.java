package clase.ejercicio3;

public class Productor extends Thread{
    private Queue queue;

    public Productor(Queue cola)
    {
        this.queue = cola;
    }

    public void run()
    {
        for (int i = 0; i < 10; i++){
            int num = (int) (Math.random() * 10) + 1;
            try {
                queue.put(num);
                Thread.sleep(300);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
