/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

import java.util.ArrayList;

/**
 *
 * @author juanka1995
 */
public class NumericBadConsequence extends BadConsequence {

    private int nVisibleTreasures;
    private int nHiddenTreasures;
    
    public NumericBadConsequence(String text, int levels, int nVisible, int nHidden) {
        super(text,levels);
        nVisibleTreasures = nVisible;
        nHiddenTreasures = nHidden;
    }
    
    @Override
    public boolean isEmpty(){
        return (nVisibleTreasures == 0 && nHiddenTreasures == 0);
    }
    
    public int getNVisibleTreasures(){
        return nVisibleTreasures;
    }
    
    public int getNHiddenTreasures() {
        return nHiddenTreasures;
    }
    
    @Override
    public void substractVisibleTreasure(Treasure t){
        nVisibleTreasures = Math.max(0, nVisibleTreasures-1);
    }
    
    @Override
    public void substractHiddenTreasure(Treasure t){
        nHiddenTreasures = Math.max(0,nHiddenTreasures-1);
    }
    
    @Override
    public NumericBadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v, ArrayList<Treasure> h){
        return new NumericBadConsequence(super.getText(), super.getLevels(), Math.min(nVisibleTreasures, v.size()), Math.min(nHiddenTreasures, h.size()));
    }
    
    @Override
    public String toString() {
        return super.toString() + "\nnVisibleTreasures: " + nVisibleTreasures + "\nHiddenTreasures: " + nHiddenTreasures;
    }
}
