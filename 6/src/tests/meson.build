gtest = dependency('gtest', main: true)
test(
    'myTests',
    executable(
        'Tests',
        sources: ['gShapesTests.cpp', 'PolynomialTests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
