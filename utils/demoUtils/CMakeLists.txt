
PROJECT(demoUtils)
CMAKE_MINIMUM_REQUIRED (VERSION 3.0)

IF(COMMAND CMAKE_POLICY)
	CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND CMAKE_POLICY)

AUX_SOURCE_DIRECTORY(. FILE_PROJECT_NAME_SRCS)
set(DIR_PROJECT_NAME_INCLUDE
	../../base
	../../input/include)
INCLUDE_DIRECTORIES(${DIR_PROJECT_NAME_INCLUDE})

foreach(SUB_DIR ${DIR_PROJECT_NAME_INCLUDE})	
	FILE(GLOB_RECURSE SUB_PROJECT_NAME_HEADERS  ${SUB_DIR}/*.h)
	set(FILE_PROJECT_NAME_HEADERS
		${SUB_PROJECT_NAME_HEADERS}
		${FILE_PROJECT_NAME_HEADERS})
endforeach()

SOURCE_GROUP("Head Files" FILES ${FILE_PROJECT_NAME_HEADERS}) 
ADD_LIBRARY(${PROJECT_NAME} ${FILE_PROJECT_NAME_SRCS} ${FILE_PROJECT_NAME_HEADERS})
set(LIBS_PROJECT_NAME_LINK	
	glad
    soil	
	imgui
	glm_static
	libglew_static
	libglewmx_static)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIBS_PROJECT_NAME_LINK})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE(STATUS "===============${PROJECT_NAME}==================")
