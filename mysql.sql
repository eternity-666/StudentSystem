-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: test
-- ------------------------------------------------------
-- Server version	8.0.34

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `student` (
  `id` int NOT NULL AUTO_INCREMENT,
  `studentNumber` varchar(20) NOT NULL DEFAULT '2004070207',
  `name` varchar(15) NOT NULL DEFAULT 'test',
  `classname` varchar(15) NOT NULL DEFAULT '软工二班',
  `chinese` int NOT NULL DEFAULT '99',
  `math` int NOT NULL DEFAULT '99',
  `english` int NOT NULL DEFAULT '99',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=31 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1,'2004070207','陈永彬','软工二班',99,99,99),(2,'2004070210','崔允','软工二班',99,99,99),(3,'2004070767','张建军','软工二班',99,99,99),(4,'2004070252','王子豪','软工二班',80,78,64),(5,'2004070211','程昊文','软工二班',98,57,89),(11,'2004070208','梨园','电信二班',100,300,500),(12,'2004070216','cici','艺术一班',57,35,78),(13,'83785389','sdhs','艺术一班',57,35,78),(14,'47347377','fdhv','sdcjs',787,54,754),(15,'3477','djc','ewfw',6,54,32),(16,'485434','fs','ad',66,43,65),(17,'34636','hg','jj',42,99,99),(18,'2399','fh','fj',55,55,55),(19,'3483747','td','fg',55,44,77),(20,'update','update','test',99,99,99),(21,'4546343','tr','fdd',66,77,88),(22,'436436','hd','sdc',88,77,66),(23,'re','4r','sdc',88,77,66),(24,'75437477','ff','fdf',667,677,677),(25,'3473747','vvs','regve',66,56,67),(26,'3727','err','er',44,33,22),(27,'434344','gd','df',554,34,6),(28,'37755','dfvv','csdc',54,6778,776),(29,'73485','dss','xccx',77,6556,54),(30,'5835485','err','d',54,54,54);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `username` text,
  `password` text,
  `auth` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES ('2074718409@qq.com','123456','temp');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-10-15 14:52:14
