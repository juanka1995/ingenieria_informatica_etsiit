/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

import java.util.ArrayList;

/**
 *
 * @author guillermogotre
 */
public abstract class BadConsequence {
    final static int MAXTREASURES = 10;
    private String text;
    private int levels;     
    
    public BadConsequence(String text, int levels){
        this.text = text;
        this.levels = levels;
    }
    
    public abstract boolean isEmpty();
    
    public String getText() {
        return text;
    }

    public int getLevels() {
        return levels;
    }
    
    public abstract void substractVisibleTreasure(Treasure t);
    
    public abstract void substractHiddenTreasure(Treasure t);
    
    public abstract BadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v, ArrayList<Treasure> h);

    @Override
    public String toString() {
        return text + "\nlevels: " + levels;
    }
    
    
}
