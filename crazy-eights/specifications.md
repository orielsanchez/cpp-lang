## Goal
- Create a 2-player version of Crazy Eights

## Requirements
- Should list 7 cards to user
- Should list 7 hidden cards to cpu opponent
- Should alternate turns between player and cpu opponent
- Should display a draw pile with remaining cards
- Should draw top card from deck and place it next to draw pile at start of game
- Should give option for what player can do, i.e. play one of their cards, draw from the draw pile
- Should allow player to draw from top draw pile when its their turn
- Should allow player to choose which card to play from their hand
- Should have cpu choose random valid option of what to play from their hand
- Should allow only valid moves to be played
- Should keep track of number of cards in each players hand
- Should check if there are no more cards in a players hand after playing a card.
- Should end game and declare winner when there are no moe cards in players hand.
- Should make sure all 52 cards are unique
- Should keep track of number of cards in draw pile
- When its a players turn, should allow plyer to play an 8.
- If a player plays an eight, they should be able to declare the suit the next player is to play.
- If a player is unable to play, they should be notified of no possible play and automatically draw from the draw pile and have their turn ended.
- If player cannot play when stock pile is exhausted, that player must pass the turn to next player.
- If no more cards in draw pile, and no player can play from their hand, game should declare Player with lowest point score the winner
- Should score 50 for 8s, 10 for court cards, and all other cards face value.
- Should create menu from new game

## Tools, Targets, Backup Plan
- nvim text editor
- c++ language
- g++ compiler
- git version control

## Task Hierarchy/Structure of Program
- Start game
- deal cards
- turn loop
    - check win conditions
- declare winner

- Start new game
    - create player, cpu, deck
    - generate random deck of 52 cards
    - alternate dealing from top of deck until each player has 7 cards
    - turn top card of stock pile face up as first card in discard pile
    - create turn loop
        - start first players turn
            - allow player to choose card to play
                - check if card is valid
            - check if no more cards in hand
                - if so, end turn loop
            - if unable to play any card, draw 1 card from stock pile
                - check if stock pile is empty, if so, end turn
            - end turn
        - start cpu turn
            - have computer randomly choose valid card to play
            - check if no more cards in hand
                - if so, end turn loop
            - if unable to play any card, draw 1 card from stock pile
                - check if stock pile is empty, if so end turn loop
            - end cpu turn
        - end turn loop
    - count 
