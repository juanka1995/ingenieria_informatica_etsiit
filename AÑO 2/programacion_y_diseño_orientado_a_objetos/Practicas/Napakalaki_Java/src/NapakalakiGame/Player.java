/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

import java.util.ArrayList;
import java.util.Random;
import GUI.Dice;

/**
 *
 * @author guillermo
 */
public class Player {
    final static int MAXLEVEL = 10;
    private String name;
    private int level;
    private boolean dead = true;
    private boolean canISteal = true;
    protected Player enemy;
    private ArrayList<Treasure> hiddenTreasures = new ArrayList();
    private ArrayList<Treasure> visibleTreasures = new ArrayList();
    private BadConsequence pendingBadConsequence;
    
    public Player(String name){
        this.name = name;
        this.level = 1;
    }
    
    public Player(Player p){
        this.name = p.name;
        this.level = p.level;
        this.dead = p.dead;
        this.canISteal = p.canISteal;
        this.enemy = p.enemy;
        this.hiddenTreasures = p.hiddenTreasures;
        this.visibleTreasures = p.visibleTreasures;
        this.pendingBadConsequence = p.pendingBadConsequence;
    }
    
    public String getName(){
        return name;
    }
    
    protected int getOponentLevel(Monster m){
        return m.getCombatLevel();
    }
    
    protected boolean shouldConvert(){
        boolean shouldconvert = false;
        Dice dice = Dice.getInstance();
        if (dice.nextNumber() == 6) {
            shouldconvert = true;
        }
        return shouldconvert;
    }
    
    public boolean isACultistPlayer(){
        return false;
    }
    
    private void bringToLife(){
        dead = false;
    }
    
    protected int getCombatLevel(){
        int flevel = level;
        for(Treasure t: visibleTreasures)
            flevel += t.getBonus();
        return flevel;
    }
    
    private void incrementLevel(int i){
        level = Math.min(level + i, MAXLEVEL);
    }
    
    private void decrementLevel(int i){
        level = Math.max(level-i,1);
    }
    
    private void setPendingBadConsequence(BadConsequence bc){
        pendingBadConsequence = bc;
        //Esto no pertenece al juego, está así por jugabilidad :)
        System.out.println(pendingBadConsequence.toString());
    }
    
    private void applyPrize(Monster m){
        int nLevels = m.getLevelsGained();
        incrementLevel(nLevels);
        int nTreasures = m.getTreasuresGained();
        if(nTreasures>0){
            CardDealer dealer = CardDealer.getInstance();
            for(int i=0; i<nTreasures; i++){
                Treasure treasure = dealer.nextTreasure();
                hiddenTreasures.add(treasure);
            }
        }
    }
    
    private void applyBadConsequence(Monster m){
        BadConsequence badConsequence = m.getBadConsequence();
        
        int nLevels = badConsequence.getLevels();
        decrementLevel(nLevels);
        BadConsequence pendingBad = badConsequence.adjustToFitTreasureLists(visibleTreasures, hiddenTreasures);
        setPendingBadConsequence(pendingBad);
    }
    
    private boolean canMakeTreasureVisible(Treasure t){
        boolean canMakeTreasureVisible = true;
        ArrayList<TreasureKind> types = new ArrayList();
        int hands = 0;
        
        for(Treasure treasure:visibleTreasures){
            types.add(treasure.getType());
            if(treasure.getType() == TreasureKind.ONEHAND)
                hands++;
            else if(treasure.getType() == TreasureKind.BOTHHANDS)
                hands += 2;
        }
        TreasureKind kind = t.getType();
        if(kind == TreasureKind.ONEHAND){
            hands++;
        }
        else if(kind == TreasureKind.BOTHHANDS){
            hands+=2;
        }

        if(types.contains(kind) && kind != TreasureKind.ONEHAND && kind != TreasureKind.BOTHHANDS){
            canMakeTreasureVisible = false;
        }
        else{
            canMakeTreasureVisible = true;
        }
        
        return canMakeTreasureVisible && (hands <=2);
    }
    
    private int howManyVisibleTreasures(TreasureKind tKind){
        int res = 0;
        for(Treasure r: visibleTreasures)
            if(r.getType() == tKind)
                res++;
        return res;
    }
    
    private void dieIfNoTreasures(){
        if(hiddenTreasures.isEmpty() && visibleTreasures.isEmpty())
            dead = true;
    }
    
    public boolean isDead(){return dead;}
    
    public ArrayList<Treasure> getHiddenTreasures(){return hiddenTreasures;} //Hay que confirmar esto
    
    public ArrayList<Treasure> getVisibleTreasures(){return visibleTreasures;} //Hay que confirmar esto
    
    public CombatResult combat(Monster m){
        int myLevel = getCombatLevel();
        int oponentLevel = getOponentLevel(m);
        CombatResult cr;
        if(!canISteal){
            Dice dice = Dice.getInstance();
            int number = dice.nextNumber();
            if(number<3){
                int enemyLevel = enemy.getCombatLevel();
                oponentLevel += enemyLevel;
            }
        }
        if(myLevel>oponentLevel){
            applyPrize(m);
            cr=(this.level >= MAXLEVEL)?CombatResult.WINGAME:CombatResult.WIN;
        }
        else{
            applyBadConsequence(m);
            cr=CombatResult.LOSE;
            if(shouldConvert())
                cr = CombatResult.LOSEANDCONVERT;
        }
        return cr;
    }
    
    public void makeTreasureVisible(Treasure t){
        boolean canI = canMakeTreasureVisible(t);
        if(canI){
            visibleTreasures.add(t);
            hiddenTreasures.remove(t);
        }
    }
    
    public void discardVisibleTreasure(Treasure t){
        visibleTreasures.remove(t);
        if((pendingBadConsequence != null) && !pendingBadConsequence.isEmpty())
            pendingBadConsequence.substractVisibleTreasure(t);
        dieIfNoTreasures();
    }
    
    public void discardHiddenTreasure(Treasure t){
        hiddenTreasures.remove(t);
        if((pendingBadConsequence != null) && !pendingBadConsequence.isEmpty())
            pendingBadConsequence.substractHiddenTreasure(t);
        dieIfNoTreasures();
    }
    
    public boolean validState(){
        return (hiddenTreasures.size() < 5 && (pendingBadConsequence == null || pendingBadConsequence.isEmpty()));
    }
    
    public void initTreasures(){
        CardDealer dealer = CardDealer.getInstance();
        Dice dice = Dice.getInstance();
        bringToLife();
        //Primer tesoro
        hiddenTreasures.add(dealer.nextTreasure());
        int number = dice.nextNumber();
        //Segundo tesoro
        if(number>1)
            hiddenTreasures.add(dealer.nextTreasure());
        //Tercer tesoro
        if(number==6)
            hiddenTreasures.add(dealer.nextTreasure());
    }
    
    public int getLevels(){
        return level;
    }
    
    public Treasure stealTreasure(){
        Treasure treasure = null;
        boolean canI = canISteal();
        if(canI){
            boolean canYou = enemy.canYouGiveMeATreasure();
            if(canYou){
                treasure = enemy.giveMeATreasure();
                hiddenTreasures.add(treasure);
                haveStolen();
            }
        }
        return treasure;
    }
    
    public void setEnemy(Player enemy){
        this.enemy = enemy;
    }
    
    private Treasure giveMeATreasure(){
        int n = hiddenTreasures.size();
        Random rand = new Random();
        return hiddenTreasures.get(rand.nextInt(n));
    }
    
    public boolean canISteal(){
        return canISteal;
    }
    
    private boolean canYouGiveMeATreasure(){
        return !hiddenTreasures.isEmpty();
    }
    
    private void haveStolen(){
        canISteal = false;
    }
    
    public void discardAllTreasures(){
        ArrayList<Treasure> cVisibleTreasures = new ArrayList(visibleTreasures);
        ArrayList<Treasure> cHiddenTreasures = new ArrayList(hiddenTreasures);
        for(Treasure t:cVisibleTreasures)
            discardVisibleTreasure(t);
        for(Treasure t:cHiddenTreasures)
            discardHiddenTreasure(t);
    }
    
    public String getEnemyName(){
        return enemy.getName();
    }

    protected Player getEnemy(){
        return enemy;
    }

    public BadConsequence getPendingBadConsequence() {
        return pendingBadConsequence;
    }
    
    @Override
    public String toString() {
        return name + ":\n nivel=" + level + ", nivel de combate= " + getCombatLevel() + ", muerto=" + dead + ", enemigo=" + enemy.name;
    }


}
