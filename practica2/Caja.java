package practica2;

import practica.Camion;

public class Caja {
    private boolean ocupado;
    private int num;

    Caja(int num){
        ocupado = false;
        this.num = num;
    }

    public synchronized void atenderCliente(int clienteId) throws InterruptedException {
            ocupado = true;
            System.out.println("Caja " + num + " atendiendo al cliente " + clienteId);
            Thread.sleep(5000); // Simula el tiempo de atención
            System.out.println("Caja " + num + " terminó con el cliente " + clienteId);

            ocupado = false;
            notifyAll(); // Notifica a otros clientes en espera

    }


    public boolean isOcupado() {
        return ocupado;
    }
}
