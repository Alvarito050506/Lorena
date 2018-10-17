# Lorena

[![Join the chat at https://gitter.im/Lorena-SO/Lobby](https://badges.gitter.im/Lorena-SO/Lobby.svg)](https://gitter.im/Lorena-SO/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge) [![Build Status](https://travis-ci.org/Alvarito050506/Lorena.svg?branch=master)](https://travis-ci.org/Alvarito050506/Lorena) [![Download LorenaSO](https://img.shields.io/sourceforge/dd/lorenaso.svg)](https://sourceforge.net/projects/lorenaso/files/latest/download)

Lorena es un sistema operativo escrito en C, C++ y Ensamblador basado en [NextDivel](https://github.com/aarroyoc/next-divel). Este es el canal "beta" en GitHub, estas versiones no son muy estables y pueden tener demasiados bugs.

## Prerequistos
* git
* CMake

## Compilar

Para compilar el sistema ingrese los siguientes comandos en la terminal:

```sh
git clone http://github.com/Alvarito050506/Lorena.git
cd ./Lorena/src
cmake .
make
```

## Crear imagen ISO

Para crear la imagen ISO del sistema ingrese estos comandos en la terminal:

```sh
cd ./Lorena/src
mv START.ELF ../sys/START.ELF
cd ../..
grub-mkrescue --product-name=Lorena --product-version=0.4.1 -o Lorena.iso Lorena
```

## Licencia

Lorena se distribuye bajo la licencia GPL 2.0.
