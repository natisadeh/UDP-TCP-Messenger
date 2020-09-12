################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/clientTest.cpp \
../src/main.cpp 

OBJS += \
./src/clientTest.o \
./src/main.o 

CPP_DEPS += \
./src/clientTest.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/user/Desktop/workspace3/FinalProjectBeforeTest/Final/SocketUtils/src" -I"/home/user/Desktop/workspace3/FinalProjectBeforeTest/Final/MCAStatic/src" -I"/home/user/Desktop/workspace3/FinalProjectBeforeTest/Final/MSAStatic/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


