package clase.ejercicio3;

public class Consumidor extends Thread{
    private Queue queue;
    private int opcion;
    int resultado;
    public Consumidor(Queue cola, int opcion)
    {
        this.queue = cola;
        this.opcion = opcion;
        this.resultado = 0;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                int numero = queue.get(opcion); // Obtiene el número según la opción.
                if (opcion == 1) { // Sumar.
                    if (numero % 2 == 0)
                    {
                        resultado += numero;
                        System.out.println("Consumidor Suma: par leído = " + numero + ", sumatorio actual de pares = " + resultado);
                    }

                } else if (opcion == 2) { //Impares
                    if (numero % 2 != 0)
                    {
                        resultado += numero;
                        System.out.println("Consumidor Producto: impar leído = " + numero + ", sumatorio actual de impares = " + resultado);
                    }
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }


}
