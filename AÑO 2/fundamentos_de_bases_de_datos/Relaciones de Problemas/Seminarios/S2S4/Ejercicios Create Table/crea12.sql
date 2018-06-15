create table avion(
id number(4) primary key,
capacidad number(3)
);

create table destino(
id number(4) primary key,
nombre varchar(20)
);

create table pasajero(
dni varchar(9) primary key,
nombre varchar(20),
apellidos varchar(40)
);

create table asiento(
id_avion references avion(id),
fila number(2),
letra varchar(1),
primary key(id_avion,fila,letra)
);

create table trayecto(
id_destino references destino(id),
ciudad_llegada varchar(20),
ciudad_partida varchar(20),
primary key(id_destino,ciudad_partida),
unique(id_destino,ciudad_llegada)
);

create table vuelo(
id_avion references avion(id),
fecha_partida date,
hora_partida date,
id_destino number(4),
ciudad_llegada varchar(20),
ciudad_partida varchar(20),
hora_llegada date,
foreign key(id_destino,ciudad_partida) references trayecto(id_destino,ciudad_partida),
primary key(id_avion,fecha_partida,hora_partida)
);

create table t_embarque(
dni_pasajero references pasajero(dni),
fecha_partida date,
hora_partida date,
id_avion number(4),
fila number(2),
letra varchar(1),
primary key(dni_pasajero,fecha_partida,hora_partida,id_avion),
unique(fecha_partida,hora_partida,id_avion,fila,letra),
foreign key(fecha_partida,hora_partida,id_avion) references vuelo(fecha_partida,hora_partida,id_avion),
foreign key(id_avion,fila,letra) references asiento(id_avion,fila,letra)
);
