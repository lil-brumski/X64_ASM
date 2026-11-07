add_executable(LearnCV)
target_sources(LearnCV
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/learncv.cc
)
target_link_libraries(LearnCV PRIVATE opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs opencv_videoio)

if(UNIX)
    file(CREATE_LINK ${CMAKE_SOURCE_DIR}/images ${CMAKE_CURRENT_BINARY_DIR}/images SYMBOLIC)
endif(UNIX)