# Lorena

Lorena es un sistema operativo escrito en C, C++ y Ensamblador basado en [NextDivel](https://github.com/aarroyoc/next-divel).

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

Lorena se distribuye bajo la licencia GPL 3.
