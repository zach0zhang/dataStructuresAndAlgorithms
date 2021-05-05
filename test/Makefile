P_NAME			:= testAll
P_SRCS			:= $(wildcard *.cpp)
P_OBJS			:= ${P_SRCS:.c=.o}
P_INCLUDE		:= ../list ../stack ../queue
CXX				:= g++
CFLAGS			:= -g -Wall -O2
CPPFLAGS		:= $(CFLAGS)
CPPFLAGS		+= $(addprefix -I,$(P_INCLUDE))
RM				:= del


.PHONY:			all clean
all:			$(P_NAME)
$(P_NAME):		$(P_OBJS)
				$(CXX) -o $(P_NAME) $(P_OBJS) $(CPPFLAGS)

clean:			
				@- $(RM) $(addprefix $(P_NAME),.exe)