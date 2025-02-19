package ejercicio1UDP;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Cliente1 {
    public static void main(String[] argv) throws Exception {
        InetAddress destino = InetAddress.getLocalHost();
        int port = 12345; // Puerto del servidor

        // Mensaje para enviar
        String saludo = "5";
        byte[] mensaje = saludo.getBytes();

        // Crear el socket del cliente en un puerto aleatorio
        DatagramSocket socket = new DatagramSocket();

        // Crear el datagrama de envío
        DatagramPacket envio = new DatagramPacket(mensaje, mensaje.length, destino, port);

        System.out.println("Enviando número al servidor: " + saludo);
        socket.send(envio);  // Enviar al servidor

        // ---------------------- RECIBIR RESPUESTA ----------------------
        byte[] buffer = new byte[1024];
        DatagramPacket respuesta = new DatagramPacket(buffer, buffer.length);

        System.out.println("Esperando respuesta del servidor...");
        socket.receive(respuesta);  // Esperar respuesta del servidor

        // Procesar respuesta
        String factorial = new String(respuesta.getData(), 0, respuesta.getLength());
        System.out.println("Factorial recibido: " + factorial);

        socket.close();  // Cerrar el socket
    }
}
