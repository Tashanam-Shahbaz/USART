# USART

### Description

A microcontroller/microprocessor-based application to operate a password-protected locker with machine-to-machine (M2M) communication incorporated in the design. Password is entered through a keypad and a digital display (LCD or seven-segment display) is used to show the current status of the locker. If the locker door is latched, password can be entered by the user to unlatch it. The password entered, by the user, is sent by the microcontroller (which we call the transmitter microcontroller) to another serially interfaced (UART) microcontroller (called the receiver microcontroller). At the receiver end, password entered is matched to the correct password of the respective locker.

### Components Used

- USART Transmitter and Receiver (Serial communication used between two devices)
- 4x4 Keypad (Used to enter password)
- 7 segment display (To show the status of the password protected locker)
- DC Motor

## Description of the Implementation

##### - Keypad:

We have used 4x4 keypad in this task. The keypad is used as an input device for the user that types the four-digit password to be sent to the transmitter. When the key is pressed GetKeyPressed function is used that returns the function.

##### - 7 segment display:

The seven-segment display is used an output device to show the status of the password protected locker. The status shown is “O” (the door is opened) or “C” (the door is closed). Initially, on seven segment display it shows C to indicate that the door is closed. When the user types in the correct password, it shows “O” on seven segment display. If the user types in the wrong password, “C” will be shown on seven segment display.

##### - UART Transmitter:

The user enters the password through a keypad. The password is sent serially from the transmitter to the receiver. If the password is valid, transmitter modifies contents of PORTAto show “O” on the 7-segment display otherwise it shows“C”.

##### - UART Receiver:

The correct password is already defined. The user then types the password, it is sent from the transmitter to the receiver. The receiver then matches the user typed password with the password that is already defined in the receiver. If the password is correct, it sends the message to the transmitter, then transmitter gives signal to the seven-segment display to show O (that the door is unlocked).

#####  - DC Motor:

The DC motor is stationary at the start. If the password entered by the user is valid, the motor starts rotating in clock-wise direction. On the other hand, if the password is invalid the motor remains stationary. When user press push button for reinitializing the system, DC motor rotate counter-Clock wise.

<img src="./schematices/schematices_1.png" alt="Alt text" title="Optional title">

<img src="./schematices/closed.png" alt="Alt text" title="Optional title">

<img src="./schematices/open.png" alt="Alt text" title="Optional title">
