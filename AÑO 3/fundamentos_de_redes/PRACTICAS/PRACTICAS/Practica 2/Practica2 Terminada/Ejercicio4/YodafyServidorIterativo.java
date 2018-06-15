import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

//
// YodafyServidorIterativo
// (CC) jjramos, 2012
//
public class YodafyServidorIterativo {

	public static void main(String[] args) throws SocketException, IOException {
                int port=8888;
		DatagramSocket serverSocket = new DatagramSocket(port);
                InetAddress direccion = null;
		DatagramPacket mensajeRecibir;
                
		
		while(true){
                    ProcesadorYodafy procesador=new ProcesadorYodafy(serverSocket);
                    procesador.procesa();
                }
	}

}
