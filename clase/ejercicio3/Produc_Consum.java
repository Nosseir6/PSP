package clase.ejercicio3;

public class Produc_Consum {
    public static void main(String[] args) {
        Queue queue = new Queue();

        Consumidor consPar = new Consumidor(queue,1);
        Consumidor consImpar = new Consumidor(queue,2);
        Productor productor = new Productor(queue);

        consPar.start();
        consImpar.start();
        productor.start();
    }
}
