
#define NOMINMAX


#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Value_Slider.H>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Light_Button.H>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "math.h"
#include "stdio.h"

#include <vector>
#include "core.h"

#include "Mover.h"
#include "MoverConnection.h"

#include "3DUtils.h"
#include "Vec3f.h"
#include "Viewer.h"


class MyGlWindow : public Fl_Gl_Window {
public:
    MyGlWindow(int x, int y, int w, int h);

    Fl_Light_Button *ui;
    Fl_Slider *time;

    int run;
    void update();
    void drawStuff();
    void doPick();
    void test();
    int selected;
    void putText(const char *str, int x, int y, float r, float g, float b);
    void setProjectileMode() const;

    const char *getProjectileMode() const;
    void step();

private:
    void draw(); // standard FlTk
    int handle(int); // standard FlTk

    Viewer *m_viewer;
    float fieldOfView;
    std::map<int, Mover *> m_movers;
    MoverConnection *m_connection;

    void setProjection(int clearProjection = 1);
    void getMouseNDC(float &x, float &y);
    void setupLight(float x, float y, float z);
};
