create table pieza(
codigo number(8) primary key,
denominacion varchar(20),
precio number(7,3)
);

create table simple(
cod_pieza references pieza(codigo) primary key
);

create table compuesta(
cod_pieza references pieza(codigo) primary key
);

create table compone(
cod_pieza references pieza(codigo) primary key,
cod_pieza_comp references compuesta(cod_pieza),
n_piezas number(3)
);
