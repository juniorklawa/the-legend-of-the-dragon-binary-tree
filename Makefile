teste1: # Jogo vai até o final 1
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 1 1 2 2 2 1 1| ./game

teste2: # Jogo vai até o final 2
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 1 1 2 2 2 1 2| ./game

teste3: # Falha critica 1
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 2 1 1 1 1 2 1 1 1 2 2 2 1 1 1 1| ./game

teste4: # Falha critica 2
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 2 1 1 2 1 1 1 2 2 2 1 1 1 1| ./game

teste5: # Falha critica 3
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 1 2 2 2 2| ./game

teste6: # Falha critica 4
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 2 2 2 1 1| ./game

teste7: # Falha critica 5
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 2 2 2 1 1| ./game


teste8: # Falha no desafio 1
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 2 2 1 2 2 2 1 1| ./game

teste9: # Falha no desafio 2
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 2 2 2 2 2 2 1 1| ./game

teste10: # Falha no desafio 3
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 1 1 1 2 2 1 1| ./game

teste11: # Falha no desafio 4
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 1 1 2 2 2 2 1| ./game

teste12: # Teste load
	gcc -w -o game main.c game_story.c game_classes.c game_base.c game_ascii_arts.c game_challenges.c
	yes 1 "Teste" 1 1 1 1 1 2 1 1 1 2 2 2 1 2| ./game
	yes 2 1|./game

clean:
	rm game