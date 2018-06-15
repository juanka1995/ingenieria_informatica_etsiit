#encoding: utf-8
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

class Monster
  attr_reader :name, :combatLevel, :prize, :badConsequence
  def initialize(name,combatLevel,bc,prize)
    @name=name
    @combatLevel=combatLevel
    @prize=prize
    @badConsequence=bc
  end
  
  def getLevelsGained
    return @prize.level
  end
  
  def getTreasuresGained
    return @prize.treasures
  end
  
  def to_s
    "Monster{name=#{@name}, combatLevel=#{@combatLevel}, prize=#{@prize.to_s}, badConsequence=#{@badConsequence.to_s}}";
  end
end
