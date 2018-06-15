# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'bad_consequence.rb'

class NumericBadConsequence < BadConsequence
  
  attr_reader :nVisibleTreasures, :nHiddenTreasures
  
  def initialize(text,levels,nVisibleTreasures,nHiddenTreasures)
    super(text,levels)
    @nVisibleTreasures = nVisibleTreasures
    @nHiddenTreasures = nHiddenTreasures
  end
  
  def empty?
    (@nHiddenTreasures == 0) && (@nVisibleTreasures == 0)
  end
  
  def substractVisibleTreasure(t)
    @nVisibleTreasures = [0,@nVisibleTreasures-1].max
  end
  
  def substractHiddenTreasure(t)
    @nHiddenTreasures = [0,@nHiddenTreasures-1].max
  end
  
  def adjustToFitTreasureLists(v,h)
    NumericBadConsequence.new(@text,@levels,[@nVisibleTreasures,v.length].min, [@nHiddenTreasures,h.length].min)
  end
  
  def to_s
    super() + ", nVisibleTreasures=#{@nVisibleTreasures}, nHiddenTreasures=#{@nHiddenTreasures}";
  end
end
