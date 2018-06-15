import monitor.* ;

/**
 *
 * @author juanka1995
 */

class Estanco extends AbstractMonitor{
    // -1 indica que no hay ingrediente en la mesa
    private int ingrediente = -1;
    private Condition[] fumador = {makeCondition(),makeCondition(),makeCondition()};
    private Condition estanquero = makeCondition();
    
    // invocado por cada fumador, indicando su ingrediente o numero
    public void obtenerIngrediente( int miIngrediente ){
        enter();
        // Mostramos que ingrediente espera cada fumador
        System.out.println("Fumador "+(miIngrediente+1)+" esperando "+Fumadores.INGREDIENTES[miIngrediente]+".\n");
        // Si el ingrediente es distinto del de un fumador concreto bloqueamos a dicho fumador, 
        // que estará esperando a que el Estanquero le avise de que ya esta su
        // ingrediente en la mesa
        if(ingrediente != miIngrediente)
            fumador[miIngrediente].await();
        // Marcamos el ingrediente como recogido despues del await del fumador, lo que quiere 
        // decir que para llegar hasta aqui previamente el estanquero a tenido que desbloquear al fumador
        // y a su vez eso quiere decir que el ingrediente de la mesa lo recoje nuestro fumador
        ingrediente = -1;
        //Avisamos al fumador de que el incrediente ya ha sido recogido
        estanquero.signal();
        //Mostramos que fumador esta ahora fumando
        System.out.println("Fumador "+(miIngrediente+1)+" fumando...\n");
        leave();
    }
    // invocado por el estanquero, indicando el ingrediente que pone
    public void ponerIngrediente( int ingrediente ){
        enter();
        // Mostramos que ingrediente pone el estanquero en la mesa
        System.out.println("\t\tEstanquero pone "+Fumadores.INGREDIENTES[ingrediente]+" en la mesa.\n");
        // Asignamos el ingrediente generado anteriormente
        this.ingrediente = ingrediente;
        // Desbloquea al fumador que necesita el ingrediente existente en la mesa
        fumador[this.ingrediente].signal();
        leave();
    }
    // invocado por el estanquero
    public void esperarRecogidaIngrediente(){
        enter();
        // En el caso de que el estanquero vuelva a generar un ingrediente de un fumador
        // que se encuentra fumando en ese momento, haría un signal a nadie con lo que 
        // el ingrediente no se marcaría como recogido y debemos de detener al estanquero
        // hasta que dicho fumador termine de fumar y al pedir y recoger el ingrediente desbloquee
        // nuevamente al estanquero
        if(ingrediente != -1)
            estanquero.await();
        leave();
    }
}

class Fumador implements Runnable {
    int miIngrediente;
    private Estanco estanco;
    public Thread thr ;

    public Fumador( int p_miIngrediente, Estanco estanco, String nombre ){
        miIngrediente = p_miIngrediente;
        this.estanco = estanco;
        thr = new Thread(this,nombre);
    }
    public void run(){
        System.out.println(thr.getName()+" tiene "+Fumadores.INGREDIENTES[(miIngrediente+1)%3]+
                            " y "+Fumadores.INGREDIENTES[(miIngrediente+2)%3]+
                            ". Espera "+Fumadores.INGREDIENTES[miIngrediente]+".\n\n");
        while ( true ){ 
            estanco.obtenerIngrediente( miIngrediente );
            aux.dormir_max( 2000 );
            System.out.println(thr.getName()+" termina de fumar.\n");
        }
    }
}

class Estanquero implements Runnable { 
    public Thread thr;
    private Estanco estanco;
    
    public Estanquero(Estanco estanco, String nombre){
        this.estanco = estanco;
        thr = new Thread(this,nombre);
    }
    
    public void run() { 
        int ingrediente ;
        while (true){
            ingrediente = (int) (Math.random () * Fumadores.NUM_FUM); // 0,1 o 2
            estanco.ponerIngrediente( ingrediente );
            estanco.esperarRecogidaIngrediente() ;
        }
    }
}

class Fumadores {
    public static int NUM_FUM;
    public final static String[] INGREDIENTES= {"TABACO","PAPEL","CERILLAS"};
    
    public static void main(String[] args){
        NUM_FUM = 3;
        //Creamos los vectores de hebras
        Fumador[] vfum = new Fumador[NUM_FUM];
        Estanquero est;

        //Creamos el monitor
        Estanco estanco = new Estanco();

        //Creamos las hebras
        for(int i = 0 ; i < vfum.length; i++)
            vfum[i] = new Fumador(i,estanco,"Fumador "+(i+1));
        est = new Estanquero(estanco,"Estanquero");
        
        //Lanzamos las hebras
        for (int i = 0; i < vfum.length; i++)
            vfum[i].thr.start();    
        est.thr.start();
    
    }
}
