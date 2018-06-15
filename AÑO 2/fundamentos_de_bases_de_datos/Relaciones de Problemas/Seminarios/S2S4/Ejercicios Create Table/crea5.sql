create table año(
año number(4) primary key
);

create table tema(
tema varchar(20) primary key
);

create table titulo(
titulo varchar(30) primary key,
tema references tema(tema)
);

create table copia(
id number(5) primary key,
sist_repr varchar(10),
titulo references titulo(titulo),
año references año(año)
);

create table clientes(
dni varchar(9) primary key,
nombre varchar(20),
direccion varchar(50),
telefono number(9)
);

create table pelicula(
titulo references titulo(titulo),
año references año(año),
actores varchar(100),
primary key(titulo,año)
);

create table alquilan(
id_copia references copia(id),
fecha date,
dni_cliente references clientes(dni),
primary key(id_copia,fecha)
);
