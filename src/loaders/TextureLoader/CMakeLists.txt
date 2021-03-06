cmake_minimum_required( VERSION 2.8.8 )

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} FILLWAVE_TEXTURE_LOADER_SOURCES)

include_directories(${FILLWAVE_PATH_INCLUDE} ${FILLWAVE_TEXTURE_LOADER_INCLUDES}
        ${FILLWAVE_TEXTURE_LOADER_INCLUDES}/external/glm ${FILLWAVE_TEXTURE_WRITER_INCLUDES}
        )

IF(WIN32)
	include_directories(${FILLWAVE_EXT_GLEW_INCLUDES})
ENDIF(WIN32)

add_library(textureloader SHARED ${FILLWAVE_TEXTURE_LOADER_SOURCES})

if (FILLWAVE_BUILD_DEV)
else()
	if(FILLWAVE_BUILD_RPM)
		install(TARGETS textureloader DESTINATION lib64)
	else(FILLWAVE_BUILD_RPM)
		install(TARGETS textureloader DESTINATION lib)
	endif(FILLWAVE_BUILD_RPM)
endif()

target_link_libraries(textureloader logger)

IF(ANDROID)
	target_link_libraries(textureloader log android GLESv3)
ENDIF(ANDROID)
