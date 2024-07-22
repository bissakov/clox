@echo off

call vcvarsall.bat x64 > nul 2>&1
mkdir build > nul 2>&1
pushd build

cl -Fe: lox.exe -nologo -Oi -GR- -EHa- -MT -Gm- -Od -W4 -WX -wd4201 -wd4127 -wd4100 -FC -Z7 -Fm: lox.map ../src/main.c ../src/scanner.c ../src/win32_file_io.c ../src/utils.c /link -opt:ref

popd

echo:
