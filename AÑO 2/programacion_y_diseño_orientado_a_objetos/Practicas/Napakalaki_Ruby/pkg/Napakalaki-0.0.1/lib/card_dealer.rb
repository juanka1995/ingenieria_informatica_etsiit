#encoding: utf-8
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require 'singleton.rb'
require_relative 'monster.rb'
require_relative 'treasure.rb'
require_relative 'prize.rb'

class CardDealer
  include Singleton
  #Private methods
  def initialize
    @usedMonsters = Array.new
    @unusedMonsters = Array.new
    @usedTreasures = Array.new
    @unusedTreasures = Array.new
  end
  
  def initTreasureCardDeck
    @unusedTreasures << Treasure.new("¡Si mi amo!",4,TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Botas de investigación",3,TreasureKind::SHOES)
    @unusedTreasures << Treasure.new("Capucha de Cthulhu",3,TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("A prueba de babas",2,TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Botas de lluvia ácida",1,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Casco minero",2,TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Ametralladora ACME",4,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Camiseta de la ETSIIT",1,TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Clavo de rail ferroviario",3,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Cuchillo de sushi arcano",2,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Fez alópodo",3,TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Hacha prehistórica",2,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("El aparato del Pr. Tesla",4,TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Gaita",4,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Insecticida",2,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Escopeta de 3 cañones",4,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Garabato místico",2,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("La rebeca metálica",2,TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Lanzallamas",4,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Necrocomisión",1,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necronomicón",5,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Linterna a 2 manos",3,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Necrognomicón",2,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necrotelecom",2,TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Mazo de los antiguos",3,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necroplayboycón",3,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Porra preternatural",2,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Shogulador",1,TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Varita de atizamiento",3,TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Tentáculo de pega",2,TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Zapato deja-amigos",1,TreasureKind::SHOES)
    shuffleTreasures
  end
  
  def initMonsterCardDeck
    @unusedMonsters << Monster.new(
      "Byakhees de bonanza",
      8,
      BadConsequence.newLevelSpecificTreasures(
        "Pierdes tu armadura visible y otra oculta",
        0,
        [TreasureKind::ARMOR], 
        [TreasureKind::ARMOR]),
      Prize.new(2,1))

    @unusedMonsters << Monster.new(
      "Tenochtitlan",
      2,
      BadConsequence.newLevelSpecificTreasures(
        "Embobados con el lindo primigenio te descartas de tu casco visible",
        0,
        [TreasureKind::HELMET], 
        []),
      Prize.new(1,1))

    @unusedMonsters << Monster.new(
    "El sopor de Dunwich",
    2,
    BadConsequence.newLevelSpecificTreasures(
      "El primordial bostezo contagioso. Pierdes el calzado visible",
      0,
      [TreasureKind::SHOES], 
      []),
    Prize.new(1,1))

    @unusedMonsters << Monster.new(
    "Demonios de Magaluf",
    2,
    BadConsequence.newLevelSpecificTreasures(
      "Te atrapa para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta",
      0,
      [TreasureKind::ONEHAND], 
      [TreasureKind::ONEHAND]),
    Prize.new(4,1))

    @unusedMonsters << Monster.new(
      "El gorrón en el umbral",
      13,
      BadConsequence.newLevelNumberOfTreasures("Pierdes todos tus tesoros visibles",0,BadConsequence.MAXTREASURES,0),
      Prize.new(3,1))

    @unusedMonsters << Monster.new(
    "H.P. Munchcraft",
    6,
    BadConsequence.newLevelSpecificTreasures(
      "Pierdes la armadura visible",
      0,
      [TreasureKind::ARMOR], 
      []),
    Prize.new(2,1))    

    @unusedMonsters << Monster.new(
    "Necrófago",
    13,
    BadConsequence.newLevelSpecificTreasures(
      "Sientes bichos bajo la ropa.Descarta la armadura visible",
      0,
      [TreasureKind::ARMOR], 
      []),
    Prize.new(1,1))   

    @unusedMonsters << Monster.new(
      "El rey de rosado",
      11,
      BadConsequence.newLevelNumberOfTreasures("Pierdes 5 niveles y 3 tesoros visibles",5,3,0),
      Prize.new(3,2))    

    @unusedMonsters << Monster.new(
      "Flecher",
      2,
      BadConsequence.newLevelNumberOfTreasures("Toses los pulmones y pierdes 2 niveles",2,0,0),
      Prize.new(1,1))   

    @unusedMonsters << Monster.new(
      "Los hondos",
      8,
      BadConsequence.newDeath("Estos monstruos resultan bastante superficiales y te aburren mortalmente. Estas muerto"),
      Prize.new(2,1))    

    @unusedMonsters << Monster.new(
      "Semillas Cthulhu",
      4,
      BadConsequence.newLevelNumberOfTreasures("Pierdes 2 niveles y 2 tesoros ocultos",2,0,2),
      Prize.new(2,1))

    @unusedMonsters << Monster.new(
    "Dameargo",
    1,
    BadConsequence.newLevelSpecificTreasures(
      "Te intentas escaquear. Pierdes una mano visible",
      0,
      [TreasureKind::ONEHAND], 
      []),
    Prize.new(2,1))

    @unusedMonsters << Monster.new(
      "Pollipolipo volante",
      3,
      BadConsequence.newLevelNumberOfTreasures("Da mucho asquito. Pierdes 3 niveles",3,0,0),
      Prize.new(2,1))

    @unusedMonsters << Monster.new(
      "Yskhtihyssg-Goth",
      14,
      BadConsequence.newDeath("No le hace gracia que pronuncien mal su nombre. Estas muertos"),
      Prize.new(3,1))

    @unusedMonsters << Monster.new(
      "Familia feliz",
      1,
      BadConsequence.newDeath("La familia te atrapa. Estas muerto"),
      Prize.new(3,1))

    @unusedMonsters << Monster.new(
    "Roboggoth",
    8,
    BadConsequence.newLevelSpecificTreasures(
      "La quinta directiva primaria te obliga a perder dos niveles y un tesoro 2 manos visible",
      2,
      [TreasureKind::BOTHHANDS], 
      []),
    Prize.new(2,1))

    @unusedMonsters << Monster.new(
    "El espia sordo",
    5,
    BadConsequence.newLevelSpecificTreasures(
      "Te asustas en la noche. Pierdes un casco visible",
      0,
      [TreasureKind::HELMET], 
      []),
    Prize.new(1,1))

    @unusedMonsters << Monster.new(
      "Tongue",
      19,
      BadConsequence.newLevelNumberOfTreasures("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles",2,5,0),
      Prize.new(2,1))    

    @unusedMonsters << Monster.new(
    "Bicéfalo",
    21,
    BadConsequence.newLevelSpecificTreasures(
      "Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos",
      3,
      [TreasureKind::ONEHAND , TreasureKind::BOTHHANDS], 
      []),
    Prize.new(2,1))
    shuffleMonsters
  end
  
  def shuffleTreasures
    @unusedTreasures.shuffle!
  end
  
  def shuffleMonsters
    @unusedMonsters.shuffle!
  end
  
  #Public methods
  def nextTreasure
    if(@unusedTreasures.empty?) then
      @unusedTreasures = @usedTreasures.pop(@usedTreasures.length)
      shuffleTreasures
    end
    @unusedTreasures.pop
  end
  
  def nextMonster
    if(@unusedMonsters.empty?) then
      @unusedMonsters = @usedMonsters.pop(@usedMonsters.length)
      shuffleMonsters
    end
    @unusedMonsters.pop
  end
  
  def giveTreasureBack(t)
    @usedTreasures << t    
  end
  
  def giveMonsterBack(m)
    @usedMonsters << m    
  end
  
  def initCards
    initTreasureCardDeck
    initMonsterCardDeck
  end
  
  private :initTreasureCardDeck, :initMonsterCardDeck, :shuffleTreasures, :shuffleMonsters
  
end
