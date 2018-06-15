/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

/**
 *
 * @author guillermogotre
 */
public class Treasure {
    //public static final int MAX_TREASURES = 5;
    private String name;
    private int bonus;
    private TreasureKind type;
    
    public Treasure(String n, int bonus, TreasureKind t){
        name = n;
        this.bonus = bonus;
        type = t;
    }
    public String getName(){return name;}
    
    public int getBonus(){return bonus;}
    
    public TreasureKind getType(){return type;}

    @Override
    public String toString() {
        return "Treasure{" + "name=" + name + ", bonus=" + bonus + ", type=" + type + '}';
    }
    
}
