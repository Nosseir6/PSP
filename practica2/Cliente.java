package practica2;

public class Cliente extends Thread{

    private int id;
    private GestorCajas gestorCajas;

    public Cliente(int id,GestorCajas gestorCajas)
    {
        this.id = id;
        this.gestorCajas = gestorCajas;

    }

    @Override
    public void run() {
        System.out.println("Cliente "+id+" entra en la lista de espera");
        try {
            Caja caja = gestorCajas.cajaLibre();
            caja.atenderCliente(id);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
