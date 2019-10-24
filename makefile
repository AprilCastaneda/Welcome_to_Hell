###
### File: makefile
### Author: April Castaneda 
### Description: Makefile for Welcome to Hell
###

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

SRCS = *.cpp
EXEC = Final_Project_v4_Castaneda_April

build:
	${CXX} ${CXXFLAGS} ${SRCS} -o edit

zip:
	zip $(EXEC).zip *.cpp *.hpp *.* makefile

clean:
	rm -rf *o *.dSYM ${EXEC}
