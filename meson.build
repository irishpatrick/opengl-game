project('opengl-game', 'cpp')

inc = include_directories('include')

sdl2 = dependency('sdl2')
glew = dependency('glew')
gl = dependency('gl')
assimp = dependency('assimp')
glm = dependency('glm')

main = 'src/main.cc'
mesh = 'src/mesh.cc'
shader = 'src/shader.cc'

executable(
    'a',

    main,
    mesh,
    shader,

    include_directories: [inc],
    dependencies: [sdl2, glew, gl, glm, assimp]
)
