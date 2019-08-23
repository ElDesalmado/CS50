cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CS50)

set(problems
	01-Mario
	)

foreach(problem ${problems})
	add_executable(${problem} 
		${CMAKE_CURRENT_SOURCE_DIR}/src/${problem}/${problem}.cpp
		)
endforeach(problem)