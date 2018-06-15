create table revista(
issn number(10) primary key,
nombre varchar(20),
editorial varchar(15)
);

create table autor(
codigo number(4) primary key,
nombre varchar(20),
nacionalidad varchar(15)
);

create table numeros(
issn references revista(issn),
id_numero number(3),
primary key(issn,id_numero)
);

create table articulo(
issn number(10),
id_numero number(3),
titulo varchar(20),
pg_inicio number(3),
pg_fin number(3),
foreign key(issn,id_numero) references numeros(issn,id_numero),
primary key(issn,id_numero,titulo)
);

create table escrito(
cod_autor references autor(codigo),
issn number(10),
id_numero number(3),
titulo varchar(20),
primary key(cod_autor,issn,id_numero,titulo),
foreign key(issn,id_numero,titulo) references articulo(issn,id_numero,titulo)
);

create table aparece(
issn_citado number(10),
id_numero_cit number(3),
titulo_cit varchar(20),
issn_referido number(10),
id_numero_ref number(3),
titulo_ref varchar(20),
primary key(issn_citado,id_numero_cit,titulo_cit,issn_referido,id_numero_ref,titulo_ref),
foreign key(issn_citado,id_numero_cit,titulo_cit) references articulo(issn,id_numero,titulo),
foreign key(issn_referido,id_numero_ref,titulo_ref) references articulo(issn,id_numero,titulo),
check(issn_citado!=issn_referido and id_numero_cit!=id_numero_ref and titulo_cit!=titulo_ref)
);
