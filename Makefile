##
## EPITECH PROJECT, 2020
## B-CPE-110-LYN-1-1-pushswap-amoz.pay
## File description:
## Makefile
##

TARGET		=	mysh#ADD HERE TARGET NAME

SRCFILES	=	main.c	\
				nodes.c	\
				cleanstr.c	\
				array_and_list.c	\
				line_parsing.c	\
				mod_env_list.c\
				exec_cmd.c	\
				load_path.c	\
				sh_commands.c	\
				disp_env.c	\
				cd_ctl.c	\
				setenv.c	\
				unsetenv.c	\
				signal.c	\
				prompt.c	\
				cd_permissions.c#ADD HERE SRC FILES NAME WITHOUT DIR NAME

CFLAGS		=	-I includes

CFLAGS		+=	-Wall -Wextra

LDFLAGS		=	-L lib -lmy

TESTFILES	=	#ADD HERE UNIT TESTS FILES NAME

SRCDIR		=	src/

SRC		=	$(foreach file, $(SRCFILES), $(addprefix $(SRCDIR), $(file)))

OBJFILES	=	$(SRCFILES:.c=.o)

OBJDIR		=	obj/

OBJ			=	$(foreach file, $(OBJFILES), $(addprefix $(OBJDIR), $(file)))

TESTDIR		=	unit_tests/

TEST		=	$(foreach file, $(TESTFILES), $(addprefix $(TESTDIR), $(file)))

TESTNAME	=	crtests

DBNAME		=	debug

CC		=	gcc


all: $(TARGET)
	@echo "\e[32m\e[1mBuild Successful\e[0m"

$(TARGET):	bins
	@echo "\e[34m\e[1mBuilding Target\n\e[0m"
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

lib:
	@echo "\e[34m\e[1mBuilding Lib\n\e[0m"
	@make -C lib/my
	@echo "\e[32m\e[1mLib build Successful\e[0m\n"

bins: lib
	@echo "\e[34m\e[1mBuilding Binaries\n\e[0m"
	@$(CC) -c $(SRC) $(CFLAGS)
	@mv $(OBJFILES) $(OBJDIR)
	@echo "\e[32m\e[1mBinary build Successful\e[0m\n"

clean:
	@rm -f $(OBJ)
	@make clean -C lib/my

fclean:
	@rm -f $(OBJ)
	@rm -f $(TARGET)
	@rm -f $(TESTNAME)
	@rm -f $(DBNAME)
	@make fclean -C lib/my

re:	fclean all

$(TESTNAME):	lib
	@$(CC) -o $(TESTNAME) $(SRC) $(TEST) $(CFLAGS) $(LDFLAGS) --coverage -lcriterion
	./$(TESTNAME)

debug:	lib
	@echo "\e[34m\e[1mBuilding debuging core\n\e[0m"
	@$(CC) -o $(DBNAME) $(SRC) $(CFLAGS) $(LDFLAGS) -g3
	@echo "\e[32m\e[1mDebuging gore build successful\e[0m\n"

.PHONY:	all lib bins clean fclean re debug
