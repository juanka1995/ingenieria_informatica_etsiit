insert into equipos values('RMA','Real Madrid','Madrid','Pablo Laso',to_date('13/05/1931','DD/MM/YYYY'));
insert into equipos values('FCB','Barcelona Regal','Barcelona','Xavi Pascual',to_date('24/08/1926','DD/MM/YYYY'));
insert into equipos values('UNI','Unicaja','Malaga','Luis Casimiro',to_date('05/10/1977','DD/MM/YYYY'));
insert into equipos values('VAL','Valencia','Valencia Basket','Velimir Perasovic',to_date('04/03/1986','DD/MM/YYYY'));
insert into equipos values('CAL','Caja Laboral','Vitoria','Dusko Ivanovic',to_date('24/11/1959','DD/MM/YYYY'));
insert into equipos values ('REG','Regal FC Barcelona','Barcelona','Xavier Pascual',to_date('24/08/1926','DD/MM/YYYY'));
insert into equipos values ('BIZ','Bizkaia Bilbao Basket','Bilbao','Fotis Katsikaris',to_date('01/01/2000','DD/MM/YYYY'));
insert into equipos values ('BLR','Blancos de Rueda Valladolid','Valladolid','Luis Casimiro',to_date('01/01/1976','DD/MM/YYYY'));
insert into equipos values ('VLB','Valencia Basket','Valencia','Pacos Olmos',to_date('01/01/1986','DD/MM/YYYY'));



insert into jugadores values('A1','CAL','Pau Ribas');
insert into jugadores values('A2','CAL','F. San Emeterio');
insert into jugadores values('A3','CAL','Unai Calbarro');
insert into jugadores values('A4','CAL','Andres Nocioni');
insert into jugadores values('A5','CAL','Pablo Prigioni');

insert into jugadores values('B1','RMA','Carlos Suarez');
insert into jugadores values('B2','RMA','Felipe Reyes');
insert into jugadores values('B3','RMA','Sergio Rodriguez');
insert into jugadores values('B4','RMA','Sergio Llull');
insert into jugadores values('B5','RMA','Ante Tomic');

insert into jugadores values('C1','FCB','Victor Sada');
insert into jugadores values('C2','FCB','Juan Carlos Navarro');
insert into jugadores values('C3','FCB','Fran Vazquez');
insert into jugadores values('C4','FCB','Joe Ingles');
insert into jugadores values('C5','FCB','Boniface Ndong');

insert into jugadores values('D1','UNI','Berni Rodriguez');
insert into jugadores values('D2','UNI','Jorge Garbajosa');
insert into jugadores values('D3','UNI','Luka Zoric');
insert into jugadores values('D4','UNI','Alberto Diaz');
insert into jugadores values('D5','UNI','Joel Freeland');

insert into jugadores values('E1','VAL','Rodrigo San Miguel');
insert into jugadores values('E2','VAL','Victor Claver');
insert into jugadores values('E3','VAL','Alberto Perez');
insert into jugadores values('E4','VAL','Taquan Dean');
insert into jugadores values('E5','VAL','Juanlu Navarro');

insert into jugadores values ('F1','REG','Huertas, Marcelinho');
insert into jugadores values ('F2','REG','Jawai, Nathan');
insert into jugadores values ('F3','REG','Lorbek, Eraem');
insert into jugadores values ('F4','REG','Tomic, Ante');
insert into jugadores values ('F5','REG','Jasikeviius, Arnas');

insert into jugadores values ('G1','BIZ','Zisis, Nikolaos');
insert into jugadores values ('G2','BIZ','Rakovich, Milovan');
insert into jugadores values ('G3','BIZ','Pilepic, Fran');
insert into jugadores values ('G4','BIZ','Hamilton, Lamont');
insert into jugadores values ('G5','BIZ','Vasileiadis, Kostas');

insert into jugadores values ('H1','BLR','Faverani, Vitor');
insert into jugadores values ('H2','BLR','Markovick, Stefan');
insert into jugadores values ('H3','BLR','Doellman, Justin');
insert into jugadores values ('H4','BLR','Dubljevic, Bojan');
insert into jugadores values ('H5','BLR','Hanley, Will');

insert into jugadores values ('I1','VLB','Pietrus, Florent');
insert into jugadores values ('I2','VLB','Kelati, Thomas');
insert into jugadores values ('I3','VLB','Robinson, Jason');
insert into jugadores values ('I4','VLB','Hrycaniuk, Adam');
insert into jugadores values ('I5','VLB','Martinez, Rafa ');




insert into encuentros values('CAL','VAL',to_date('23/10/2011','DD/MM/YYYY'),'72','82');
insert into encuentros values('UNI','VAL',to_date('26/02/2012','DD/MM/YYYY'),'58','68');
insert into encuentros values('RMA','VAL',to_date('04/11/2011','DD/MM/YYYY'),'81','64');
insert into encuentros values('RMA','FCB',to_date('04/01/2012','DD/MM/YYYY'),'78','74');
insert into encuentros values('UNI','RMA',to_date('13/11/2011','DD/MM/YYYY'),'80','96');
insert into encuentros values('CAL','FCB',to_date('18/12/2011','DD/MM/YYYY'),'71','60');
insert into encuentros values('FCB','UNI',to_date('11/12/2011','DD/MM/YYYY'),'72','62');
insert into encuentros values('FCB','VAL',to_date('24/05/2012','DD/MM/YYYY'),'84','57');
insert into encuentros values('RMA','CAL',to_date('22/01/2012','DD/MM/YYYY'),'84','73');
insert into encuentros values('UNI','CAL',to_date('26/11/2011','DD/MM/YYYY'),'79','66');
insert into encuentros values ('REG','BIZ',to_date('29/09/2012','DD/MM/YYYY'),'73','89');
insert into encuentros values ('BLR','VLB',to_date('01/10/2012','DD/MM/YYYY'),'78','111');
insert into encuentros values ('REG','BLR',to_date('09/10/2012','DD/MM/YYYY'),'101','89');
insert into encuentros values ('BIZ','VLB',to_date('12/10/2012','DD/MM/YYYY'),'87','99');
insert into encuentros values ('VLB','REG',to_date('15/10/2012','DD/MM/YYYY'),'120','80');
insert into encuentros values ('BLR','BIZ',to_date('18/10/2012','DD/MM/YYYY'),'110','99');
insert into encuentros values ('REG','VLB',to_date('29/10/2012','DD/MM/YYYY'),'91','99');
insert into encuentros values ('BIZ','BLR',to_date('01/11/2012','DD/MM/YYYY'),'97','89');
insert into encuentros values ('BIZ','REG',to_date('07/11/2012','DD/MM/YYYY'),'79','88');
insert into encuentros values ('VLB','BLR',to_date('12/11/2012','DD/MM/YYYY'),'71','88');

insert into faltas values ('F1' ,'REG','BIZ',1);
insert into faltas values ('G3' ,'REG','BIZ',2);
insert into faltas values ('F4' ,'REG','BIZ',2);
insert into faltas values ('G2' ,'REG','BIZ',3);
insert into faltas values ('G1' ,'REG','BIZ',1);

insert into faltas values ('C3' ,'FCB','UNI',4); 
insert into faltas values ('D5' ,'FCB','UNI',3); 
insert into faltas values ('C5' ,'FCB','UNI',2); 
insert into faltas values ('D1' ,'FCB','UNI',3); 
insert into faltas values ('D4' ,'FCB','UNI',1); 

insert into faltas values ('B3' ,'RMA','VAL',1);
insert into faltas values ('B2' ,'RMA','VAL',1);
insert into faltas values ('E1' ,'RMA','VAL',2);
insert into faltas values ('E5' ,'RMA','VAL',3);
insert into faltas values ('B5' ,'RMA','VAL',4);
insert into faltas values ('B1' ,'RMA','VAL',4);
insert into faltas values ('E2' ,'RMA','VAL',4);

insert into faltas values ('F5' ,'VLB','REG',1);
insert into faltas values ('I3' ,'VLB','REG',1); 
insert into faltas values ('I4' ,'VLB','REG',1);
insert into faltas values ('F2' ,'VLB','REG',1);
 
