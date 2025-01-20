package uno;

public class Produc_Consum {
  public static void main(String[] args) {  

      /*Recurso compartido*/
    Cola cola = new Cola();

    //Hilos productor/consumidor
    Productor prod = new Productor(cola, 1);	
    Consumidor cons = new Consumidor(cola, 1);
	
    prod.start();
    cons.start();

  }
}