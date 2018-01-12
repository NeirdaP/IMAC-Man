#version 330 core

in vec3 vFragPosition;
in vec3 vFragNormal;
in vec2 vFragTexCoords;

uniform sampler2D uTex;
uniform sampler2D uTex2;

out vec3 fFragColor;

void main(){
    vec4 texture1 = texture(uTex, vFragTexCoords);
    vec4 texture2 = texture(uTex2, vFragTexCoords);
//    fFragColor = (texture1 + texture2).xyz;
    fFragColor = vec3 (0.7,0.7,0.7);

}