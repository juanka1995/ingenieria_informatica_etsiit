create table empresa(
nif number(10) primary key,
nombre varchar(20),
direccion varchar(50)
);

create table factura(
num_fac number(5) primary key,
fecha date,
importe number(8,3),
nif_emisor references empresa(nif),
nif_receptor references empresa(nif),
check(nif_emisor!=nif_receptor)
);

create table productos(
id number(5) primary key,
precio_unitario number(8,3),
existencias number(3),
iva number(2)
);

create table contiene(
num_factura references factura(num_fac),
id_producto references productos(id),
cantidad number(4),
n_linea number(3),
primary key(num_factura,id_producto)
);
