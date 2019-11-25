gtest = dependency('gtest', main: true)
test(
    'myTests',
    executable(
        'Tests',
        sources: ['accountTests.cpp', 'mergeSortTests.cpp', 'nIteratorTests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
