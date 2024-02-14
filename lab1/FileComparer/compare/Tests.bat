@echo off

SET MyProgram="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
) 

REM Check empty file
%MyProgram% Empty.txt Empty.txt || goto err
echo Test 1 passed

REM Тесты прошли успешно
echo All testts passed successfuly
exit /B 0

REM Обнаружена ошибка
:err
echo Test failed
exit /B 1