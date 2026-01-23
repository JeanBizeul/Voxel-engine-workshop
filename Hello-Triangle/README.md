# Hello Triangle
## Setup

Before starting, I'm going to explain what I already have set-up for you.

In the root of this repository, you can find a vendor folder with some dependencies inside, most of the uses git submodules systems and are required for you to compile your code:

```bash
# Initialize & download submodules in your local copy of the repo
# Run from the root of the repo
git submodule init
git submodule update
```

After you have these installed properly, you will be able to compile directly via vscode in the build tab (or hit f5).

You can select the target you want to build, for each exercises, you have your version & a finished one, you can use the completed one as a reference to know what to expect.

# Chapter 0 - OpenGL Introduction

Before we start, you need to know a bit about what is OpenGL and how you will interact with it.

## A teeny tiny bit of history

OpenGL is a specification defined by the Khronos Group since +25 years, GPU vendors implement drivers that claim conformance to it.

It has came a long way since 1993 but the Core versions stopped evolving significantly after 4.6 (2017), with most innovation happening through extensions or newer APIs like Vulkan

For this tutorial we will be using OpenGL 3.3, it is the last 3.x version and I choose it because it is compatible with a wide range of cards (released in 2010).

And if you're GPU does not support this version, sorry but you will not be able to follow some parts of these exercises.

## How doe I access it ?

In order to use OpenGL's functionalities, you will need to load them at runtime via function pointers. This is extremely long and boring that why GLAD exists: it will provide us with a simple loader to call once. If you are curious, you can go take a look at it [here](../vendor/glad/include/glad/glad.h).

Once this step is done, you now need a way to create a window and bind OpenGL to it. Again, this is annoying because each OS handles this in a different way. So we will use GLFW to create our window, create the OpenGL context, make it the current one & fetch inputs. It is a very basic API so we can focus on OpenGL mainly and limit overhead. But you can also use SDL, SFML or even Raylib to create the window & retreive the context.

## How does it work ?

OpenGL is by itself a large state machine: a collection of variables that define how OpenGL should currently operate. The state of OpenGL is commonly referred to as the OpenGL context. When using OpenGL, we often change it's state by setting some options, manipulating some buffers and then render using the current context.

The OpenGL libraries are written in C and allows for many derivations in other languages, but in it's core it remains a C-library. Since many of C's language-constructs do not translate that well to other higher-level languages, OpenGL was developed with several abstractions in mind. One of those abstractions are objects in OpenGL.

An object in OpenGL is a collection of options that represents a subset of OpenGL's state. For example, we could have an object that represents the settings of the drawing window; we could then set it's size, how many colors it supports and so on. One could visualize an object as a C-like struct:


```cpp
struct object_name {
    float  option1;
    int    option2;
    char[] name;
};
```

Whenever we want to use objects it generally looks something like this (with OpenGL's context visualized as a large struct):

```cpp
// The State of OpenGL
struct OpenGL_Context {
  	...
  	object_name* object_Window_Target;
  	...
};
```
```cpp
// create object
unsigned int objectId = 0;
glGenObject(1, &objectId);
// bind/assign object to context
glBindObject(GL_WINDOW_TARGET, objectId);
// set options of object currently bound to GL_WINDOW_TARGET
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH,  800);
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
// set context target back to default
glBindObject(GL_WINDOW_TARGET, 0);
```
This little piece of code is a workflow you'll frequently see when working with OpenGL. We first create an object and store a reference to it as an id (the real object's data is stored behind the scenes). Then we bind the object (using it's id) to the target location of the context (the location of the example window object target is defined as `GL_WINDOW_TARGET`). Next we set the window options and finally we un-bind the object by setting the current object id of the window target to 0. The options we set are stored in the object referenced by objectId and restored as soon as we bind the object back to `GL_WINDOW_TARGET`.

The great thing about using these objects is that we can define more than one object in our application, set their options and whenever we start an operation that uses OpenGL's state, we bind the object with our preferred settings. There are objects for example that act as container objects for 3D model data (a house or a character) and whenever we want to draw one of them, we bind the object containing the model data that we want to draw (we first created and set options for these objects). Having several objects allows us to specify many models and whenever we want to draw a specific model, we simply bind the corresponding object before drawing without setting all their options again.

> Ok, now that you have the basics along some history in mind, we can start with your first application shall we ?

# Chapter 1 - Hello Triangle !


