import pygame
from pygame.locals import *

import os
import sys
import time
from typing import List

WIDTH, HEIGHT = 800, 800
TILESIZE = 80

BOARD_SIZE = 3
XMARGIN = (WIDTH - (TILESIZE * BOARD_SIZE)) // 2
YMARGIN = (HEIGHT - (TILESIZE * BOARD_SIZE)) // 2


BLANK = 0

FPSCLOCK = pygame.time.Clock()
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
BRIGHTBLUE = (0, 50, 255)
DARKTURQUOISE = (3,  54,  73)
GREEN = (0, 204, 0)
RED = (144, 0, 0)
FPS = 30

UP = 'u'
LEFT = 'l'
RIGHT = 'r'
DOWN = 'd'


def make_text(text, text_color, bg_color, top, left):
    text_font = pygame.font.Font('freesansbold.ttf', 30)
    text_surf = text_font.render(text, True, text_color, bg_color)
    text_rect = text_surf.get_rect()
    text_rect.topleft = (left - text_rect.width // 2, top - text_rect.height // 2)
    return text_surf, text_rect


def get_blank_position(board):
    for y in range(BOARD_SIZE):
        for x in range(BOARD_SIZE):
            if board[y][x] == BLANK:
                return y, x


def slide_animation(screen, board, direction):

    speed = 5
    blank_y, blank_x = get_blank_position(board)

    if direction == UP:
        move_y = blank_y - 1
        move_x = blank_x
    elif direction == DOWN:
        move_y = blank_y + 1
        move_x = blank_x
    elif direction == LEFT:
        move_y = blank_y
        move_x = blank_x - 1
    else:
        move_y = blank_y
        move_x = blank_x + 1

    draw_board(screen, board)
    base_screen = screen.copy()
    move_left, move_top = get_left_top_for_tile(move_y, move_x)
    pygame.draw.rect(base_screen, BLACK, (move_left, move_top, TILESIZE, TILESIZE))

    for step in range(0, TILESIZE + 2 * speed, speed):
        check_for_quit()
        screen.blit(base_screen, (0, 0))
        if direction == UP:
            draw_tile(screen, move_y, move_x, board[move_y][move_x], 0, step)
        if direction == DOWN:
            draw_tile(screen, move_y, move_x, board[move_y][move_x], 0, -step)
        if direction == LEFT:
            draw_tile(screen, move_y, move_x, board[move_y][move_x], step, 0)
        if direction == RIGHT:
            draw_tile(screen, move_y, move_x, board[move_y][move_x], -step, 0)

        pygame.display.update()
        FPSCLOCK.tick(FPS)


def make_move(board, move):
    blank_y, blank_x = get_blank_position(board)

    if move == UP:
        board[blank_y][blank_x], board[blank_y - 1][blank_x] = \
            board[blank_y - 1][blank_x], board[blank_y][blank_x]
    elif move == DOWN:
        board[blank_y][blank_x], board[blank_y + 1][blank_x] = \
            board[blank_y + 1][blank_x], board[blank_y][blank_x]
    elif move == LEFT:
        board[blank_y][blank_x], board[blank_y][blank_x - 1] = \
            board[blank_y][blank_x - 1], board[blank_y][blank_x]
    elif move == RIGHT:
        board[blank_y][blank_x], board[blank_y][blank_x + 1] = \
            board[blank_y][blank_x + 1], board[blank_y][blank_x]


def solve_puzzle(screen, board, solution):

    for move in solution:
        check_for_quit()
        slide_animation(screen, board, move)
        make_move(board, move)
        time.sleep(0.5)
    return board


def get_left_top_for_tile(tile_y, tile_x):
    left = XMARGIN + (tile_x * TILESIZE) + tile_x * 5
    top = YMARGIN + (tile_y * TILESIZE) + tile_y * 5
    return left, top


def draw_tile(screen, tile_y, tile_x, tile_value, adj_x=0, adj_y=0):
    text_font = pygame.font.Font('freesansbold.ttf', 30)
    check_for_quit()

    left, top = get_left_top_for_tile(tile_y, tile_x)
    pygame.draw.rect(screen, GREEN, (left + adj_x, top + adj_y, TILESIZE, TILESIZE))
    text_surf = text_font.render(str(tile_value), True, WHITE)
    text_rect = text_surf.get_rect()
    text_rect.center = left + int(TILESIZE / 2) + adj_x, top + int(TILESIZE / 2) + adj_y
    screen.blit(text_surf, text_rect)


def draw_board(screen, board: List[List[int]], message: str = None):
    if message:
        text_surf, text_rect = make_text(message, WHITE, DARKTURQUOISE, 5, 5)
        screen.blit(text_surf, text_rect)

    for tile_y in range(BOARD_SIZE):
        for tile_x in range(BOARD_SIZE):
            if board[tile_y][tile_x]:
                draw_tile(screen, tile_y, tile_x, board[tile_y][tile_x])

    left, top = get_left_top_for_tile(0, 0)
    width = BOARD_SIZE * TILESIZE + BOARD_SIZE * 5 - 5
    height = BOARD_SIZE * TILESIZE + BOARD_SIZE * 5 - 5
    pygame.draw.rect(screen, RED, (left - 5, top - 5, width + 11, height + 11), 4)
    check_for_quit()


def check_for_quit():
    for _ in pygame.event.get(QUIT):
        terminate()
    for event in pygame.event.get(KEYUP):
        if event.key == K_ESCAPE:
            terminate()
        pygame.event.post(event)


def terminate():
    pygame.quit()
    sys.exit()


def load_background():
    background = pygame.image.load(os.path.join(os.getcwd(), 'graphics', 'background.jpg'))
    return background


def set_title_and_icon():
    pygame.display.set_caption("N-PUZZLE")
    icon = pygame.image.load(os.path.join(os.getcwd(), 'graphics', 'puzzle.png'))
    pygame.display.set_icon(icon)


def header_text(font):
    header = font.render('Solve this puzzle!', True, RED)
    header_rect = header.get_rect()
    header_rect.center = (WIDTH // 2, HEIGHT // 10)
    return header, header_rect


def vizual(puzzle: List[int], size: int, solution: str):
    pygame.init()
    font = pygame.font.Font('freesansbold.ttf', 42)

    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    set_title_and_icon()
    header, header_rect = header_text(font)
    puzzle_vizual = [puzzle[i: i + size] for i in range(0, size * size, size)]

    running = True
    while running:
        check_for_quit()
        screen.blit(header, header_rect)

        draw_board(screen, puzzle_vizual)
        pygame.display.update()
        check_for_quit()

        if solve_puzzle(screen, puzzle_vizual, solution):
            text_surf, text_rect = make_text("DONE!", WHITE, BLACK, HEIGHT // 2, WIDTH // 2)
            screen.blit(text_surf, text_rect)
            pygame.display.update()
            time.sleep(1)
            break
        FPSCLOCK.tick(FPS)


if __name__ == '__main__':

    vizual([8, 3, 1, 4, 0, 5, 2, 6, 7], 3, 'lurddruullddruruldlurd')

