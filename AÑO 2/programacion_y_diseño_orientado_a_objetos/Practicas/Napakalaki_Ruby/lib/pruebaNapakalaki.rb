#encoding: utf-8
require_relative "prize.rb"
require_relative "treasure_kind.rb"
require_relative "monster.rb"
require_relative "bad_consequence.rb"
class PruebaNapakalaki
  @@MAX_VALUE=0xFFFFFF
  @@monsters=Array.new
  def self.createMonsters
    @@monsters << Monster.new(
      "Byakhees de bonanza",
      8,
      BadConsequence.newLevelSpecificTreasures(
        "Pierdes tu armadura visible y otra oculta",
        0,
        [TreasureKind::ARMOR], 
        [TreasureKind::ARMOR]),
      Prize.new(2,1))

    @@monsters << Monster.new(
      "Tenochtitlan",
      2,
      BadConsequence.newLevelSpecificTreasures(
        "Embobados con el lindo primigenio te descartas de tu casco visible",
        0,
        [TreasureKind::HELMET], 
        []),
      Prize.new(1,1))

    @@monsters << Monster.new(
    "El sopor de Dunwich",
    2,
    BadConsequence.newLevelSpecificTreasures(
      "El primordial bostezo contagioso. Pierdes el calzado visible",
      0,
      [TreasureKind::SHOES], 
      []),
    Prize.new(1,1))

    @@monsters << Monster.new(
      "Demonios de Magaluf",
      2,
      BadConsequence.newLevelSpecificTreasures(
        "Te atrapa para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta",
        0,
        [TreasureKind::ONEHAND], 
        [TreasureKind::ONEHAND]),
      Prize.new(4,1))

    @@monsters << Monster.new(
      "El gorrón en el umbral",
      13,
      BadConsequence.newLevelNumberOfTreasures("Pierdes todos tus tesoros visibles",0,@@MAX_VALUE,0),
      Prize.new(3,1))

    @@monsters << Monster.new(
    "H.P. Munchcraft",
    6,
    BadConsequence.newLevelSpecificTreasures(
      "Pierdes la armadura visible",
      0,
      [TreasureKind::ARMOR], 
      []),
    Prize.new(2,1))    

    @@monsters << Monster.new(
      "Necrófago",
      13,
      BadConsequence.newLevelSpecificTreasures(
        "Sientes bichos bajo la ropa.Descarta la armadura visible",
        0,
        [TreasureKind::ARMOR], 
        []),
      Prize.new(1,1))   

    @@monsters << Monster.new(
      "El rey de rosado",
      11,
      BadConsequence.newLevelNumberOfTreasures("Pierdes 5 niveles y 3 tesoros visibles",5,3,0),
      Prize.new(3,2))    

    @@monsters << Monster.new(
      "Flecher",
      2,
      BadConsequence.newLevelNumberOfTreasures("Toses los pulmones y pierdes 2 niveles",2,0,0),
      Prize.new(1,1))   

    @@monsters << Monster.new(
      "Los hondos",
      8,
      BadConsequence.newDeath("Estos monstruos resultan bastante superficiales y te aburren mortalmente. Estas muerto"),
      Prize.new(2,1))    

    @@monsters << Monster.new(
      "Semillas Cthulhu",
      4,
      BadConsequence.newLevelNumberOfTreasures("Pierdes 2 niveles y 2 tesoros ocultos",2,0,2),
      Prize.new(2,1))

    @@monsters << Monster.new(
      "Dameargo",
      1,
      BadConsequence.newLevelSpecificTreasures(
        "Te intentas escaquear. Pierdes una mano visible",
        0,
        [TreasureKind::ONEHAND], 
        []),
      Prize.new(2,1))

    @@monsters << Monster.new(
      "Pollipolipo volante",
      3,
      BadConsequence.newLevelNumberOfTreasures("Da mucho asquito. Pierdes 3 niveles",3,0,0),
      Prize.new(2,1))

    @@monsters << Monster.new(
      "Yskhtihyssg-Goth",
      14,
      BadConsequence.newDeath("No le hace gracia que pronuncien mal su nombre. Estas muertos"),
      Prize.new(3,1))

    @@monsters << Monster.new(
      "Familia feliz",
      1,
      BadConsequence.newDeath("La familia te atrapa. Estas muerto"),
      Prize.new(3,1))

    @@monsters << Monster.new(
      "Roboggoth",
      8,
      BadConsequence.newLevelSpecificTreasures(
        "La quinta directiva primaria te obliga a perder dos niveles y un tesoro 2 manos visible",
        2,
        [TreasureKind::BOTHHANDS], 
        []),
      Prize.new(2,1))

    @@monsters << Monster.new(
      "El espia sordo",
      5,
      BadConsequence.newLevelSpecificTreasures(
        "Te asustas en la noche. Pierdes un casco visible",
        0,
        [TreasureKind::HELMET], 
        []),
      Prize.new(1,1))

    @@monsters << Monster.new(
      "Tongue",
      19,
      BadConsequence.newLevelNumberOfTreasures("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles",2,5,0),
      Prize.new(2,1))    

    @@monsters << Monster.new(
      "Bicéfalo",
      21,
      BadConsequence.newLevelSpecificTreasures(
        "Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos",
        3,
        [TreasureKind::ONEHAND , TreasureKind::BOTHHANDS], 
        []),
      Prize.new(2,1))
  end
  def self.nivelMayorDiez
    ms = Array.new
    for m in @@monsters do
      if m.level > 10 then
        ms << m
      end
    end
    ms
  end
  def self.soloPerdidaNiveles
    ms = Array.new
    for m in @@monsters do
      bc = m.badConsequence
      if (bc.levels > 0 &&
          bc.nVisibleTreasures == 0 &&
          bc.nHiddenTreasures == 0 &&
          bc.specificVisibleTreasures.empty? &&
          bc.specificHiddenTreasures.empty?
      ) then
        ms << m
      end
    end
    ms
  end
  def self.ganarNivelMayorUno
    ms = Array.new
    for m in @@monsters do
      if m.prize.level > 1 then
        ms << m
      end
    end
    ms
  end
  def self.perdidaTesoro(tk)
    ms = Array.new
    for m in @@monsters do
      if (m.badConsequence.specificHiddenTreasures.include?(tk) ||
            m.badConsequence.specificVisibleTreasures.include?(tk)) then
        ms << m
      end
    end
    ms
  end
  
  createMonsters
  
#  m = Monster.new(
#    "Nombre", 
#    1, 
#    BadConsequence.newLevelNumberVisibleSpecificHidden(
#      "Baddd", 
#      2, 
#      1,
#      [TreasureKind::ARMOR]),
#    Prize.new(2, 1)
#  )
#  
#  mL = Array.new
#  mL << m
#  for i in 0..2 do
#    mL << @@monsters[i]
#  end
#  
#  mL2 = Array.new
#  for m in mL do
#    if (m.badConsequence.someLevels > 0 || m.badConsequence.specificVisibleTreasures.include?(TreasureKind::ARMOR)) then
#      mL2 << m
#    end
#  end
#  
#  puts mL2.to_s
  
  #puts nivelMayorDiez
  #puts soloPerdidaNiveles
  #puts ganarNivelMayorUno
  puts perdidaTesoro(TreasureKind::ARMOR)
  puts perdidaTesoro(TreasureKind::BOTHHANDS)
  puts perdidaTesoro(TreasureKind::HELMET)
  puts perdidaTesoro(TreasureKind::ONEHAND)
  puts perdidaTesoro(TreasureKind::SHOES)
  puts @@MAX_VALUE
end