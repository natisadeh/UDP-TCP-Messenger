################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ChatRoom.cpp \
../src/LoginAndRegister.cpp \
../src/ScreenDisplay.cpp \
../src/ServerInfo.cpp \
../src/ServerManager.cpp \
../src/User.cpp 

OBJS += \
./src/ChatRoom.o \
./src/LoginAndRegister.o \
./src/ScreenDisplay.o \
./src/ServerInfo.o \
./src/ServerManager.o \
./src/User.o 

CPP_DEPS += \
./src/ChatRoom.d \
./src/LoginAndRegister.d \
./src/ScreenDisplay.d \
./src/ServerInfo.d \
./src/ServerManager.d \
./src/User.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/user/Desktop/workspace3/FinalProjectBeforeTest/Final/SocketUtils/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


