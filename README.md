# Arduino-Solar-Tracker
My first project on a circuit based-code written in Arduino IDE which runs on the syntax of CPP. 

Arduino-Based Sun Tracker Project

This repository contains the code and documentation for an Arduino-based Sun Tracker system, designed to increase the efficiency of solar panels by continuously adjusting their position to face the sun throughout the day. This project demonstrates how to leverage Arduino microcontrollers, light sensors, and servo motors to create a functional dual-axis tracking system.

Features:

	•	Dual-Axis Tracking: The system tracks the sun’s movement in both horizontal (azimuth) and vertical (altitude) axes, ensuring the solar panel is always aligned for maximum energy capture.
	•	Light Sensors (LDRs): Light Dependent Resistors (LDRs) are used to detect sunlight intensity and provide input to the Arduino for calculating the optimal panel orientation.
	•	Servo Motor Control: Servo motors are controlled by the Arduino to adjust the solar panel’s position based on sensor data.
	•	Energy Efficiency: Improves solar energy harvesting by increasing the panel’s exposure to direct sunlight, potentially boosting efficiency by up to 40% over fixed installations.
	•	Self-Sustaining: Can be powered by a solar panel, making it suitable for off-grid applications.
	•	Customizable: The design is scalable and adaptable for different sizes of solar panels and installations.

Components:

	•	Arduino Uno (or any compatible microcontroller)
	•	4x Light Dependent Resistors (LDRs)
	•	2x Servo Motors (for horizontal and vertical movement)
	•	Solar Panel (for demonstration or full use)
	•	Resistors and wiring for circuit connections
	•	Mounting frame for the solar panel

How It Works:

	1.	Sensors: Four LDRs are placed in different positions around the solar panel to detect sunlight from multiple angles.
	2.	Arduino Processing: The Arduino continuously reads the LDR values, determines the direction of the brightest light source, and calculates the angle adjustments.
	3.	Servo Control: The Arduino controls the servo motors to adjust the solar panel’s position in real-time, following the sun’s movement from east to west and adjusting its tilt for optimal energy capture.
	4.	Energy Harvesting: The aligned solar panel collects maximum sunlight throughout the day, improving overall energy efficiency.
