class CuentaBancaria {
    //Saldo inicial de la cuenta
    int saldo = 1000;

    //método sacarDinero:
    // nombre -> persona que realiza la operación
    //importe -> cantidad a retirar
    synchronized void sacarDinero (String nombre, int importe)
    {

        if (importe <= saldo){
            setSaldo(getSaldo()-importe);
            System.out.println(nombre + " ha sacado " + importe);
            System.out.println("Importe de la cuenta -> " + getSaldo());
        }else {
            System.out.println(nombre + " no puede sacar " + importe + "-> Saldo insuficiente");
        }

        //Después de la operación dormir el hilo
        try {
            Thread.sleep(1000);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    //método ingresarDinero
    //nombre -> persona que realiza la operación
    //importe -> cantidad a retirar
    synchronized void ingresarDinero (String nombre, int importe)
    {
        setSaldo(getSaldo()+ importe);
        System.out.println(nombre + " ingreso " + importe);
        System.out.println("Saldo actual -> "+ getSaldo());
        //Después de la operación dormir el hilo
        try {
            Thread.sleep(1000);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public int getSaldo() {
        return saldo;
    }

    public void setSaldo(int saldo) {
        this.saldo = saldo;
    }
}