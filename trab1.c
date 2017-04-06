#include <GL/glut.h> // diretorio aonde esta a biblioteca

GLfloat R=0.0f, G=0.0f, B=0.0f;
GLfloat  grauRotacao = 0;
void on_mouseClick(int botao_clicado, int estado_do_click, int x_mouse_position, int y_mouse_position) {

  if(estado_do_click == GLUT_DOWN)
  {
    /*      if(botao_clicado == GLUT_RIGTH_BUTTON)
    {
      // SORTEI CORES
      R = 0.0f;
      G = 0.0f;
      B = 0.0f;

    }*/
    if (botao_clicado == GLUT_LEFT_BUTTON)
    {
      
       grauRotacao +=10 ;
    }
  }

  glutPostRedisplay(); // Força a glut redesenhar a cena após a atualização.
}

void rothelice(GLfloat angulo_inicial, GLfloat grauRotacao)
{

 glTranslatef(350,400.0f,0.0f);
 glRotatef(angulo_inicial + grauRotacao ,0.0f,0.0f,1.0f);
 glTranslatef(-350.0f,-400.0f,0.0f); 

}
void Draw(void){ 
  
  // Define cor de fundo da cena
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Pinta a tela com a cor definida acima
  glMatrixMode(GL_MODELVIEW); // Inicia-se a matriz de transformações da openGL
  glLoadIdentity();
  // Define vermelho como cor inicial de desenho
glColor3f(0.0f, 1.0f, 0.0f);
  // Define os vértices de um quadrado
 glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 300.0f);
    glVertex2f(1300.0f, 300.0f); 
    glVertex2f(1300.0f, 0.0f);                    
  glEnd();

glLoadIdentity();

glColor3f(0.59f, 0.29f, 0.0f);
  // Define os vértices de um quadrado
 glBegin(GL_QUADS); // apoio da helice
    glVertex2f(345.0f, 50.0f);
    glVertex2f(345.0f, 400.0f); 
    glVertex2f(360.0f, 400.0f);
    glVertex2f(360.0f, 50.0f); 

                       
  glEnd();

glLoadIdentity();

//Primeiro Triangulo
  
  rothelice(0.0,grauRotacao); 
  
  // Especifica a cor rosa
  glColor3f(1.0f,0.0f,1.0f);

  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(300.0f , 300.0f); 
  glVertex2f(350.0f, 300.0f); 
  glVertex2f(350.0f, 400.0f); //c
  glEnd();
  glLoadIdentity();


  rothelice(0.0, grauRotacao);
  //rosa escuro
  glColor3f(1.0f, 0.0f, 0.5f);

  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(400.0f, 382.0f); 
  glVertex2f(350.0f, 300.0f); // em comum
  glVertex2f(350.0f, 400.0f); // em comum
  glEnd();
  glLoadIdentity();




//Segundo Triangulo  
  rothelice(180.0, grauRotacao);
  // Especifica a cor vermelho
  glColor3f(1.0f, 0.0f, 0.0f);
  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(300.0f, 300.0f); 
  glVertex2f(350.0f, 300.0f); 
  glVertex2f(350.0f, 400.0f); //c
  glEnd();
  glLoadIdentity();  

  rothelice(180.0, grauRotacao);
  glColor3f(0.55f, 0.0f, 0.0f);

  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(400.0f, 382.0f); 
  glVertex2f(350.0f, 300.0f); // em comum
  glVertex2f(350.0f, 400.0f); // em comum
  glEnd();
  glLoadIdentity();


//Terceiro Triangulo
   rothelice(270.0, grauRotacao);
 

  // Especifica a cor amarelo
  glColor3f(1.0f, 1.0f, 0.5f);

  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(300.0f, 300.0f); 
  glVertex2f(350.0f, 300.0f); 
  glVertex2f(350.0f, 400.0f); //c
  glEnd();
  glLoadIdentity();


  rothelice(270.0, grauRotacao);
  glColor3f(1.0f, 1.0f, 0.0f); // amarelo


  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(390.0f, 382.0f); 
  glVertex2f(350.0f, 300.0f); // em comum
  glVertex2f(350.0f, 400.0f); // em comum
  glEnd();
  glLoadIdentity();


  //Quarto triangulo
   rothelice(90.0, grauRotacao);
  // Especifica a cor preto
  glColor3f(1.0f, 0.65f, 0.0f); // laranja

  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(300.0f, 300.0f); 
  glVertex2f(350.0f, 300.0f); 
  glVertex2f(350.0f, 400.0f); //c
  glEnd();
  glLoadIdentity();


  rothelice(90.0, grauRotacao);
  glColor3f(1.0f, 0.55f, 0.0f); //laranja


  // Desenha o triangulo
  glBegin(GL_TRIANGLES);
  glVertex2f(390.0f, 382.0f); 
  glVertex2f(350.0f, 300.0f); // em comum
  glVertex2f(350.0f, 400.0f); // em comum
  glEnd();
  glLoadIdentity();

  glFlush();     
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1300, 800);
    glutCreateWindow("Exemplo OpenGL");
    glutMouseFunc(on_mouseClick); // Evento de click do mouse
    glutDisplayFunc(Draw);
    glMatrixMode(GL_PROJECTION); // Especificações de observação de cena
    gluOrtho2D(0, 1300, 0, 800);
       
    glutMainLoop();

    return 0;
}