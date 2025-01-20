public class HiloParImpar implements Runnable
{
    private final int tipo;

    public HiloParImpar(int tipo)
    {
        this.tipo = tipo;
    }

    @Override
    public void run()
    {
        switch (tipo)
        {
            case 0 -> contador_pares();
            case 1 -> contador_impares();
        }
    }

    public static synchronized void contador_pares()
    {
        for (int i = 2; i <= 100; i += 2)
        {
            System.out.println("Hilo xx generando numero par: " + i);
        }
    }

    public static synchronized void contador_impares()
    {
        for (int i = 101; i <= 200; i += 2)
        {
            System.out.println("Hilo yy generando numero impar: " + i);
        }
    }

    public static void main(String[] args)
    {
        Thread xx  = new Thread(new HiloParImpar(0));
        Thread yy = new Thread(new HiloParImpar(1));

        yy.start();
        xx.start();


    }
}
