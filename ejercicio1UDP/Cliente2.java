package ejercicio1UDP;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Cliente2 {
    public static int factorial(int numero) {
        if (numero == 0) {
            return 1;
        }
        return numero * factorial(numero - 1);
    }

    public static void main(String[] argv) throws Exception {
        int port = 12346;  // Puerto donde escucha Cliente2

        DatagramSocket socket = new DatagramSocket(port);
        System.out.println("Cliente2 escuchando en el puerto " + port);

        // RECIBIR DEL SERVIDOR
        byte[] buffer = new byte[1024];
        DatagramPacket paqueteRecibido = new DatagramPacket(buffer, buffer.length);

        System.out.println("Esperando número del Servidor...");
        socket.receive(paqueteRecibido); // Recibe el número del Servidor

        String numeroRecibido = new String(paqueteRecibido.getData(), 0, paqueteRecibido.getLength());
        System.out.println("Número recibido de Servidor: " + numeroRecibido);

        // Calcular el factorial
        int factCalculado = factorial(Integer.parseInt(numeroRecibido));
        System.out.println("El factorial es: " + factCalculado);

        // ENVIAR EL FACTORIAL DE VUELTA AL SERVIDOR
        InetAddress direccionServidor = paqueteRecibido.getAddress(); // Obtener la IP del servidor
        int puertoServidor = 12345;  // Puerto donde escucha el Servidor

        String mensaje = String.valueOf(factCalculado);
        byte[] bufferEnvio = mensaje.getBytes();

        DatagramPacket paqueteEnvio = new DatagramPacket(bufferEnvio, bufferEnvio.length, direccionServidor, puertoServidor);
        System.out.println("Enviando factorial al Servidor...");
        socket.send(paqueteEnvio);  // Envía el factorial al servidor

        socket.close();  // Cierra el socket
    }
}

