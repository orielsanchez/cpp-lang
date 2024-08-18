### User Story 1: Basic Gameplay - Human vs. Human

**Title**: Human players want to play chess against each other.  
**As a**: Chess player  
**I want to**: Play a full game of chess against another human player, alternating turns.  
**So that**: I can enjoy a competitive game with a friend or opponent.

**Acceptance Criteria**:  
- The game starts with a standard chessboard setup.
- Players take turns making moves in algebraic notation.
- The game enforces all chess rules (e.g., check, checkmate, stalemate).
- The game ends with checkmate, stalemate, draw, or resignation.

---

### User Story 2: Playing Against AI

**Title**: Human player wants to play chess against the AI.  
**As a**: Chess player  
**I want to**: Play a game of chess against an AI opponent.  
**So that**: I can practice my chess skills when no human opponent is available.

**Acceptance Criteria**:  
- The player can choose to play against an AI opponent before the game starts.
- The AI should make legal and competitive moves.
- The AI difficulty level can be selected before starting the game (e.g., easy, medium, hard).
- The game enforces all chess rules, and AI respects them.

---

### User Story 3: Undo Move

**Title**: Player wants the ability to undo a move.  
**As a**: Chess player  
**I want to**: Undo the last move I made.  
**So that**: I can correct mistakes or reconsider my strategy.

**Acceptance Criteria**:  
- The player can undo the last move at any point during their turn.
- The game restores the previous board state before the move was made.
- Undoing moves should be allowed until the game ends.

---

### User Story 4: Load a Game State via FEN

**Title**: Player wants to load a specific board state using FEN.  
**As a**: Chess player  
**I want to**: Load a specific chessboard position using a FEN string.  
**So that**: I can analyze particular game positions or resume an interrupted game.

**Acceptance Criteria**:  
- The player can input a FEN string to load a specific board state.
- The game sets the board to the loaded state and resumes from that point.
- All chess rules are enforced based on the loaded state.

---

### User Story 5: Move Validation Feedback

**Title**: Player wants feedback on illegal moves.  
**As a**: Chess player  
**I want to**: Be informed if I try to make an illegal move.  
**So that**: I can correct my move and play within the rules.

**Acceptance Criteria**:  
- When a player attempts an illegal move, the game provides feedback indicating why the move is illegal.
- The game does not allow the illegal move to be executed.
- The player can retry the move until a valid one is made.

---
