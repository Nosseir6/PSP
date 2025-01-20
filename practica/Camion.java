package practica;

public class Camion extends Thread {

    private Deposito deposito;
    private int numCamion;

    public Camion(Deposito dep, int n) {
        this.deposito = dep;
        this.numCamion = n;
    }

    public void run() {
        double cargaTotal = 0;

        for (int i = 0; i < 5; i++) {
            try {
                Thread.sleep(1000); // Simular tiempo de carga
                double carga = deposito.llenarDepositoCamion();
                System.out.println("Camión " + numCamion + " carga: " + carga + " litros por "+i+" vez");
                cargaTotal += carga;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Camión " + numCamion + " => Volumen Total Recogido = "+cargaTotal+" Operación carga finalizada!!");
    }
}
