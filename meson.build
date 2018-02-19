project('opengl-game', 'cpp')

inc = include_directories('include')

add_global_arguments(['-Wall', '-g', '--std=c++11'], language: 'cpp')

sdl2 = dependency('sdl2')
sdl2_image = dependency('SDL2_image')
glew = dependency('glew')
#gl = dependency('gl')
assimp = dependency('assimp')
#glm = dependency('glm')

specific_args = []

if host_machine.system() == 'windows'
    specific_args += ['-lglu32', '-lopengl32']
endif

c = run_command('sources.py')
sources = c.stdout().strip().split('\n')

executable(
    'a',
    sources,
    include_directories: [inc],
    dependencies: [sdl2, glew, assimp, sdl2_image],
    link_args: specific_args
)
