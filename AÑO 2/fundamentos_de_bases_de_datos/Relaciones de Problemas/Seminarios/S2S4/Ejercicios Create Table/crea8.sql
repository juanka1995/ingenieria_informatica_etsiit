create table sala(
numero number(2) primary key
);

create table peliculas(
codigo number(5) primary key,
titulo varchar(20)
);

create table copias(
codigo_p references peliculas(codigo),
n_copia number(3),
primary key(codigo_p,n_copia)
);

create table asiento(
n_sala references sala(numero),
fila number(2),
columna number(2),
primary key(n_sala,fila,columna)
);

create table proyecta(
n_sala references sala(numero),
fecha date,
hora date,
codigo_cop number(5),
n_copia number(3),
foreign key(codigo_cop,n_copia) references copias(codigo_p,n_copia),
primary key(n_sala,fecha,hora),
unique(fecha,hora,codigo_cop,n_copia)
);

create table entrada(
fila number(2),
columna number(2),
n_sala number(2),
fecha date,
hora date,
foreign key (fila,columna,n_sala) references asiento(fila,columna,n_sala),
foreign key (n_sala,fecha,hora) references proyecta(n_sala,fecha,hora),
primary key(fila,columna,n_sala,fecha,hora)
);
