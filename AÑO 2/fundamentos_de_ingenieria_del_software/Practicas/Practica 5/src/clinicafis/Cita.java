/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clinicafis;

import java.lang.reflect.Array;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

/**
 *
 * @author ana anaya
 */
class Cita {
    private static int TiempoDeCita = 10; // variable de ámbito de clase que indica el tiempo que tiene asignado cada cita
    private Calendar fecha;
    private TipoEstado estado = TipoEstado.LIBRE;   
    private Medico miMedico;
    private Paciente paciente;
    
    Cita(){}
    
    // A partir del número de cita de esa fecha se calcula la hora de la cita
    // a cada cita se le reservan 10 minutos
    Cita(Calendar fecha, int numeroCita, Medico medico) { 
        this.fecha =(Calendar) fecha.clone();
        this.fecha.set(Calendar.HOUR,9);
        this.fecha.set(Calendar.MINUTE,0);
        this.fecha.add(fecha.MINUTE,numeroCita*TiempoDeCita);
        this.miMedico = medico;
        this.paciente = null;
    }
    
    void liberarCita(){
        modificarEstado(TipoEstado.LIBRE);
    }
    
    List<String> anularCita() throws Exception{
        if(fecha.after(Calendar.getInstance()) || estado == TipoEstado.ATENDIDA) throw new  Exception("La cita no puede ser cancelada"); 
        liberarCita();
        String nombreMedico = miMedico.obtenerNombre();
        List datosAnulacion = new ArrayList();
        datosAnulacion.add(fecha.toString());
        datosAnulacion.add(nombreMedico);
        return datosAnulacion;
    }
    
    List<String> obtenerDatos(){
        String nombreMedico = miMedico.obtenerNombre();
        String especialidad = miMedico.obtenerEspecialidad();
        List datosCita = new ArrayList();
        datosCita.add(Calendar.getInstance().toString());
        datosCita.add(nombreMedico);
        datosCita.add(especialidad);
        return datosCita;
    }
    
    Calendar obtenerFecha(){
        return fecha;
    }
    
    void asignarPaciente(Paciente paciente){
        modificarEstado(TipoEstado.PENDIENTE);
        paciente.incluirCita(this);
        this.paciente = paciente;
    }
    
    boolean esTuPaciente(Paciente paciente){
        return this.paciente.equals(paciente);
    }
    
    void modificarEstado(TipoEstado estado){
        this.estado = estado;
    }
    
    public Medico getMedico(){
        return miMedico;
    }
    
    public TipoEstado getEstado(){
        return estado;
    }
    
    // Redefinición de toString, cuando la cita tenga asignado el Paciente 
    // tendrás que quitar los comentarios que hay en este código
    @Override
    public String toString()
     {
          SimpleDateFormat hmsf = new SimpleDateFormat("hh:mm");
          String salida =  "hora: " + hmsf.format(fecha.getTime()) +" (" + estado.toString()+ ")";
//          if (miPaciente != null)
//              salida += "Paciente: " + miPaciente.getNombre();
          salida +=  "\n";
          return salida;
     }
    
}
