myproject_src = files([
	'11.cpp',
	'mergeSort.h',
	'mergeSortThreads.h',
	'myThread.h'
])

threads = dependency('threads')

executable(
	'myproject', # название исполняемого файла
	include_directories: src, # где ищутся заголовочные файлы
	sources: myproject_src, # список исходный файлов
	dependencies: [threads], # зависимости проекта (если имеются)
	install: true # устанавливать ли файл
)