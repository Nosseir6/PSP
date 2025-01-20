package practica2;

public class Cliente extends Thread {
    private int numCliente;
    private Caja[] cajas;  // Usamos un arreglo de cajas
    private boolean atendido;

    public Cliente(int numCliente, Caja[] cajas) {
        this.numCliente = numCliente;
        this.cajas = cajas;
        atendido = false;
    }

    @Override
    public void run() {
        for (Caja caja : cajas) {
            if (!atendido && !caja.isOcupado()) {
                try {
                    caja.atenderCliente(this); // El cliente es atendido por la caja
                    atendido = true;  // Marcar como atendido
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public int getNumCliente() {
        return numCliente;
    }
}
