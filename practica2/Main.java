package practica2;

import java.util.concurrent.ArrayBlockingQueue;

public class Main {
    public static void main(String[] args) {
        Caja[] cajas = new Caja[3];
        for (int i = 0; i < 3; i++) {
            cajas[i] = new Caja(i);
        }

        Cliente[] clientes = new Cliente[15];
        for (int i = 0; i < 15; i++) {
            clientes[i] = new Cliente(i + 1, cajas);
            clientes[i].start();  // Inicia el hilo para cada cliente
        }

        System.out.println("Supermercado cerrado.");
    }

}

