#encoding: utf-8

class BadConsequence
  attr_reader :text, :levels, :nVisibleTreasures, :nHiddenTreasures, :specificVisibleTreasures, :specificHiddenTreasures, :death
  
  @@MAXTREASURES = 10
  def self.MAXTREASURES
    @@MAXTREASURES
  end
  
  def initialize(text,levels,nVisibleTreasures,nHiddenTreasures,specificVisibleTreasures,specificHiddenTreasures,death)
    @text=text
    @levels=levels
    @nVisibleTreasures=nVisibleTreasures
    @nHiddenTreasures=nHiddenTreasures
    @specificVisibleTreasures=specificVisibleTreasures
    @specificHiddenTreasures=specificHiddenTreasures
    @death=death
  end
  
  def self.newLevelNumberOfTreasures(text,levels,nVisibleTreasures,nHiddenTreasures)
    new(text,levels,nVisibleTreasures,nHiddenTreasures,[],[],false)
  end
  
  def self.newLevelSpecificTreasures(text,levels,specificVisibleTreasures,specificHiddenTreasures)
    new(text,levels,0,0,specificVisibleTreasures,specificHiddenTreasures,false)
  end
  
  def self.newDeath(text)
    new(text,Player.maxLevel,@@MAXTREASURES,@@MAXTREASURES,[],[],true)
  end
  
  def empty?
    ((@nHiddenTreasures == 0) && (@nVisibleTreasures == 0) && (@specificVisibleTreasures.empty?) && (@specificHiddenTreasures.empty?))
  end
  
  def substractVisibleTreasure(t)
    if(@nVisibleTreasures == 0 && @nHiddenTreasures == 0) then
      if(@specificVisibleTreasures.include?(t.type)) then
        @specificVisibleTreasures.delete(t.type)
      end
    else
      @nVisibleTreasures = [0,@nVisibleTreasures-1].max
    end
  end
  
  def substractHiddenTreasure(t)
    if(@nVisibleTreasures == 0 && @nHiddenTreasures == 0) then
      if(@specificHiddenTreasures.include?(t.type)) then
        @specificHiddenTreasures.delete(t.type)
      end
    else
      @nHiddenTreasures = [0,@nHiddenTreasures-1].max
    end
  end
  
  def adjustToFitTreasureLists(v,h)
    nuevo = nil
    nOneHand = 0
    if(@nHiddenTreasures > 0 || @nVisibleTreasures > 0) then
      nuevo = BadConsequence.newLevelNumberOfTreasures(@text,@levels,[@nVisibleTreasures,v.length].min, [@nHiddenTreasures,h.length].min)
    elsif(!@specificHiddenTreasures.empty? || !@specificVisibleTreasures.empty?) then
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
      nuevo = BadConsequence.newLevelSpecificTreasures(@text,@levels,v2,h2)
    else
      nuevo = self
    end
    nuevo
  end
  
  def to_s
    "BadConsequence{text=#{@text}, levels=#{@levels}, nVisibleTreasures=#{@nVisibleTreasures}, nHiddenTreasures=#{@nHiddenTreasures}, death=#{@death}, specificHiddenTreasures=#{@specificHiddenTreasures}, specificVisibleTreasures=#{@specificVisibleTreasures}}";
  end
  private_class_method :new
end
