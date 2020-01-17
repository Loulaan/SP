gtest = dependency('gtest', main: true)
test(
    'myTests',
    executable(
        'Tests',
        sources: ['mergeSortTests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
