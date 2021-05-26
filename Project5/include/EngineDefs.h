#pragma once

#ifdef _WIN32
#define __ENGINE__WINDOWS__

#elif __linux__
#define __ENGINE__LINUX__
#endif

#include <glew.h>
#include <gl/GL.h>
#include "glm/glm.hpp"
