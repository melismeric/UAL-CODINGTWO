## Interactive Paintings 

Video with interaction: https://youtu.be/3lNxoQRVv9Y 
<br/>


Screen recordings: https://youtu.be/io_zu4sApUc & https://youtu.be/j5H8rU4BUKE
<br/>


OF version: 11 (of_v0.11.0_osx_release)
<br/>

Interactive paintings are implemented using GLSL shaders and OpenFrameworks. I also used a sound sample and visualized it. Users can interact with the paintings and the sound with their touch. The pressure of their touch changes the color of the painting. Piezo disc sensor, connected to an Arduino Leonardo, detects touch input. Shaders take sound, sensor values, and input from GUI as uniforms. When the user touches the sensor it disturbs the shader and sound. As the sensor value is added to the sin wave of the shader it speeds up the forms on the shaders and creates different visual effects. If the touch sensor value is bigger than a certain threshold it also speeds up the sound by multiplying its value.
Addons: 
* ofxMaxim
  * Using ofxMaxim addon I added sample sound to the project. To visualize the sound waves I used a waveform array to store values and then draw them on the screen.
  
* ofxGUI
  *  Using GUI users can can scroll through the shaders.
  *  To modify shader details I used ofxGUI on the screen. 


Here are still screen shots of the shaders.
<br/>
<img width="600" alt="Screen Shot 2022-03-18 at 10 50 45" src="https://git.arts.ac.uk/storage/user/227/files/4a6d3e80-a6a9-11ec-9e62-12093d35a487"><em>shader.vert & shader.frag</em>


<img width="600" alt="Screen Shot 2022-03-17 at 12 58 15" src="https://git.arts.ac.uk/storage/user/227/files/9c0cbf00-a5fe-11ec-87a4-ba2da1564c3a"><em>oilcolor.vert & oilcolor.frag</em>


<img width="600" alt="Screen Shot 2022-03-17 at 12 58 27" src="https://git.arts.ac.uk/storage/user/227/files/9d3dec00-a5fe-11ec-841e-e3507d463aa8"><em>simple.vert & simple.frag</em>


## Physical Interaction
I used Arduino Leonardo to add physical interaction to the shaders.
* Using Piezzo disc sensor to detect touchues
* Arduino outputs communicated with Openframeworks by ofSerial. ofSerial provides a cross-platform system for interfacing with the serial port.
* Arduino code: https://git.arts.ac.uk/21004071/MSc-Coding-2/blob/master/Final%20Project/arduino%20src/piezzo-simple.ino

Circuit:
<img width="300" alt="Screen Shot 2022-03-18 at 15 45 20" src="https://git.arts.ac.uk/storage/user/227/files/6d601880-a6d2-11ec-8fbd-d1e939903df8">

<img width="614" alt="Screen Shot 2022-03-18 at 10 49 28" src="https://git.arts.ac.uk/storage/user/227/files/1a25a000-a6a9-11ec-909c-dc2a8b58ace6">
