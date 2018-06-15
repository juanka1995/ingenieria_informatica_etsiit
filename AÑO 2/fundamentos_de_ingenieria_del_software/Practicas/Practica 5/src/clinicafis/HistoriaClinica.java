/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clinicafis;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

/**
 *
 * @author juanka1995
 */
public class HistoriaClinica {
    
    public static int NumeroDeHistorias = 0;
    private Calendar fechaApertura;
    private int numeroHistoria;
    private List<AnotacionHC> anotaciones;
    
    HistoriaClinica(){
        fechaApertura = Calendar.getInstance();
        numeroHistoria = NumeroDeHistorias + 1;
        anotaciones = new ArrayList();
    }
    
    List obtenerDatosHistoriaClinica(){
        List datosHistoria = new ArrayList();
        datosHistoria.add(numeroHistoria);
        datosHistoria.add(fechaApertura);
        for (int i = 0; i < anotaciones.size(); i++) {
            List<String> datosAnotacion = anotaciones.get(i).obtenerDatos();
            datosHistoria.add(datosAnotacion);
        }
        return datosHistoria;
    }
    
    List<String> nuevoDiagnostico(String codDiagnostico, String TextoExplicativo, Medico medico){
        Diagnostico unDiagnostico = new Diagnostico(codDiagnostico, TextoExplicativo, medico);
        List<String> datosDiagnostico = unDiagnostico.obtenerDatos();
        anotaciones.add(unDiagnostico);
        return datosDiagnostico;
    } 
    
}
