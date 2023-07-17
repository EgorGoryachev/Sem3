#pragma once
#include "Header.h"

GLuint kubeInd[] = { 0,1,2, 2,3,0, 4,5,6, 6,7,4, 3,2,5, 6,7,3, 0,1,5, 5,4,0, 1,2,6, 6,5,1, 0,3,7, 7,4,0 };
float kube[] = { 0,0,0, 0,1,0, 1,1,0, 1,0,0, 0,0,1, 0,1,1, 1,1,1, 1,0,1 };
float pyramid[] = { 0,0,2, 1,1,0, 1,-1,0, -1,-1,0, -1,1,0, 1,1,0 };
float vert[] = { 1,1,0, 1,-1,0, -1,-1,0, -1,1,0 };
int speed_world = 15;
int size_world = 25;
float x, y, z;

class kube3D {
public:
	float x, y, z;

	void spawn(float x,float y,float z) {
        glVertexPointer(3, GL_FLOAT, 0, kube);
        glPushMatrix();
        glColor3f(1, 0, 1);
        glTranslatef(x, y, z);
        glScalef(1, 1, 1);
        glRotatef(speed_world, 1, 1, 1);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, kubeInd);
        glPopMatrix();
	}
};

class Pyramid {
public:
    float x, y, z;

    void spawn(float x, float y, float z, int Check) {
        glVertexPointer(3, GL_FLOAT, 0, &pyramid);
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(180, 0, 0, Check);
        if (Check == 0) {
            glColor3f(1, 0, 0);
        }
        else {
            glColor3f(0, 1, 0);
        }
        glRotatef(speed_world, 0, 0, 1);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
        glPopMatrix();
    }
};