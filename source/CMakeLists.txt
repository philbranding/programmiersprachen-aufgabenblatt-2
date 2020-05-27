# Build example
add_executable(example
  window.cpp
  window.hpp
  glew.c
  example.cpp
  vec2.cpp
  vec2.hpp
  mat2.cpp
  mat2.hpp
  color.hpp
  rectangle.cpp
  circle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
window.cpp
window.hpp
  glew.c
  tests.cpp
  vec2.cpp
  vec2.hpp
  mat2.cpp
  mat2.hpp
  color.hpp
  rectangle.cpp
  circle.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )


