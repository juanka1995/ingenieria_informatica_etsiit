/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cyk;

import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author juanka1995
 */
public class CYK {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException { 
        String entrada = args[0];

        if(!entrada.isEmpty()){
            System.out.println("Ruta: " +args[0]);
        
            Gramatica miGramatica = new Gramatica(entrada);
            ArrayList<ArrayList<String>> miMatriz = new ArrayList<>();
            
            // Gramatica 1
//            String palabra = "aabbcd";
//            String palabra = "abbccd";
            // Gramatica 2
            String palabra = "baaba";
            // Gramatica 3
//            String palabra = "ababba";
            
            System.out.println("Gramatica a utilizar: ");
            miGramatica.showMapContent();

            inicializarMatriz(miMatriz, palabra);
            mostrarMatriz(miMatriz);

            if(algoritmoCYK(miMatriz, palabra,miGramatica))
                System.out.println("La palabra "+palabra+" SI PUEDE ser generada por la grámatica.");
            else
                System.out.println("La palabra "+palabra+" NO PUEDE ser generada por la grámatica.");
        }
        else{
            System.out.println("Numero de argumentos invalido, por favor pase la ruta del fichero con la gramática");
        }        
    }
    
    public static void inicializarMatriz(ArrayList<ArrayList<String>> miMatriz, String palabra){
        for (int i = 0; i < palabra.length(); i++) {
            ArrayList<String> elArray = new ArrayList<>();
            for (int j = 0; j < palabra.length()-i; j++) {
                elArray.add(null);
            }
            miMatriz.add(elArray);
        }
    }
    
    public static void inicializarMatriz_IG(ArrayList<ArrayList<String>> miMatriz, String palabra){
        for (int i = 0; i < palabra.length(); i++) {
            ArrayList<String> elArray = new ArrayList<>();
            for (int j = 0; j < palabra.length()-i; j++) {
                elArray.add("");
            }
            miMatriz.add(elArray);
        }
    }
    
    public static void mostrarMatriz(ArrayList<ArrayList<String>> miMatriz){
        for (int i=0; i < miMatriz.size();i++){
            for (int j=0; j < miMatriz.get(i).size(); j++){
                String unChat= miMatriz.get(i).get(j);
                System.out.print(unChat);
                if (j!=miMatriz.get(i).size()-1) {
                    System.out.print("\t");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
    
    public static boolean algoritmoCYK(ArrayList<ArrayList<String>> miMatriz, String palabra, Gramatica miGramatica){
        boolean pertenece = false;
        String values = new String();
        int n = miMatriz.size();
        
        // Primera fila
        for (int i = 0; i < palabra.length(); i++) {
            values = miGramatica.getValues(Character.toString(palabra.charAt(i)));
            miMatriz.get(0).set(i, values);
        }
        
        mostrarMatriz(miMatriz);
        
        // Resto

        for (int i = 1; i < n; i++) {
//            System.out.println("i: "+i);
            for (int j = 0; j < n-i; j++) {
//                System.out.println("i: "+i+"\tj: "+j);
//                System.out.println(miMatriz.get(i).get(j));
                values = "";
                for (int k = 0; k < i; k++) {
                    mostrarMatriz(miMatriz);
//                    System.out.println("k: "+k+"\tj: "+j);
//                    System.out.println("1: " + miMatriz.get(k).get(j) + " ["+k+"]["+j+"]");
//                    System.out.println("2: " + miMatriz.get(i-k-1).get(j+k+1) + " ["+(i-k-1)+"]["+(j+k+1)+"]");
                    String resultado = comprobarCombinaciones(miMatriz.get(k).get(j), miMatriz.get(i-k-1).get(j+k+1), miGramatica);
                    if((resultado == "0" && values.isEmpty()) || (values == "0" && resultado != "0") || (values == "0" && resultado == "0"))
                        values = resultado;
                    else if(resultado != "0"){
                        if(values.isEmpty())
                            values += resultado;
                        else
                            values = values.concat(" ".concat(resultado));
                    }
                }
                values = eliminarRepetidos(values);
                miMatriz.get(i).set(j, values);
                mostrarMatriz(miMatriz);
            }
        }
        
        if(miMatriz.get(n-1).get(0).contains("S"))
            pertenece = true;
       
        return pertenece;
    }
    
    private static ArrayList<ArrayList<String>> copyMatrix(ArrayList<ArrayList<String>> m){
        ArrayList<ArrayList<String>> new_m = new ArrayList<>();
        for(int i=0; i<m.size(); i++){
            new_m.add(new ArrayList<>());
            for (int j = 0; j < m.get(i).size(); j++) {
                new_m.get(i).add(m.get(i).get(j));
            }
        }
        return new_m;
    }
    
    public static boolean algoritmoCYK_IG(ArrayList<ArrayList<String>> miMatriz, String palabra, Gramatica miGramatica, ArrayList<ArrayList<ArrayList<String>>> vectorMatrices, ArrayList<ArrayList<Integer>> matrizIndices){
        boolean pertenece = false;
        String values = new String();
        int n = miMatriz.size();
        
        // Primera fila
        for (int i = 0; i < palabra.length(); i++) {
            values = miGramatica.getValues(Character.toString(palabra.charAt(i)));
            miMatriz.get(0).set(i, values);
        }
        
//        vectorMatrices.add(copyMatrix(miMatriz));
        
//        mostrarMatriz(vectorMatrices.get(0));
        
        // Resto

        int i, j, k;
        
        for (i = 1; i < n; i++) {
//            System.out.println("i: "+i);
            for (j = 0; j < n-i; j++) {
//                System.out.println("i: "+i+"\tj: "+j);
//                System.out.println(miMatriz.get(i).get(j));
                values = "";
                for (k = 0; k < i; k++) {
                    vectorMatrices.add(copyMatrix(miMatriz));
                    ArrayList<Integer> indices = new ArrayList<>();
                    indices.add(k);
                    indices.add(j);
                    indices.add(i-k-1);
                    indices.add(j+k+1);
                    indices.add(i);
                    indices.add(j);
                    matrizIndices.add(indices);
//                    System.out.println("k: "+k+"\tj: "+j);
//                    System.out.println("1: " + miMatriz.get(k).get(j) + " ["+k+"]["+j+"]");
//                    System.out.println("2: " + miMatriz.get(i-k-1).get(j+k+1) + " ["+(i-k-1)+"]["+(j+k+1)+"]");
                    String resultado = comprobarCombinaciones_IG(miMatriz.get(k).get(j), miMatriz.get(i-k-1).get(j+k+1), miGramatica, vectorMatrices, matrizIndices, indices, palabra);
                    if((resultado == "0" && values.isEmpty()) || (values == "0" && resultado != "0") || (values == "0" && resultado == "0"))
                        values = resultado;
                    else if(resultado != "0"){
                        if(values.isEmpty())
                            values += resultado;
                        else
                            values = values.concat(" ".concat(resultado));
                    }
                }
                values = eliminarRepetidos(values);
                miMatriz.get(i).set(j, values);
                vectorMatrices.add(copyMatrix(miMatriz));
                ArrayList<Integer> indices = new ArrayList<>();
                indices.add(k-1);
                indices.add(j);
                indices.add(i-k);
                indices.add(j+k);
                indices.add(i);
                indices.add(j);
                matrizIndices.add(indices);
            }
        }
        
        if(miMatriz.get(n-1).get(0).contains("S"))
            pertenece = true;
       
        return pertenece;
    }
    
    public static String comprobarCombinaciones_IG(String a, String b, Gramatica miGramatica, ArrayList<ArrayList<ArrayList<String>>> vectorMatrices, ArrayList<ArrayList<Integer>> matrizIndices, ArrayList<Integer> indices, String palabra){
        String values = "";
        String var1 = null, var2 = null;
        int numOfSpacesA, numOfSpacesB;
        numOfSpacesA = a.length() - a.replace(" ", "").length();
        for (int i = 0; i <= numOfSpacesA; i++) {
            if(numOfSpacesA == 0){
                var1 = a;
            }
            else{
                var1 = a.substring(0, a.indexOf(" "));
                a = a.substring(a.indexOf(" ")+1, a.length());
                numOfSpacesA--;
                i--;
            }
            numOfSpacesB = b.length() - b.replace(" ", "").length();
            for (int j = 0; j <= numOfSpacesB; j++) {
                if(numOfSpacesB == 0){
                    var2 = b;
                }
                else{
                    var2 = b.substring(0, b.indexOf(" "));
                    b = b.substring(b.indexOf(" ")+1, b.length());
                    numOfSpacesB--;
                    j--;
                }
                
                if(!miGramatica.getValues(var1.concat(var2)).isEmpty()){
                    values += miGramatica.getValues(var1.concat(var2)) + " ";
                    
                    ArrayList<ArrayList<String>> matrizAux = new ArrayList<>();
                    inicializarMatriz_IG(matrizAux, palabra);
                    
                    matrizAux.get(matrizIndices.get(matrizIndices.size()-1).get(0)).set(matrizIndices.get(matrizIndices.size()-1).get(1), var1);
                    matrizAux.get(matrizIndices.get(matrizIndices.size()-1).get(2)).set(matrizIndices.get(matrizIndices.size()-1).get(3), var2);

                    matrizAux.get(matrizIndices.get(matrizIndices.size()-1).get(4)).set(matrizIndices.get(matrizIndices.size()-1).get(5), values.substring(0,values.length()-1));
                    
                    vectorMatrices.add(matrizAux);
                    matrizIndices.add(matrizIndices.get(matrizIndices.size()-1));
                }
            }
        }
        if(values.isEmpty())
            values = "0";
        else{
            values = values.substring(0, values.length()-1);
        }
        return values;
    }
    
    public static String comprobarCombinaciones(String a, String b, Gramatica miGramatica){
        String values = "";
        String var1 = null, var2 = null;
        int numOfSpacesA, numOfSpacesB;
        numOfSpacesA = a.length() - a.replace(" ", "").length();
        for (int i = 0; i <= numOfSpacesA; i++) {
            if(numOfSpacesA == 0){
                var1 = a;
            }
            else{
                var1 = a.substring(0, a.indexOf(" "));
                a = a.substring(a.indexOf(" ")+1, a.length());
                numOfSpacesA--;
                i--;
            }
            numOfSpacesB = b.length() - b.replace(" ", "").length();
            for (int j = 0; j <= numOfSpacesB; j++) {
                if(numOfSpacesB == 0){
                    var2 = b;
                }
                else{
                    var2 = b.substring(0, b.indexOf(" "));
                    b = b.substring(b.indexOf(" ")+1, b.length());
                    numOfSpacesB--;
                    j--;
                }
                
                if(!miGramatica.getValues(var1.concat(var2)).isEmpty())
                    values += miGramatica.getValues(var1.concat(var2)) + " ";
            }
        }
        if(values.isEmpty())
            values = "0";
        else{
            values = values.substring(0, values.length()-1);
        }
        return values;
    }
    
    public static String eliminarRepetidos(String cadena){
        String salida = "";
        CharSequence caracter = "";
        int numOfSpaces = cadena.length() - cadena.replaceAll(" ", "").length();
        for (int i = 0; i <= numOfSpaces; i++) {
            if(numOfSpaces == 0){
                caracter = cadena;
            }
            else{
                caracter = cadena.substring(0,cadena.indexOf(" ")+1);
                cadena = cadena.substring(cadena.indexOf(" ")+1,cadena.length());
                numOfSpaces--;
                i--;
            }
            if(!salida.contains(caracter))
                salida += caracter;
        }
        return salida;
    }
    
    public static String ponerEspaciosEntreCaracteres(String cadena){
        return cadena.replaceAll(" +", " ");
    }
    
}
