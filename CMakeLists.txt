
## PERSONAL MAINTENANCE BY DEGAWONG
## MAINLY REFER TO MAXINT'S(LNY) WORK

PROJECT(ArcSoftAlgorithm)

CMAKE_MINIMUM_REQUIRED (VERSION 3.0)

# use new stl c++11
SET(CMAKE_CXX_STANDARD 11)

IF(COMMAND CMAKE_POLICY)
	CMAKE_POLICY(SET CMP0003 NEW)
	CMAKE_POLICY(SET CMP0014 NEW)	
ENDIF(COMMAND CMAKE_POLICY)

# display the plantform infomation
MESSAGE(STATUS "======================================") 
MESSAGE(STATUS "OPERATION SYSTEM : ${CMAKE_SYSTEM}") 
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	MESSAGE(STATUS "CURRENT PLATFORM : LINUX")
	OPTION (DEGA_PLATFORM_LINUX "platform flag" ON)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	MESSAGE(STATUS "CURRENT PLATFORM : WINDOWS")
	OPTION (DEGA_PLATFORM_WINDOW "platform flag" ON)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	MESSAGE(STATUS "CURRENT PLATFORM : FREEBSD")
	OPTION (DEGA_PLATFORM_FREEBSD "platform flag" ON)
ELSE ()
	MESSAGE(STATUS "CURRENT PLATFORM : ${CMAKE_SYSTEM_NAME}")
	MESSAGE(STATUS "STILL NO PLATFORM FUNCTION IN ${CMAKE_SYSTEM_NAME}")
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Linux")

IF(DEGA_PLATFORM_LINUX)
	ADD_DEFINITIONS(-DDEGA_PLATFORM_LINUX)
ELSEIF(DEGA_PLATFORM_WINDOW)
	ADD_DEFINITIONS(-DDEGA_PLATFORM_WINDOW)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
ELSEIF(DEGA_PLATFORM_FREEBSD)	
	ADD_DEFINITIONS(-DDEGA_PLATFORM_FREEBSD)
ENDIF(DEGA_PLATFORM_LINUX)
MESSAGE(STATUS "======================================")

# user define marco
OPTION (DEGA_NEED_ALLIGN "memo need allign" ON)
IF(DEGA_NEED_ALLIGN)
	ADD_DEFINITIONS(-DDEGA_NEED_ALLIGN)
ENDIF(DEGA_NEED_ALLIGN)
# use 3rd party lib
OPTION (DEGA_3RD_PARTY "use 3rd party" ON)
OPTION (DEGA_3RD_PARTY_IGL "use igl party" OFF)
OPTION (DEGA_3RD_PARTY_DLIB "use dlib party" OFF)
IF(DEGA_3RD_PARTY)
	ADD_DEFINITIONS(-DDEGA_3RD_PARTY)
	IF(DEGA_3RD_PARTY_DLIB)
		ADD_DEFINITIONS(-DDEGA_3RD_PARTY_DLIB)
	ENDIF(DEGA_3RD_PARTY_DLIB)
ENDIF(DEGA_3RD_PARTY)

set(DIR_SUB_PROJ
	utils	
	3rdParty	
	algorithm)	

foreach(SUB_DIR
    ${DIR_SUB_PROJ}
    )
	ADD_SUBDIRECTORY(${SUB_DIR})
endforeach()

AUX_SOURCE_DIRECTORY(. FILE_ROOT_SRCS)

# enable the pack function
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON) 
SET_PROPERTY(TARGET degaUtils PROPERTY FOLDER "Utils")
SET_PROPERTY(TARGET demoUtils PROPERTY FOLDER "Utils")
# SET_PROPERTY(TARGET laplaceBlend PROPERTY FOLDER "Algorithm")

SET_PROPERTY(TARGET glad PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET glfw PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET soil PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET glm_static PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET glm_shared PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET libglew_static PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET libglew_shared PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET libglewmx_shared PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET libglewmx_static PROPERTY FOLDER "OpenGL")
SET_PROPERTY(TARGET glad-generate-files PROPERTY FOLDER "OpenGL")

IF(DEGA_3RD_PARTY)
	ADD_DEFINITIONS(-DDEGA_3RD_PARTY)
	IF(DEGA_3RD_PARTY_DLIB)
		SET_PROPERTY(TARGET dlib PROPERTY FOLDER "3rdParty")
	ENDIF(DEGA_3RD_PARTY_DLIB)
ENDIF(DEGA_3RD_PARTY)

SET_PROPERTY(TARGET Eigen PROPERTY FOLDER "3rdParty")
SET_PROPERTY(TARGET imgui PROPERTY FOLDER "3rdParty")
SET_PROPERTY(TARGET armadillo PROPERTY FOLDER "3rdParty")

SET_PROPERTY(TARGET uninstall PROPERTY FOLDER "CMakePredefinedTargets")

IF(DEGA_3RD_PARTY)
	IF(DEGA_3RD_PARTY_DLIB)
	ENDIF(DEGA_3RD_PARTY_DLIB)
ENDIF(DEGA_3RD_PARTY)

set(DIR_ROOT_LINK
	input/library/android
	input/library/windows)
LINK_DIRECTORIES(${DIR_ROOT_LINK})

set(DIR_ROOT_INCLUDE
	base
	input/include)
INCLUDE_DIRECTORIES(${DIR_ROOT_INCLUDE})

set(DIRE_ROOT_HEAD
	base
	input/include)

foreach(SUB_DIR
    ${DIRE_ROOT_HEAD}
    )
FILE(GLOB_RECURSE SUB_ROOT_HEADERS  ${SUB_DIR}/*.h)
set(FILE_ROOT_HEADERS
	${SUB_ROOT_HEADERS}
	${FILE_ROOT_HEADERS})
endforeach()

SOURCE_GROUP("Head Files" FILES ${FILE_ROOT_HEADERS}) 

set(LIBS_DIR_ROOT	
	cv
	glad
	soil
	Eigen
	imgui
	armadillo
	degaUtils
	demoUtils
	glm_static
	libglew_static
	libglewmx_static)

IF(DEGA_3RD_PARTY)
	# dlib
	IF(DEGA_3RD_PARTY_DLIB)
		set(LIBS_DIR_ROOT
			dlib
			${LIBS_DIR_ROOT})
	ENDIF(DEGA_3RD_PARTY_DLIB)
ENDIF(DEGA_3RD_PARTY)

ADD_EXECUTABLE(algorithmDemo 
		algorithmDemo.cpp
		${FILE_ROOT_HEADERS})
ADD_EXECUTABLE(imageAlgorithm 
		imageAlgorithm.cpp
		${FILE_ROOT_HEADERS})
ADD_EXECUTABLE(videoAlgorithm 
		videoAlgorithm.cpp
		${FILE_ROOT_HEADERS})

TARGET_LINK_LIBRARIES(algorithmDemo ${LIBS_DIR_ROOT})
TARGET_LINK_LIBRARIES(imageAlgorithm ${LIBS_DIR_ROOT})
TARGET_LINK_LIBRARIES(videoAlgorithm ${LIBS_DIR_ROOT})

SET_DIRECTORY_PROPERTIES(PROPERTIES VS_STARTUP_PROJECT imageAlgorithm)

SET_TARGET_PROPERTIES(algorithmDemo PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
SET_TARGET_PROPERTIES(imageAlgorithm PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
SET_TARGET_PROPERTIES(videoAlgorithm PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
MESSAGE(STATUS "===============END====================")
