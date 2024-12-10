package clase.ejercicio1;

import java.util.concurrent.ArrayBlockingQueue;

public class Produc_Consum {
    public static void main(String[] args) {
        Queue queue = new Queue();

        Consumidor consumidor = new Consumidor(queue);
        Productor productor = new Productor(queue);

        consumidor.start();
        productor.start();
    }
}
