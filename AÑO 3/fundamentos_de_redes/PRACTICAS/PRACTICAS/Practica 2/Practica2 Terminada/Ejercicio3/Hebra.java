
import java.net.Socket;
import java.util.Random;


public class Hebra extends Thread{
    private Socket socketServicio;
     
    public Hebra(Socket socketServicio) {
        this.socketServicio=socketServicio;
    }
    @Override
    public void run() {
        ProcesadorYodafy procesador=new ProcesadorYodafy(socketServicio);
	procesador.procesa();
    }
}