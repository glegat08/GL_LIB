@echo off
setlocal enabledelayedexpansion

set BUILD_DIR=build
set CONFIG=Release

REM --- Detecter la version de CMake ---
for /f "tokens=3" %%v in ('cmake --version 2^>nul ^| findstr /C:"cmake version"') do set CMAKE_VERSION=%%v
if not defined CMAKE_VERSION (
    echo ERREUR : CMake n'est pas installe ou pas dans le PATH.
    pause
    exit /b 1
)

echo CMake version detectee : %CMAKE_VERSION%

REM Extraire le numero majeur.mineur
for /f "tokens=1,2 delims=." %%a in ("%CMAKE_VERSION%") do (
    set CMAKE_MAJOR=%%a
    set CMAKE_MINOR=%%b
)

set /a CMAKE_NUM=%CMAKE_MAJOR%*100+%CMAKE_MINOR%

REM --- Nettoyer l'ancien build ---
if exist %BUILD_DIR% rmdir /s /q %BUILD_DIR%

REM --- Tester VS 2026 si CMake 3.30+ ---
if %CMAKE_NUM% GEQ 330 (
    echo Testing Visual Studio 2026...
    mkdir %BUILD_DIR%
    cmake -S . -B %BUILD_DIR% -G "Visual Studio 18 2026" -A x64 >nul 2>&1
    if !ERRORLEVEL! EQU 0 (
        set VS_GENERATOR=Visual Studio 18 2026
        goto :build
    )
    rmdir /s /q %BUILD_DIR%
)

REM --- Tester VS 2022 si CMake 3.21+ ---
if %CMAKE_NUM% GEQ 321 (
    echo Testing Visual Studio 2022...
    mkdir %BUILD_DIR%
    cmake -S . -B %BUILD_DIR% -G "Visual Studio 17 2022" -A x64 >nul 2>&1
    if !ERRORLEVEL! EQU 0 (
        set VS_GENERATOR=Visual Studio 17 2022
        goto :build
    )
    rmdir /s /q %BUILD_DIR%
)

REM --- Tester VS 2019 si CMake 3.14+ ---
if %CMAKE_NUM% GEQ 314 (
    echo Testing Visual Studio 2019...
    mkdir %BUILD_DIR%
    cmake -S . -B %BUILD_DIR% -G "Visual Studio 16 2019" -A x64 >nul 2>&1
    if !ERRORLEVEL! EQU 0 (
        set VS_GENERATOR=Visual Studio 16 2019
        goto :build
    )
    rmdir /s /q %BUILD_DIR%
)

REM --- Tester VS 2017 si CMake 3.7+ ---
if %CMAKE_NUM% GEQ 307 (
    echo Testing Visual Studio 2017...
    mkdir %BUILD_DIR%
    cmake -S . -B %BUILD_DIR% -G "Visual Studio 15 2017" -A x64 >nul 2>&1
    if !ERRORLEVEL! EQU 0 (
        set VS_GENERATOR=Visual Studio 15 2017
        goto :build
    )
    rmdir /s /q %BUILD_DIR%
)

echo ERREUR : Aucune version de Visual Studio compatible detectee.
echo Verifie que Visual Studio est installe avec le workload C++.
pause
exit /b 1

:build
echo.
echo =========================================
echo Using generator: %VS_GENERATOR%
echo =========================================
echo.

cmake --build %BUILD_DIR% --config %CONFIG%
if %ERRORLEVEL% NEQ 0 (
    echo ERREUR : Compilation echouee.
    pause
    exit /b 1
)

echo.
echo =========================================
echo Build termine avec succes en %CONFIG%.
echo =========================================
pause