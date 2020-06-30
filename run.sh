rm -r build
mkdir build
cd build

echo
echo " === Building... ==="
echo

cmake ..
make
cd ..

echo 
echo " === Rendering, about 20 seconds, result is test.ppm ... ==="
echo

./build/mraytracer
