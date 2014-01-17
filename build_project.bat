mkdir tracking_module_build
cd tracking_module_build
cmake -G "Visual Studio 10" ..\tracking_module
cmake --build . --config Debug