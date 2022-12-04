# PoloMan

## Project description

Polo Man is a project based on the `pololu 3Pi+` robot to explore the control of a robot based on magnetic fields. We want to be able to use the 3Pi+ `magnetometer (LIS3MDL)` to detect the surrounding magnetic field and to use an algorithm that allows the robot to actively lock the distance to the magnetic substance when it detects the presence of a magnetic substance in front of it, and to maintain the distance to the magnetic substance when it moves forward or backward. This means that the robot is able to follow the magnetic material in a non-contact manner.

![image-20221204203908346](https://s2.loli.net/2022/12/05/gsXv6AWBcHpGIrk.png)

## Project progress

* Beta 1.0 **Completed the magnetometer-related drive and calibration of the robot**
* Beta 2.0 **Conducted robot magnetometer schematic collection and experimented with relevant parameters**
* Beta 3.0 **Completed writing of the motor class and adaptation of the related programs and completed distance keeping**
* Beta 3.1 **Modified technical details and added light cues**

## Project test results

![image-20221204204006228](https://s2.loli.net/2022/12/05/qFLZIpdTsJYbXRh.png)

We have repeated the experiment several times using magnetic substances at different distances and the results are shown in the figure. After analyzing the results we concluded that `7-10 cm` from the central point of the robot is an extremely effective area for identifying magnetic substances.