# Travolution

Each year, there are thousands of highway deaths and tens of thousands of serious injuries due to "Run-Off-Road" accidents. Everything from simple driver inattentiveness, to fatigue, callousness, to drunk driving, is responsible. Simple sensors can be fitted inside vehicles embedded with various features like, automatic collision notification, speed control which can give impetus to an efficient road safety system. The features that are proposed in this work are: Automatic collision notification that gives notification to the victim's relative,Speed control alters speed in different zones, Horn control prevents honking in horn prohibited zone, Alcohol detection detects drunk driving. The project and implementation presented here is a novel approach towards vehicle navigation and safety implementation. One can develop a system which will automatically sense such traffic signs automatically and accordingly control the vehicle speed or the horn forcibly in such zones. As the whole project and implementation is not just limited for these few functions, this project and implementation can be made mandatory. That way one can provide a more reliable security device and streamline traffic flow. 



                                             2.1.1 Transmitter Section Block Diagram
  
  ![alt text](https://github.com/Krrish3398/Travolution/blob/master/TX.png)

The module designed here mainly consists of three data transmitting modules for two different zones i.e., one for no horn zone, one for speed restriction zone entrance, one for speed restriction zone exit and single data receiving module i.e., the vehicle. The data transmitting module consisting of microcontroller 89C2051, 555 timer and optical (IR Transmitter) sensor, generates pre-programmed digital data from Microcontroller and it is modulated with 38 KHz frequency generated by the timer IC. This modulated digital information is radiated into the air through an optical sensor. The data receiving module consisting of Arduino Microcontroller, gas sensor MQ2 for alcohol detection, bump sensor for collision detection, Bluetooth module for transmitting the accident information, TSOP 1738 (IR Receiver), Relays and DC motor that receives the digital data through optical sensor (TSOP 1738) and fed to arduino Microcontroller. The Microcontroller decodes this data and accordingly controls the DC motor speed through the relays.
                                          
                                                2.1.2 Receiver Section Block Diagram 

![alt text](https://github.com/Krrish3398/Travolution/blob/master/RX_color%20.jpg)


Once the start button is pressed in the module, the controller drives the DC motor through the relays by which the vehicle will be moving. The relay used in this project work is an electromagnetic relay. This relay is nothing but a switch, which operates electromagnetically.The controller controls the movement of the vehicle through the DC motor by providing different voltages to vary its speed by the relays.

The controller switches ON the relay that provides +12v to the DC motor by which the vehicle moves at normal speed. And when the vehicle enters the zone where the IR transmitted signal will be received and decoded by the controller on the vehicle, the controller switches OFF the relay 1 and switches ON the other relay that provides +9V to the DC motor, due to which the vehicle moves at reduced speed in the particular zone. And once the vehicle receives the IR signal at the end of the zone, the controller operates the vehicle at normal speed again. Here relays are required to drive the DC motor because the controller will not be able to deliver the required power levels for the DC motor to be operating i.e., 12V or 9V and 150 milliamps of current.

The gas (alcohol) sensor is connected to the Op-Amp as one input and a reference voltage is fed to the other input. When the alcohol fumes are more than the set value of the op-amp, the output of the op-amp will become high, which is fed to the controller. Here the op-amp is connected as a comparator that compares with the reference value and provides a logic signal to the controller.

Limit switch is one kind of force sensor. In this project, it is used to detect accidents when the vehicle collides with obstacles and this switch is interfaced with a microcontroller as input signal. This limit switch is having a long lever & when little pressure is applied to the lever, the switch will be activated automatically. Limit switches are small and normally used as bumper detection in robot application. A thin aluminum plate and a spring are placed together with the limit switch, which act like a long push button. There are two types of limit switch which are normally open and normally closed. Commonly used is the normally open, when the accident occurs, logic low, ‘0’ will be sent to the microcontroller. In contrast, when the vehicle does not detect any obstacles (no collision or contact), the microcontroller will detect logic ‘high’ 1 but it more depends on how the connection of limit switches.
                                                          
                                                          2.2 Circuit Diagram 
 
![alt text](https://github.com/Krrish3398/Travolution/blob/master/New-Microsoft-Office-Word-Document-_2_.jpg)


