#!/usr/bin/env python
# Build the project on AppVeyor.

import os
from subprocess import check_call

build = os.environ['BUILD']
config = os.environ['CONFIGURATION']
platform = os.environ.get('PLATFORM')
path = os.environ['PATH']
cmake_command = ['cmake', '-DFMT_PEDANTIC=ON', '-DCMAKE_BUILD_TYPE=' + config, '-DASSIMP_BUILD_TESTS=OFF', '-DGLFW_BUILD_TESTS=OFF', '-DASSIMP_BUILD_ASSIMP_TOOLS=OFF', '-DGLFW_BUILD_EXAMPLES=OFF',  '-DGLFW_BUILD_DOCS=OFF']
if build == 'mingw':
  cmake_command.append('-GMinGW Makefiles')
  build_command = ['mingw32-make', '-j4']
  test_command = ['mingw32-make', 'test']
  # Remove the path to Git bin directory from $PATH because it breaks MinGW config.
  path = path.replace(r'C:\Program Files (x86)\Git\bin', '')
  os.environ['PATH'] = r'C:\MinGW\bin;' + path
else:
  # Add MSBuild 14.0 to PATH as described in
  # http://help.appveyor.com/discussions/problems/2229-v140-not-found-on-vs2105rc.
  #os.environ['PATH'] = r'C:\Program Files (x86)\MSBuild\14.0\Bin;' + path
  generator = 'Visual Studio 12 2013'
  if platform == 'x64':
    generator += ' Win64'
  cmake_command.append('-G' + generator)
  build_command = ['cmake', '--build', '.']
  #test_command = ['echo', '%PATH%']

print path
check_call(cmake_command)
check_call(build_command)
#check_call(test_command)
