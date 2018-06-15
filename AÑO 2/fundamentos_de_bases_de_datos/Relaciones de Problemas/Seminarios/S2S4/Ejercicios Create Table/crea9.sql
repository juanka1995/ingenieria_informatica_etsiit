create table telefono(
numero number(9) primary key,
tipo varchar(10)
);

create table llamada(
n_emisor references telefono(numero),
hora_inicio date,
n_receptor references telefono(numero),
hora_fin date,
primary key(n_emisor,hora_inicio),
unique(hora_inicio,n_receptor),
check(n_emisor!=n_receptor),
check(hora_inicio<hora_fin)
);
