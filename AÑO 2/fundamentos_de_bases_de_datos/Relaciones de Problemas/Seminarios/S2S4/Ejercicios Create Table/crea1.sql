create table Titular(
dni varchar(9) primary key,
domicilio varchar(50),
telefono number(9)
);

create table Cuenta(
codigo number(8) primary key,
saldo number(9,3),
fecha_apertura date
);

create table Tiene(
dni_cliente references Titular(dni),
codigo_cuenta references Cuenta(codigo),
primary key(dni_cliente,codigo_cuenta)
);

create table Tarjeta(
numero number(15) primary key,
tipo varchar(20),
dni_cliente varchar(9),
codigo_cuenta number(8),
foreign key (dni_cliente,codigo_cuenta) references Tiene(dni_cliente,codigo_cuenta)
);

