package practica;

public class Productor extends Thread {
    //Constructor clase productor
    private Deposito dep;

    public Productor(Deposito dep)
    {
        this.dep = dep;
    }
    public void run()
    {
        for (int i = 0; i < 15; i++){
            double num = (Math.random() * 1000) + 1;
            try {
                this.dep.prodLlenaDep(num);
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

}
