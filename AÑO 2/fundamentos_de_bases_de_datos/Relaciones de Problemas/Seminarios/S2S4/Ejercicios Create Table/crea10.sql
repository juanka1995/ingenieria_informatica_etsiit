create table receta(
codr number(5) primary key,
nombre varchar(20),
dificultad varchar(15),
tipo varchar(10)
);

create table ingredientes(
codi number(5) primary key,
nombre varchar(20),
tipo varchar(10),
precio number(4,3)
);

create table pasos(
cod_rec references receta(codr),
n_paso number(2),
primary key(cod_rec,n_paso)
);

create table incluye(
cod_rec number(5),
n_paso number(2),
cod_ing references ingredientes(codi),
cantidad number(3),
primary key(cod_rec,n_paso,cod_ing),
foreign key (cod_rec,n_paso) references pasos(cod_rec,n_paso)
);
