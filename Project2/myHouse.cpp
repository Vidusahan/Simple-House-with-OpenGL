#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Use arrow keys to rotate the house

// Global variables for rotation
float rotationAngleY = 0.0; // Rotation angle around the Y-axis (left/right)
float rotationAngleX = 0.0; // Rotation angle around the X-axis (up/down)
 
void init() {
    glClearColor(0.529, 0.808, 0.922, 1.0); // Sky blue background
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); // Enable lighting
    glEnable(GL_LIGHT0);   // Enable light #0
    glEnable(GL_LIGHT1);   // Enable light #1
    glEnable(GL_COLOR_MATERIAL); // Enable color tracking

    // Set light properties for light #0
    GLfloat light0Ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light0Diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat light0Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light0Position[] = { 5.0f, 5.0f, 5.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);

    // Set light properties for light #1
    GLfloat light1Ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat light1Diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat light1Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light1Position[] = { 5.0f, 5.0f, -5.0f, 1.0f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);

    // Set material properties
    GLfloat matAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matShininess[] = { 50.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
}

void drawFrontHouse() {
    // Main house body (solid magenta)
    glColor3f(0.8, 0.8, 0.8); // gray color
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(3.0, 2.0, 3.5);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //house base
    glColor3f(0.5, 0.5, 0.5); // gray color
    glPushMatrix();
    glTranslatef(0.0, -1.1, 0.0);
    glScalef(3.2, 0.2, 3.7);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

}

void drawRoof() {
    // Front triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1.5f, 1.0f, -1.75f); // Bottom left
    glVertex3f(1.5f, 1.0f, -1.75f);  // Bottom right
    glVertex3f(0.0f, 2.5f, -1.75f);  // Top center
    glEnd();

    // Back triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1.5f, 1.0f, 1.75f); // Bottom left
    glVertex3f(1.5f, 1.0f, 1.75f);  // Bottom right
    glVertex3f(0.0f, 2.5f, 1.75f);  // Top center
    glEnd();

    //chimney for roof
    glColor3f(0.5, 0.5, 0.5); // cream color
    glPushMatrix();
    glTranslatef(1.0, 1.0, -1.25);
    glScalef(0.3, 2.0, 0.3);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.5, 0.5, 0.5); //ash color
    glPushMatrix();
    glTranslatef(1.0, 2.0, -1.25);
    glScalef(0.35, 0.1, 0.35);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    // Connect the front and back triangles with rectangles (sides of the prism)
    glBegin(GL_QUADS);
    // Left side
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(-1.5f, 1.0f, -1.95f);
    glVertex3f(-1.5f, 1.0f, 1.95f);
    glVertex3f(0.0f, 2.5f, 1.95f);
    glVertex3f(0.0f, 2.5f, -1.95f);

    // Right side
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(1.5f, 1.0f, -1.95f);
    glVertex3f(1.5f, 1.0f, 1.95f);
    glVertex3f(0.0f, 2.5f, 1.95f);
    glVertex3f(0.0f, 2.5f, -1.95f);

    glEnd();
}
void drawGrass() {
    // Draw a large green quad as the grass plane
    glColor3f(0.0, 0.5, 0.0); // Green color for grass
    glBegin(GL_QUADS);
    glVertex3f(-3.0f, -1.2f, -4.0f); // Bottom-left corner
    glVertex3f(5.0f, -1.2f, -4.0f);  // Bottom-right corner
    glVertex3f(5.0f, -1.2f, 4.0f);   // Top-right corner
    glVertex3f(-3.0f, -1.2f, 4.0f);  // Top-left corner
    glEnd();
}
void drawRoad() {
    // Draw a large green quad as the grass plane
    glColor3f(0.4, 0.4, 0.4); // Green color for grass
    glBegin(GL_QUADS);
    glVertex3f(1.5f, -1.19f, 0.3f); // Bottom-left corner
    glVertex3f(5.0f, -1.19f, 0.3f);  // Bottom-right corner
    glVertex3f(5.0f, -1.19f,1.4f);   // Top-right corner
    glVertex3f(1.5f, -1.19f, 1.4f);  // Top-left corner
    glEnd();
}

void drawWindows() {
    // Glass windows
    glEnable(GL_BLEND); // Enable blending for transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set blending function

    // Front window
    glColor4f(0.0, 0.1, 0.45, 0.7); // Semi-transparent blue
    glBegin(GL_QUADS);
    glVertex3f(1.51f, -0.3f, -0.2f); // Bottom left
    glVertex3f(1.51f, -0.3f, -1.1f);  // Bottom right
    glVertex3f(1.51f, 0.7f, -1.1f);  // Top right
    glVertex3f(1.51f, 0.7f, -0.2f);  // Top left
    glEnd();

    //vertical borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(1.525, 0.2, -0.65);
    glScalef(0.05, 1.1, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(1.525, 0.2, -1.125);
    glScalef(0.05, 1.1, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(1.525, 0.2, -0.175);
    glScalef(0.05, 1.1, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //horizontal borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(1.525, 0.2, -0.65);
    glScalef(0.05, 0.05, 1.0);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(1.525, 0.725, -0.65);
    glScalef(0.05, 0.05, 1.0);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(1.525, -0.325, -0.65);
    glScalef(0.05, 0.05, 1.0);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    // Slide window
    glColor4f(0.0, 0.1, 0.45, 0.7); // Semi-transparent blue
    glBegin(GL_QUADS);
    glVertex3f(0.25f, -0.3f, -1.76f); // Bottom right
    glVertex3f(0.8f, -0.3f, -1.76f);  // Bottom left
    glVertex3f(0.8f, 0.5f, -1.76f);  // Top left
    glVertex3f(0.25f, 0.5f, -1.76f);  // Top right
    glEnd();

    //vertical borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, 0.1, -1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.225, 0.1, -1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.825, 0.1, -1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //horizontal borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, 0.1, -1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, 0.525, -1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, -0.325, -1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //slide window 2 
    glColor4f(0.0, 0.1, 0.45, 0.7); // Semi-transparent blue
    glBegin(GL_QUADS);
    glVertex3f(-0.25f, -0.3f, -1.76f); // Bottom right
    glVertex3f(-0.8f, -0.3f, -1.76f);  // Bottom left
    glVertex3f(-0.8, 0.5f, -1.76f);  // Top left
    glVertex3f(-0.25f, 0.5f, -1.76f);  // Top right
    glEnd();

    //vertical borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, 0.1, -1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.225, 0.1, -1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.825, 0.1, -1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //horizontal borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, 0.1, -1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, 0.525, -1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, -0.325, -1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor4f(0.0, 0.1, 0.45, 0.7); // Semi-transparent blue
    glBegin(GL_QUADS);
    glVertex3f(0.25f, 1.5f, -1.76f); // Bottom right
    glVertex3f(-0.25f, 1.5f, -1.76f);  // Bottom left
    glVertex3f(-0.25f, 2.0f, -1.76f);  // Top left
    glVertex3f(0.25f, 2.0f, -1.76f);  // Top right
    glEnd();

    //vertical borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.275, 1.75, -1.776);
    glScalef(0.05, 0.6, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.275, 1.75, -1.776);
    glScalef(0.05, 0.6, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //horizontal borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.0, 1.475, -1.776);
    glScalef(0.6, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.0, 2.025, -1.776);
    glScalef(0.6, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();


    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(0.875f, 0.725f, -1.76f);
    glVertex3f(0.875f, 0.525f, -1.76f); 
    glVertex3f(0.875f, 0.525f, -1.96f);  
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(0.175f, 0.725f, -1.76f); 
    glVertex3f(0.175f, 0.525f, -1.76f);  
    glVertex3f(0.175f, 0.525f, -1.96f);  
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(0.875f, 0.725f, -1.76f);
    glVertex3f(0.175f, 0.725f, -1.76f);
    glVertex3f(0.175f, 0.525f, -1.96f);
    glVertex3f(0.875f, 0.525f, -1.96f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(-0.875f, 0.725f, -1.76f); // Bottom left
    glVertex3f(-0.875f, 0.525f, -1.76f);  // Bottom right
    glVertex3f(-0.875f, 0.525f, -1.96f);  // Top center
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(-0.175f, 0.725f, -1.76f); // Bottom left
    glVertex3f(-0.175f, 0.525f, -1.76f);  // Bottom right
    glVertex3f(-0.175f, 0.525f, -1.96f);  // Top center
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(-0.875f, 0.725f, -1.76f);
    glVertex3f(-0.175f, 0.725f, -1.76f);
    glVertex3f(-0.175f, 0.525f, -1.96f);
    glVertex3f(-0.875f, 0.525f, -1.96f);
    glEnd();

    // Slide window 2nd side
    glColor4f(0.0, 0.1, 0.45, 0.7); // Semi-transparent blue
    glBegin(GL_QUADS);
    glVertex3f(0.25f, -0.3f, 1.76f); // Bottom right
    glVertex3f(0.8f, -0.3f, 1.76f);  // Bottom left
    glVertex3f(0.8f, 0.5f, 1.76f);  // Top left
    glVertex3f(0.25f, 0.5f, 1.76f);  // Top right
    glEnd();

    //vertical borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, 0.1, 1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.225, 0.1, 1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.825, 0.1, 1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //horizontal borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, 0.1, 1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, 0.525, 1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.525, -0.325, 1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor4f(0.0, 0.1, 0.45, 0.7); // Semi-transparent blue
    glBegin(GL_QUADS);
    glVertex3f(-0.25f, -0.3f, 1.76f); // Bottom right
    glVertex3f(-0.8f, -0.3f, 1.76f);  // Bottom left
    glVertex3f(-0.8, 0.5f, 1.76f);  // Top left
    glVertex3f(-0.25f, 0.5f, 1.76f);  // Top right
    glEnd();

    //vertical borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, 0.1, 1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.225, 0.1, 1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.825, 0.1, 1.775);
    glScalef(0.05, 0.9, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //horizontal borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, 0.1, 1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, 0.525, 1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.525, -0.325, 1.775);
    glScalef(0.65, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(0.875f, 0.725f, 1.76f);
    glVertex3f(0.875f, 0.525f, 1.76f);
    glVertex3f(0.875f, 0.525f, 1.96f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(0.175f, 0.725f, 1.76f);
    glVertex3f(0.175f, 0.525f, 1.76f);
    glVertex3f(0.175f, 0.525f, 1.96f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(0.875f, 0.725f, 1.76f);
    glVertex3f(0.175f, 0.725f, 1.76f);
    glVertex3f(0.175f, 0.525f, 1.96f);
    glVertex3f(0.875f, 0.525f, 1.96f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(-0.875f, 0.725f, 1.76f); // Bottom left
    glVertex3f(-0.875f, 0.525f, 1.76f);  // Bottom right
    glVertex3f(-0.875f, 0.525f, 1.96f);  // Top center
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(-0.175f, 0.725f, 1.76f); // Bottom left
    glVertex3f(-0.175f, 0.525f, 1.76f);  // Bottom right
    glVertex3f(-0.175f, 0.525f, 1.96f);  // Top center
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.45f, 0.1f);
    glVertex3f(-0.875f, 0.725f, 1.76f);
    glVertex3f(-0.175f, 0.725f, 1.76f);
    glVertex3f(-0.175f, 0.525f, 1.96f);
    glVertex3f(-0.875f, 0.525f, 1.96f);
    glEnd();

    glColor4f(0.0, 0.1, 0.45, 0.7); // Semi-transparent blue
    glBegin(GL_QUADS);
    glVertex3f(0.25f, 1.5f, 1.76f); // Bottom right
    glVertex3f(-0.25f, 1.5f, 1.76f);  // Bottom left
    glVertex3f(-0.25f, 2.0f, 1.76f);  // Top left
    glVertex3f(0.25f, 2.0f, 1.76f);  // Top right
    glEnd();

    //vertical borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.275, 1.75, 1.776);
    glScalef(0.05, 0.6, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(-0.275, 1.75, 1.776);
    glScalef(0.05, 0.6, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //horizontal borders
    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.0, 1.475, 1.776);
    glScalef(0.6, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.75); // light gray color
    glPushMatrix();
    glTranslatef(0.0, 2.025, 1.776);
    glScalef(0.6, 0.05, 0.05);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glDisable(GL_BLEND); // Disable blending
}

void drawDoor() {
    // Wooden door
    glColor3f(0.55, 0.27, 0.07); // Brown color
    glBegin(GL_QUADS);
    glVertex3f(1.51f, -1.0f, 1.2f); // Bottom left
    glVertex3f(1.51f, -1.0f, 0.5f);  // Bottom right
    glVertex3f(1.51f, 0.5f, 0.5f);  // Top right
    glVertex3f(1.51f, 0.5f, 1.2f);  // Top left
    glEnd();

    //borders
    glColor3f(0.5, 0.5, 0.5); // light gray color
    glPushMatrix();
    glTranslatef(1.55, -0.15, 1.3);
    glScalef(0.1, 1.7, 0.1);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.5, 0.5, 0.5); // light gray color
    glPushMatrix();
    glTranslatef(1.55, -0.15, 0.4);
    glScalef(0.1, 1.7, 0.1);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    glColor3f(0.5, 0.5, 0.5); // light gray color
    glPushMatrix();
    glTranslatef(1.55, 0.65, 0.85);
    glScalef(0.1, 0.1, 0.9);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();

    //stair
    glColor3f(0.45, 0.45, 0.45); // Magenta color
    glPushMatrix();
    glTranslatef(1.7, -1.15, 0.85);
    glScalef(0.2, 0.1, 0.8);
    glutSolidCube(1.0); // Draw solid cube
    glPopMatrix();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(8.0, 2.0, -7.0,  // Camera position
        0.0, 0.0, 0.0,  // Look at point
        0.0, 1.0, 0.0); // Up vector

    // Apply rotations to the entire house
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); // Rotate around the origin
    glRotatef(rotationAngleY, 0.0, 1.0, 0.0); // Rotate around the Y-axis (left/right)
    glRotatef(rotationAngleX, 1.0, 0.0, 0.0); // Rotate around the X-axis (up/down)
    drawGrass();
    drawFrontHouse();
    drawRoof();
    drawWindows();
    drawDoor();
    drawRoad();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
}

// Keyboard input handling
void handleSpecialKeypress(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT: // Rotate counterclockwise around Y-axis
        rotationAngleY -= 5.0;
        break;
    case GLUT_KEY_RIGHT: // Rotate clockwise around Y-axis
        rotationAngleY += 5.0;
        break;
    case GLUT_KEY_UP: // Rotate up around X-axis
        rotationAngleX += 5.0;
        break;
    case GLUT_KEY_DOWN: // Rotate down around X-axis
        rotationAngleX -= 5.0;
        break;
    }
    glutPostRedisplay(); // Redraw the scene
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL House with Rotation");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(handleSpecialKeypress); // Register special key callback
    glutMainLoop();
    return 0;
}