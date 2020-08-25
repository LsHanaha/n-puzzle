import pygame
from pygame.locals import *

import os
import sys
from typing import List

WIDTH, HEIGHT = 800, 800


FPSCLOCK = pygame.time.Clock()


def check_for_quit():
    for _ in pygame.event.get(QUIT):  # get all the QUIT events
        terminate()  # terminate if any QUIT events are present
    for event in pygame.event.get(KEYUP):  # get all the KEYUP events
        if event.key == K_ESCAPE:
            terminate()  # terminate if the KEYUP event was for the Esc key
        pygame.event.post(event)  # put the other KEYUP event objects back


def terminate():
    pygame.quit()
    sys.exit()


def load_background():
    # background image
    background = pygame.image.load(os.path.join(os.getcwd(), 'graphics', 'background.jpg'))
    return background


def set_title_and_icon():
    # Title and icon
    pygame.display.set_caption("N-PUZZLE")
    icon = pygame.image.load(os.path.join(os.getcwd(), 'graphics', 'puzzle.png'))
    pygame.display.set_icon(icon)


def header_text(font):
    # add field header
    header = font.render('Solve this puzzle!', True, (144, 0, 0))
    header_rect = header.get_rect()
    header_rect.center = (WIDTH // 2, HEIGHT // 10)
    return header, header_rect


def vizual(puzzle: List[int], goal: List[int], size: int, solution: str):
    # Window size
    pygame.init()
    font = pygame.font.Font('freesansbold.ttf', 42)

    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    set_title_and_icon()
    background = load_background()
    header, header_rect = header_text(font)

    running = True
    while running:
        check_for_quit()
        screen.blit(background, (0, 0))
        screen.blit(header, header_rect)

        pygame.display.update()


if __name__ == '__main__':
    vizual([1], [2], 3, '4')
