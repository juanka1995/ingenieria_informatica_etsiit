/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ohmydiet;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.swing.JOptionPane;

/**
 *
 * @author juanka1995
 */
public class Conectar {

    Connection connection = null;
    public static boolean conectado = false;

    public Conectar() {

    }
    
    public Connection conexion() throws SQLException{
        String url = "jdbc:mysql://localhost:3306/ohmydiet!?autoReconnect=true&useSSL=false";
        String user = "root";
        String pass = "ddsi2018";
        connection = DriverManager.getConnection(url, user,pass);
        
        if(connection.isClosed())
            connection = null;
        
        return connection;
    }
    
}
