/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author guillermo
 */
public class Napakalaki {
    //Atributos
    final private static Napakalaki instance = new Napakalaki();
    private Monster currentMonster;
    private CardDealer dealer;
    private ArrayList<Player> players;
    private Player currentPlayer;
    
    //Constructor
    private Napakalaki(){
        players = new ArrayList();
        dealer = CardDealer.getInstance();
    }
    
    //Métodos
    private void initPlayers(ArrayList<String> names){
        for(String name: names)
            players.add(new Player(name));
    }
    
    private Player nextPlayer(){
        Random rand = new Random();
        if(currentPlayer == null)
            currentPlayer = players.get(rand.nextInt(players.size()));
        else 
            currentPlayer = players.get(
                    (players.indexOf(currentPlayer)+1) % players.size()
            );
        return currentPlayer;
    }
    
    private boolean nextTurnIsAllowed(){
        if(currentPlayer == null)
            return true;
        else
            return currentPlayer.validState();
    }
    
    private void setEnemies(){
        Random rand = new Random();
        int i = rand.nextInt(players.size()-1)+1;
        for(Player p: players){
            p.setEnemy(players.get(i));
            i = (++i)%players.size();
        }
    }
    
    static public Napakalaki getInstance(){
        return instance;
    }
    
    public CombatResult developCombat(){
        CombatResult cr = currentPlayer.combat(currentMonster);
        if (cr == CombatResult.LOSEANDCONVERT) {
            CultistPlayer nuevo = new CultistPlayer(currentPlayer,dealer.nextCultist());
            for(Player p:players){
                if(p.getEnemy() == currentPlayer)
                    p.enemy = currentPlayer;
            }
            players.remove(currentPlayer);
            currentPlayer = nuevo;
            players.add(currentPlayer);
        }
        dealer.giveMonsterBack(currentMonster);
        return cr;        
    }
    
    public void discardVisibleTreasures(ArrayList<Treasure> treasures){
        for(Treasure t: treasures){
            currentPlayer.discardVisibleTreasure(t);
            dealer.giveTreasureBack(t);
        }
    }
    
    public void discardHiddenTreasures(ArrayList<Treasure> treasures){
        for(Treasure t: treasures){
            currentPlayer.discardHiddenTreasure(t);
            dealer.giveTreasureBack(t);
        }
    }
    
    public void makeTreasuresVisible(ArrayList<Treasure> treasures){
        for(Treasure t: treasures){
            currentPlayer.makeTreasureVisible(t);
        }
    }
    
    public void initGame(ArrayList<String> players){
        initPlayers(players);
        setEnemies();
        dealer.initCards();
        nextTurn();
    }
    
    public Player getCurrentPlayer(){
        return currentPlayer;
    }
    
    public Monster getCurrentMonster(){
        //TODO
        return currentMonster;
    }
    
    public boolean nextTurn(){
        boolean stateOk = nextTurnIsAllowed();
        if(stateOk){
            currentMonster = dealer.nextMonster();
            currentPlayer = nextPlayer();
            boolean dead = currentPlayer.isDead();
            if(dead)
                currentPlayer.initTreasures();
        }
        return stateOk;
    }
    
    public boolean endOfGame(CombatResult result){
        return result == CombatResult.WINGAME;
    }
}
