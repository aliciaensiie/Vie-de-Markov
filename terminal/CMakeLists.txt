cmake_minimum_required(VERSION 3.10)
project(schoolBattle_terminal)

if(WIN32)
	set(WINDOWS_PATH C:/Users/alici/OneDrive/Documents/project4/DLLwindow)
endif()


#PATH TO SOURCE
set(SOURCE src/cartes.c src/effets.c src/joueuses.c src/main.c src/personnages.c src/structures.c src/interface.c src/zones.c )

#executable
if(UNIX)
	add_executable(schoolBattle_terminal ${SOURCE} )
elseif (WIN32)
	#executable like an application (WIN32) and file with path to the icon(Appicon.rc)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
	add_executable(schoolBattle_terminal WIN32 ${SOURCE} Appicon.rc)
endif()

#compile option
if(UNIX)
	target_compile_options(schoolBattle_terminal PUBLIC -Wall -Wextra -std=c99 -g)
elseif (WIN32)
	target_compile_definitions(schoolBattle PUBLIC OPEN_TERMINAL="Start-Process powershell -ArgumentList '-NoExit -Command {Get-Content /tmp/my_fifo; Read-Host 'Press Enter to exit'}'")
endif()

#generator package
if(UNIX)
	set(CPACK_GENERATOR "DEB")
elseif (WIN32)
	set(CPACK_GENERATOR "NSIS")
endif()

#cpack package
set(CPACK_PACKAGE_NAME "schoolBattle_terminal")
set(CPACK_PACKAGE_VERSION "1.0.0")  
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "2 players needed")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Arry")
set(CPACK_NSIS_DISPLAY_NAME "The School Battle / TERMINAL VERSION")
#desktop application windows
set(CPACK_NSIS_CREATE_ICONS_EXTRA
    "CreateShortCut \\\"$DESKTOP\\\\schoolBattle_terminal.lnk\\\" \\\"$INSTDIR\\\\bin\\\\schoolBattle_terminal.exe\\\" \\\"-foo -bar\\\" "
)
#icon windows
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/Ressources/school2.ico")

#dll window
if(WIN32)
	file (GLOB WINDOWS_DLL "{WINDOWS_PATH}/*.dll")
	install(FILES ${WINDOWS_DLL} DESTINATION bin)
endif()


install(TARGETS schoolBattle_terminal RUNTIME DESTINATION bin)

#install ressources + permissons
if (UNIX)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Ressources" DESTINATION share/schoolBattle_terminal FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE)
elseif (WIN32)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Ressources" DESTINATION . )
	set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "AccessControl::GrantOnFile \\\".\\\\Ressources\\\" \\\"(BU)\\\" \\\"FullAccess\\\"")
endif()

#desktop linux
if (UNIX)
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/schoolBattle_terminal.desktop.in" "${CMAKE_CURRENT_SOURCE_DIR}/schoolBattle_terminal.desktop")
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/schoolBattle_terminal.desktop" DESTINATION share/applications)
endif()

include(CPack)



