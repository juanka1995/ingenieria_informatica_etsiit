#encoding: utf-8

class Prize
  attr_reader :treasures, :level
  def initialize(treasures, level)
    @treasures=treasures
    @level=level
  end
  
  def to_s
    "Prize{treasures=#{@treasures},level=#{@level}}"
  end
end


