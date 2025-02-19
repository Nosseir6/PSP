package ejercicio1TCP;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Cliente1 {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String host = "localhost";
        int puerto = 12345;

        //Creamos el socket para el cliente
        System.out.println("El cliente1 se esta iniciando");
        Socket cliente1 = new Socket(host,puerto);

        System.out.println("Numero para calcular el factorial");
        String numeroCliente1 = scanner.next();

        //Creacion del flujo direccion (cliente -> servidor)
        DataOutputStream flujoSalida = new DataOutputStream(cliente1.getOutputStream());
        flujoSalida.writeUTF(numeroCliente1);

        //Creacion del flujo direccion (servidor -> cliente)
        System.out.println("Recibiendo del servidor...");
        DataInputStream flujoEntrada = new DataInputStream(cliente1.getInputStream());
        String factorial = flujoEntrada.readUTF();

        System.out.println("El factorial del numero "+numeroCliente1+" es "+factorial);
        cliente1.close();
        flujoEntrada.close();
        flujoSalida.close();
    }
}
