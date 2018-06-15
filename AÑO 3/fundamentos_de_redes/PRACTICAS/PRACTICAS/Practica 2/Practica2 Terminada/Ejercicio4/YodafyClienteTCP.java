//
// YodafyServidorIterativo
// (CC) jjramos, 2012
//
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class YodafyClienteTCP {

	public static void main(String[] args) throws SocketException, UnknownHostException, IOException {
		
            int port=8888;
            InetAddress direccion = null;
            DatagramPacket paquete;
            byte[] receiveData = new byte[256];
            byte[] sendData = new byte[256];
                
            sendData = "Al monte del volcan debes ir sin demora".getBytes();
                
            DatagramSocket socket = null;
                
            socket = new DatagramSocket();

                
            direccion = InetAddress.getByName("localhost");

                
            paquete = new DatagramPacket(sendData, sendData.length, direccion, port);
                
            socket.send(paquete);

                
            DatagramPacket mensajeRecibir = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(mensajeRecibir);

            String salida = new String(mensajeRecibir.getData());
            System.out.println(salida);
            
               
            socket.close();
                
	}
}
