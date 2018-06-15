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
public class SpecificBadConsequence extends BadConsequence {

    private ArrayList<TreasureKind> specificHiddenTreasures = new ArrayList();
    private ArrayList<TreasureKind> specificVisibleTreasures = new ArrayList();
    
    public SpecificBadConsequence(String text, int levels, 
            ArrayList<TreasureKind> tVisible, ArrayList<TreasureKind> tHidden) {
        super(text,levels);
        specificVisibleTreasures = tVisible;
        specificHiddenTreasures = tHidden;
    }
    
    @Override
    public boolean isEmpty(){
        return (specificHiddenTreasures.isEmpty() && specificVisibleTreasures.isEmpty());
    }
    
    public ArrayList<TreasureKind> getSpecificHiddenTreasures() {
        return specificHiddenTreasures;
    }

    public ArrayList<TreasureKind> getSpecificVisibleTreasures() {
        return specificVisibleTreasures;
    }
    
    @Override
    public void substractVisibleTreasure(Treasure t){
        if(specificVisibleTreasures.contains(t.getType()))
            specificVisibleTreasures.remove(t.getType());
    }
    
    @Override
    public void substractHiddenTreasure(Treasure t){
        if(specificHiddenTreasures.contains(t.getType()))
            specificHiddenTreasures.remove(t.getType());
    }
    
    @Override
    public SpecificBadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v, ArrayList<Treasure> h){
        SpecificBadConsequence nuevo;
        int nOneHand = 0;
        if (!specificHiddenTreasures.isEmpty() || !specificVisibleTreasures.isEmpty()){
            ArrayList<TreasureKind> v2 = new ArrayList();
            ArrayList<TreasureKind> h2 = new ArrayList();
            // Calculo el numero de ONEHAND ocultos
            for ( TreasureKind type:this.specificHiddenTreasures )
                if(type == TreasureKind.ONEHAND)
                    nOneHand++;
            for ( Treasure treasure:h ) {
                if(specificHiddenTreasures.contains(treasure.getType()) && treasure.getType() != TreasureKind.ONEHAND){
                    h2.add(treasure.getType());
                }
                else if (specificHiddenTreasures.contains(treasure.getType()) && treasure.getType() == TreasureKind.ONEHAND && nOneHand > 0){
                    h2.add(treasure.getType());
                    nOneHand--;
                }
            }
            nOneHand = 0;
            // Calculo el numero de ONEHAND visibles
            for ( TreasureKind type:this.specificVisibleTreasures )
                if(type == TreasureKind.ONEHAND)
                    nOneHand++;
            for ( Treasure treasure:v ) {
                if(specificVisibleTreasures.contains(treasure.getType()) && treasure.getType() != TreasureKind.ONEHAND){
                    v2.add(treasure.getType());
                }
                else if (specificVisibleTreasures.contains(treasure.getType()) && treasure.getType() == TreasureKind.ONEHAND && nOneHand > 0){
                    v2.add(treasure.getType());
                    nOneHand--;
                }
            }
            nuevo = new SpecificBadConsequence(super.getText(), super.getLevels(), v2, h2);
        }
        else{
            return this;
        }
        return nuevo;
    }
    
    @Override
    public String toString() {
        return super.toString() + "\nspecificHiddenTreasures: " + specificHiddenTreasures + "\nspecificVisibleTreasures: " + specificVisibleTreasures;
    }
}
