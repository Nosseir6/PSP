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
                int numero = queue.get(opcion); // Obtiene el número.
                if (opcion == 1) { // Sumar.
                    if (numero % 2 == 0)
                    {

                        resultado += numero;
                        System.out.println("Consumidor Pares: par leído = " + numero + ", sumatorio actual de pares = " + resultado);
                    }
                    else
                        System.out.println("Numero impar el consumidor de pares no lo quiere");
                } else if (opcion == 2) { //Impares
                    if (numero % 2 != 0)
                    {
                        resultado += numero;
                        System.out.println("Consumidor Impar: impar leído = " + numero + ", sumatorio actual de impares = " + resultado);
                    }
                    else
                        System.out.println("Numero par el consumidor de impares no lo quiere");
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }


}
