
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//C++
#include <iostream>

//Prototype de la fonction de callback pour le resize de la fenetre
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void close_window(GLFWwindow* window);

//Parametre de la fenetre
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main(void)
{
	//Init de la fenetre => pointeur de type GLFWwindow
    GLFWwindow* window;

    /* Init de la lib GLFW */
    if (!glfwInit())
        return -1;

    //Version de GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Profile de compatibilité = core profile (OpenGL 3.3)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Creer la fenetre principale et son contexte */
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Mic OpenGL", NULL, NULL);
	//Si la création de la fenetre a échoué
    if (!window)
    {
		std::cout << "Erreur lors de la création de la fenetre" << std::endl;
        glfwTerminate();
        return -1;
    }

    /*Ajouter la fenetre au contexte courant glfw pour le rendu graphqiue*/
    glfwMakeContextCurrent(window);
	//Resize de la fenetre
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
		std::cout << "Erreur lors du chargement de GLAD => chargement des fonctions pointers" << std::endl;
		glfwTerminate();
		return -1;
    }

    /* Boucle infinie tant que l'on ne ferme pas la fenetre */
    while (!glfwWindowShouldClose(window))
    {
        close_window(window);

		//Changer la couleur de fond de la fenetre
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        /* Efface l'ecran et affiche le rendu pour la prochaine frame (evite un redraw constant) => tableau 2D de pixel RGBA a chaque frames */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Echange front (ecran) et back (rendu) buffers => 2 colors buffers */
        glfwSwapBuffers(window);

        /* Inspecte - analyse - sonde les processus d'evenement (resize, input keyboard, joypad, instance, etc...) */
        glfwPollEvents();
    }

	//Stop le processus de rendu GLFW
    glfwTerminate();
    return 0;
}


//Fonction de callback pour le resize de la fenetre
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void close_window(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
