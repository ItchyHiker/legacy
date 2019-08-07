//
//  ch9_coordinate_system3.cpp
//  learnopengl
//
//  Created by yuhua.cheng on 2018/12/3.
//  Copyright © 2018 yuhua.cheng. All rights reserved.
//

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
#include "Shader.hpp"
#include "stb_image.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main()
{
    // Init GLFW
    glfwInit( );
    
    // Set all the required options for GLFW
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    
    glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
    
    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow *window = glfwCreateWindow( WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr );
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize( window, &screenWidth, &screenHeight );
    
    if ( nullptr == window )
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate( );
        
        return EXIT_FAILURE;
    }
    
    glfwMakeContextCurrent( window );
    
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Define the viewport dimensions
    glViewport( 0, 0, screenWidth, screenHeight );
    
    // Setup OpenGL options
    glEnable( GL_DEPTH_TEST );
    
    // enable alpha support
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    
    // enable depth test
    glEnable(GL_DEPTH_TEST);
    
    // Build and compile our shader program
    Shader ourShader("/Users/yuhua.cheng/Documents/study/OPENGL/learnopengl/learnopengl/chap09 Coordinates Systems/9_3D_multi_cubics.vs", "/Users/yuhua.cheng/Documents/study/OPENGL/learnopengl/learnopengl/chap09 Coordinates Systems/9_3D_multi_cubics.fs");
    
    // Set up vertex data (and buffer(s)) and attribute pointers
    // use with Orthographic Projection
    
     GLfloat vertices[] = {
     -0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 0.0f,
     0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  1.0f, 0.0f,
     0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  1.0f, 1.0f,
     0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  1.0f, 1.0f,
     -0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,
     -0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 0.0f,

     -0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  0.0f, 0.0f,
     0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,
     0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 1.0f,
     0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 1.0f,
     -0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  0.0f, 1.0f,
     -0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  0.0f, 0.0f,

     -0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,
     -0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  1.0f, 1.0f,
     -0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,
     -0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,
     -0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  0.0f, 0.0f,
     -0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,

     0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,
     0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  1.0f, 1.0f,
     0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,
     0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,
     0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  0.0f, 0.0f,
     0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,

     -0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,
     0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  1.0f, 1.0f,
     0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,
     0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,
     -0.5f * 2 , -0.5f * 2 ,  0.5f * 2 ,  0.0f, 0.0f,
     -0.5f * 2 , -0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,

     -0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f,
     0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  1.0f, 1.0f,
     0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,
     0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  1.0f, 0.0f,
     -0.5f * 2 ,  0.5f * 2 ,  0.5f * 2 ,  0.0f, 0.0f,
     -0.5f * 2 ,  0.5f * 2 , -0.5f * 2 ,  0.0f, 1.0f
     };

    // define multiple cubic positions
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    /*
    // use with Perspective Projection
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    */
    
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO );
    glGenBuffers(1, &VBO );
    
    glBindVertexArray(VAO);
    
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT , GL_FALSE, 5 * sizeof( GLfloat ), ( GLvoid * ) 0);
    glEnableVertexAttribArray( 0 );
    // TexCoord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray(1);
    
    // Load and create textures
    GLuint texture1, texture2;
    // texture1
    glGenTextures(1, &texture1 );
    glBindTexture( GL_TEXTURE_2D, texture1);
    // Set our texture parameters
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );    // Set texture wrapping to GL_REPEAT
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    // Set texture filtering
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    // Load, create texture and generate mipmaps
    int width, height, nrChannels;
    const char *path = "/Users/yuhua.cheng/Documents/study/OPENGL/learnopengl/learnopengl/resources/container.jpg";
    unsigned char *image = stbi_load(path, &width, &height, &nrChannels, 0);
    if (image)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(image);
    
    // texture2
    glGenTextures(1, &texture2 );
    glBindTexture( GL_TEXTURE_2D, texture2);
    
    // Set our texture parameters
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );    // Set texture wrapping to GL_REPEAT
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    // Set texture filtering
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    // Load, create texture and generate mipmaps
    path = "/Users/yuhua.cheng/Documents/study/OPENGL/learnopengl/learnopengl/resources/awesomeface.png";
    image = stbi_load(path, &width, &height, &nrChannels, 0);
    if (image)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(image);
    
//    glBindTexture( GL_TEXTURE_2D, 0 ); // Unbind texture when done, so we won't accidentily mess up our texture.
    
    glm::mat4 projection;
    projection = glm::perspective( 45.0f, ( GLfloat )screenWidth / ( GLfloat )screenHeight, 0.1f, 100.0f );
    
    // Activate shader
    ourShader.use();
    ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);
    
    // Game loop
    while ( !glfwWindowShouldClose( window ) )
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents( );
        
        // Clear the colorbuffer
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
        // Bind Textures using texture units
        glActiveTexture( GL_TEXTURE0 );
        glBindTexture( GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        
        // Create translate transformations
        glm::mat4 view(1.0f);
        view = glm::translate( view, glm::vec3( 0.0f, 0.0f, -5.0f ) );
        
        GLint viewLoc = glGetUniformLocation( ourShader.ID, "view" );
        GLint projLoc = glGetUniformLocation( ourShader.ID, "projection" );
        glUniformMatrix4fv( viewLoc, 1, GL_FALSE, glm::value_ptr( view ) );
        glUniformMatrix4fv( projLoc, 1, GL_FALSE, glm::value_ptr( projection ) );
        
        // Draw container
        glBindVertexArray( VAO );
        
        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model(1.0);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * (i + 1.0f);
            model = glm::rotate(model, (GLfloat)glfwGetTime()*glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            GLint modelLoc = glGetUniformLocation(ourShader.ID, "model" );
            glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr(model) );
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        
        // Swap the screen buffers
        glfwSwapBuffers( window );
        glfwPollEvents();
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays( 1, &VAO );
    glDeleteBuffers( 1, &VBO );
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate( );
    
    return EXIT_SUCCESS;
}
