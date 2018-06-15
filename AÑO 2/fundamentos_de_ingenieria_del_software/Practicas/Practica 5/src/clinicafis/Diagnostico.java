/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clinicafis;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

/**
 *
 * @author juanka1995
 */
public class Diagnostico extends AnotacionHC{
    
    String codDiagnostico;

    Diagnostico(String codDiagnostico, String textoExplicativo, Medico medico) {
        super(textoExplicativo,medico);
        this.codDiagnostico = codDiagnostico;
    }
    
    @Override
    List<String> obtenerDatos(){
        String nombreMedico = super.getMedico().obtenerNombre();
        List<String> datosAnotacion = new ArrayList();
        datosAnotacion.add(Calendar.getInstance().toString());
        datosAnotacion.add(super.getComentario());
        datosAnotacion.add(nombreMedico);
        return datosAnotacion;
    }
    
}
