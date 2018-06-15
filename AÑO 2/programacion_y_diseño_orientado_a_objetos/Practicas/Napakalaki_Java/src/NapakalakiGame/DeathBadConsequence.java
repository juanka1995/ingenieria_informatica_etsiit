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
public class DeathBadConsequence extends NumericBadConsequence{
    
    private boolean death;
    
    public DeathBadConsequence (String text, boolean death){
        super(text,Player.MAXLEVEL,MAXTREASURES,MAXTREASURES);
        this.death = death;
    }
    
    public boolean isDeath() {
        return death;
    }
    
    @Override
    public NumericBadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v, ArrayList<Treasure> h){
        return super.adjustToFitTreasureLists(v,h);
    }
    
    @Override
    public String toString() {
        return super.toString() +  "\ndeath:"  + death;
    }
}
