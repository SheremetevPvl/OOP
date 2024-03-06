@echo off

REM "$(ProjectDir)Tests.bat" "$(TargetPath)"
SET MyProgram="%~1"

REM Flip empty number
%MyProgram%  && goto err
echo Test 1 success

REM Flip 6 to 96
%MyProgram% 6 || goto err
echo Test 2 success

REM Flip number over 255
%MyProgram% 289 && goto err
echo Test 3 success

REM Flip string or char
%MyProgram% char && goto err
echo Test 4 success

REM Flip number over 255
%MyProgram% 256 && goto err
echo Test 5 success

REM Flip number under 0
%MyProgram% -1 && goto err
echo Test 6 success

REM Успешные тесты
echo All tests passed succesfuly
exit /B 0
REM Не успешные тесты
:err
echo Test Failed
exit /B 1