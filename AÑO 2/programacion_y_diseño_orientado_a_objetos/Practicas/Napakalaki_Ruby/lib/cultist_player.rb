# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'cultist'
require_relative 'player'

class CultistPlayer < Player
  @@totalCultistPlayers = 0
  def initialize(p,c)
    copy(p)
    @myCultistCard = c
    @@totalCultistPlayers += 1
  end
  
  def combatLevel
    (super*1.7 + @myCultistCard.gainedLevels*@@totalCultistPlayers).floor
  end
  
  def oponentLevel(m)
    m.combatLevelAgainstCultistPlayer
  end
  
  def shouldConvert
    false
  end
  
  def giveMeATreasure
    n = @visibleTreasures.size
    @visibleTreasures[rand(n)]
  end
  
  def canYouGiveMeATreasure
    return !@visibleTreasures.empty?
  end
  
  def self.totalCultistPlayers
    @@totalCultistPlayers
  end
  
  def to_s
    super + ", cultist=true"
  end
  protected :combatLevel, :oponentLevel, :shouldConvert
  private :giveMeATreasure, :canYouGiveMeATreasure
end
