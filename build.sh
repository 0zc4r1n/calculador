echo "Eliminando carpeta build (si es que existe!)"
rm -rf build
echo "Creando carpeta build"
mkdir build && cd build
conan install ..
echo "Ingresando a src"
cd ../src
echo "Eliminano artefactos"
rm -rf *.o calculador
make
echo "Compilando Test"
cd test/src
make clean
make
