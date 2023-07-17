#include "Header.h"

void MoveCamera();
void ShowWorld();

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, "3DAnimation", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glFrustum(-1,1,-1,1,2,80);
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        MoveCamera();
        ShowWorld();
        glPopMatrix();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}