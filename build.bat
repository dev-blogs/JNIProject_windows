set BUILD_JAVA=build_java
set BUILD_C=build_c
set SRC_JAVA=src\java
set SRC_C=src\c
set JAVA_NAME=JNIProject
set HEADER_NAME=%JAVA_NAME%
set DLL_NAME=JNIProject
set HEADERS_FROM_JAVA_DIR=C:\bin\Java\32\jdk1.7.0_71\include

:: clear %BUILD_JAVA% directory
rd /s /q %BUILD_JAVA%
if exist %BUILD_JAVA% rd /s /q %BUILD_JAVA%

:: make %BUILD_JAVA% and %GENERATED_DIR% directories
mkdir %BUILD_JAVA%

:: clear %BUILD_C% directory
rd /s /q %BUILD_C%
if exist %BUILD_C% rd /s /q %BUILD_C%

::make %BUILD_C% and %GENERATED_DIR% directories
mkdir %BUILD_C%

:: compilation and generate header
javac -d %BUILD_JAVA% %SRC_JAVA%\com\task\%JAVA_NAME%.java
:: generate header
javah -d %SRC_C% -cp %BUILD_JAVA% com.task.%JAVA_NAME%

:: create MathExpressions.dll
g++ -shared -o %BUILD_C%\MathExpressions.dll %SRC_C%\mathExpressions.cpp

:: create JNIProject.dll lib which java application works with
g++ -Wl,--add-stdcall-alias -I%HEADERS_FROM_JAVA_DIR% -I%HEADERS_FROM_JAVA_DIR%\win32 -shared -o %BUILD_C%\%DLL_NAME%.dll %SRC_C%\%DLL_NAME%.cpp

:: copy headers to %BUILD_C% directory
copy %SRC_C%\MathExpressions.h %BUILD_C%
copy %SRC_C%\com_task_JNIProject.h %BUILD_C%

:: run java program
java -Djava.library.path=%BUILD_C% -cp %BUILD_JAVA% com.task.%JAVA_NAME%