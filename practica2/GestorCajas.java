package practica2;

public class GestorCajas {
    private Caja [] cajas;


    public GestorCajas(int numCajas)
    {
        cajas = new Caja[numCajas];
        for (int i = 0; i < numCajas; i++) {
            cajas[i] = new Caja(i+1);
        }
    }

    public synchronized Caja cajaLibre() throws InterruptedException {
        while (true)
        {
            for (Caja caja : cajas)
            {
                if (!caja.isOcupado())
                {
                    return caja;
                }
            }
            wait();
        }
    }
}
