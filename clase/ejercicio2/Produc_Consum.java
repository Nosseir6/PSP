package clase.ejercicio2;


import java.util.concurrent.ArrayBlockingQueue;

public class Produc_Consum {
    public static void main(String[] args) {
        Queue queue = new Queue();

        Consumidor consSum = new Consumidor(queue,1);
        Consumidor consProd = new Consumidor(queue,2);
        Productor productor = new Productor(queue);

        consSum.start();
        consProd.start();
        productor.start();
    }
}
