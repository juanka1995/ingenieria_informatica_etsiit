/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package InterfazGrafica;
import java.awt.*;
import javax.swing.*;
import javax.swing.table.*;

/**
 *
 * @author juanka1995
 */
public class MyRender extends DefaultTableCellRenderer{
    String palabra;
    int i1, j1;
    int i2, j2;
    int ires, jres;
    
    public MyRender(String palabra){
        this.palabra = palabra;
        i1=j1=i2=j2=ires=jres-1;
    }
    
    public void setIndices(int i1, int j1, int i2, int j2, int ires, int jres){
        this.i1 = i1;
        this.j1 = j1;
        
        this.i2 = i2;
        this.j2 = j2;
        
        this.ires = ires;
        this.jres = jres;
    }
    
    @Override
    public Component getTableCellRendererComponent(JTable table, Object value, boolean Selected, boolean hasFocus, int row, int col){
        JLabel cell = (JLabel) super.getTableCellRendererComponent(table, value, Selected, hasFocus, row, col);

        // Dentro de la matriz triangular
        if(col<palabra.length()-row){
            if((row == i1 && col == j1) || (row == i2 && col == j2)){
                cell.setBackground(new Color(37,135,2));
                cell.setForeground(Color.WHITE);
            }
            else if(row == ires && col == jres){
                cell.setBackground(Color.RED);
                cell.setForeground(Color.WHITE);
            }
            else{
                cell.setBackground(Color.WHITE);
                cell.setForeground(Color.BLACK);
            }
        }
        else{
            cell.setBackground(Color.WHITE);
            cell.setForeground(Color.BLACK);
        }

     return this;

    }

}
