create table tema(
codigo number(8) primary key,
descripcion varchar(200)
);

create table libro(
isbn number(10) primary key,
titulo varchar(25)
);

create table autor(
dni varchar(9) primary key,
nombre varchar(20)
);

create table usuario(
dni varchar(9) primary key,
nombre varchar(20),
apellidos varchar(40)
);

create table trata(
codigo_tema references tema(codigo),
isbn_libro references libro(isbn),
primary key(codigo_tema,isbn_libro)
);

create table escrito(
isbn_libro references libro(isbn),
dni_autor references autor(dni),
primary key(isbn_libro,dni_autor)
);

create table prestado(
isbn_libro references libro(isbn) primary key,
dni_usuario references usuario(dni) unique,
dia date
);
