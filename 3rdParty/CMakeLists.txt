

IF(DEGA_3RD_PARTY)
	# dlib
	IF(DEGA_3RD_PARTY_DLIB)
		ADD_SUBDIRECTORY(dlib)
	ENDIF(DEGA_3RD_PARTY_DLIB)	
ENDIF(DEGA_3RD_PARTY)

ADD_SUBDIRECTORY(glm)
ADD_SUBDIRECTORY(glad)
ADD_SUBDIRECTORY(glew)
ADD_SUBDIRECTORY(glfw)
ADD_SUBDIRECTORY(soil)
ADD_SUBDIRECTORY(Eigen)
ADD_SUBDIRECTORY(imgui)
ADD_SUBDIRECTORY(armadillo)
