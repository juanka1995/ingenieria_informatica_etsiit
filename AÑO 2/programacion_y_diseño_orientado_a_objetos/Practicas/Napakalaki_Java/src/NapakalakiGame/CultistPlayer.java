/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

import java.util.Random;

/**
 *
 * @author juanka1995
 */
public class CultistPlayer extends Player{
    private static int totalCultistPlayers = 0;
    private Cultist myCultistCard;
    
    public CultistPlayer(Player p, Cultist c){
        super(p);
        totalCultistPlayers++;
        this.myCultistCard = c;
    }
    
    @Override
    protected int getCombatLevel(){
        return (int) (super.getCombatLevel() + 0.7*super.getCombatLevel() + myCultistCard.getGainedLevels()*getTotalCultistPlayers());
    }
    
    @Override
    protected int getOponentLevel(Monster m){
        return m.getCombatLevelAgainstCultistPlayer();
    }
    
    @Override
    protected boolean shouldConvert(){
        return false;
    }
    
    @Override
    public boolean isACultistPlayer(){
        return true;
    }
    
    private Treasure giveMeATreasure(){
        Random rand = new Random();
        return this.getVisibleTreasures().get(rand.nextInt(getVisibleTreasures().size())+1);
    }
    
    private boolean canYouGiveMeATreasure(){
        return this.getEnemy().getVisibleTreasures().isEmpty();
    }
    
    public int getTotalCultistPlayers(){
        return totalCultistPlayers;
    }    
    
}
