package clase.ejercicio1;

import java.util.concurrent.ArrayBlockingQueue;

public class Queue {
    private static int CAPACIDAD = 5;
    ArrayBlockingQueue<Integer> queue = new ArrayBlockingQueue<>(CAPACIDAD );

    public Queue(){}

    public synchronized void put(int numero) throws InterruptedException {
        while(queue.size() == CAPACIDAD){
            System.out.println("Productor espera, cola llena");
            wait();
        }
        queue.add(numero);
        System.out.println("Productor produce: " + numero);
        notifyAll();
    }

    public synchronized int get() throws InterruptedException {
        while (queue.isEmpty()){
            System.out.println("Consummior espera, cola vacia");
            wait();
        }
        int numero = queue.poll();
        System.out.println("Consumidor consume: " + numero);
        notifyAll();
        return numero;

    }

}
