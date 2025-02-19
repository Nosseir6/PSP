package ejercicio1TCP;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Cliente2 {
    public static void main(String[] args) throws IOException {
        String host = "localhost";
        int puerto = 12346;

        //Creamos el socket para el cliente
        System.out.println("El cliente1 se esta iniciando");
        Socket cliente2 = new Socket(host,puerto);

        //Creacion del flujo direccion (servidor -> cliente)
        System.out.println("Recibiendo del servidor...");
        DataInputStream flujoEntrada = new DataInputStream(cliente2.getInputStream());
        String factorial = flujoEntrada.readUTF();

        System.out.println("Numero para calcular el factorial " + factorial);
        int factorialCalculado = calcFactorial(Integer.parseInt(factorial));


        //Creacion del flujo direccion (cliente -> servidor)
        DataOutputStream flujoSalida = new DataOutputStream(cliente2.getOutputStream());
        flujoSalida.writeUTF(String.valueOf(factorialCalculado));

        cliente2.close();
        flujoSalida.close();
        flujoEntrada.close();
    }

    public static int calcFactorial(int numero)
    {
        if (numero == 0)
        {
            return 1;
        }

        return numero*calcFactorial(numero-1);
    }
}
