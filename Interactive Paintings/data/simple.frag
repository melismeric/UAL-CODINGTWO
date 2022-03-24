

#version 150


out vec4 outputColor;
precision highp float;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_sensor;
uniform int sound;
uniform int sound2;
uniform float value;


void main(){
  vec2 coord = 10.0 * gl_FragCoord.xy / u_resolution;

  for (int n = 1; n < 8; n++){
     float i = float(n);
      coord += vec2(0.7 / i * tan(i * coord.y* u_sensor*0.01/ u_resolution.y + u_time + 0.3 * i) + value, 0.4 / i * sin(coord.x * 5.064) + 1.6);
   }

   coord *= vec2(0.0007 / sin(coord.y + sound + u_time*0.05 + 0.3) + 0.312, 0.0004 / sin(coord.x + u_time + 0.3) + 1.6);
   vec3 color = vec3(2.220 * sin(coord.x) + 3.100, 1.180 * sin(coord.y) + 0.444, sin(coord.x + coord.y ));

  outputColor = vec4(color,1.0);
    
}
