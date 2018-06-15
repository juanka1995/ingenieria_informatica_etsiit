create table usuario(
dni varchar(9) primary key,
nombre varchar(20),
apellidos varchar(40)
);

create table libro(
isbn number(8) primary key,
tema varchar(15)
);

create table autor(
dni varchar(9) primary key,
nombre varchar(20),
apellidos varchar(40)
);

create table ejemplar(
isbn_libro references libro(isbn),
codigo number(8),
primary key(isbn_libro,codigo)
);

create table escrito(
isbn_libro references libro(isbn),
dni_autor references autor(dni),
primary key(isbn_libro,dni_autor)
);

create table prestado(
isbn_libro number(8),
cod_ejemplar number(8),
fecha date,
dni_usuario references usuario(dni),
primary key(isbn_libro,cod_ejemplar,fecha),
foreign key (isbn_libro,cod_ejemplar) references ejemplar(isbn_libro,codigo)
);
