# Calculador
Proyecto para prueba de concepto CI-CD con git, gcc, conan.io y jenkins

## Requisitos para compilar los fuentes
1. Tener instalado el cliente conan.io.
2. Tener instalado el compilador gcc.
3. Tener configurado el servidor conan-repo.

## Pasos para compilar
1. Clonar proyecto.
```
clone https://...
```
2. Crear carpeta build e ingresar a ella.
```
mkdir build && cd build
```
3. Instalar las dependencias del archivo conanfile.txt
```
conan install ..
```
4. Ir a la carpeta de fuentes src
```
cd ../src
```
5. Compilar
```
make
```

## Pasos para compilar (Forma Facil)
1. Clonar proyecto.
```
  clone https://...
```
2. Ejecutar script build.sh
```
  ./build.sh
```

## Ejecución
```
cd src && ./calculador
```
