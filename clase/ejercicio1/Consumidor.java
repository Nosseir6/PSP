package clase.ejercicio1;

import java.util.concurrent.ArrayBlockingQueue;

public class Consumidor extends Thread{
    private Queue queue = new Queue();

    public Consumidor(Queue cola)
    {
        this.queue = cola;
    }

    public void run()
    {
        int sum = 0;
        try {
           for (int i = 0; i < 10; i++){
               int numero = queue.get();
                sum += numero;
               System.out.println("Numero leido: "+numero);
               System.out.println("Sumatorio actual: "+sum);
               Thread.sleep(700);
           }

        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

}
