// fragment shader

#version 150


        out vec4 outputColor;
        precision highp float;
        uniform float time;
        uniform vec2 resolution;
        uniform vec2 mouse;
        #define M_PI 3.14159265358979323846
        #define TWO_PI 6.28318530718
        
    vec3 hsb2rgb( in vec3 c ){
        vec3 rgb = clamp(abs(mod(c.x*6.0+vec3(0.0,4.0,2.0),
                                 6.0)-3.0)-1.0,
                         0.0,
                         1.0 );
        rgb = rgb*rgb*(3.0-2.0*rgb);
        return c.z * mix( vec3(1.0), rgb, c.y);
    }
        
        void main(void) {
        vec2 st = gl_FragCoord.xy/resolution;
        vec3 color = vec3(0.0);
        vec3 color2 = vec3(0.0);
        vec3 color3 = vec3(0.0);

        // Use polar coordinates instead of cartesian
        vec2 toCenter = vec2(mouse.y)-st;
        float angle = atan(toCenter.y,toCenter.x)*time;
        float radius = length(toCenter)*5.0;

        color = hsb2rgb(vec3((angle/TWO_PI)+0.5,radius,1.0));
        
        vec2 toCenter2 = vec2(mouse.x)-st;
        float angle2 = atan(toCenter2.y,toCenter2.x)*time;
        float radius2 = length(toCenter2)*5.0;

        color2 = hsb2rgb(vec3((angle2/TWO_PI)+0.5,radius2,1.0));
         
        vec2 toCenter3 = vec2(mouse)-st;
        float angle3 = atan(toCenter3.y,toCenter3.x)*time;
        float radius3 = length(toCenter3)*5.0;

        color3 = hsb2rgb(vec3((angle3/M_PI)*1.5,radius3,1.0));

        outputColor = vec4(color + color2 + color3,1.0);
            
        }

