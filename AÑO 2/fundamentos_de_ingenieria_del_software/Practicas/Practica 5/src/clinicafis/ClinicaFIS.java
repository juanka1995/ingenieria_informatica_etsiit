/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clinicafis;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * @author ana anaya
 */
public class ClinicaFIS {
    // patrón singleton
    private static ClinicaFIS instancia = new ClinicaFIS();
    public static ClinicaFIS getInstance() { 
        return instancia;
    }
    
    // Map en el que se guardan los médicos, la key es el dni del médico
    private Map<String, Medico> misMedicos = new HashMap();
    // Map en el que se guardan los pacientes, la key es el dni del paciente
    private Map<String, Paciente> misPacientes = new HashMap();
     
    
    public void nuevoMedico(String dni,String nombre,String especialidad) throws Exception{
        if(existeMedico(dni)) throw new Exception("YA EXISTE UN MÉDICO CON ESE DNI");
        misMedicos.put(dni, new Medico(dni,nombre,especialidad));
    }     

    private boolean existeMedico(String dni) {
         return misMedicos.containsKey(dni);
    }
    
    public void definirAgenda(String dniM,int aPartirDe) throws Exception { 
         Medico unMedico = buscarMedico(dniM);
         unMedico.definirAgenda(aPartirDe);
    }

    private Medico buscarMedico(String dni) throws Exception {
       if(!existeMedico(dni)) throw new  Exception("NO EXISTE EL MÉDICO CON ESE DNI"); 
       return misMedicos.get(dni);
    }

    public List<String> consultarAgenda(String dniM,int numeroDias) throws Exception { 
        Medico unMedico = buscarMedico(dniM);
        return unMedico.obtenerCitas(numeroDias);
    }
    
    public List<String> todosLosMedico(){
        List<String> salida = new ArrayList();
        for (Map.Entry<String, Medico> entry : misMedicos.entrySet()) {            
            Medico unMedico = entry.getValue();
            salida.add(unMedico.toString());
        }
        return salida;
    }
   
    public void crearPaciente(String dni, String nombre, String numeroTarjeta, String telefono) throws Exception{
        boolean existe;
        existe = existePaciente(dni);
        if(existe) throw new  Exception("Ya existe otro paciente con ese dni");
        existe = existePacienteConTarjeta(numeroTarjeta);
        if(existe) throw new Exception("Ya existe otro paciente con ese numero de tarjeta");
        Paciente unPaciente = new Paciente(dni,nombre,numeroTarjeta,telefono);
        misPacientes.put(dni, unPaciente);
    }
    
    public List<String> consultarPaciente(String dni) throws Exception{
        Paciente paciente = buscarPaciente(dni);
        List<String> infoPaciente = paciente.obtenerDatos();
        return infoPaciente;
    }
    
    public List consultarDatosClinicos(String dni) throws Exception{
        Paciente paciente = buscarPaciente(dni);
        List infoPaciente = paciente.obtenerDatosClinicos();
        return infoPaciente;
    }
    
    public List<String> eliminarPaciente(String dni) throws Exception{
        Paciente paciente = buscarPaciente(dni);
        List<String> infoBajaClinica = paciente.bajaClinica();
        return infoBajaClinica;
    }
    
    public List anularCita(String dni, Calendar fecha) throws Exception{
        Paciente paciente = buscarPaciente(dni);
        List datosConfirmacion = paciente.anularCita(fecha);
        return datosConfirmacion;
    }
    
    public List consultarCitas(String dni) throws Exception{
        Paciente paciente = buscarPaciente(dni);
        List<String> listadoCitas = paciente.consultarCitas();
        return listadoCitas;
    }
    
    public List diagnosticar(String dniP, String codDiagnostico, String textoExplicativo, String dniM) throws Exception{
        Medico medico = buscarMedico(dniM);
        Paciente paciente = buscarPaciente(dniP);
        List infoPaciente = paciente.diagnostico(codDiagnostico, textoExplicativo, Calendar.getInstance(), medico);
        return infoPaciente;
    }
    
    public List<Calendar> obtenerPosiblesCitas(String dniM, String dniP) throws Exception{
        Medico medico = buscarMedico(dniM);
        Paciente paciente = buscarPaciente(dniP);
        boolean tienesCita = paciente.tienesCitas(medico);
        if(tienesCita) throw new Exception("Ya tienes cita PENDIENTE para ese medico");
        List<Calendar> listaPosiblesFechas = medico.obtenerPosiblesCitas();
        return listaPosiblesFechas;
    }
    
    public List<String> pedirCita(String dniP, String dniM, Calendar fecha) throws Exception{
        Medico medico = buscarMedico(dniM);
        Paciente paciente = buscarPaciente(dniP);
        List<String> infoCita = medico.asignarCita(paciente, fecha);
        return infoCita;
    }
    
    public void terminarConsulta(String dniM, String dniP) throws Exception{
        Medico medico = buscarMedico(dniM);
        Paciente paciente = buscarPaciente(dniP);
        medico.terminarConsulta(paciente);
    }
    
    private Paciente buscarPaciente(String dni) throws Exception{
       boolean encontrado = false;
       Paciente pacienteBuscado = new Paciente();
       for (int i = 0; i < misPacientes.size() && !encontrado; i++) {
           pacienteBuscado = misPacientes.get(i);
           if(pacienteBuscado.getDni().equals(dni))
               encontrado = true;
       }
       if(!encontrado) throw new Exception("No existe un paciente con ese dni");
       return pacienteBuscado;
    }
    
    private boolean existePaciente(String dni){
        boolean encontrado = false;
        Paciente pacienteBuscado = new Paciente();
        for (int i = 0; i < misPacientes.size() && !encontrado; i++) {
            pacienteBuscado = misPacientes.get(i);
            if(pacienteBuscado.getDni().equals(dni))
              encontrado = true;
        }
        return encontrado;
    }
    
    private boolean existePacienteConTarjeta(String numeroTarjeta) throws Exception{
       boolean encontrado = false;
       Paciente pacienteBuscado = new Paciente();
       for (int i = 0; i < misPacientes.size() && !encontrado; i++) {
           pacienteBuscado = misPacientes.get(i);
           if(pacienteBuscado.getNumeroTarjeta().equals(numeroTarjeta))
               encontrado = true;
       }
       return encontrado;
    }
    
}
