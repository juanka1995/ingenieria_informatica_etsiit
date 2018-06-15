#encoding: utf-8

class BadConsequence
  attr_reader :text, :levels
  
  @@MAXTREASURES = 10
  def self.MAXTREASURES
    @@MAXTREASURES
  end
  
  def initialize(text,levels)
    @text=text
    @levels=levels
  end
  
  def to_s
    "BadConsequence: text=#{@text}, levels=#{@levels}";
  end
end
