@echo off

SET MyProgram="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program                  
	exit /B 1
) 

REM Check non-existent or closed file
%MyProgram% NonExistentFile.txt "string to find" || goto err
echo Test 1 passed

REM Check empty file
%MyProgram% EmptyFile.txt "string to find" || goto err
echo Test 2 passed

REM Check file with one string, which we must find
%MyProgram% FileWithString.txt "string to find" || goto err
echo Test 3 passed

REM Check file with one string, which we mustn`t find
%MyProgram% FileWithString.txt "Error" || goto err
echo Test 4 passed

REM Check file with two string, where we must find our string
%MyProgram% FileWithTwoStrings.txt "second" || goto err
echo Test 5 passed

REM Check file with two string, where we mustn`t find our string
%MyProgram% FileWithTwoStrings.txt "Error" || goto err
echo Test 6 passed

REM Check file with two string, where we must find our string in two places
%MyProgram% FileWithTwoStrings.txt "string" || goto err
echo Test 7 passed

REM Успешные тесты
echo All tests passed succesfuly
exit /B 0
REM Не успешные тесты
:err
echo Test Failed
exit /B 1