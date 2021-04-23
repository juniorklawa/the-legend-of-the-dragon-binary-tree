cmake_minimum_required(VERSION 3.17)
project(binary_tree_rpg C)

set(CMAKE_C_STANDARD 99)

add_executable(binary_tree_rpg main.c game_base.c game_base.h game_classes.h game_classes.c game_ascii_arts.c game_story.c game_challenges.c)