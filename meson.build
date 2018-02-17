project('opengl-game', 'cpp')

inc = include_directories('include')

add_global_arguments('-Wall -g --std=c++11', language: 'cpp')

sdl2 = dependency('sdl2')
glew = dependency('glew')
#gl = dependency('gl')
#assimp = dependency('assimp')
#glm = dependency('glm')

c = run_command('sources.py')
sources = c.stdout().strip().split('\n')

executable(
    'a',
    sources,
    include_directories: [inc],
    dependencies: [sdl2, glew]
)
