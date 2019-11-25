gtest = dependency('gtest', main: true)
test(
    'Test',
    executable(
        'Tests',
        sources: ['tests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
