DROP DATABASE IF EXISTS TD2;

CREATE DATABASE TD2;

USE TD2;

-- table Étudiant
CREATE TABLE Etudiant( numEtu INT PRIMARY KEY, nom VARCHAR(50) NOT NULL, prenom VARCHAR(50) NOT NULL);

-- table UE
CREATE TABLE UE( codeUE CHAR(10) PRIMARY KEY, libelle VARCHAR(100) NOT NULL, nb_heures INT);

-- table Enseignant
CREATE TABLE Enseignant( numProf INT PRIMARY KEY, nom VARCHAR(50) NOT NULL, prenom VARCHAR(50) NOT NULL, age INT, ville VARCHAR(50));

-- table Participe
CREATE TABLE Participe(numEtu INT, codeUE CHAR(10), noteCC FLOAT DEFAULT 0, noteExam FLOAT DEFAULT 0, FOREIGN KEY(numEtu) REFERENCES Etudiant(numEtu), FOREIGN KEY(codeUE) REFERENCES UE(codeUE), PRIMARY KEY(numEtu, codeUE));
