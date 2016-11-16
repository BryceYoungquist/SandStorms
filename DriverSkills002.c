#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    leftP,          sensorPotentiometer)
#pragma config(Sensor, in3,    rightP,         sensorPotentiometer)
#pragma config(Sensor, in4,    light,          sensorReflection)
#pragma config(Sensor, in5,    Battery,        sensorAnalog)
#pragma config(Sensor, dgtl1,  leftBase,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightBase,      sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftSonar,      sensorSONAR_mm)
#pragma config(Sensor, dgtl7,  rightSonar,     sensorSONAR_mm)
#pragma config(Sensor, dgtl9,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl10, Bumper,         sensorTouch)
#pragma config(Sensor, dgtl11, Red,            sensorLEDtoVCC)
#pragma config(Motor,  port1,           FR,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           BL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           L1A,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           L2A,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           R1A,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           R2A,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           BR,            tmotorVex393_MC29, openLoop)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)
int autonomousMode = 1;
int driverControlModeCount = 1;
#pragma DebuggerWindows("VexLCD")
void clearLCD ()
{bLCDBacklight = true;
	clearLCDLine(0);
	clearLCDLine(1);
	SensorValue[leftBase] = 0;
	SensorValue[rightBase] = 0;
}

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
void TankDrive()
{{
motor[FL]=Vexrt[ch3];
motor[FR]=vexRT[Ch2];
motor[Bl]=vexRT[CH3];
motor[BR]=vexRT[Ch2]:
}

	if( vexRT[ Btn6D ])
	{
		if(SensorValue[rightP] < 900;
		motor[L1A] =127;
		motor[L2A] = 127;
		motor[R1A] = 127;
		motor[R2A] = 127;
	}
	else if(vexRT[ Btn6U ])
	{
		if(SensorValue[rightP] < 900;
		motor[L1A] = -127;
		motor[L2A] = -127;
		motor[R1A] = -127;
		motor[R2A] = -127;
	}

	else
	{
		motor[L1A] =0;
		motor[L2A] = 0;
		motor[R1A] = 0;
		motor[R2A] = 0;

}}
void autonomous1 ()
{

}

void autonomous2 ()
{

}

clearLCD()

	while (nLCDButtons != 2)
	{
		displayLCDCenteredString(0,"Autonomous");
		displayLCDNumber(0,14,autonomousMode,2);
		displayLCDCenteredString(1,"<<  Selection >>");
		if (nLCDButtons == 1)
		{
			autonomousMode--;
			while(nLCDButtons == 1){wait1Msec(10);}
		}
		if (nLCDButtons == 4)
		{
			autonomousMode++;
			while(nLCDButtons == 4){wait1Msec(10);}
		}
		if (autonomousMode < 1)
		{
			autonomousMode = 12;
		}
		else if (autonomousMode > 12)
		{
			autonomousMode = 1;
		}
		wait1Msec(10);
	}
	clearLCD();
}


/////////////////////////////////////////////////////Nothing


void nothingOnScreen ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Currently");
	displayLCDCenteredString(1,"Empty");
}
///////////////////////////////////////////////////////Batterydisplay
void displayBatteryValues ()

{bLCDBacklight = true;

	string mainBatteryVoltage, backupBatteryVoltage;

	displayLCDString(0,0,"Main:");

	displayLCDString(1,0,"BackUp:");

	sprintf(mainBatteryVoltage,"%1.2f%c",nImmediateBatteryLevel/1000.0,'V');

	sprintf(backupBatteryVoltage,"%1.2f%c",BackupBatteryLevel/1000.0,'V');

	displayLCDString(0,8,mainBatteryVoltage);

	displayLCDString(1,8,backupBatteryVoltage);
}
//////////////////////////////////////////////////////SwapAuton

void swapAuton ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Autonomous");
	displayLCDCenteredString(1,"Swap");
	displayLCDNumber(0,14,autonomousMode,2);
	if (nLCDButtons == 2)
	{
		autonomousMode++;
		while(nLCDButtons == 2){wait1Msec(10);}
	}
	if (autonomousMode > 12)
	{
		autonomousMode = 1;
	}
}
/////////////////////////////////////////////////////Start Acton
void startAuton ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"press to");
	displayLCDCenteredString(1,"start autonomous");
}
//////////////////////////////////////////////////////GYRO
void gyroValue ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Gyro Value");
	displayLCDNumber(1,5,SensorValue[gyro],5);
	if (nLCDButtons == 2)
	{bLCDBacklight = true;
		SensorType[gyro]=sensorNone;
		wait1Msec(1200);
		SensorType[gyro]=sensorGyro;
		wait1Msec(2000);
	}
}
////////////////////////////////////////////////////Potentiometer
void displayPotentiometerValues ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Pot Values");
	displayLCDNumber(1,2,SensorValue[leftP],4);
	displayLCDNumber(1,10,SensorValue[rightP],4);
}
////////////////////////////////////////////////////Encoders
void displayEncoderValues ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Left    Right");
	float ldec = abs(100*SensorValue[leftBase]/360);
	float rdec = abs(100*SensorValue[rightBase]/360);
	displayLCDNumber(1,1,ldec,2);
	displayLCDNumber(1,9,rdec,2);
	if (nLCDButtons == 2)
	{
		SensorValue[leftBase] = 0;
		SensorValue[rightBase] = 0;
	}
}
////////////////////////////////////////////////////[ColorSensorValue]

void displayColorSensorValue()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Color Sensor");
	displayLCDNumber(1,6,SensorValue[light],4);
}
////////////////////////////////////////////////////[UltrasonicValues]
void displayUltrasonicValues ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Ultrasonics");
	displayLCDNumber(1,2,SensorValue[leftSonar],4);
	displayLCDNumber(1,9,SensorValue[rightSonar],4);
}
////////////////////////////////////////////////////[DigitalInputs]
void displayDigitalInputs ()
{bLCDBacklight = true;
	displayLCDCenteredString(0,"Digital Inputs");
	displayLCDNumber(1,3,SensorValue[Bumper],1);
	displayLCDNumber(1,9,SensorValue[limitSwitch],1);
}
////////////////////////////////////////////////////
task driverControlViewValues ()
{bLCDBacklight = true;
	clearLCD ();
	while (true)
	{

		if (nLCDButtons == 1)
		{
			driverControlModeCount--;
			clearLCD ();
			while(nLCDButtons == 1){wait1Msec(10);}
		}
		if (nLCDButtons == 4)
		{
			driverControlModeCount++;
			clearLCD ();
			while(nLCDButtons == 4){wait1Msec(10);}
		}
		if (driverControlModeCount < 1)
		{
			driverControlModeCount = 12;
		}
		else if (driverControlModeCount > 12)
		{
			driverControlModeCount = 1;
		}

		switch (driverControlModeCount)
		{
		case 1:
			displayBatteryValues();
			break;
		case 2:
			swapAuton();
			break;
		case 3:
			startAuton();
			break;
		case 4:
			gyroValue();
			break;
		case 5:
			displayPotentiometerValues();
			break;
		case 6:
			displayEncoderValues();
			break;
		case 7:
			displayColorSensorValue();
			break;
		case 8:
			displayUltrasonicValues();
			break;
		case 9:
			displayDigitalInputs();
			break;
		case 10:
			nothingOnScreen();
			break;
		case 11:
			nothingOnScreen();
			break;
		case 12:
			nothingOnScreen();
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                         Driver Skills Template
//
// This is a template for the driver skills competition. It is identical in structure to
// the standard competition template except that the two "#pragma' statements above (and
// copied below) adjust the time limits for the competition.
//				#pragma autonomousDuration(0)
//				#pragma userControlDuration(60)
// The autonomous duration for "Driver Skills" is zero; i.e. there is no autonomous phase.
// The user control duration is 60 seconds
//
// NOTE: The above two pragmas only impact the Crystal implementation. For systems using
//       VEXNET, the VEXNET system ignores these statements as it has the durations
//       for the competition built-in.
//
// Whenever this user program is run, the duration is automatically sent to the VEX master
// processor. The master CPU will only accept these commands once per power=on cycle. So, it's
// best to power cycle your VEX to ensure that they get recognized in case you were
// previously running a standard competition program with different durations.
//
// Testing Via Crystals:
// ====================
//
// The procedure to test a Driver Skills program using the crystals is as follows:
//
// 1. Turn off power to the Crystal transmitter/joysticks.
//
// 2. Turn on your VEX so that the Driver Skills program is running.
//
// 3. Driver skills program segment of your program will start running. At the end of 60
//    seconds the VEX Master CPU will turn off the motors.
//
// 4. Repeat the above sequence
//
//
// Testing Via VEXNET Using VEXNET Competition Switch
// ==================================================
//
// The procedure to test a Driver Skills program using VEXNET Competition Switch is as follows:
//
// 1. Set the two switches on the Competition switch to "DISABLE" and "USER CONTROL"
//
// 2. Start the Driver skills program
//
// 3. Set Switch to ENABLE from DISABLE
//
// 4. You need to manually time the 60 second duration.
//
// 5. Set Switch to DISABLE
//
// 6. Repeat from step (3) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
//
// Testing Via VEXNET Using ROBOTC IDE
// ==================================================
//
// It is not necessary to own a VEXNET switch. ROBOTC has a test window that allows the same functionality.
// The test window has three buttons for "DISABLE", "AUTONOMOUS", "USER CONTROL".
//
// 1. Open the ROBOTC Debugger. Then open the "Competition Control" Debugger window.
//
// 2. Start your Driver Skills program running.
//
// 3. Click the "DISABLED" button on the "Competition Control" window.
//
// 4. Click the "USER CONTROL" button on the "Competition Control" window.
//
// 5. You need to manually time the 60 second duration.
//
// 6. Click the "DISABLED" button on the "Competition Control" window.
//
// 7. Repeat from step (4) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// The "Driver Skills" competition has no autonomous phase. Simply leave the following
// placeholder.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	if (autonomousMode == 1)
	{
		autonomous1();
	}
	else if (autonomousMode == 2)
	{
		autonomous2();
	}  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	clearLCD();
	startTask(driverControlViewValues);
	while (true)
	{
		TankDrive ();

		if ((driverControlModeCount==3&&nLCDButtons==2)||vexRT[Btn7R]==1)
		{
			startTask(autonomous);
			wait1Msec(15000);
			stopTask(autonomous);
		}
		wait1Msec(20);

}}
