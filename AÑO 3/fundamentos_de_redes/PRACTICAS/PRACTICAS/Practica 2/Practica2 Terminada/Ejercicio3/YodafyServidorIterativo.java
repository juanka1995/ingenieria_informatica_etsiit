import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

//
// YodafyServidorIterativo
// (CC) jjramos, 2012
//
public class YodafyServidorIterativo {

	public static void main(String[] args) {
	
		ServerSocket serverSocket;
		Socket socketServicio = null;
		// Puerto de escucha
		int port=8989;
		// array de bytes auxiliar para recibir o enviar datos.ç
		String buffer;

                // Número de bytes leídos
		int bytesLeidos=0;
		
		try {
			// Abrimos el socket en modo pasivo, escuchando el en puerto indicado por "port"
			serverSocket= new ServerSocket(port);

			// Mientras ... siempre!
			do {
				
				// Aceptamos una nueva conexión con accept()
				try {
					socketServicio= serverSocket.accept();

				} catch(IOException ex) {
					System.err.println("Error. No se pudo aceptar la conexcion solicitada");
				}
				
				
				// Creamos un objeto de la clase ProcesadorYodafy, pasándole como 
				// argumento el nuevo socket, para que realice el procesamiento
				// Este esquema permite que se puedan usar hebras más fácilmente.
                                Hebra h=new Hebra(socketServicio);
                                h.start();
                                
			} while (true);
			
		} catch (IOException e) {
			System.err.println("Error al escuchar en el puerto "+port);
		}

	}

}
