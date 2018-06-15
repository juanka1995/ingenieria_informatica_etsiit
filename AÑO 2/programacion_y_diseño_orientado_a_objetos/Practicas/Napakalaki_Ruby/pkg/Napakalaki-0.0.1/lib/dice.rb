#encoding: utf-8
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require 'singleton.rb'

class Dice
  include Singleton
  
  def nextNumber
    return rand(6)+1
  end
end
