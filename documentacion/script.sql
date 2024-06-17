-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema imagis
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `imagis` ;

-- -----------------------------------------------------
-- Schema imagis
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `imagis` ;
USE `imagis` ;

-- -----------------------------------------------------
-- Table `imagis`.`sistemas`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`sistemas` ;

CREATE TABLE IF NOT EXISTS `imagis`.`sistemas` (
  `id_sistema` INT NOT NULL AUTO_INCREMENT,
  `nombre_sistema` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`id_sistema`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`usuarios`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`usuarios` ;

CREATE TABLE IF NOT EXISTS `imagis`.`usuarios` (
  `id_usuario` INT NOT NULL AUTO_INCREMENT,
  `id_sistema` INT NULL DEFAULT NULL,
  `username` VARCHAR(50) NOT NULL,
  `password` VARCHAR(50) NOT NULL,
  `created_at` TIMESTAMP NULL DEFAULT NULL,
  `updated_at` TIMESTAMP NULL DEFAULT NULL,
  `deleted_at` TIMESTAMP NULL DEFAULT NULL,
  PRIMARY KEY (`id_usuario`),
  INDEX `fk_usuarios_1_idx` (`id_sistema` ASC) VISIBLE,
  CONSTRAINT `fk_usuarios_1`
    FOREIGN KEY (`id_sistema`)
    REFERENCES `imagis`.`sistemas` (`id_sistema`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`modulos`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`modulos` ;

CREATE TABLE IF NOT EXISTS `imagis`.`modulos` (
  `id_modulo` INT NOT NULL AUTO_INCREMENT,
  `id_licencia` INT NULL DEFAULT NULL,
  `nombre_modulo` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`id_modulo`),
  INDEX `fk_modulos_1_idx` (`id_licencia` ASC) VISIBLE,
  CONSTRAINT `fk_modulos_1`
    FOREIGN KEY (`id_licencia`)
    REFERENCES `imagis`.`licencias` (`id_licencia`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`paises`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`paises` ;

CREATE TABLE IF NOT EXISTS `imagis`.`paises` (
  `id_pais` INT NOT NULL AUTO_INCREMENT,
  `nombre_pais` VARCHAR(100) NOT NULL,
  `created_at` TIMESTAMP NULL DEFAULT NULL,
  `updated_at` TIMESTAMP NULL DEFAULT NULL,
  `deleted_at` TIMESTAMP NULL DEFAULT NULL,
  PRIMARY KEY (`id_pais`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`provincias`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`provincias` ;

CREATE TABLE IF NOT EXISTS `imagis`.`provincias` (
  `id_provincia` INT NOT NULL AUTO_INCREMENT,
  `id_pais` INT NOT NULL,
  `nombre_provincia` VARCHAR(100) NOT NULL,
  `created_at` TIMESTAMP NULL DEFAULT NULL,
  `updated_at` TIMESTAMP NULL DEFAULT NULL,
  `deleted_at` TIMESTAMP NULL DEFAULT NULL,
  PRIMARY KEY (`id_provincia`),
  INDEX `fk_provincias_1_idx` (`id_pais` ASC) VISIBLE,
  CONSTRAINT `fk_provincias_1`
    FOREIGN KEY (`id_pais`)
    REFERENCES `imagis`.`paises` (`id_pais`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`municipios`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`municipios` ;

CREATE TABLE IF NOT EXISTS `imagis`.`municipios` (
  `id_municipio` INT NOT NULL AUTO_INCREMENT,
  `id_provincia` INT NOT NULL,
  `nombre_municipio` VARCHAR(100) NOT NULL,
  `created_at` TIMESTAMP NULL DEFAULT NULL,
  `updated_at` TIMESTAMP NULL DEFAULT NULL,
  `deleted_at` TIMESTAMP NULL DEFAULT NULL,
  PRIMARY KEY (`id_municipio`),
  INDEX `fk_municipios_1_idx` (`id_provincia` ASC) VISIBLE,
  CONSTRAINT `fk_municipios_1`
    FOREIGN KEY (`id_provincia`)
    REFERENCES `imagis`.`provincias` (`id_provincia`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`direccion`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`direccion` ;

CREATE TABLE IF NOT EXISTS `imagis`.`direccion` (
  `id_direccion` INT NOT NULL AUTO_INCREMENT,
  `id_municipio` INT NULL DEFAULT NULL,
  `calle` VARCHAR(100) NULL DEFAULT NULL,
  `numero` VARCHAR(100) NULL DEFAULT NULL,
  `descripcion` VARCHAR(100) NULL DEFAULT NULL,
  PRIMARY KEY (`id_direccion`),
  INDEX `fk_direccion_1_idx` (`id_municipio` ASC) VISIBLE,
  CONSTRAINT `fk_direccion_1`
    FOREIGN KEY (`id_municipio`)
    REFERENCES `imagis`.`municipios` (`id_municipio`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`centros`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`centros` ;

CREATE TABLE IF NOT EXISTS `imagis`.`centros` (
  `id_centro` INT NOT NULL AUTO_INCREMENT,
  `nombre_centro` VARCHAR(100) NOT NULL,
  `id_direccion` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id_centro`),
  INDEX `fk_centros_1_idx` (`id_direccion` ASC) VISIBLE,
  CONSTRAINT `fk_centros_1`
    FOREIGN KEY (`id_direccion`)
    REFERENCES `imagis`.`direccion` (`id_direccion`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`licencias`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`licencias` ;

CREATE TABLE IF NOT EXISTS `imagis`.`licencias` (
  `id_licencia` INT NOT NULL AUTO_INCREMENT,
  `titulo` VARCHAR(100) NULL DEFAULT NULL,
  `costo` DOUBLE NULL DEFAULT NULL,
  `fecha_inicio` DATE NULL DEFAULT NULL,
  `fecha_final` DATE NULL DEFAULT NULL,
  `id_centro` INT NULL DEFAULT NULL,
  `id_modulo` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id_licencia`),
  INDEX `fk_licencias_1_idx` (`id_modulo` ASC) VISIBLE,
  INDEX `fk_licencias_2_idx` (`id_centro` ASC) VISIBLE,
  CONSTRAINT `fk_licencias_1`
    FOREIGN KEY (`id_modulo`)
    REFERENCES `imagis`.`modulos` (`id_modulo`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_licencias_2`
    FOREIGN KEY (`id_centro`)
    REFERENCES `imagis`.`centros` (`id_centro`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`roles`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`roles` ;

CREATE TABLE IF NOT EXISTS `imagis`.`roles` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `rol` VARCHAR(50) NOT NULL,
  `nombre_de_usuario` VARCHAR(45) NULL,
  `carne_de_identidad` VARCHAR(45) NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`roles_de_usuario`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`roles_de_usuario` ;

CREATE TABLE IF NOT EXISTS `imagis`.`roles_de_usuario` (
  `id_usuario` INT NOT NULL,
  `id_rol` INT NOT NULL,
  INDEX `fk_roles_de_usuario_1_idx` (`id_usuario` ASC) VISIBLE,
  INDEX `fk_roles_de_usuario_2_idx` (`id_rol` ASC) VISIBLE,
  CONSTRAINT `fk_roles_de_usuario_1`
    FOREIGN KEY (`id_usuario`)
    REFERENCES `imagis`.`usuarios` (`id_usuario`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_roles_de_usuario_2`
    FOREIGN KEY (`id_rol`)
    REFERENCES `imagis`.`roles` (`id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`especialidades`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`especialidades` ;

CREATE TABLE IF NOT EXISTS `imagis`.`especialidades` (
  `id_especialidad` INT NOT NULL AUTO_INCREMENT,
  `especialidad` VARCHAR(200) NULL,
  PRIMARY KEY (`id_especialidad`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`personal`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`personal` ;

CREATE TABLE IF NOT EXISTS `imagis`.`personal` (
  `id_persona` INT NOT NULL,
  `id_direccion` INT NULL DEFAULT NULL,
  `id_usuario` INT NULL DEFAULT NULL,
  `id_centro` INT NULL DEFAULT NULL,
  `id_especialidad` INT NULL DEFAULT NULL,
  `id_pais` INT NULL DEFAULT NULL,
  `nombre` VARCHAR(100) NULL,
  `primer_apellido` VARCHAR(100) NULL,
  `segundo_apellido` VARCHAR(100) NULL,
  `sexo` VARCHAR(45) NULL,
  `telefono` VARCHAR(45) NULL DEFAULT NULL,
  `pasaporte` VARCHAR(45) NULL DEFAULT NULL,
  `carne_de_identidad` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`id_persona`),
  INDEX `fk_personas_1_idx` (`id_direccion` ASC) VISIBLE,
  INDEX `fk_personas_2_idx` (`id_usuario` ASC) VISIBLE,
  INDEX `fk_personas_3_idx` (`id_centro` ASC) VISIBLE,
  INDEX `fk_personas_4_idx` (`id_especialidad` ASC) VISIBLE,
  INDEX `fk_personal_1_idx` (`id_pais` ASC) VISIBLE,
  CONSTRAINT `fk_personas_1`
    FOREIGN KEY (`id_direccion`)
    REFERENCES `imagis`.`direccion` (`id_direccion`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_personas_2`
    FOREIGN KEY (`id_usuario`)
    REFERENCES `imagis`.`usuarios` (`id_usuario`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_personas_3`
    FOREIGN KEY (`id_centro`)
    REFERENCES `imagis`.`centros` (`id_centro`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_personas_4`
    FOREIGN KEY (`id_especialidad`)
    REFERENCES `imagis`.`especialidades` (`id_especialidad`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_personal_1`
    FOREIGN KEY (`id_pais`)
    REFERENCES `imagis`.`paises` (`id_pais`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`reportes`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`reportes` ;

CREATE TABLE IF NOT EXISTS `imagis`.`reportes` (
  `id_reporte` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(100) NULL,
  `id_usuario` INT NULL DEFAULT NULL,
  `id_personal` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id_reporte`),
  INDEX `fk_reportes_1_idx` (`id_usuario` ASC) VISIBLE,
  INDEX `fk_reportes_2_idx` (`id_personal` ASC) VISIBLE,
  CONSTRAINT `fk_reportes_1`
    FOREIGN KEY (`id_usuario`)
    REFERENCES `imagis`.`usuarios` (`id_usuario`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_reportes_2`
    FOREIGN KEY (`id_personal`)
    REFERENCES `imagis`.`personal` (`id_persona`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`dispositivos`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`dispositivos` ;

CREATE TABLE IF NOT EXISTS `imagis`.`dispositivos` (
  `id_dispositivo` INT NOT NULL AUTO_INCREMENT,
  `id_modulo` INT NULL DEFAULT NULL,
  `tipo` VARCHAR(45) NULL,
  `marca` VARCHAR(45) NULL,
  `modelo` VARCHAR(45) NULL,
  PRIMARY KEY (`id_dispositivo`),
  INDEX `fk_dispositivos_1_idx` (`id_modulo` ASC) VISIBLE,
  CONSTRAINT `fk_dispositivos_1`
    FOREIGN KEY (`id_modulo`)
    REFERENCES `imagis`.`modulos` (`id_modulo`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`servicios`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`servicios` ;

CREATE TABLE IF NOT EXISTS `imagis`.`servicios` (
  `id_servicio` INT NOT NULL AUTO_INCREMENT,
  `id_centro` INT NULL DEFAULT NULL,
  `nombre_del_servicio` VARCHAR(100) NOT NULL,
  `nombre_del_departamento` VARCHAR(100) NULL,
  `costo` DOUBLE NULL DEFAULT 0,
  PRIMARY KEY (`id_servicio`),
  INDEX `fk_servicios_1_idx` (`id_centro` ASC) VISIBLE,
  CONSTRAINT `fk_servicios_1`
    FOREIGN KEY (`id_centro`)
    REFERENCES `imagis`.`centros` (`id_centro`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`modulos_de_usuarios`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`modulos_de_usuarios` ;

CREATE TABLE IF NOT EXISTS `imagis`.`modulos_de_usuarios` (
  `id_modulo` INT NOT NULL,
  `id_usuario` INT NOT NULL,
  INDEX `fk_modulos_de_usuarios_1_idx` (`id_modulo` ASC) VISIBLE,
  INDEX `fk_modulos_de_usuarios_2_idx` (`id_usuario` ASC) VISIBLE,
  CONSTRAINT `fk_modulos_de_usuarios_1`
    FOREIGN KEY (`id_modulo`)
    REFERENCES `imagis`.`modulos` (`id_modulo`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_modulos_de_usuarios_2`
    FOREIGN KEY (`id_usuario`)
    REFERENCES `imagis`.`usuarios` (`id_usuario`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`servidores`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`servidores` ;

CREATE TABLE IF NOT EXISTS `imagis`.`servidores` (
  `id_servidor` INT NOT NULL AUTO_INCREMENT,
  `aet` VARCHAR(18) NULL,
  `host` VARCHAR(100) NULL,
  `puerto` INT UNSIGNED NULL,
  `tipo_servidor` ENUM('Remoto', 'Local') NULL DEFAULT 'Local',
  `descripcion` VARCHAR(200) NULL,
  PRIMARY KEY (`id_servidor`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`recursos`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`recursos` ;

CREATE TABLE IF NOT EXISTS `imagis`.`recursos` (
  `id_recurso` INT NOT NULL AUTO_INCREMENT,
  `tipo_de_recurso` VARCHAR(100) NULL,
  `descripcion` VARCHAR(100) NULL,
  PRIMARY KEY (`id_recurso`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `imagis`.`actualizacion`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `imagis`.`actualizacion` ;

CREATE TABLE IF NOT EXISTS `imagis`.`actualizacion` (
  `id_actualizacion` INT NOT NULL AUTO_INCREMENT,
  `fecha` DATE NULL,
  `id_persona` INT NULL DEFAULT NULL,
  `id_centro` INT NULL DEFAULT NULL,
  `id_modulo` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id_actualizacion`),
  INDEX `fk_actualizacion_1_idx` (`id_centro` ASC) VISIBLE,
  INDEX `fk_actualizacion_2_idx` (`id_persona` ASC) VISIBLE,
  INDEX `fk_actualizacion_3_idx` (`id_modulo` ASC) VISIBLE,
  CONSTRAINT `fk_actualizacion_1`
    FOREIGN KEY (`id_centro`)
    REFERENCES `imagis`.`centros` (`id_centro`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_actualizacion_2`
    FOREIGN KEY (`id_persona`)
    REFERENCES `imagis`.`personal` (`id_persona`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_actualizacion_3`
    FOREIGN KEY (`id_modulo`)
    REFERENCES `imagis`.`modulos` (`id_modulo`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
