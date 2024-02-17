@echo off

SET MyProgram="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program                  
	exit /B 1
) 

REM Check empty file (Добавить даже тесты которые обрабатываются самой программой. Несуществуюищий файл + больше аргументов чем нужно) Лучше проверять ошибки в разных местах файлов
%MyProgram% Empty.txt Empty.txt || goto err
echo Test 1 passed

REM Check same files
%MyProgram% firstFile.txt secondFile.txt || goto err
echo Test 2 passed

REM Check different files with same num of strings
%MyProgram% FirstDiffFile.txt SecondDiffFile.txt || goto err
echo Test 3 passed

REM Check files with same first string but with different num of strings
%MyProgram% firstFilePlusOneStr.txt secondFile.txt || goto err
echo Test 4 passed

REM Check first file with empty file
%MyProgram% firstFile.txt Empty.txt || goto err
echo Test 5 passed

REM Тесты прошли успешно
echo All testts passed successfuly
exit /B 0

REM Обнаружена ошибка
:err
echo Test failed
exit /B 1