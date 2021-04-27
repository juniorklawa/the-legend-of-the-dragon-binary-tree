all:
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
clean:
	rm game