import monitor.* ;
/**
 *
 * @author juanka1995
 */

class Barberia extends AbstractMonitor {
    private Condition sala_espera = makeCondition(); // Condicion para los clientes de la sala de espera
    private Condition silla_pelar = makeCondition(); // Condicion para ver que cliente pasa a la silla de pelar
    private Condition barbero = makeCondition(); // Condicion para ver cuando el barbero pela y cuando duerme
    String cliente_pelandose; // Nombre del cliente que esta pelando el barbero en cada momento
    
    // invcado por los clientes para cortarse el pelo
    public void cortarPelo (String cliente) {
        enter();
        System.out.println(cliente+" entra en la barberia\n");
        // Entra un cliente y pregunta si la silla de pelar esta ocupada, en ese caso pasa a la sala de espera
        // hasta que el barbero le llame y pasará a la silla de pelar (silla_pelar.await() despues del if)
        if(!silla_pelar.isEmpty()){
            System.out.println(cliente+" pasa a la sala de espera\n");
            sala_espera.await();
            cliente_pelandose = cliente;
            System.out.println(cliente+" pasa a la silla de pelar\n");
        }
        // Si la silla de pelar esta vacia el cliente pregunta si no hay nadie en la sala de espera
        // para no colarse al resto de clientes. Si no hay nadie en la sal de espera despierta al barbero 
        // para que lo pele y pasará a la silla de pelar (silla_pelar.await() despues del if)
        else if(sala_espera.isEmpty()){
            cliente_pelandose = cliente;
            System.out.println("La barbería estaba vacía. "+cliente+" pasa a la silla de pelar\n");
            barbero.signal();
        }
        silla_pelar.await();
        System.out.println(cliente+" sale de la barberia\n");
        leave();
    }
    
    // invocado por el barbero para esperar (si procede) a un nuevo cliente y sentarlo para el corte
    public void siguienteCliente () {
        enter();
        // El barbero mira si la silla de pelar esta vacia y si la sala de espera tambien lo está,
        // en ese caso se pone a dormir. Esperando a que cuando entre un cliente lo despierte para
        // que le corte el pelo.
        if(silla_pelar.isEmpty() && sala_espera.isEmpty()){
            System.out.println("El barbero esta durmiendo.\n");
            barbero.await();
        }
        // Si alguna de las dos condiciones anteriores no se cumpliese, el barbero mira primero si la 
        // sala de espera no esta vacia y si la silla de pelar si lo esta, en ese caso llama a un nuevo cliente
        // de la sala de espera que pasará a la silla de pelar. Tiene que comprobar si la silla de pelar esta vacia
        // para no sentar a ningun cliente encima de otro.
        // Si la silla de pelar estubiera vacia y la sala de espera tambien significaría que la barberia estaba vacía
        // y acaba de entrar un cliente, por lo que ese cliente pasaría a la silla de pelar directamente.
        else if(!sala_espera.isEmpty() && silla_pelar.isEmpty()){
            sala_espera.signal();
        }
        System.out.println("\t\tEl barbero esta cortando el pelo al "+cliente_pelandose+".\n");
        leave();
    }

    // invocado por el barbero para indicar que ha terminado de cortar el pelo
    public void finCliente () {
        enter();
        // Cuando el barbero termina de pelar a un cliente le avisa y este sale de la barbería.
        System.out.println("\t\t"+cliente_pelandose+" ha terminado de pelarse\n");
        silla_pelar.signal();
        leave();
    }
}

class Cliente implements Runnable { 
    Barberia barberia;
    public Thread thr;
    int id_cliente;
    
    public Cliente(Barberia barberia, String nombre){
        this.barberia = barberia;
        thr = new Thread(this,nombre);
    }
    
    public void run () { 
        while (true) {
            barberia.cortarPelo (thr.getName()); // el cliente espera (si procede) y se corta el pelo
            aux.dormir_max( 2000 ); // el cliente está fuera de la barberia un tiempo
        }
    }
}

class Barbero implements Runnable { 
    public Thread thr;
    public Barberia barberia;
    
    public Barbero(Barberia barberia,String nombre){
        this.barberia = barberia;
        thr = new Thread(this,nombre);
    }
    
    public void run () { 
        while (true) {
            barberia.siguienteCliente ();
            aux.dormir_max( 2500 ); // el barbero está cortando el pelo
            barberia.finCliente ();
        }
    }
}

public class BarberoDurmiente {
    public static int NUM_CLI = 3;
    
    public static void main(String[] args){
        //Creamos los vectores de hebras
        Cliente[] vcli = new Cliente[NUM_CLI];
        Barbero barv ;
        
        //Creamos el monitor
        Barberia barberia = new Barberia();
        
        //Creamos las hebras
        for (int i = 0; i < vcli.length; i++)
            vcli[i] = new Cliente(barberia,"Cliente "+(i+1));
        barv = new Barbero(barberia,"Barbero");
        
        //Lanzamos las hebras
        for (int i = 0; i < vcli.length; i++)
            vcli[i].thr.start();
        barv.thr.start();
    }
}
