@echo off

SET MyProgram="%~1"

REM ������ �� ������� ��� ���������, ��������� ���� � ���������
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
) 

REM Check empty file
%MyProgram% Empty.txt Empty.txt || goto err
echo Test 1 passed

REM ����� ������ �������
echo All testts passed successfuly
exit /B 0

REM ���������� ������
:err
echo Test failed
exit /B 1