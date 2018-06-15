-- MySQL dump 10.13  Distrib 5.7.20, for Linux (x86_64)
--
-- Host: localhost    Database: ohmydiet!
-- ------------------------------------------------------
-- Server version	5.7.20-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ingrediente`
--

DROP TABLE IF EXISTS `ingrediente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ingrediente` (
  `id_ingrediente` int(10) unsigned NOT NULL,
  `nombre` varchar(50) DEFAULT NULL,
  `categoria` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id_ingrediente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ingrediente`
--

LOCK TABLES `ingrediente` WRITE;
/*!40000 ALTER TABLE `ingrediente` DISABLE KEYS */;
INSERT INTO `ingrediente` VALUES (0,'Sal','Condimentos'),(1,'Macarrones','Pasta'),(2,'Azucar blanco','Edulcorantes'),(3,'Pimienta','Condimentos'),(4,'Leche liquida','Productos lácteos'),(5,'Nata','Productos lácteos'),(6,'Ajo','Frutas y hortalizas'),(7,'Cebolla','Frutas y hortalizas'),(8,'Pimiento','Frutas y hortalizas'),(9,'Tomate','Frutas y hortalizas'),(10,'Pollo','Productos cárnicos'),(11,'Ternera','Productos cárnicos'),(12,'Cerdo','Productos cárnicos'),(13,'Pavo','Productos cárnicos'),(14,'Dorada','Productos pesqueros'),(15,'Pulpo','Productos pesqueros'),(16,'Tortas','Productos de panadería'),(17,'Pan leudado','Productos de panadería'),(18,'Pan integral','Productos de panadería'),(19,'Mantequilla','Grasas y aceites'),(20,'Aceite de oliva','Grasas y aceites'),(21,'Aceite de girasol','Grasas y aceites'),(22,'Miel','Edulcorantes'),(23,'Lactosa','Edulcorantes'),(24,'Azucar moreno','Edulcorantes'),(25,'Queso rallado','Lácteos'),(26,'Lechuga','Frutas y hortalizas'),(27,'Habas','Frutas y hortalizas'),(28,'Limón','Frutas y hortalizas'),(29,'Oregano','Condimentos'),(30,'Arroz','Cereales'),(31,'Calamares','Productos pesqueros'),(32,'Gambas','Productos pesqueros');
/*!40000 ALTER TABLE `ingrediente` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-01-20 20:55:17
