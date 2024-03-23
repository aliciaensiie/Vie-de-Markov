cmake_minimum_required(VERSION 3.10)
project(schoolBattle)

#set PATH
set(SFML_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../CSFML/SFML-2.5.1)
set(CSFML_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../CSFML)

if(WIN32)
	set(WINDOWS_PATH C:/Users/alici/OneDrive/Documents/project4/DLLwindow)
endif()

#SFML2.5 for linux and SFML2.6 for window
link_directories(schoolBattle PUBLIC "${SFML_PATH}/lib" "${CSFML_PATH}/lib")
include_directories(schoolBattle PUBLIC "${CSFML_PATH}/include")

#PATH TO SOURCE
set(SOURCE src/cartes.c src/effets.c src/joueuses.c src/main.c src/personnages.c src/structures.c src/VueJeu.c src/zones.c )

#executable
if(UNIX)
	add_executable(schoolBattle ${SOURCE} )
elseif (WIN32)
	#executable like an application (WIN32) and file with path to the icon(Appicon.rc)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
	add_executable(schoolBattle WIN32 ${SOURCE} Appicon.rc)
endif()

#compile option and definition macro path to ressource
if(UNIX)
	target_compile_options(schoolBattle PUBLIC -Wall -Wextra -std=c99 -g)
	target_compile_definitions(schoolBattle PUBLIC PATH_RESSOURCES="/usr/share/schoolBattle/Ressources")
	target_compile_definitions(schoolBattle PUBLIC SIZE_PATH_RESSOURCES=35)
elseif(WIN32)
	target_compile_definitions(schoolBattle PUBLIC PATH_RESSOURCES="./Ressources")
	target_compile_definitions(schoolBattle PUBLIC SIZE_PATH_RESSOURCES=13)
endif()

#link libraries
if(UNIX)
    target_link_libraries(schoolBattle -lcsfml-f -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lstdc++ m)
elseif (WIN32)
    target_link_libraries(schoolBattle csfml-f sfml-graphics sfml-window sfml-system)
endif()

#generator package
if(UNIX)
	set(CPACK_GENERATOR "DEB")
elseif (WIN32)
	set(CPACK_GENERATOR "NSIS")
endif()

#cpack package
set(CPACK_PACKAGE_NAME "schoolBattle")
set(CPACK_PACKAGE_VERSION "1.0.0")  
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "2 players needed")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Arry")
set(CPACK_NSIS_DISPLAY_NAME "The School Battle")
#desktop application windows
set(CPACK_NSIS_CREATE_ICONS_EXTRA
    "CreateShortCut \\\"$DESKTOP\\\\schoolBattle.lnk\\\" \\\"$INSTDIR\\\\bin\\\\schoolBattle.exe\\\" \\\"-foo -bar\\\" "
)
#icon windows
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/Ressources/Texture/school-battle.ico")

#dll window
if(WIN32)
	file (GLOB WINDOWS_DLL "{WINDOWS_PATH}/*.dll")
	install(FILES ${WINDOWS_DLL} DESTINATION bin)
endif()


install(TARGETS schoolBattle RUNTIME DESTINATION bin)

#install ressources + permissons
if (UNIX)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Ressources" DESTINATION share/schoolBattle FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../CSFML" DESTINATION share/schoolBattle FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE)
elseif (WIN32)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Ressources" DESTINATION . )
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../CSFML" DESTINATION . )
	set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "AccessControl::GrantOnFile \\\".\\\\Ressources\\\" \\\"(BU)\\\" \\\"FullAccess\\\"")
endif()

#desktop linux
if (UNIX)
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/schoolBattle.desktop.in" "${CMAKE_CURRENT_SOURCE_DIR}/schoolBattle.desktop")
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/schoolBattle.desktop" DESTINATION share/applications)
endif()

include(CPack)



