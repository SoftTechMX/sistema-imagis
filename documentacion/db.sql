-- CREATE DATABASE BDSistemaLeonardo;
USE BDSistemaLeonardo;

-- ----------------------------------------------------------------------------------
-- Tablas del Sistema
-- ----------------------------------------------------------------------------------
DROP TABLE IF EXISTS Usuario;
CREATE TABLE Usuario (
	Id					INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	Usuario 			VARCHAR(15) NOT NULL,
	Password 			VARCHAR(15) NOT NULL,
    Tipo 				VARCHAR(15) NOT NULL,
	Nombres 			VARCHAR(30) NOT NULL,
	Apellidos 			VARCHAR(30) NOT NULL
);

-- ----------------------------------------------------------------------------------
-- Inserción de datos
-- ----------------------------------------------------------------------------------
INSERT INTO Usuario VALUES(NULL, 'USUARIO1','12345','ADMINISTRADOR','NOMBRE 01','APELLIDO 01');
INSERT INTO Usuario VALUES(NULL, 'USUARIO2','12345','ESPECIALISTA','NOMBRE 02','APELLIDO 02');
INSERT INTO Usuario VALUES(NULL, 'USUARIO3','12345','MEDICO','NOMBRE 03','APELLIDO 03');
INSERT INTO Usuario VALUES(NULL, 'USUARIO4','12345','APOYO','NOMBRE 04','APELLIDO 04');
INSERT INTO Usuario VALUES(NULL, 'USUARIO5','12345','SECRETARIA','NOMBRE 05','APELLIDO 05');
