#encoding: utf-8
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'dice.rb'
require_relative 'bad_consequence.rb'
require_relative 'treasure.rb'
require_relative 'combat_result.rb'
require_relative 'card_dealer.rb'

class Player
  
  attr_reader :name, :hiddenTreasures, :visibleTreasures, :level, :canISteal
  attr_writer :enemy, :pendingBadConsequence
  @@MAX_LEVEL = 10
  
  def initialize(name)
    @name = name
    @level = 1
    @dead = true
    @canISteal = true
    @hiddenTreasures = Array.new
    @visibleTreasures = Array.new
    @enemy = nil
    @pendingBadConsequence = Array.new
  end
  
  def getHiddenTreasures
    @hiddenTreasures
  end
  
  def getVisibleTreasures
    @visibleTreasures
  end
  
  def maxLevel
    @@MAX_LEVEL
  end
  
  def self.maxLevel
    @@MAX_LEVEL
  end
  
  def bringToLife
    @dead = false
  end
  
  def combatLevel
    bonus = 0
    @visibleTreasures.each do |i|
      bonus = bonus + i.bonus
    end
    (@level + bonus)
  end
  
  def incrementLevels(l)
    @level = [@level + l,@@MAX_LEVEL].min
  end
  
  def decrementLevels(l)
    @level = [@level - l,1].max
  end
  
  def applyPrize(m)
    nLevels = m.getLevelsGained
    incrementLevels(nLevels)
    nTreasures = m.getTreasuresGained
    if(nTreasures > 0)
      dealer = CardDealer.instance
      for i in 1..nTreasures do
        treasure = dealer.nextTreasure
        @hiddenTreasures << treasure
      end
    end
  end
  
  def applyBadConsequence(m)
    badConseq = m.badConsequence
    nLevels = badConseq.levels
    decrementLevels(nLevels)
    pendingBad = badConseq.adjustToFitTreasureLists(@visibleTreasures,@hiddenTreasures)
    puts pendingBad #Quitar luego
    @pendingBadConsequence = pendingBad
  end
  
  def canMakeTreasureVisible(t)
    canMakeTVisible = true
    types = Array.new
    hands = 0
    
    for treasure in @visibleTreasures do
      types << treasure.type
      if(treasure.type == TreasureKind::ONEHAND)
        hands = hands + 1
      elsif(treasure.type == TreasureKind::BOTHHANDS)
        hands = hands + 2
      end
    end
    
    kind = t.type
    if(kind == TreasureKind::ONEHAND)
      hands = hands + 1
    elsif(kind == TreasureKind::BOTHHANDS)
      hands = hands + 2
    end
    
    if(types.include?(kind) && kind != TreasureKind::ONEHAND && kind != TreasureKind::BOTHHANDS)
      canMakeTVisible = false
    else
      canMakeTVisible = true
    end
    
    canMakeTVisible && (hands <= 2)
  end
  
  def howManyVisibleTreasures(tKind)
    numberOftKind = 0
    @visibleTreasures.each do |i|
      if(i.type == tKind)
        numberOftKind += 1
      end
    end
    numberOftKind
  end
  
  def dieIfNoTreasures
    if(@visibleTreasures.empty? && @hiddenTreasures.empty?) then
      @dead = true
    end
  end
  
  def isDead #Pensar en cambiar por un attr_reader
    @dead
  end
  
  def combat(m)
    myLevel = combatLevel
    monsterLevel = m.combatLevel
    cr = nil
    if(!@canISteal) then
      dice = Dice.instance
      number = dice.nextNumber
      if(number < 3) then
        enemyLevel = enemy.combatLevel
        monsterLevel = monsterLevel + enemyLevel
      end
    end
    if(myLevel > monsterLevel) then
      applyPrize(m)
      cr = (@level >= maxLevel)? CombatResult::WINGAME : CombatResult::WIN
    else
      applyBadConsequence(m)
      cr = CombatResult::LOSE
    end
    cr
  end
  
  def makeTreasureVisible(t)
    canI = canMakeTreasureVisible(t)
    if(canI) then
      @visibleTreasures << t
      @hiddenTreasures.delete(t)
    end
  end
  
  def discardVisibleTreasure(t)
    @visibleTreasures.delete(t)
    if((@pendingBadConsequence != nil) && !@pendingBadConsequence.empty?) then
      @pendingBadConsequence.substractVisibleTreasure(t)
    end
    dieIfNoTreasures
  end
  
  def discardHiddenTreasure(t)
    @hiddenTreasures.delete(t)
    if((@pendingBadConsequence != nil) && !@pendingBadConsequence.empty?) then
      @pendingBadConsequence.substractHiddenTreasure(t)
    end
    dieIfNoTreasures
  end
  
  def validState
    return ((@hiddenTreasures.size < 5) && (@pendingBadConsequence.empty?));
  end
  
  def initTreasures
    dealer = CardDealer.instance
    dice = Dice.instance
    bringToLife
    #Primer tesoro
    @hiddenTreasures << dealer.nextTreasure
    number = dice.nextNumber
    #Segundo tesoro
    if(number > 1) then
      @hiddenTreasures << dealer.nextTreasure
    end
    #Tercer tesoro
    if(number == 6) then
      @hiddenTreasures << dealer.nextTreasure
    end
  end

  def stealTreasure
    treasure = nil
    canI = canISteal
    if(canI) then
      canYou = @enemy.canYouGiveMeATreasure
      if(canYou) then
        treasure = @enemy.giveMeATreasure
        @hiddenTreasures << treasure
        haveStolen
      end
    end
    treasure
  end
  
  def giveMeATreasure
    n = @hiddenTreasures.size
    @hiddenTreasures[rand(n)]
  end
  
  def canYouGiveMeATreasure
    return !@hiddenTreasures.empty?
  end
  
  def haveStolen
    @canISteal = false
  end
  
  def discardAllTreasures
    cVisibleTreasures = Array.new(@visibleTreasures)
    cHiddenTreasures = Array.new(@hiddenTreasures)
    for t in cVisibleTreasures do
      discardVisibleTreasure(t)
    end
    for t in cHiddenTreasures do
      discardHiddenTreasure(t)
    end
  end
  
  def to_s
    "#{@name}\nlevel=#{@level}, combatLevel=#{combatLevel}, dead=#{@dead}, enemy=#{@enemy.name}";
  end
  
  private :bringToLife, :combatLevel, :incrementLevels, :decrementLevels, :applyPrize, :applyBadConsequence, :canMakeTreasureVisible, :howManyVisibleTreasures, :dieIfNoTreasures, :giveMeATreasure, :canYouGiveMeATreasure, :haveStolen
  
end
