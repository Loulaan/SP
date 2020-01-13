gtest = dependency('gtest', main: true)
test(
    '5',
    executable(
        'Test5',
        sources: ['accountTests.cpp', 'mergeSortTests.cpp', 'nIteratorTests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
