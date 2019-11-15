gtest = dependency('gtest', main: true)
test(
    'myUnitTest',
    executable(
        'unitTests',
        sources: ['utests.cpp', 'ptests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
