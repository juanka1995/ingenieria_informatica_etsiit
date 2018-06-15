#encoding: utf-8
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require 'singleton.rb'
require_relative 'card_dealer.rb'
require_relative 'combat_result.rb'
require_relative 'monster.rb'
require_relative 'player.rb'
require_relative 'cultist_player.rb'

class Napakalaki
  include Singleton
  attr_reader :currentPlayer, :currentMonster
  
  def initialize
    @currentPlayer = nil
    @players = Array.new
    @dealer = CardDealer.instance
    @currentMonster = nil
  end
  
  def getCurrentPlayer
    @currentPlayer
  end
  
  def getCurrentMonster
    @currentMonster
  end
  
  def initPlayers(names)
    for n in names do
      jugador = Player.new(n)
      @players << jugador
    end
  end
  
  def nextPlayer
    if(@currentPlayer == nil ) then
      @currentPlayer = @players[rand(@players.size)]
    else
      @currentPlayer = @players[(@players.index(@currentPlayer)+1) % @players.size]
    end
    @currentPlayer
  end
  
  def nextTurnIsAllowed
    if(@currentPlayer == nil)
      return true
    else
      return @currentPlayer.validState
    end
  end
  
  def setEnemies
    i = rand(@players.size - 1) + 1
    for p in @players do
      p.enemy = @players[i]
      i = (i+1) % @players.size
    end
  end
  
  def developCombat
    cr = @currentPlayer.combat(@currentMonster)
    @dealer.giveMonsterBack(@currentMonster)
    if(cr == CombatResult::LOSEANDCONVERT)
      cultist = @dealer.nextCultist
      cp = CultistPlayer.new(@currentPlayer, cultist)
      
      #Cambiar de lista de jugadores
      i = @players.index(@currentPlayer)
      @players.delete_at(i)
      @players.insert(i,cp)
      
      #Cambiar de enemigos
      for p in @players do
        if (p.enemy == @currentPlayer)
          p.enemy = cp
        end
      end
      
      #Cambiar de currentPlayer
      @currentPlayer = cp
      
    end
    return cr
  end
  
  def discardVisibleTreasures(treasures)
    for t in treasures do
      @currentPlayer.discardVisibleTreasure(t)
      @dealer.giveTreasureBack(t)
    end
  end
  
  def discardHiddenTreasures(treasures)
    for t in treasures do
      @currentPlayer.discardHiddenTreasure(t)
      @dealer.giveTreasureBack(t)
    end
  end
  
  def makeTreasuresVisible(treasures)
    for t in treasures do
      @currentPlayer.makeTreasureVisible(t);
    end
  end
  
  def initGame(players)
    initPlayers(players)
    setEnemies
    @dealer.initCards
    nextTurn
  end
  
  def nextTurn
    stateOk = nextTurnIsAllowed
    if(stateOk) then
      @currentMonster = @dealer.nextMonster
      @currentPlayer = nextPlayer
      dead = @currentPlayer.isDead
      if(dead) then
        @currentPlayer.initTreasures
      end
    end
    stateOk
  end
  
  def endOfGame(result)
    result == CombatResult::WINGAME;
  end
  
  private :initPlayers, :nextPlayer, :nextTurnIsAllowed, :setEnemies
end
