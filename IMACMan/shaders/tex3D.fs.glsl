#version 330 core

in vec3 vFragPosition;
in vec3 vFragNormal;
in vec2 vFragTexCoords;

uniform sampler2D uTex;

out vec3 fFragColor;

void main(){
    fFragColor = (texture(uTex, vFragTexCoords)).xyz;
}