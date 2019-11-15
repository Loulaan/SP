gtest = dependency('gtest', main: true)
test(
    'myTest',
    executable(
        'tests',
        sources: ['tests.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
