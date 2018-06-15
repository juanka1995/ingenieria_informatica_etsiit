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
public class Monster {
    private String name;
    private int combatLevel;
    private Prize prize;
    private BadConsequence badConsequence;
    private int levelChangeAgainstCultistPlayer = 0;
    
    public Monster(String name, int level, BadConsequence bc, Prize prize){
        this.name = name;
        this.combatLevel = level;
        this.badConsequence = bc;
        this.prize = prize;
    }
    
    public Monster(String n,int l, BadConsequence badConsequence, Prize p, int IC){
        this.name = n;
        this.combatLevel = l;
        this.badConsequence = badConsequence;
        this.prize = p;
        this.levelChangeAgainstCultistPlayer = IC;
    }
    
    public int getCombatLevelAgainstCultistPlayer(){
        return getCombatLevel() + levelChangeAgainstCultistPlayer;
    }

    public String getName() {
        return name;
    }

    public int getCombatLevel() {
        return combatLevel;
    }

    public Prize getPrize() {
        return prize;
    }

    public BadConsequence getBadConsequence() {
        return badConsequence;
    }
    
    public int getLevelsGained(){
        return prize.getLevel();
    }
    
    public int getTreasuresGained(){
        return prize.getTreasures();
    }

    @Override
    public String toString() {
        return "Monster{" + "name=" + name + ", combatLevel=" + (combatLevel + this.levelChangeAgainstCultistPlayer) + ", prize=" + prize + ", badConsequence=" + badConsequence + '}';
    }
    
}
