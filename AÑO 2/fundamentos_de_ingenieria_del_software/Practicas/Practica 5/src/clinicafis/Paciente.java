/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clinicafis;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 *
 * @author juanka1995
 */
public class Paciente {
    
    private String dni;
    private String nombre;
    private String numeroTarjeta;
    private String telefono;
    private boolean activo;
    private HistoriaClinica historiaClinica;
    private List<Cita> citasPaciente;
    
    Paciente(){}
    
    Paciente(String dni, String nombre, String numeroTarjeta, String telefono){
        this.dni = dni;
        this.nombre = nombre;
        this.numeroTarjeta = numeroTarjeta;
        this.telefono = telefono;
        activo = true;
        historiaClinica = new HistoriaClinica();
        HistoriaClinica.NumeroDeHistorias++;
        citasPaciente = new ArrayList();
    }
    
    List<String> obtenerDatos(){
        List<String> infoPaciente = new ArrayList();
        infoPaciente.add(dni);
        infoPaciente.add(nombre);
        infoPaciente.add(numeroTarjeta);
        infoPaciente.add(telefono);
        return infoPaciente;
    }
    
    List obtenerDatosClinicos(){
        List infoPaciente = new ArrayList();
        infoPaciente.add(nombre);
        List datosHistoria = historiaClinica.obtenerDatosHistoriaClinica();
        infoPaciente.add(datosHistoria);
        return infoPaciente;
    }
    
    List<String> bajaClinica(){
        List<String> infoBajaClinica = new ArrayList();
        for (int i = 0; i < citasPaciente.size(); i++) {
            Cita cita = citasPaciente.get(i);
            cita.liberarCita();
            modificarActivo(false);
            infoBajaClinica.add(dni);
            infoBajaClinica.add(nombre);
        }
        return infoBajaClinica;
    }
    
    List anularCita(Calendar fecha) throws Exception{
        Cita cita = buscarCita(fecha);
        List datosAnulacion = cita.anularCita();
        List datosConfimacion = new ArrayList();
        datosConfimacion.add(nombre);
        datosConfimacion.add(datosAnulacion);
        citasPaciente.remove(cita);
        return datosConfimacion;
    }
    
    List consultarCitas(){
        Cita cita;
        List listadoCitas = new ArrayList();
        for (int i = 0; i < citasPaciente.size(); i++) {
            cita = citasPaciente.get(i);
            if(cita.getEstado() == TipoEstado.PENDIENTE){
                List datosCita = cita.obtenerDatos();
                listadoCitas.add(datosCita);
            }
        }
        return listadoCitas;
    }
    
    List diagnostico(String codDiagnostico, String textoExplicativo, Calendar fechaActual, Medico medico){
        List infoDiagnostico = new ArrayList();
        infoDiagnostico.add(nombre);
        List<String> datosDiagnostico = historiaClinica.nuevoDiagnostico(codDiagnostico, textoExplicativo, medico);
        infoDiagnostico.add(datosDiagnostico);
        return infoDiagnostico;
    }
    
    boolean tienesCitas(Medico medico){
        List<Cita> citas = seleccionarCitasPosteriores(Calendar.getInstance());
        boolean tienesCita = false;
        for (int i = 0; i < citas.size() && !tienesCita; i++) {
           Cita cita = citas.get(i);
           if(cita.getMedico().equals(medico))
               tienesCita = true;
        }
        return tienesCita;
    }
    
    String obtenerNombre(){
        return nombre;
    }
    
    void incluirCita(Cita cita){
        citasPaciente.add(cita);
    }
    
    private List<Cita> seleccionarCitasPosteriores(Calendar fecha){
       List<Cita> citasPosteriores = new ArrayList();
        for (int i = 0; i < citasPaciente.size(); i++) {
            Cita cita = citasPaciente.get(i);
            if(cita.obtenerFecha().after(fecha)){
                citasPosteriores.add(cita);
            }
        }
       return citasPosteriores;
    }
    
    private Cita buscarCita(Calendar fecha) throws Exception{
        boolean encontrada = false;
        Cita cita = new Cita();
        for (int i = 0; i < citasPaciente.size() && !encontrada; i++) {
            cita = citasPaciente.get(i);
            if(cita.obtenerFecha().equals(fecha)){
                encontrada = true;
            }
        }
        if(!encontrada) throw new Exception("No existe una cita para ese paciente en esa fecha");
        return cita;
    }
    
    private void modificarActivo(boolean activo){
        this.activo = activo;
    }
 
    public String getDni(){
        return dni;
    }
    
    public String getNumeroTarjeta(){
        return numeroTarjeta;
    }
    
}
