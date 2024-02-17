@echo off

SET MyProgram="%~1"

REM ������ �� ������� ��� ���������, ��������� ���� � ���������
if %MyProgram%=="" (
	echo Please specify path to program                  
	exit /B 1
) 

REM Check empty file (�������� ���� ����� ������� �������������� ����� ����������. ��������������� ���� + ������ ���������� ��� �����) ����� ��������� ������ � ������ ������ ������
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

REM ����� ������ �������
echo All testts passed successfuly
exit /B 0

REM ���������� ������
:err
echo Test failed
exit /B 1