package practica2;

import practica.Camion;

public class Caja{
    private boolean ocupado;
    int numCaja;
    public Caja(int numCaja)
    {
        this.ocupado = false;
        this.numCaja = numCaja;
    }

    public synchronized void atenderCliente(Cliente cliente) throws InterruptedException {
        while (isOcupado())
        {
            wait();
        }
        ocupado = true;
        System.out.println("Caja"+numCaja+ "Atendiendo al cliente " + cliente.getNumCliente());
        Thread.sleep(5000);
        System.out.println("El cliente " + cliente.getNumCliente() + " ha sido atendido");
        ocupado = false;
        notifyAll();

    }


    public boolean isOcupado() {
        return ocupado;
    }
}
