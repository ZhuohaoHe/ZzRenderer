#version 410 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D ShadowDebugTexture;

// required when using a perspective projection matrix
float LinearizeDepth(float depth) {
    float near_plane = 0.1;
    float far_plane = 10.0; 
    float z = depth * 2.0 - 1.0; // Back to NDC 
    return (2.0 * near_plane * far_plane) / (far_plane + near_plane - z * (far_plane - near_plane));	
}

void main() {      
    float near_plane = 0.1;
    float far_plane = 10.0;       
    float depthValue = texture(ShadowDebugTexture, TexCoords).r;
    // FragColor = vec4(vec3(LinearizeDepth(depthValue) / far_plane), 1.0); // perspective
    FragColor = vec4(vec3(depthValue), 1.0); // orthographic
}