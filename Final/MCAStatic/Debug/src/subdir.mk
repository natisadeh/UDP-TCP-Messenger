################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ClientInfo.cpp \
../src/ClientManager.cpp \
../src/ScreenDisplay.cpp \
../src/UDPmessenger.cpp 

OBJS += \
./src/ClientInfo.o \
./src/ClientManager.o \
./src/ScreenDisplay.o \
./src/UDPmessenger.o 

CPP_DEPS += \
./src/ClientInfo.d \
./src/ClientManager.d \
./src/ScreenDisplay.d \
./src/UDPmessenger.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/user/Desktop/workspace3/FinalProjectBeforeTest/Final/SocketUtils/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


