//
//  main.cpp
//  learnopengl
//
//  Created by yuhua.cheng on 2018/11/13.
//  Copyright © 2018 yuhua.cheng. All rights reserved.
//


// System Headers
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <iostream>
// 回调函数，每次用户改变窗口大小的时候，视扣也被调整
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
int main()
{
    // initialize and configure
    // ------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for Mac OS X
#endif
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glewExperimental = GL_TRUE;
    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    // 渲染开始之前告诉OPENGL渲染窗口的尺寸大小Viewport
    glViewport(0, 0, screenWidth, screenHeight);
    // 渲染完成之后，不是立即退出窗口 循环渲染
    while(!glfwWindowShouldClose(window)){
        processInput(window);
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    // 渲染循环结束之后，需要正确释放删除之前分配的所有资源
    glfwTerminate( );
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
