package ejercicio1UDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Servidor {
    public static void main(String[] argv) throws Exception {

        int port = 12345; // Puerto donde escucha el servidor

        DatagramSocket socket = new DatagramSocket(port);
        System.out.println("Servidor escuchando en el puerto " + port);

        // ----------------- RECIBIR DEL CLIENTE1 -----------------
        byte[] buffer = new byte[1024];
        DatagramPacket paqueteRecibido = new DatagramPacket(buffer, buffer.length);

        System.out.println("Esperando número del Cliente1...");
        socket.receive(paqueteRecibido);  // Recibe el número del Cliente1
        String numeroRecibido = new String(paqueteRecibido.getData(), 0, paqueteRecibido.getLength());
        System.out.println("Número recibido de Cliente1: " + numeroRecibido);

        // Dirección y puerto del Cliente2
        InetAddress direccionCliente2 = InetAddress.getLocalHost();  // Cambiar si Cliente2 está en otro dispositivo
        int puertoCliente2 = 12346;  // Puerto donde escucha Cliente2

        // ------------------- ENVIAR AL CLIENTE2 -------------------
        byte[] mensaje = numeroRecibido.getBytes();
        DatagramPacket envioCliente2 = new DatagramPacket(mensaje, mensaje.length, direccionCliente2, puertoCliente2);
        System.out.println("Enviando número al Cliente2...");
        socket.send(envioCliente2);  // Envía el número al Cliente2

        // ------------------- RECIBIR DEL CLIENTE2 ------------------
        DatagramPacket paqueteFactorialRecibido = new DatagramPacket(buffer, buffer.length);
        System.out.println("Esperando resultado del Cliente2...");
        socket.receive(paqueteFactorialRecibido);  // Recibe el factorial
        String factorialRecibido = new String(paqueteFactorialRecibido.getData(), 0, paqueteFactorialRecibido.getLength());
        System.out.println("Factorial recibido de Cliente2: " + factorialRecibido);

        // ----------------- ENVIAR AL CLIENTE1 -----------------------
        InetAddress direccionCliente1 = paqueteRecibido.getAddress();  // IP del Cliente1 desde el paquete recibido
        int puertoCliente1 = paqueteRecibido.getPort();                // Puerto del Cliente1

        byte[] factorialBytes = factorialRecibido.getBytes();
        DatagramPacket envioCliente1 = new DatagramPacket(factorialBytes, factorialBytes.length, direccionCliente1, puertoCliente1);
        System.out.println("Enviando factorial al Cliente1...");
        socket.send(envioCliente1);  // Envía el factorial de vuelta al Cliente1

        socket.close();  // Cierra el socket
    }
}
