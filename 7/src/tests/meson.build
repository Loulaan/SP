gtest = dependency('gtest', main: true)
test(
    'myTests',
    executable(
        'Tests',
        sources: ['ln80c_bufferTests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
