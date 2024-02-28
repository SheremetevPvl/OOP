@echo off

REM "$(ProjectDir)Tests.bat" "$(TargetPath)"
SET MyProgram="%~1"

REM Flip empty number
%MyProgram%  && goto err
echo Test 1 succes

REM Flip 6 to 96
%MyProgram% 6 || goto err
echo Test 2 succes

REM Flip number over 255
%MyProgram% 289 && goto err
echo Test 3 succes

REM Flip string or char
%MyProgram% char && goto err
echo Test 4 succes

REM Flip number over 255
%MyProgram% 256 && goto err
echo Test 5 succes

REM Flip number under 0
%MyProgram% -1 && goto err
echo Test 6 succes

REM Успешные тесты
echo All tests passed succesfuly
exit /B 0
REM Не успешные тесты
:err
echo Test Failed
exit /B 1