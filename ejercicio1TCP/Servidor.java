package ejercicio1TCP;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Servidor
{
    public static void main(String[] args) throws IOException {
        int puertoServidor = 12345;


        ServerSocket servidor = new ServerSocket(puertoServidor);
        Socket socketCliente1 = null;
        System.out.println("Esperando a la conexion con el Cliente 1");
        socketCliente1 = servidor.accept();

        //Flujo de entrada en direccion (cliente1 -> servidor)
        InputStream entradaCliente1 = null;
        entradaCliente1 = socketCliente1.getInputStream();
        DataInputStream flujoEntradaCliente1 = new DataInputStream(entradaCliente1);

        //Recibiendo los datos del primer cliente
        String numeroCliente1 = flujoEntradaCliente1.readUTF();
        System.out.println("Recibiendo del Cliente1: "+numeroCliente1);

        //Flujo de salida en direccion (servidor -> cliente2)
        String ipCliente2 = "localhost";
        int puertoCliente2 = 12346;

        Socket socketCliente2 = new Socket(ipCliente2,puertoCliente2);
        OutputStream salidaCliente2 =  socketCliente2.getOutputStream();
        DataOutputStream flujoSalidaCliente2 = new DataOutputStream(salidaCliente2);

        //Enviando datos al cliente2
        flujoSalidaCliente2.writeUTF(numeroCliente1);
        
        //Flujo de entrada del Cliente 2 (cliente2 -> servidor)
        InputStream entradaCliente2 = socketCliente2.getInputStream();
        DataInputStream flujoEntradaCliente2 = new DataInputStream(entradaCliente2);
        
        //Datos recibidos del primer cliente
        String numeroCliente2 = flujoEntradaCliente2.readUTF();
        System.out.println("Datos recibidos del Cliente2: "+numeroCliente2);

        //Flujo de salida en direccion (servidor -> Cliente1)
        OutputStream salidaCliente1 = socketCliente1.getOutputStream();
        DataOutputStream flujoSalidaCliente1 = new DataOutputStream(salidaCliente1);
        
        //Enviando el factorial al Cliente1
        flujoSalidaCliente1.writeUTF(numeroCliente2);
        
        //Cierre de streams y sockets
        entradaCliente1.close();
        flujoEntradaCliente1.close();
        entradaCliente2.close();
        flujoEntradaCliente2.close();
        
        salidaCliente1.close();
        flujoSalidaCliente1.close();
        salidaCliente2.close();
        flujoSalidaCliente2.close();

        servidor.close();
        
    }
}
