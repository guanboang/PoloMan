# PoloMan

## At first

Many thanks to **Minghao Xu** for all his hard work, cooperation is the best.
Many thanks to **Henry Hickson** for his guidance and help.
Many thanks to **Paul O'Dowd** for his encouragement and support.

If interested in our research, you can watch the project test video:

[PoloMan Video](https://youtu.be/IynohEmDLSs)

## Project Information 

**Task Domain**

We would like to attempt a linear magnetic substance capture and distance maintenance challenge using a 3Pi+ magnetometer and try to test the investigation of the capture range of different magnetic substances and polarized magnetic substances with different magnetic field strengths.

*我们想尝试用3Pi+磁力仪进行线性磁性物质捕获和距离保持的挑战，并尝试测试调查不同磁性物质和不同磁场强度的偏振磁性物质的捕获范围。*

**Hypothesis / Theory / Prediction:**

Thanks to the Magnetometer (LIS3MDL) built into the 3Pi+ robot, this allows 3Pi+ to detect the magnetic field strength in three dimensions. Therefore we want to be able to make the robot perceive its definite presence through the Magnetometer by means of a magnetic substance (e.g. iron) and always keep a certain distance from this magnetic substance, e.g. by moving the substance away from the robot to keep up and by moving the substance close to the robot to keep back. In addition, we will also try the effect of different magnetic substances as well as magnets on the magnetic capture range of the sensor. 

*由于3Pi+机器人中内置了磁力计（LIS3MDL），这使得3Pi+能够在三维空间中检测磁场强度。因此，我们希望能够通过磁性物质（如铁），使机器人通过磁力计感知其明确的存在，并始终与该磁性物质保持一定的距离，例如，将该物质远离机器人以保持，将该物质靠近机器人以保持。此外，我们还将尝试不同的磁性物质以及磁铁对传感器的磁性捕捉范围的影响。*

**Expected Results / Data Capture**

We expect to capture the substance with an iron block at a distance that can be identified with high confidence by the magnetometer at 3Pi+ and to be able to always maintain the distance to the magnetic substance in one dimension, i.e., the magnetic substance moves backward close to 3Pi+ and the magnetic substance moves forward away from 3Pi+, it can always keep constant distance. We will also test the effect of magnetic objects with different magnetic field strengths on the distance captured by its magnetometer.

*我们期望在3Pi+的磁力计可以高置信度地识别的距离上用铁块捕捉到该物质，并且能够始终在一个维度上保持与磁性物质的距离，即磁性物质向后移动接近3Pi+，磁性物质向前移动远离3Pi+，总能保证距离不变。我们还将测试具有不同磁场强度的磁性物体对3Pi+磁力计捕获距离的影响。*

 **Experiment Method:**

Step 1:We first calibrate the 3Pi+ with a three-axis magnetometer and determine a reasonable maximum magnetic capture distance from the sensor data. The 3Pi+ is fixed and the sensor data variation is measured by different positions of the iron block and the confidence level of the sensor data variation caused by the magnetic object at each position is given.
Step 2: We write the relevant motor drive and PID control programs so that the 3Pi+ can always maintain a certain distance from magnetic objects as they move.
Step 3:We will determine the effect of a substance with a magnetic field, such as a magnet, on the maximum magnetic capture distance of 3Pi+. We will fix 3Pi+, calibrate the magnetometer, and test the effect of different magnetic objects at different locations on the sensor readings, as well as the confidence level of the presence of the object as judged by the sensor readings.

*步骤1:我们首先将3Pi+进行三轴的磁力计校准，并通过传感器数据测定出合理的最大磁力捕获距离。将3Pi+固定，通过不同位置的铁块，测定传感器数据变化，并给出每个位置磁性物体引起传感器数据变化的置信度。
步骤2：我们编写相关电机驱动和PID控制程序，让3Pi+能够在磁性物体移动时始终与其保持一定距离。
步骤3:我们将测定磁铁等具有磁场的物质对3Pi+最大磁力捕获距离的影响，我们会将3Pi+固定，磁力计校准后，测试不同位置的不同磁性物体对传感器读数的影响，以及通过传感器读数判断该物体存在的置信度。*

**Expected Learning Outcome / Achievements**
We will have 3Pi+ complete a distance-holding challenge, thereby exploring how well 3Pi+ perceives the magnetic environment, while demonstrating the robot's interactive response to the environment by maintaining distance.
We will test the effect of different magnetic substances on the sensor's perceived distance and give confidence levels for the perception of substances at different distances. The confidence level we define as the ratio of the change in the sensor reading caused by the magnetic substance at that location in a certain time and the frequency of that change in the reading occurring at the same time without the presence of the magnetic substance. 

*我们将让3Pi+完成距离保持的挑战，由此探究3Pi+对磁场环境的感知的情况，同时通过保持距离展现出机器人对环境的交互响应。
我们会测试不同磁性物质对传感器感知距离的影响，并给出不同距离物质感知的置信度。置信度我们定义为：一定时间内该位置磁性物质引起传感器示数变化及该示数变化在没有磁性物质存在时同样时间出现的频率比。*

**Other Comments / Questions:**

Because magnetic sensors are unstable, we may also need to explore the effect of sensors on readings in a non-magnetic environment before and after the presence of a magnetic substance.

*由于磁性传感器具有不稳定性，因此我们可能还需要探究在磁性物质存在前和存在后传感器对无磁性物质环境读数的影响。*

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

After our experiments and program tests, we can verify that the feasibility of using a magnetometer to control the robot exists. The magnetometer is able to accurately capture changes in the magnetic field and, under the same conditions, has less fluctuation in the change of its indication. Therefore, if accuracy is not required, the use of raw sensor data can perform a range of tasks such as the detection of magnetic objects and the following of magnetic objects.

![pic](https://s2.loli.net/2022/12/14/qRY7k1utFBOjhCw.png)

As a result of our experiments and tests, the average error in tracking the movement of magnetic objects and maintaining the distance based on the magnetometer readings can be controlled to around 3%. This also means that the robots can use the magnetometer to determine the presence of magnetic objects around them, as well as to slow down and maintain distance before collision based on the magnetometer readings as the swarm robot advances.

## Finally

Thank you for watching here!

![IMG_7165](https://s2.loli.net/2022/12/14/hifos1nPSKD7dbC.jpg)