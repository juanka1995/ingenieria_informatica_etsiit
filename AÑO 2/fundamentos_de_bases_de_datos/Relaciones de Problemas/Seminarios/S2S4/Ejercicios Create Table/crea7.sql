create table producto(
num_ref number(5) primary key,
fabricante varchar(20),
precio number(8,3)
);

create table ordenador(
n_ref_p references producto(num_ref) primary key,
cap_disco number(5),
procesador varchar(20),
ram number(1),
velocidad number(4,2)
);

create table impresora(
n_ref_p references producto(num_ref) primary key,
color varchar(10),
tipo varchar(10),
resolucion number(4)
);

create table portatil(
n_ref_o references ordenador(n_ref_p) primary key,
tamaño_pantalla number(2)
);

create table sobremesa(
n_ref_o references ordenador(n_ref_p) primary key
);
