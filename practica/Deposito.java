package practica;

// Clase practica.Deposito
public class Deposito {
    private double litrosDeposito;

    public synchronized void prodLlenaDep(double litros) {
        this.litrosDeposito = litros;
        System.out.println("Productor llena el depósito con => " + litros + " Litros");
        notify(); // Notificar a los camiones que el depósito está lleno
    }

    public synchronized double llenarDepositoCamion() throws InterruptedException {
        while (litrosDeposito == 0) {
            wait(); // Esperar mientras el depósito esté vacío
        }
        double carga = litrosDeposito;
        litrosDeposito = 0; // Vaciar el depósito
        notify(); // Notificar al productor que el depósito está vacío
        return carga;
    }

}