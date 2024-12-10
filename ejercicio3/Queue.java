package clase.ejercicio3;

import java.util.concurrent.ArrayBlockingQueue;

public class Queue {
    private static int CAPACIDAD = 5;
    ArrayBlockingQueue<Integer> queue = new ArrayBlockingQueue<>(CAPACIDAD );
    private boolean procesSum = false;
    private boolean procesProd = false;

    public Queue(){}

    public synchronized void put(int numero) throws InterruptedException {
        while(queue.size() == CAPACIDAD){
            System.out.println("Productor espera, cola llena");
            wait();
        }
        queue.add(numero);
        System.out.println("Productor produce: " + numero);
        notifyAll();
        procesSum = false;
        procesProd = false;
    }

    public synchronized int get(int opcion) throws InterruptedException {
        while (queue.isEmpty()){
            System.out.println("Consummior espera, cola vacia");
            wait();
        }

        int numero = queue.peek(); // Obtiene el número
        if (opcion == 1) { //Comprueba que ha entrado el primer hilo
            procesSum = true;
        } else if (opcion == 2) { //Comprueba que entra el segundo hilo
            procesProd = true;
        }

        if (procesSum && procesProd) { //Una vez han entrado los dos hilos quitamos el head de la cola
            queue.poll(); // Elimina el número
            notifyAll();
        }
        return numero; // Devuelve el número.
    }
}