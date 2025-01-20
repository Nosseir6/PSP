package clase.ejercicio2;

public class Consumidor extends Thread{
    private Queue queue = new Queue();
    private int opcion;
    int resultado;
    public Consumidor(Queue cola, int opcion)
    {
        this.queue = cola;
        this.opcion = opcion;
        this.resultado = (opcion == 1) ? 0 : 1;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                int numero = queue.get(opcion);// Obtiene el número.
                Thread.sleep(5000);
                if (opcion == 1) { // Sumar.
                    resultado += numero;
                    System.out.println("Consumidor Suma: número leído = " + numero + ", sumatorio actual = " + resultado);
                } else if (opcion == 2) { // Multiplicar.
                    resultado *= numero;
                    System.out.println("Consumidor Producto: número leído = " + numero + ", producto actual = " + resultado);
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
