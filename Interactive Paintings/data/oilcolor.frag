// fragment shader

#version 150


out vec4 outputColor;
precision highp float;

uniform float u_time;
uniform vec2 u_resolution;
uniform float u_sensor;
uniform float value;
uniform int sound;

void main(){
  vec2 coord = 6.0 * gl_FragCoord.xy / u_resolution;
    for (int n = 1; n < 8; n++){
       float i = float(n);
        coord += vec2(0.7 / i * sin(i * coord.y *  value) + u_sensor*0.001, 0.4 / i * sin(coord.x * 5.8) + 1.6);
        
     }

    coord *= vec2(0.07 / sin(coord.y + sound + u_time*0.05 + 0.3) + 0.8, 0.04 / sin(coord.x + u_time + 0.3) + 1.6);
     vec3 color = vec3(3.196 * sin(coord.x) + 0.5, 0.5 * sin(coord.y) + 0.5, sin(coord.x + coord.y ));


  outputColor = vec4(color,1.0);
    
}

