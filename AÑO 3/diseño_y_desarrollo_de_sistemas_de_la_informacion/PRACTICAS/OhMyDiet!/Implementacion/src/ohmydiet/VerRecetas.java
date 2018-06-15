/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ohmydiet;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author juanka1995
 */
public final class VerRecetas extends javax.swing.JFrame {

    DefaultTableModel model;
    String idDieta = null;
    ArrayList<String> id_recetas, ingredientesRecetas;
    ArrayList<ArrayList<String>> ids_ingredientes;
    
    /**
     * Creates new form VerRecetas
     * @param id
     * @throws java.sql.SQLException
     */
    public VerRecetas(String id) throws SQLException {
        this.id_recetas = new ArrayList();
        this.ingredientesRecetas = new ArrayList();
        this.ids_ingredientes = new ArrayList<>();
        initComponents();
        this.setLocationRelativeTo(null);
        idDieta = id;
        this.setTitle("Recetas de la dieta "+id);
        rellenarTablaConRecetasEIngredientes();
    }

    private VerRecetas() {
        this.id_recetas = new ArrayList();
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    public void rellenarTablaConRecetasEIngredientes() throws SQLException{
        // Calcular las recetas que tiene la dieta
        String sql = "SELECT * FROM asignar WHERE id_dieta=\"" + idDieta + "\"";
        Conectar cc = new Conectar();
        Connection cn = cc.conexion();
        
        try{
            Statement st = cn.createStatement();
            ResultSet rs  = st.executeQuery(sql);
            
            while(rs.next()){
                id_recetas.add(rs.getString("id_receta"));
            }

        } catch (SQLException ex){
            JOptionPane.showMessageDialog(null, "Error en la conexión.\n"+ex);
        }    
        
        // Calcular los ingredientes que tienen las recetas
        for (int i = 0; i < id_recetas.size(); i++) {
            ArrayList<String> nuevo = new ArrayList<>();
            sql = "SELECT * FROM compuesta WHERE id_receta=\"" + id_recetas.get(i) + "\"";
            
            try{
                Statement st = cn.createStatement();
                ResultSet rs  = st.executeQuery(sql);

                
                while(rs.next()){
                    nuevo.add(rs.getString("id_ingrediente"));
                }

            } catch (SQLException ex){
                JOptionPane.showMessageDialog(null, "Error en la conexión.\n"+ex);
            }
            
            ids_ingredientes.add(nuevo);
        }
        
        // Calcular los nombres de los ingredientes
        for (int i = 0; i < ids_ingredientes.size(); i++) {
            String aux = "";
            for (int j = 0; j < ids_ingredientes.get(i).size(); j++) {
                sql = "SELECT * FROM ingrediente WHERE id_ingrediente=\"" + ids_ingredientes.get(i).get(j) + "\"";
                
                try{
                    Statement st = cn.createStatement();
                    ResultSet rs  = st.executeQuery(sql);

                    while(rs.next()){
                        aux += rs.getString("nombre")+", ";
                    }
                    
                    
                } catch (SQLException ex){
                    JOptionPane.showMessageDialog(null, "Error en la conexión.\n"+ex);
                }
            }
            aux = aux.substring(0,aux.length()-1);
            ingredientesRecetas.add(aux);
        }
        
        // Escribir los datos en la tabla
        String [] titulos = {"Nombre","Descripción","Ingredientes"};
        String [] registros = new String[3];
        
        model = new DefaultTableModel(null, titulos);
        
        for (int i = 0; i < id_recetas.size(); i++) {
            sql = "SELECT * FROM receta WHERE id_receta=\"" + id_recetas.get(i) + "\"";
            
            try{
                Statement st = cn.createStatement();
                ResultSet rs  = st.executeQuery(sql);

                while(rs.next()){
                registros[0]=rs.getString("titulo");
                registros[1]=rs.getString("descripcion");
                registros[2]=ingredientesRecetas.get(i);
                model.addRow(registros);
                }

                jTable1.setModel(model);
            } catch (SQLException ex){
                JOptionPane.showMessageDialog(null, "Error en la conexión.\n"+ex);
            } 
        }
    }

    public void limpiarTabla(){
        String [] titulos = {};
        
        model = new DefaultTableModel(null, titulos);
        
        jTable1.setModel(model);
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();

        jLabel1.setText("jLabel1");

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {},
                {},
                {},
                {}
            },
            new String [] {

            }
        ));
        jScrollPane1.setViewportView(jTable1);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 771, Short.MAX_VALUE)
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 329, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(VerRecetas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VerRecetas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VerRecetas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VerRecetas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new VerRecetas().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable jTable1;
    // End of variables declaration//GEN-END:variables
}
