################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/useMyLib.cpp \
../src/AllTests.cpp \
../src/Foo.cpp \
../src/FooTest.cpp \
../src/FunPara.cpp \
../src/test/testFunPara.cpp \
../src/ModifyArray.cpp \
../src/test/testModifyArray.cpp \
../src/Car.cpp \
../src/Benz.cpp \
../src/test/testBenz.cpp \
../src/BasicClass.cpp \
../src/test/testBasicClass.cpp \
../src/MyString.cpp \
../src/test/testMyString.cpp \
../src/test/testFunTemplate.cpp

OBJS += \
./src/useMyLib.o \
./src/AllTests.o \
./src/Foo.o \
./src/FooTest.o \
./src/FunPara.o \
./src/test/testFunPara.o \
./src/ModifyArray.o \
./src/test/testModifyArray.o \
./src/Car.o \
./src/Benz.o \
./src/test/testBenz.o \
./src/BasicClass.o \
./src/test/testBasicClass.o \
./src/MyString.o \
./src/test/testMyString.o \
./src/test/testFunTemplate.o

CPP_DEPS += 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -Wall -c $(@:%.o) -I/home/dongronghui/workspace/useMyLib/include -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


