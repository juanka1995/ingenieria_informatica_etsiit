# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'bad_consequence.rb'

class SpecificBadConsequence < BadConsequence
  
  attr_reader :specificVisibleTreasures, :specificHiddenTreasures
  
  def initialize(text,levels,specificVisibleTreasures,specificHiddenTreasures)
    super(text,levels)
    @specificVisibleTreasures = specificVisibleTreasures
    @specificHiddenTreasures = specificHiddenTreasures
  end
  
  def empty?
    (@specificVisibleTreasures.empty?) && (@specificHiddenTreasures.empty?)
  end
  
  def substractVisibleTreasure(t)
    if(@specificVisibleTreasures.include?(t.type)) then
      @specificVisibleTreasures.delete(t.type)
    end
  end
  
  def substractHiddenTreasure(t)
    if(@specificHiddenTreasures.include?(t.type)) then
      @specificHiddenTreasures.delete(t.type)
    end
  end
  
  def adjustToFitTreasureLists(v,h)
    v2 = Array.new  
    h2 = Array.new
    #ONEHAND ocultos
    nOneHand = 0
    for type in @specificHiddenTreasures do
      if(type == TreasureKind::ONEHAND)
        nOneHand = nOneHand + 1
      end
    end
    for treasure in h do
      if(@specificHiddenTreasures.include?(treasure.type) && treasure.type != TreasureKind::ONEHAND) then
        h2 << treasure.type
      elsif(@specificHiddenTreasures.include?(treasure.type) && (treasure.type == TreasureKinde::ONEHAND) && (nOneHand > 0)) then
        h2 << treasure.type  
        nOneHand = nOneHand - 1
      end
    end
    #ONEHAND visibles
    nOneHand = 0
    for type in @specificVisibleTreasures do
      if(type == TreasureKind::ONEHAND)
        nOneHand = nOneHand + 1
      end
    end
    for treasure in v do
      if(@specificVisibleTreasures.include?(treasure.type) && treasure.type != TreasureKind::ONEHAND) then
        v2 << treasure.type
      elsif(@specificVisibleTreasures.include?(treasure.type) && (treasure.type == TreasureKind::ONEHAND) && (nOneHand > 0)) then
        v2 << treasure.type  
        nOneHand = nOneHand - 1
      end
    end
    SpecificBadConsequence.new(@text,@levels,v2,h2)
  end
  
  def to_s
    super() + ", specificVisibleTreasures=#{@specificVisibleTreasures}, specificHiddenTreasures=#{@specificHiddenTreasures}"
  end
end
