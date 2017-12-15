.PHONY : all clean compile test

all : clean compile test

clean :
	rm -f CommentRemoval.lexer.c CommentRemoval.output CommentRemoval.tab.h CommentRemoval.tab.c output/* preproc

compile :
#	bison -d -v CommentRemoval.y
	flex -o CommentRemoval.lexer.c CommentRemoval.l
#	gcc CommentRemoval.tab.c CommentRemoval.lexer.c -o preproc -lfl
	gcc CommentRemoval.lexer.c -o preproc -lfl

test :
#	./preproc ../STEP_files/Trap.stp > output/out.txt 2> output/err.txt
