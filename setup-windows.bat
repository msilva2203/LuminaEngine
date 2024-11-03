@echo off
set PREMAKE_ACTION=vs2022

@echo on
call %~dp0Engine/Build/Windows/premake-5.0.0-beta2-windows/premake5.exe %PREMAKE_ACTION%

@echo off
pause