package practica2;

public class Main {
    public static void main(String[] args) {
            final int NUM_CAJAS = 3;
            final int NUM_CLIENTES = 15;

            GestorCajas gestorCajas = new GestorCajas(NUM_CAJAS);

            // Crear y arrancar los hilos para los clientes
            Thread[] clientes = new Thread[NUM_CLIENTES];
            for (int i = 0; i < NUM_CLIENTES; i++) {
                clientes[i] = new Cliente(i + 1, gestorCajas);
                clientes[i].start();
            }


            System.out.println("Supermercado cerrado.");
        }

    }

