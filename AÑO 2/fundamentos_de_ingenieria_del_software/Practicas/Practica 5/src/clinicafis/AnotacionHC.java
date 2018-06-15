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
public abstract class AnotacionHC {
    
    private Calendar fecha;
    private String comentario;
    private Medico medico;

    AnotacionHC(String textoExplicativo, Medico medico) {
        comentario = textoExplicativo;
        this.medico = medico;
        fecha = Calendar.getInstance();
    }
    
    abstract List<String> obtenerDatos();      
    
    public Medico getMedico(){
        return medico;
    }
    
    public Calendar getFecha(){
        return fecha;
    }
    
    public String getComentario(){
        return comentario;
    }
    
}
