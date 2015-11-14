cd ../..
IF exist fillwave_windows_build_vs ( echo directory exists ) ELSE ( mkdir fillwave_windows_build_vs && echo fillwave_windows_build_vs created)
mkdir fillwave_windows_build_vs
cd fillwave_windows_build_vs
cmake ../fillwave -G "Visual Studio 14 2015" -DBUILD_ASSIMP_TOOLS=OFF -DBUILD_SHARED_LIBS:BOOL=false -DASSIMP_BUILD_TESTS=OFF -DGLFW_BUILD_TESTS=OFF -DBUILD_ASSIMP_TOOLS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_DOCS=OFF
cmake --build .
pause