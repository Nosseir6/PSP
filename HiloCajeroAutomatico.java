public class HiloCajeroAutomatico {

    public static void main(String[] args)
    {
        CuentaBancaria c = new CuentaBancaria();

        HiloIngresarDinero hilo1 = new HiloIngresarDinero(c,"Padre",200);
        HiloSacarDinero hilo2 = new HiloSacarDinero(c,"Abuelo",600);
        HiloSacarDinero hilo3 = new HiloSacarDinero(c, "Hijo2",800);
        HiloIngresarDinero hilo4 = new HiloIngresarDinero(c,"Hijo1",300);
        HiloSacarDinero hilo5 = new HiloSacarDinero(c, "Mama", 400);

        hilo1.start();
        hilo2.start();
        hilo3.start();
        hilo4.start();
        hilo5.start();

    }
}

