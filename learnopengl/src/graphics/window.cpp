#include "window.h"

namespace engine
{
	namespace graphics
	{
		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char *name, int width, int height)
		{
			m_Name = name;
			m_Width = width;
			m_Height = height;
			if (!init()) 			
				glfwTerminate();		
			glfwSetWindowSizeCallback(m_Window,windowResize);
		}

		bool Window::init() 
		{
			if (!glfwInit()) 
			{
				std::cout << "faild to init glfw quiting" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
			if (!m_Window) 
			{
				glfwTerminate();
				std::cout << "Faild to create window" << std::endl;
				return false;
			}
			return true;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		Window::~Window() 
		{
			glfwTerminate();
		}

		void Window::update() 	
		{
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		void Window::clear() const 
		{
			glClear(GL_ACCUM_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void windowResize(GLFWwindow* window, int width,int height) 
		{
			glViewport(0, 0, width, height);
		}
	}
}