#include "Header.h"
#include "Shapes.h"


void Creation_kube(std::vector <kube3D> vec) {
     vec.push_back(kube3D());
     vec.at(0).spawn(x, y, z);
}

void Creation_pir(std::vector <Pyramid> vec_pir, int Check) {
    vec_pir.push_back(Pyramid());
    vec_pir.at(0).spawn(x, y, z, Check);
}

void ShowWorld() {
    std::vector <kube3D> vec;
    std::vector <Pyramid> vec_pir;
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vert);
    for (int i = -5; i < size_world; i++) {
        for (int j = -5; j < size_world; j++)
        {
            glPushMatrix();
            if((i + j) % 2 == 0) { 
              glColor3f(0, 0.5f, 0);
            }
            else {
                glColor3f(1, 1, 1);
                if (j == -5 || j == (size_world - 1) || i == -5 || i == (size_world - 1)) {
                    x = (i + 0.25f) * 2; y = (j + 0.25f) * 2; z = 3;
                    Creation_pir(vec_pir, 1);
                    Creation_pir(vec_pir, 0);
                    z = 8;
                    Creation_kube(vec);
                }
            }
            glTranslatef(i * 2, j * 2, 0);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glPopMatrix();
        }
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    speed_world += 1;
    if (speed_world >= 360) {
        speed_world = 0;
    }
}